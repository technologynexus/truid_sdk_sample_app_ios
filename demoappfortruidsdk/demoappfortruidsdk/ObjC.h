//
//  ObjC.h
//  TruIDSDK
//
//  Created by vijay nexus on 5/15/17.
//  Copyright © 2017 nexusgroup. All rights reserved.
//

#ifndef ObjC_h
#define ObjC_h

@interface ObjC : NSObject

+ (BOOL)catchException:(void(^)())tryBlock error:(__autoreleasing NSError **)error;

@end

#endif /* ObjC_h */
