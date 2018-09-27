//
//  Cancellable.h
//  TruIDSDK
//
//  Created by vijay on 10/08/16.
//  Copyright © 2016 nexusgroup. All rights reserved.
//

#ifndef Cancellable_h
#define Cancellable_h

/*!
 @protocol TSDKCancellable
 @brief This is used by SDK.
 @help DSKPPImpl class implements this.
 */
@protocol TSDKCancellable <NSObject>
@required

/*!
 @brief SDK call this method to cancel DSKPP flow.
 */
-(void ) cancelDskppReq;

@end
#endif /* Cancellable_h */
