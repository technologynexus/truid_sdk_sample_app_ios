//
//  ActivationRequest.h
//  TruIDSDK
//
//  Created by vijay on 31/07/16.
//  Copyright © 2016 nexusgroup. All rights reserved.
//

#ifndef ActivationRequest_h
#define ActivationRequest_h
#import "TSDKProfile.h"
#import "Constants.h"
/*!
 @class TSDKActivationRequest
 @brief The ActivationRequest class
 @discussion This class should be used with TSDKProfileManager.ActivateProfile(). To create instance of this class use Build() method of TSDKActivationRequestBuilder.
 @helps It help TSDKProfileManagerImpl class.
 */
@interface TSDKActivationRequest : NSObject
{
    @private
    NSString * host;
    NSNumber *  port;
    NSString * scheme;
    NSString * path;
    
    @public
    NSString * activationCode;
    NSString * userId;
    NSString * seed;
    NSString * profileName;
    ProfileType profileType;

}
/*! this is activation code for DSKPP request*/
@property (nonatomic, retain)NSString * activationCode;
/*! user id for dskpp request*/
@property (nonatomic,retain)NSString * userId;
/*! this is seed field*/
@property (nonatomic,retain)NSString * seed;
/*! this profile type , synchronized or challenge*/
@property ProfileType profileType;
/*! name of profile to be created*/
@property (nonatomic, retain)NSString * profileName;
/*! Port of DSKPP server*/
@property (nonatomic, retain)NSNumber * port;
/*! Host name of DSKPP server*/
@property (nonatomic,retain) NSString * host;

/*!
 @brief Initializer method of this class. It fetches required fields from URL.
 @param url This is activation address for DSKPP request.
 @return Initialized object.
 */
-(id) initWithUrl:(NSString *) url;

/*!
 @brief This method is used in DSKPP class to get activation URL, it forms URL from fields and return it.
 @return Activation URL for DSKPP.
 */
-(NSString *) GetActivationURI;
/*!
 @brief It fetches required fields from URL. This method is called internally.
 @param url This is activation address for DSKPP request.
 */
-(void) SetActivationURI:(NSString *) url;
/*!
 @brief This is used internally to check weather request is DSKPP.
 */
-(BOOL) IsDSKPP;
/*!
 @brief This is used internally.
 @return Returns true if user id is missing.
 */
-(BOOL) NeedUserId;
/*!
 @brief This is used internally.
 @return Returns true if activation code is needed.
 */
-(BOOL) NeedActivationCode;
/*!
 @brief This is used internally.
 @return Returns true if seed is needed.
 */
-(BOOL) NeedSeed;
/*!
 @brief This is used internally.
 @return Returns true if profile type is needed.
 */
-(BOOL) NeedProfileType;
@end
#endif /* ActivationRequest_h */
