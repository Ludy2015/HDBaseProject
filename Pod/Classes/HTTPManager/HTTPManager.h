//
//  HTTPMethods.h
//  Hotchpotch
//
//  Created by Harry on 15/8/3.
//  Copyright (c) 2015年 Harry. All rights reserved.
//

/******************************************************************************************************
 * 所有网络请求方法都在这里
 ****************************************************************************************************/

#import <Foundation/Foundation.h>


typedef void(^ httpRequestSuccess)(id responseObject);
typedef void(^ httpRequestFailure)(NSString *errorResult);

@interface HTTPManager : NSObject

//DEMO
+ (void)getWeixinJingxuanPageIndex:(NSInteger)pageIndex
                           success:(httpRequestSuccess)success
                           failure:(httpRequestFailure)failure;

@end
