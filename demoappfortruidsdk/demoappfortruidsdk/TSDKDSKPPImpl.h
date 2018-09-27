//
//  DSKPPWrap.h
//  TruIDSDK
//
//  Created by vijay on 10/08/16.
//  Copyright © 2016 nexusgroup. All rights reserved.
//

#ifndef DSKPPWrap_h
#define DSKPPWrap_h

#import "TSDKCancellable.h"

#import "TSDKDelegateDskpp.h"
#import "Constants.h"
#import "TSDKProfile.h"

/*!
 @class TSDKDSKPPImpl
 @brief This class is internal to SDK, used to store delegator of user DSKPPDelegate. It receives DSKPP status from DSKPP process and call user delegate method to pass on message.
 */
@interface TSDKDSKPPImpl: NSObject<TSDKCancellable,DSKPPDelegate>
{
    
}
-(id) initWithkDelegate:(id<TSDKDelegateDskpp>)del;
-(id) init;
-(void) setValDskpp:(id)dskp;
@end
#endif /* DSKPPWrap_h */
