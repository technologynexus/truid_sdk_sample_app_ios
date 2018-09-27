//
//  TSDKDelegateDskpp.h
//  TruIDSDK
//
//  Created by vijay on 11/08/16.
//  Copyright © 2016 nexusgroup. All rights reserved.
//
#ifndef TSDKDelegateDskpp_h
#define TSDKDelegateDskpp_h
#import "TSDKProfile.h"
#import "DSKPPDelegate.h"

typedef enum
{
    TSDK_OK, // all ok, ref ERROR_SUCCESS
    TSDK_INTERNAL,
    TSDK_INCORRECT_MSG_RECV,
    TSDK_DATA_RECV_MISSING, // Not all data received from server,
    TSDK_SERVER_HELLO_REJECT, // Server did not say continue in server hello
    TSDK_SERVER_FINISH_REJECT, // Server did not say continue in server finish
    TSDK_SESSION_ID,
    TSDK_MAC_INCORRECT,
    TSDK_HTTP,
    TSDK_SOCKET_INIT,
    TSDK_SOCKET,
    TSDK_INVALID_SEED
} TSDKErrorId;

/*!
 @protocol TSDKDelegateDskpp
 @brief User code has to implement this protocol. User code will receive status update while DSKPP activation. Methodos in this protocol will be called from SDK code according to status received from DSKPP process via DSKPPDelegate.
 */
@protocol TSDKDelegateDskpp <NSObject>

@required

/*!
 @brief Get called on request completions.User code will receive new profile after activation request complete through this method. User should implements this method to handle new profile. This method will be called from SDK once activation is success.
 @param profile New profile after DSKPP request complete.
 */
-(void) onComplete:(TSDKProfile * )profile;

/*!
 @brief Indicates DSKPP request has been submitted.
 */
- (void) startProgress;

/*!
 @brief Indicate some error occured during DSKPP flow. User code will receive error through this method.
 @param errorString Error message.
 @param num Error number. Below are list of possible error.
 @code
 typedef enum
 {
 TSDK_OK, // all ok, ref ERROR_SUCCESS
 TSDK_INTERNAL,
 TSDK_INCORRECT_MSG_RECV,
 TSDK_DATA_RECV_MISSING, // Not all data received from server,
 TSDK_SERVER_HELLO_REJECT, // Server did not say continue in server hello
 TSDK_SERVER_FINISH_REJECT, // Server did not say continue in server finish
 TSDK_SESSION_ID,
 TSDK_MAC_INCORRECT,
 TSDK_HTTP,
 TSDK_SOCKET_INIT,
 TSDK_SOCKET,
 TSDK_INVALID_SEED
 } TSDKErrorId;
 @endcode
 */
- (void) stopProgressWithError:(NSString *) errorString Error:(TSDKErrorId)id Errno:(int)num ;

/*!
 @brief Start UIApplication network indicator
 */
- (void) startNetworking;

/*!
 @brief Stop UIApplication network indicator
 */
- (void) stopNetworking;

@end
#endif /* TSDKDelegateDskpp_h */
