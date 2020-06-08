#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
namespace DBA
{
/*
DBA.dk API LIB - UNVERIFIED TEST VERSION 0.1-a

NOT READY FOR RELEASE

USE AT YOUR OWN RISK

As of now it seems that only Android emulation works

By AnzoDK
*/
enum ApiVersion {v1/*v1 does not work anymore*/,v2,v3};
enum ApiAgent {Android,iPhone};
enum Category{};
struct ApiSettings
{
    ApiVersion version;
    ApiAgent agent;
    std::string customKey = "";
    bool debug = 0;
    std::string currentApiUrl;
};

class DBAapi
{
    public:
        DBAapi();
        DBAapi(ApiVersion _version, ApiAgent _agent);
        DBAapi(ApiVersion _version, ApiAgent _agent, bool _debug);
        DBAapi(ApiVersion _version, ApiAgent _agent, std::string _customKey);
        DBAapi(ApiVersion _version, ApiAgent _agent, std::string _customKey, bool _debug);
        std::string Search(std::string searchText);
        std::string SearchInCategory(std::string searchText, Category category);
        
        //Saves the current Categories from the api to CurrCat.json on disk
        void GetCategories();
        
        //Get Localized Category name
        std::string GetCategoryName(Category cat);
        
    private:
        std::string iphoneUserAgent = "dba/5.9 iPhone 12.1"; 
        std::string androidUserAgent = "Android"; /*found by NaY at the forum mentioned below - and is needed to fool the api to allow the lib to access the api - Update: some say that it is not needed, but I have not had any success without*/
        std::string androidApiKey = "64424762-f650-450f-909d-08d6d22703fd"; /*Apikey found by decompiling of the DBA app on android - Credit to Unknown poster on http://fas.mide.dk/2011/11/hemmelig-dba-api.html*/
        std::string iphoneApiKey = "3d8cbae-ae89-47bb-a423-08d646555519";
        std::string baseUrl = "https://api.dba.dk/api/";
        std::string v3Url = "v3/"; /*Only has a few features - most are v2*/
        std::string v2Url = "v2/";

        /* small sections to create C strings for later use */

        std::string fullAndroidUserAgent = "User-Agent: " + androidUserAgent;
        std::string fullIphoneUserAgent = "User-Agent: " + iphoneUserAgent;
        std::string fullAndroidApiKey = "DbaApiKey: " + androidApiKey;
        std::string fullIphoneApiKey = "DbaApiKey: " + iphoneApiKey;
        std::string fullV3Url = "https://api.dba.dk/api/v3/";
        std::string fullV2Url = "https://api.dba.dk/api/v2/";
        
        ApiSettings apisettings;
        //Send an API-request and do minimal Json Processing on it
        std::string CurlJsonRequest(std::string requestUrl,bool writeToFile=1);
        //Get the API url for the selected ApiVersion
        std::string GetApiUrl(ApiVersion ver);
};
}
