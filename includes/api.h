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

USE AT YOUR OWN RISK

As of now it seems that only Android emulation works

By AnzoDK
*/

/*
Data collected from dissasemble of APK file.
 public static final String HTTPHEADER_ACCEPT = "Accept";
 public static final String HTTPHEADER_ADVERTISINGID = "X-Ad-Id";
 public static final String HTTPHEADER_AUTHORIZATION = "Authorization";
 public static final String HTTPHEADER_DBAPIKEY = "dbaapikey";
 public static final String HTTPHEADER_EXPERIMENT = "Dba-Experiments-v2";
 public static final String HTTPHEADER_GDPR_CONSENT = "X-GdprConsent";
 public static final String HTTPHEADER_IMPRESSION_COUNTER = "X-Ad-DFP-Impression-Counter";
 public static final String HTTPHEADER_INSTALLATIONID = "X-InstallationId";
 public static final String HTTPHEADER_USERAGENT = "User-Agent";



public interface DbaAuthApi {
    @GET("/api/v2/oauth/invalidatetoken")
    C7359l<LoginResponse> invalidateToken(@Query("oauth_token") String str);

    @FormUrlEncoded
    @POST("/api/v2/oauth/accesstoken")
    C7359l<LoginResponse> login(@Field("username") String str, @Field("password") String str2);

    @GET("/api/v2/oauth/refreshtoken?grant_type=refresh_token")
    C7359l<LoginResponse> refreshToken(@Query("refresh_token") String str);
}
public interface DbaRestApi {
    @GET("/api/v2/user/changepassword")
    Object getChangePassword(C8641d<? super Response<ChangePasswordResponse>> dVar);

    @GET("/api/v2/user/password/finishreset/")
    Object getFinishResetPassword(C8641d<? super Response<FinishResetPasswordResponse>> dVar);

    @GET("api/v3/homepage/feed")
    Object getFrontPageFeed(@Query("feedKey") String str, @Query("page") int i, @Query("latitude") Double d, @Query("longitude") Double d2, C8641d<? super Response<FrontPageFeed>> dVar);

    @GET("api/v2/ads/search/intermingled")
    Object getIntermingledSearchByOptions(@QueryMap Map<String, String> map, C8641d<? super Response<IntermingledSearchResponse>> dVar);

    @GET("api/v2/ads/search/intermingled/fromweb")
    Object getIntermingledSearchByUrl(@Query("Url") String str, C8641d<? super Response<IntermingledSearchResponse>> dVar);

    @GET("api/v2/ads/verticalsearch/intermingled")
    Object getIntermingledVerticalSearchByOptions(@QueryMap Map<String, String> map, C8641d<? super Response<IntermingledSearchResponse>> dVar);

    @GET("api/v3/dba-soi/{tenant}/{userId}/profile")
    Object getProfile(@Path("tenant") String str, @Path("userId") String str2, C8641d<? super Response<ProfileDto>> dVar);

    @GET("api/v2/soi/profile/{sellerId}")
    Object getProfileLegacy(@Path("sellerId") String str, @Query("ownerType") Integer num, C8641d<? super Response<SellersProfileResponse>> dVar);

    @GET("api/v3/dba-soi/{tenant}/{userId}/listings")
    Object getProfileListings(@Path("tenant") String str, @Path("userId") String str2, @Query("page") int i, C8641d<? super Response<SoiListingsDto>> dVar);

    @GET("api/v2/soi/{sellerId}")
    Object getProfileListingsLegacy(@Path("sellerId") String str, @Query("ownerType") Integer num, @Query("page") Integer num2, @Query("pageSize") Integer num3, C8641d<? super Response<SellersOtherItemsResponse>> dVar);

    @GET("api/v2/syi/externalid/{ExternalId}/allowedlistingactions")
    Object getSyiAllowedListingActionsAsync(@Path("ExternalId") Integer num, @Query("VipType") String str, C8641d<? super Response<SyiAllowedListingActionsDto>> dVar);

    @GET("api/v3/vip/")
    Object getVipByListingIdAsync(@Query("listingId") String str, C8641d<? super Response<VipDto>> dVar);

    @GET("api/v2/listing/{externalId}/secondaryinfo")
    Object getVipSecondaryListingInfoAsync(@Path("externalId") String str, @Query("VipType") String str2, C8641d<? super Response<SecondaryListingInfoResponse>> dVar);

    @POST
    Object postAction(@Url String str, C8641d<? super Response<Void>> dVar);

    @POST("/api/v2/ads/{ExternalId}/state?state=1")
    Object postActivateListing(@Path("ExternalId") String str, C8641d<? super Response<Void>> dVar);

    @POST("/api/v2/ads/{ExternalId}/state?state=2")
    Object postDeactivateListing(@Path("ExternalId") String str, C8641d<? super Response<Void>> dVar);

    @POST("/api/v2/ads/{ExternalId}/delete/")
    Object postDeleteListing(@Path("ExternalId") String str, @Query("sold") Boolean bool, C8641d<? super Response<Void>> dVar);

    @POST("/api/v2/ads/{ExternalId}/disable-running-subscription")
    Object postDisableRunningSubscription(@Path("ExternalId") String str, C8641d<? super Response<Void>> dVar);

    @POST("/api/v2/ads/{ExternalId}/enable-running-subscription")
    Object postEnableRunningSubscription(@Path("ExternalId") String str, C8641d<? super Response<Void>> dVar);

    @POST("/api/v2/user/password/finishreset/")
    Object postFinishResetPassword(@Query("passwordresettoken") String str, @Query("newpassword") String str2, C8641d<? super Response<FinishResetPasswordResponse>> dVar);

    @POST("/api/v2/ads/{ExternalId}/emailstoowner/")
    Object postSendEmailForListing(@Path("ExternalId") String str, @Query("email") String str2, @Query("name") String str3, @Query("message") String str4, C8641d<? super Response<Void>> dVar);

    @POST("/api/v2/user/password/startreset/")
    Object postStartResetPassword(@Query("email") String str, C8641d<? super Response<StartResetPasswordResponse>> dVar);

    @PUT("/api/v2/user/changepassword")
    Object putChangePassword(@Body ChangePasswordRequest changePasswordRequest, C8641d<? super Response<ChangePasswordResponse>> dVar);
}
public interface DbaRestApiLegacy {
    @PUT("/api/v2/ads/favorites/{listingId}")
    C7359l<FavoriteChangedResponse> addFavorite(@Path("listingId") String str);

    @DELETE
    C7359l<Response<Void>> deleteConversation(@Url String str);

    @DELETE("api/v2/social/followees/{FolloweeId}")
    C7359l<Response<Void>> deleteFollowUserRequest(@Path("FolloweeId") String str);

    @DELETE("api/v2/payment/{PaymentId}/creditcard")
    C7359l<Response<Void>> deleteKeepOrDiscardCreditCardRequest(@Path("PaymentId") String str);

    @DELETE("/api/v2/notifications/subscription")
    C7359l<Response<Void>> deleteSubscriptionRequest(@Query("token") String str, @Query("tokentype") String str2);

    @GET("/api/v2/search/abundancesearch")
    C7359l<AbundanceSearchResponse> getAbundanceSearchRequest(@QueryMap Map<String, String> map);

    @GET("api/v2/app/configuration")
    C7359l<AppConfigurationResponse> getAppConfigurationRequest();

    @GET("api/v2/search/blog/section/{SectionId}")
    C7359l<BlogContentResponse> getBlogContentBySectionRequest(@Path("SectionId") Integer num);

    @GET("api/v2/user")
    C7359l<CurrentUserResponse> getCurrentUserRequest();

    @GET("/api/v2/ads/favorites")
    C7359l<FavoriteResponse> getFavorites(@QueryMap Map<String, String> map);

    @GET("api/v2/featuretoggles")
    C7359l<FeatureToggles> getFeatureToggles();

    @GET("api/v2/social/followees")
    C7359l<FolloweesResponse> getFollowees();

    @GET("api/v2/common/geocode")
    C7359l<GeocodeResponse> getGeocodeRequest(@Query("Address") String str, @Query("ZipCode") String str2, @Query("City") String str3, @Query("Country") String str4);

    @GET("api/v2/tracking/global")
    C7359l<GlobalTrackingResponse> getGlobalTrackingRequest();

    @GET("api/v2/ads/search/intermingled/fromweb")
    C7359l<Response<IntermingledSearchResponse>> getIntermingledByDbaUrlRequest(@Query("Url") String str);

    @GET("api/v2/ads/search/intermingled")
    C7359l<Response<IntermingledSearchResponse>> getIntermingledSearchRequest(@QueryMap Map<String, String> map);

    @GET("api/v2/ads/verticalsearch/intermingled")
    C7359l<Response<IntermingledSearchResponse>> getIntermingledVerticalSearchRequest(@QueryMap Map<String, String> map);

    @GET("api/v2/search/latest/category/{CategoryId}")
    C7359l<LatestSearchesResponse> getLatestSearchesRequest(@Path("CategoryId") Integer num);

    @GET("/api/v2/listing/{ExternalId}/conversation/buyer")
    C7359l<BuyerConversation> getListingBuyerConversation(@Path("ExternalId") String str);

    @GET("api/v2/ads/{ExternalId}")
    C7359l<C8782Ad> getListingByExternalIdRequest(@Path("ExternalId") String str);

    @GET("/api/v2/listing/{ExternalId}/conversation")
    C7359l<BuyerConversation> getListingConversation(@Path("ExternalId") String str);

    @GET("/api/v2/listing/{ExternalId}/conversation/seller")
    C7359l<SellerConversation> getListingSellerConversation(@Path("ExternalId") String str);

    @GET("api/v2/messagecenter/items")
    C7359l<MessageCenterItemsResponse> getMessageCenterItemsRequest();

    @GET("api/v2/messagecenter/state")
    C7359l<MessageCenterStateResponse> getMessageCenterStateRequest();

    @GET("api/v2/taxonomy/predict")
    C7359l<PredictiveTaxonomyResponse> getPredictiveTaxonomyRequest(@Query("Query") String str, @Query("SectionId") Integer num, @Query("CategoryId") Integer num2);

    @GET("api/v2/user/profile")
    C7359l<ProfileResponse> getProfileRequest();

    @GET("api/v2/notifications/resolve-location")
    C7359l<ResolveLocationResponse> getResolveLocationRequest(@Query("Data") String str);

    @GET("resources")
    C7359l<Response<Void>> getResources(@Query("apiKey") String str);

    @GET("api/v2/listing/{ExternalId}/secondaryinfo")
    C7359l<SecondaryListingInfoResponse> getSecondaryListingInfoRequest(@Path("ExternalId") String str, @Query("VipType") String str2);

    @GET("api/v2/users")
    C7359l<PutUserResponse> getStartCreateUserRequest();

    @GET("api/v2/listing/{ExternalId}/complain")
    C7359l<ListingComplaintResponse> getStartListingComplaintRequest(@Path("ExternalId") String str);

    @GET("api/v2/common/startup-message")
    C7359l<StartupMessageResponse> getStartupMessageRequest();

    @GET("api/v2/syi/externalid/{ExternalId}")
    C7359l<SyiResponse> getSyiStateByExternalIdRequest(@Path("ExternalId") Integer num);

    @GET("api/v2/syi/syiid/{SyiId}")
    C7359l<SyiResponse> getSyiStateRequest(@Path("SyiId") String str);

    @GET("api/v2/taxonomy")
    C7359l<List<TaxonomySectionGroup>> getTaxonomyRequest();

    @GET("api/v2/taxonomy/search")
    C7359l<List<SyiClassificationDto>> getTaxonomySearchRequest(@Query("q") String str);

    @GET("/api/v2/user/consent")
    C7359l<ConsentData> getUserConsent();

    @GET("/api/v2/ads/user")
    C7359l<List<C8782Ad>> getUserListings(@Query("page") int i, @Query("pageSize") int i2);

    @GET("/api/v2/search/verticalsearch")
    C7359l<VerticalSearchModelResponse> getVerticalSearchModelRequest(@QueryMap Map<String, String> map);

    @POST("api/v2/syi/{SyiId}/vehicle/initializedrilldown?useSelectedClassificationAsMake=true")
    C7359l<SyiResponse> initializeDrilldownRequest(@Path("SyiId") String str);

    @POST("api/v2/syi/{SyiId}/vehicle/initializedrilldown?useSelectedClassificationAsMake=false")
    C7359l<SyiResponse> initializeDrilldownWithoutMakeRequest(@Path("SyiId") String str);

    @POST("api/v2/syi/{SyiId}/vehicle/licenseplate/{Licenseplate}")
    C7359l<Vehicle> lookupLicenseplateRequest(@Path("SyiId") String str, @Path("Licenseplate") String str2);

    @POST("/api/v2/messagecenter/markallread")
    C7359l<Response<Void>> markAllMessagesRead();

    @POST
    C7359l<BuyerConversation> postBuyerComment(@Url String str, @Body ConversationRequest conversationRequest);

    @POST("api/v2/tracking/ctr/{EventId}")
    C7359l<Response<Void>> postCtrTrackingRequest(@Path("EventId") String str, @Body CtrTrackingRequest ctrTrackingRequest);

    @POST("api/v2/payment/{PaymentId}/accept")
    C7359l<PaymentResponse> postDibsAcceptPaymentRequest(@Path("PaymentId") String str, @Body DibsAcceptPaymentRequest dibsAcceptPaymentRequest);

    @POST("api/v2/payment/{PaymentId}/paywithsavedcard")
    C7359l<SyiPaymentResponse> postPayWithSavedCardRequest(@Path("PaymentId") String str, @Body PayWithSavedCardRequest payWithSavedCardRequest);

    @POST("api/v2/payment/{PaymentId}/prepare")
    C7359l<SyiPaymentDetailsDto> postPreparePaymentRequest(@Path("PaymentId") String str);

    @POST("/api/v2/listing/{ExternalId}/conversation/viewed")
    C7359l<Response<Void>> postRegisterConversationViewed(@Path("ExternalId") String str);

    @POST
    C7359l<SellerConversation> postSellerComment(@Url String str, @Body ConversationRequest conversationRequest);

    @POST("api/v2/shipping/requestpackagelabel")
    C7359l<Response<Void>> postSendRequestShippingLabelRequest(@Body SendRequestShippingLabelRequest sendRequestShippingLabelRequest);

    @POST("api/v2/users/{EmailAddress}/start-reset-password")
    C7359l<Response<Void>> postStartResetPasswordRequest(@Path("EmailAddress") String str);

    @POST("api/v2/syi/pictures/set")
    C7359l<SyiResponse> postSyiAddPicturesRequest(@Body SyiAddPicturesRequest syiAddPicturesRequest);

    @POST("api/v2/syi/classification")
    C7359l<SyiResponse> postSyiAssignClassificationListingTypeRequest(@Body SyiAssignClassificationListingTypeRequest syiAssignClassificationListingTypeRequest);

    @POST("api/v2/syi/create/{SyiId}")
    C7359l<SyiConfirmationDto> postSyiCreateRequest(@Path("SyiId") String str, @Body SyiCreateRequest syiCreateRequest);

    @POST("api/v2/syi/payment/{SyiId}/accept")
    C7359l<SyiPaymentResponse> postSyiDibsAcceptPaymentRequest(@Path("SyiId") String str, @Body SyiDibsAcceptPaymentRequest syiDibsAcceptPaymentRequest);

    @POST("api/v2/syi/payment/{SyiId}/web/accept")
    C7359l<SyiPaymentResponse> postSyiDibsAcceptPaymentRequestWeb(@Path("SyiId") String str, @Body SyiDibsAcceptPaymentRequest syiDibsAcceptPaymentRequest);

    @POST("api/v2/syi/edit/{SyiId}")
    C7359l<SyiResponse> postSyiEditRequest(@Path("SyiId") String str, @Body SyiEditRequest syiEditRequest);

    @POST("api/v2/syi/payment/{SyiId}/paywithsavedcard")
    C7359l<SyiPaymentResponse> postSyiPayWithSavedCardRequest(@Path("SyiId") String str, @Body SyiPayWithSavedCardRequest syiPayWithSavedCardRequest);

    @POST("api/v2/syi/payment/{SyiId}/prepare")
    C7359l<SyiPaymentDetailsDto> postSyiPreparePaymentRequest(@Path("SyiId") String str, @Body SyiPreparePaymentRequest syiPreparePaymentRequest);

    @POST("api/v2/syi/publish/{SyiId}")
    C7359l<SyiResponse> postSyiPublishRequest(@Path("SyiId") String str);

    @POST("api/v2/syi/edit/{SyiId}/runningSubscription")
    C7359l<Response<Void>> postSyiRunningSubscriptionRequest(@Path("SyiId") String str, @Body SyiRunningSubscriptionRequest syiRunningSubscriptionRequest);

    @POST("api/v2/syi/setdependentmatrixdata/{SyiId}")
    C7359l<SyiMatrixDataDto> postSyiSetDependentMatrixDataRequest(@Path("SyiId") String str, @Body SyiSetDependentMatrixDataRequest syiSetDependentMatrixDataRequest);

    @POST("api/v2/syi/start")
    C7359l<SyiResponse> postSyiStartRequest();

    @POST("/api/v2/syi/pictures/upload")
    C7359l<SyiUploadPictureResponse> postSyiUploadPictureRequest(@Body RequestBody requestBody);

    @POST("api/v2/syi/edit/{SyiId}/products/upsell")
    C7359l<SyiUpsellResponse> postSyiUpsellRequest(@Path("SyiId") String str, @Body SyiUpsellRequest syiUpsellRequest);

    @POST("/api/v2/users/profile-picture")
    C7359l<UploadPictureResponse> postUploadProfilePictureRequest(@Body RequestBody requestBody);

    @PUT("api/v2/user/subscription/cancel")
    C7359l<CancelDbaPlusSubscriptionResponse> putCancelDbaPlusSubscriptionRequest();

    @PUT("api/v2/listing/{ExternalId}/complain")
    C7359l<ListingComplaintResponse> putCreateListingComplaintRequest(@Path("ExternalId") String str, @Body CreateListingComplaintRequest createListingComplaintRequest);

    @PUT("api/v2/social/followees/{FolloweeId}")
    C7359l<Response<Void>> putFollowUserRequest(@Path("FolloweeId") String str);

    @PUT("api/v2/tracking/ga/{BatchId}")
    C7359l<GATrackingResponse> putGATrackingRequest(@Path("BatchId") String str, @Body GATrackingRequest gATrackingRequest);

    @PUT("api/v2/payment/{PaymentId}/creditcard")
    C7359l<Response<Void>> putKeepOrDiscardCreditCardRequest(@Path("PaymentId") String str);

    @PUT("api/v2/users")
    C7359l<PutUserResponse> putPutUserRequest(@Body PutUserRequest putUserRequest);

    @PUT("/api/v2/notifications/subscription")
    C7359l<ResponseBody> putSubscriptionRequest(@Query("token") String str, @Query("tokentype") String str2, @Query("brazeenabled") boolean z);

    @PUT("api/v2/user/profile/description")
    C7359l<Response<Void>> putUpdateProfileDescriptionRequest(@Body UpdateProfileDescriptionRequest updateProfileDescriptionRequest);

    @DELETE("/api/v2/ads/favorites/{listingId}/delete")
    C7359l<FavoriteChangedResponse> removeFavorite(@Path("listingId") String str, @Query("ft") int i);

    @POST("api/v2/user/profile/resendvalidationemail")
    C7359l<Response<Void>> resendValidationEmail();

    @POST("api/v2/syi/{SyiId}/vehicle/variant/{VariantId}")
    C7359l<SyiResponse> selectVehicleVariantRequest(@Path("SyiId") String str, @Path("VariantId") String str2);

    @PUT("/api/v2/user/consent")
    C7359l<Response<Void>> setUserConsent(@Body ConsentData consentData);
}

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
        
        std::string CurlJsonRequest(std::string requestUrl,bool writeToFile=1);
        std::string GetApiUrl(ApiVersion ver);
};
}
