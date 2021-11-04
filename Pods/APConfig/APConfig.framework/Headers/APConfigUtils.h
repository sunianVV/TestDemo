//
//  APConfigUtils.h
//  APConfig
//
//  Created by yangwei on 2020/12/8.
//  Copyright © 2020 WenBi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface APConfigUtils : NSObject

@property (nonatomic, assign) BOOL autoFetchConfigFromRpc;  // 启动或后台回前台是否自动更新开关，默认为YES

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
