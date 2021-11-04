//
//  MPaaSInterface+TestDemo.m
//  TestDemo
//
//  Created by wsn on 2021/11/04. All rights reserved.
//

#import "MPaaSInterface+TestDemo.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

@implementation MPaaSInterface (TestDemo)

- (BOOL)enableSettingService
{
    return NO;
}

- (NSString *)userId
{
    return nil;
}

@end

#pragma clang diagnostic pop

