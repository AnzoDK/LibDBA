#include "../includes/api.h"
std::string* tempString = new std::string();
    std::size_t callback(
            void* in,
            std::size_t size,
            std::size_t num,
            void* out)
    {
       
        tempString->append((char*)in);
        out = tempString;
        return size * num;
        
    }


DBA::DBAapi::DBAapi()
{
    apisettings = ApiSettings();
    apisettings.agent = ApiAgent::Android;
    apisettings.version = ApiVersion::v2;
    apisettings.currentApiUrl = fullV2Url;
}

DBA::DBAapi::DBAapi(ApiVersion _version, ApiAgent _agent)
{
    apisettings = ApiSettings();
    apisettings.agent = _agent;
    apisettings.version = _version;
    apisettings.currentApiUrl = GetApiUrl(_version);
}

DBA::DBAapi::DBAapi(ApiVersion _version, ApiAgent _agent, bool _debug)
{
    apisettings = ApiSettings();
    apisettings.agent = _agent;
    apisettings.version = _version;
    apisettings.debug = _debug;
    apisettings.currentApiUrl = GetApiUrl(_version);
}

DBA::DBAapi::DBAapi(ApiVersion _version, ApiAgent _agent, std::string _customKey)
{
    apisettings = ApiSettings();
    apisettings.agent = _agent;
    apisettings.version = _version;
    apisettings.customKey = _customKey;
    apisettings.currentApiUrl = GetApiUrl(_version);
}

DBA::DBAapi::DBAapi(ApiVersion _version, ApiAgent _agent, std::string _customKey, bool _debug)
{
    apisettings = ApiSettings();
    apisettings.agent = _agent;
    apisettings.version = _version;
    apisettings.customKey = _customKey;
    apisettings.debug = _debug;
    apisettings.currentApiUrl = GetApiUrl(_version);
}
std::string DBA::DBAapi::Search(std::string searchText)
{
    std::string url = apisettings.currentApiUrl + "taxonomy/search?=" + searchText + "&format=json";
    return CurlJsonRequest(url);
}
std::string DBA::DBAapi::SearchInCategory(std::string searchText, DBA::Category category)
{
    return "Not Implimented";
}
//A function to get the localized string instead of the enum name
std::string DBA::DBAapi::GetCategoryName(Category cat)
{
    switch(static_cast<int>(cat))
    {
        default:
            return "Unknown or unimplimented category";
        break;
    }
}

void DBA::DBAapi::GetCategories()
{
    std::string url = apisettings.currentApiUrl + "taxonomy?format=json";
    std::ofstream out = std::ofstream("CurrCat.json",std::ios::out);
    out << CurlJsonRequest(url,0);
    out.close();
    std::cout << "Saved to CurrCat.json" << std::endl;
}

std::string DBA::DBAapi::CurlJsonRequest(std::string requestUrl, bool WriteToFile)
{
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) 
    {
        struct curl_slist *chunk = NULL;
        std::string* responseString = new std::string();

        //Adding the custom User-Agent
        if(apisettings.agent == ApiAgent::Android)
        {
            chunk = curl_slist_append(chunk,fullAndroidUserAgent.c_str());
            //Adding the ApiKey
            chunk = curl_slist_append(chunk,fullAndroidApiKey.c_str());
        }
        else
        {
            chunk = curl_slist_append(chunk,fullIphoneUserAgent.c_str());
            //Adding the ApiKey
            chunk = curl_slist_append(chunk,fullIphoneApiKey.c_str());
        }
        
        if(apisettings.customKey != "")
        {
            std::string tmps = "DbaApiKey: " + apisettings.customKey;
            chunk = curl_slist_append(chunk,tmps.c_str());
        }
        
        //Passing the headers to curl
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

        
        
        //some api calls require v2 and some v3 - this section is made so that if search (taxonomy/search?q=) becomes v3, it will be easier to change.
        //api calls that require v3 will always go v3 no matter the setting. So most api calls will work if the setting is v2

        //Setting URL
        curl_easy_setopt(curl, CURLOPT_URL, requestUrl.c_str());

        //Setting curl to verbose as this is a debug build
        if(apisettings.debug)
        {
            curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        }

        //Setting up callback
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &callback);

        //Setting where to store response
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseString);

        //Perform the request - old
        res = curl_easy_perform(curl);
        

        if(res != CURLE_OK)
        {
            std::cout << "Request failed - function used: 'curl_easy_peform()' with error: ";
            std::cout << curl_easy_strerror(res) << std::endl;
        }
        else
        {

            //Cleaning up curl
            curl_easy_cleanup(curl);

            //Freeing the custom headers
            curl_slist_free_all(chunk);
            

            Json::Value jsonData;
            Json::Reader jsonReader;
            if (jsonReader.parse(*tempString, jsonData))
            {
                
                //Formatting the string to be easier to read
                *tempString = jsonData.toStyledString();
                
                if(apisettings.debug && WriteToFile)
                {
                    //While debug is true - let's write the responseString to a file :)
                    std::ofstream of = std::ofstream("responseData.json",std::ios::out);
                    std::cout << "Reponse Written to 'responseData.json'" << std::endl;
                    of << jsonData.toStyledString();
                    of.close();
                }
                
                //Delete the, no longer needed, responseString
                delete(responseString);
            }
        }
        
    }
    else
    {
        /*Error on creation of curl - Prob a libcurl issue*/
        return "LibCurl Error - Curl Could not be initilized";
    }
    return *tempString;
}
std::string DBA::DBAapi::GetApiUrl(DBA::ApiVersion ver)
{
    std::string apiVerson = std::string();
    
    switch(static_cast<int>(ver))
    {
        case 0:
            /*Break as we cant use it*/
            std::cout << "Useless Api Selected" << std::endl;
        break;
        
        case 1:
            apiVerson = v2Url;
        break;
        
        case 2:
            apiVerson = v3Url;
        break;
        
        default:
            std::cout << "unexpected api version" << std::endl;
        break;
    }
    return baseUrl + apiVerson;
}


