//
//  PSDConfigMgr.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PSDPluginConfig;
@class PSDJsApiConfig;
@protocol RVKExtensionConfigManagerProtocol;

//配置管理类
@interface PSDConfigManager : NSObject

@property(nonatomic, weak)       id<RVKExtensionConfigManagerProtocol> configDelegate;

+ (instancetype)sharedInstance;

- (void)loadAllConfigs;

/**
 *  @brief 所有插件配置对象列表
 *
 *  @date 2014-08-11
 *
 *  @return 返回插件配置对象列表
 */
- (NSArray *)allPluginCfgs:(NSString *)scope; // PSDPluginConfig

/**
 *  @brief 所有JsApi配置对象列表
 *
 *  @date 2014-08-20
 *
 *  @return 返回JsApi配置对象列表
 */
- (NSArray *)allJsApiCfgs:(NSString *)scope; // PSDJsApiConfig

- (void)registerPluginCfg:(PSDPluginConfig *)pluginCfg;

- (void)unRegisterPluginCfg:(PSDPluginConfig *)pluginCfg;

- (void)registerJsApiCfg:(PSDJsApiConfig *)jsApiCfg;

- (void)unRegisterJsApiCfg:(PSDJsApiConfig *)jsApiCfg;

- (void)registerComponentWithName:(NSString *)name clsName:(NSString *)clsName;
- (void)unRegisterComponentWithName:(NSString *)name;
- (NSDictionary *)components;


@end
