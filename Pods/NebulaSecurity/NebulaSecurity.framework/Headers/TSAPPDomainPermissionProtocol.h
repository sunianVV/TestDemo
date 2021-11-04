//
//  TSAPPDomainPermissionProtocol.h
//  NebulaSecurity
//
//  Created by shaochangying.scy on 2021/7/7.
//  Copyright © 2021 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TSAPPDomainPermissionProtocol <NSObject>

+ (BOOL)shouldIgnoreDomainManagementWithApp:(NAMApp *)app;

@end

NS_ASSUME_NONNULL_END
