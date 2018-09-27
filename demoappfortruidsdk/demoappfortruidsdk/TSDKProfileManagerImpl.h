//
//  ProfileManagerImpl.h
//  TruIDSDK
//
//  Created by vijay on 31/07/16.
//  Copyright © 2016 nexusgroup. All rights reserved.
//
#ifndef NewProfileManagerImpl_h
#define NewProfileManagerImpl_h

#import <Foundation/Foundation.h>
#import "TSDKProfile.h"
#import "TSDKProfile.h"
#import "TSDKActivationRequest.h"
#import "TSDKDelegateDskpp.h"
#import "TSDKCancelToken.h"
#import "TSDKDSKPPImpl.h"

/*!
 @class TSDKProfileManagerImpl
 @brief This class wrap core profileManager, implements core of SDK.
 @discussion This class is used by TSDKProfileManager interface, and use its API. User can get instance of this interface by calling Instance() method of TSDKProfileManger. To activate new profile user code will go throgh TSDKProfileManager interface. refer TSDKProfileManager interface.
 @classdesing singleton
 
 */
@interface TSDKProfileManagerImpl : NSObject
{
}
/*!
 @brief Initialize instance.
 @param storeLib This is reference to keychain storage, in SDK this is getting created. User code dont have bother about this.
 @param crypt This reference to CommonCryptoLib class, this is used for cryptography.
 @return This returns initialized TSDKProfileManagerImpl instance.
 @remark User code will not call this method, user code has to call Instance method of TSDKProfileManager to get instance this class.
*/
-(id) initWithStorageLib:(id) storelib CryptoLib:(id) crypt;

/*!
 @brief Activate new profile with user input seed
 @param name User suggested profile name.
 @param user input seed.
 @return Active profile, this method returns activated new profile.
 */
-(TSDKProfile *) ActivateWithSeed:(NSString *)name withProfileType:(ProfileType)mode withSeed:(NSString *) seed;

/*!
 @brief Delete a active profile
 @param profile Profile to be deleted.
 */
-(void) DeleteProfile:(TSDKProfile *) profile;

/*!
 @brief returns all active profile.
 @return NSMutableSet, this contains all active profile.
 */
-(NSMutableSet *) GetProfiles;

/*!
 @brief To get TSDKProfile at a index.
 @param index Index, profile at that index would be return.
 */
-(TSDKProfile *) GetProfile:(int)index;

/*!
 @brief This method to store profile in keychain store, this is used internally in SDK.
 @param profile TSDKProfile to be persist.
 */
-(void) SaveProfile:(TSDKProfile *)profile;

/*!
 @brief This returns unique string profile name.
 @param name Suggestion.
 */
-(NSString *) GetUniqueProfileName:(NSString *) name;

/*!
 @brief This method is to activate a new profile.
 @param request User code will use TSDKActivationRequestBuilder.Builder() method to get object of TSDKActivationRequest.
 @param del SDK DSKPP delegator, user code should implements TSDKDelegateDskpp protocol and pass reference to this method. Delegator method will be called during DSKPP activation. refer TSDKDelegateDskpp protocol.
 @param cnlTkn user code will pass reference to TSDKCancelToken, this is to cancel DSKPP request before activation finished.
 @return TSDKProfile, Method return activated profile or nil in case of DSKPP request.
 @remark This method is used by TSDKProfileManager interface, user code will call TSDKProfileManager implementation.
 */
-(void) ActivateWithDSKPP:(TSDKActivationRequest *) request delegate:(id<TSDKDelegateDskpp>) del cancelToken:(TSDKCancelToken *)cnlTkn;

/*!
 @brief This method to activate profile with binary seed.
 @param seed Binary seed, output of DSKPP activation.
 @param name ProfileName.
 @param mode Profile type of profile, Synchronized or Challenge.
 @return TSDKProfile active profile.
 @remark This method is used by TSDKProfileManager.
 */

-(TSDKProfile *) ActivateWithBinarySeed:(NSData *)seed profileName:(NSString *)name profileType:(ProfileType)mode;

/*!
 @brief this method is internal to SDK.
 @return return instance of internal profile manager
 */
-(id) GetManager;

@end
#endif /* NewProfileManagerImpl_h*/
