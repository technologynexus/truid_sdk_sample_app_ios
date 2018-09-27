//
//  DSKPPDelegate.h
//  TruID
//
//  Created by Nils Gambini on 12/9/11.
//  Copyright (c) 2011 PortWise AB. All rights reserved.
//

#ifndef TruID_DSKPPDelegate_h
#define TruID_DSKPPDelegate_h


#import <UIKit/UIKit.h>

typedef enum
{
  DERR_OK, // all ok, ref ERROR_SUCCESS
  DERR_INTERNAL,
  DERR_INCORRECT_MSG_RECV,
  DERR_DATA_RECV_MISSING, // Not all data received from server,
  DERR_SERVER_HELLO_REJECT, // Server did not say continue in server hello
  DERR_SERVER_FINISH_REJECT, // Server did not say continue in server finish
  DERR_SESSION_ID,
  DERR_MAC_INCORRECT,
  DERR_HTTP,
  DERR_SOCKET_INIT,
  DERR_SOCKET
} DSKPPErrorId;

/**
 * Protocoll for view controllers to handle progress and errors.
 */
@protocol DSKPPDelegate <NSObject>

@required	

/**
 * Force all implementors to implement start-progress behaviour
 */
- (void) startProgress;

/**
 * Force all implementors to implement stop-progress behaviour
 */
- (void) stopProgressWithError:(NSString *) errorString Error:(DSKPPErrorId)id Errno:(int)num;

/**
 * Start UIApplication network indicator
 */
- (void) startNetworking;

/**
 * Stop UIApplication network indicator
 */
- (void) stopNetworking;

/**
 * Login, call this when username or activation-code is missing 
 * @params activationLabelType, 0 - Activation Code, 1 - OTP 
 */
- (void) login:(int) activationLabelType;

/**
 * Complete, call this when dskpp completed sussessfully
 */
- (void) complete:(NSString *) suggestedProfileName seed:(NSData *) seed method:(int) method;


@end

#endif
