//
//  NewProfile.h
//  TruIDSDK
//
//  Created by vijay on 31/07/16.
//  Copyright © 2016 nexusgroup. All rights reserved.
//
#ifndef _NewProfile_h
#define _NewProfile_h

#import <Foundation/Foundation.h>

#define PROFILE_TYPE_UNSPECIFIED -1
/*!
 @brief Enumeration of profile type.
 @code
 Synchronized = 0,
 Challenge,
 Unspecified = -1
 @endcode
 */
typedef enum ProfileType
{
    Synchronized = 0,
    Challenge,
    Unspecified = -1
}ProfileType;

/*!
 @class TSDKProfile
 @brief The profile class
 @discussion This class is to implement profile object in SDK.
 @classdesign This class wrap original profile class in core part.
 @help This class implements profile in SDK, it has object of core profileManager and profile.
 */
@interface TSDKProfile : NSObject
{

}

/*!
@brief Constructor for TSDKProfile
 */
-(id) initWithProfile:(id *)profile;
/*!
 @brief Generate new OTP for given profile with pin.
 @param userPin User inputs pin for OTP.
 @return This method return NSString as OTP.
 @remark Call this method to get OTP for a active profile.
 */
-(NSString *) GenerateOTP:(NSString *)userPin;

/*!
 @brief Generate new OTP for given profile with pin and challenge.
 @param userPin User inputs pin for OTP.
 @param challenge This is for challenge mode profile, users enters challenge.
 @return This method return NSString as OTP.
 @remark Call this method to get OTP for a active profile.
 */
-(NSString *) GenerateOTP:(NSString *)userPin withChallenge:(char *) challenage;
/*!
 @brief Returns name of itself.
 @return profile name,string
 */
-(NSString *) GetName;

-(id) GetProfile;
/*!
 @brief Get profile type
 @return instance of enum ProfileType
 */
-(ProfileType) GetProfileType;
@end
#endif // _NewProfile_h
