//
//  ActivationRequestBuilder.h
//  TruIDSDK
//
//  Created by vijay on 31/07/16.
//  Copyright © 2016 nexusgroup. All rights reserved.
//

#ifndef ActivationRequestBuilder_h
#define ActivationRequestBuilder_h
#import <Foundation/Foundation.h>
#import "TSDKProfile.h"
#import "TSDKActivationRequest.h"
#import "Constants.h"
/*!
 @class TSDKActivatioRequestBuilder
 @brief This class should be used to create activation request for new porfile.
 @discussion This class can be instantiated with a activation URL. It can also be instantiated without any parameter, in that case user code has to set required fileds for profile activation.
 @classdesign When instantiated with URL it extracts required fields from URL. Build method throw exception in case of any missing fileds for activation of profile.
 */
@interface TSDKActivationRequestBuilder : NSObject
{
    @public
    NSString * host;
    NSString * activationCode;
    NSString * userId;
    NSString * seed;
    ProfileType profileType;
    NSString * link;
    NSString * profileName;
}
/*! host name for DSKPP server*/
@property (nonatomic,retain)NSString * host;
/*! activatio code for DSKPP request*/
@property (nonatomic, retain)NSString * activationCode;
/*! user id for DSKPP request*/
@property (nonatomic,retain)NSString * userId;
/*! this know seed of activation request*/
@property (nonatomic,retain)NSString * seed;
/*! method of profile, synchronized or challenge*/
@property ProfileType profileType;
/*! URL link for DSKPP activation*/
@property (nonatomic,retain)NSString * link;
/*! name of profile to be created*/
@property (nonatomic, retain)NSString * profileName;

/*!
 @brief Default initializer of ActivationRequestBuilder.
 @discussion If instantiated this way, user code has to fill required fields for profile activation.
 @return Returns instance of TSDKActivationRequestBuilder
 */
-(id)init;
/*!
 @brief Initialize with URL link.
 @discussion URL should contain all required fields for activation of new profile. ex. https://localhost:8080/?u=manish.test0;ac=123123.
 @param slink Activation address(URL).
 @return Returns initialized instance of TSDKActivationRequestBuilder.
 */
-(id) initWithLink:(NSString *) slink;

/*!
 @brief This method verify for any missing fields in activation request.
 @discussion This method verify for missing fields for either way of profile activation(seed or DSKPP). If any required fields are missing it will throw PartialInitializationException.
 @return After successful verification of activation request it returns object TSDKActivationRequest.
 */
-(TSDKActivationRequest *) Build;

@end
#endif /* ActivationRequestBuilder_h */
