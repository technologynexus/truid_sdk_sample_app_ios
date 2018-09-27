//
//  PartialInitializationException.h
//  TruIDSDK
//
//  Created by vijay on 18/08/16.
//  Copyright © 2016 nexusgroup. All rights reserved.
//

#ifndef PartialInitializationException_h
#define PartialInitializationException_h
/*!
 @brief Enumeration of missing exception fields.
 */
typedef NS_ENUM(NSInteger,FIELD)
{
    ACTIVATION_CODE = 0,
    SEED,
    PROFILE_NAME,
    PROFILE_TYPE,
    USER_ID,
    INVALID_URL
};

/*!
 @class PartialInitializationException
 @brief In case of missing fields while activating profile this exception would be thrown. ActivationRequestBuilder.Build() method would throw this exception. filedList contains all missing fileds that need to be set before calling Build() method of TSDKActivationRequestBuilder class.
 */
@interface PartialInitializationException : NSException
{
    @private
    /*! contains all missing field*/
    NSMutableSet * fieldList;
}
/*! missing filed set*/
@property(nonatomic,retain)NSMutableSet * fieldlist;

/*!
 @brief Initializer of PartialInitializationException class.
 @param msg Exception message, user code will receive this message.
 @param set A set containing all misssing fields.
 @return Initialized PartialInitializationException.
 */
-(id)initWithMsg:(NSString *)msg missingField:(NSMutableSet *)set;

/*!
 @brief User will call this method to get list of missing fields.
 @return NSMutableSet missing fields.
 */
-(NSMutableSet *) getFileds;
@end
#endif /* PartialInitializationException_h */
