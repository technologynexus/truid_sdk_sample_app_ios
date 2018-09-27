//
//  CancelToken.h
//  TruIDSDK
//
//  Created by vijay on 10/08/16.
//  Copyright © 2016 nexusgroup. All rights reserved.
//

#ifndef CancelToken_h
#define CancelToken_h
#include "TSDKCancellable.h"

/*!
 @class TSDKCancelToken
 @brief This is to cancel DSKPP request before completion.
 @discussion User code will create object of this class and sent it to SDK via ProfileManager.ActivateProfile() method. user can cancel DSKPP request by calling cancel() method.
 @codedesign This class matains list of all DSKPP delegator, whenever user call cancel method it calls DSKPP cancel. SDK will call addListener() method to all delegator to list.
 */
@interface TSDKCancelToken : NSObject
{
    @private
    /*! this will contain all cancellable token, once user will call cancel*/
    // all DSKPP request will be canceled
    NSMutableArray * listOfCancellable;
}
/*!
 @brief client code will call this method to cancel DSKPP flow.
 */
-(void) cancel;

/*!
 @brief SDK will call this method to add dskpp delegator to list.
 @param cancellable Reference to DSKPPImpl class.
 */
-(void) addListener:(id<TSDKCancellable>)cancellable;

@end

#endif /* CancelToken_h */
