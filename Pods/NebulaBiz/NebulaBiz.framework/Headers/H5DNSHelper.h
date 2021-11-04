//
//  H5DNSHelper.h
//  H5Service
//
//  Created by chenwenhong on 15-4-1.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H5DNSHelper : NSObject

+ (void)getIPAddressWithHost:(NSString *)host complete:(void (^)(NSString *ipAddress))complete;

/**
 *  获取IP地址中的最后一个地址
 *
 *  @param addresses
 *
 *  @return
 */
+ (NSString*)getAddressFromArray:(CFArrayRef)addresses;
@end
