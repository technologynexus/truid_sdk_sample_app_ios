//
//  NewProfileManager.h
//  TruIDSDK
//
//  Created by vijay on 02/08/16.
//  Copyright © 2016 nexusgroup. All rights reserved.
//
#ifndef NewProfileManager_h
#define NewProfileManager_h

#import "Foundation/Foundation.h"
#import "TSDKActivationRequest.h"

#import "TSDKProfileManagerImpl.h"
#import "TSDKCancelToken.h"
#import "TSDKDelegateDskpp.h"

/*!
 @class TSDKProfileManager
 @brief This class manages all profile objects and operations on the profile.
 @discussion This class is main interface to the SDK, class has all static method.
 User should not create object of this class. Most of the time user code would be communicating to SDK through this class.
 @helps This creates single object of TSDKProfileManagerImpl class and that exist for life time.
 */
@interface TSDKProfileManager : NSObject
{
    
}
/*!
 @brief It returns unique profile name based on suggestion.
 @param profileName The string profile name.
 @return NSString, unique profile name.
 @remarks user code should call this function to get unique profile name based on a suggested one.
 */
+(NSString *) GetUniqueName:(NSString *) profileName;

/*!
 @brief This method is to activate profile. User code would call this method to activate a new profile through either activate with seed or with DSKPP.
 @param request Use TSDKActivationRequestBuilder.Build() method to get object of TSDKActivationRequest.
 @param del SDK DSKPP delegator, user code should implements TSDKDelegateDskpp protocol and pass reference to this function. Delegator method will be called during profile activation. refer TSDKDelegateDskpp protocol.
 @param cnlTkn user code will pass reference to TSDKCancelToken, this is to cancel DSKPP request before activation finished.
 @return void Method return void. After success user code would receive a new profile through onComplete() method of TSDKDelegateDskpp. Refer TSDKDelegateDskpp delegator. In case of errors this throw NSException.
 @remark Static method.
 */
+(void) ActivateProfile:(TSDKActivationRequest *) request dskppDelegator:(id<TSDKDelegateDskpp>)del cancelToken:(TSDKCancelToken *)cnlTkn;

/*!
 @brief returns all active profile.
 @return NSMutableSet, this contains all active profile.
 */
+(NSMutableSet *) GetProfiles;

/*!
 @brief This method is to get name of a profile.
 @param profile Reference to TSDKProfile.
 @return NSString, return name of profile passed in argument.
 @remark static method.
 */
+(NSString *) GetName:(TSDKProfile *) profile;

/*!
 @brief This method is to deactivate a active profile.
 @param profile Reference to a profile that is to be deactivated. After deletion of a profile it will be deleted from storage.
 @return nil.
 @remark static method,this method deactivate profile and delete it.
 */
+(void) DeleteProfile:(TSDKProfile *) profile;
/*!
 @brief profileManager class will have instance of ProfileManagerImpl, that instance would be retured.
 @return instance of ProfileManagerImpl.
 @remark this method should be called to get instance of TSDKProfileManagerImpl object.
 */

+(volatile TSDKProfileManagerImpl *) Instance;
@end
#endif /* NewProfileManager_h */
