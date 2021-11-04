//
//  PSDLogger.h
//  NebulaPoseidon
//
//  Created by theone on 16/11/25.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PSDConfiguration.h"

PSDConfiguration * _Nonnull PSDConfigurationGet();

#define PSDLogInfo(logType,fmt, ...)  PSDLog(nil, logType,fmt, ##__VA_ARGS__)
#define PSDLogDebug(logType,fmt, ...) PSDLog(PSDLocalLogLevelDebug, logType, fmt, ##__VA_ARGS__)
#define PSDLogLevel(level, logType, fmt, ...) PSDLog(level, logType, fmt, ##__VA_ARGS__)
#define PSDLog(level, logType, fmt, ...) (PSDConfigurationGet().disableRunloggerCollect?:[[PSDLogger shareInstance] localLogWithLevel:level type:logType content:[NSString stringWithFormat:fmt,  ##__VA_ARGS__]])

typedef NSString * PSDLocalLogType;
typedef NSString * PSDLocalLogSubType;
typedef NSString * PSDLocalLogLevel;

extern PSDLocalLogLevel const _Nonnull PSDLocalLogLevelDebug;
extern PSDLocalLogLevel const _Nonnull PSDLocalLogLevelInfo;
extern PSDLocalLogLevel const _Nonnull PSDLocalLogLevelWarn;
extern PSDLocalLogLevel const _Nonnull PSDLocalLogLevelError;

extern PSDLocalLogType const _Nonnull PSDLocalLogTypeConnection;
extern PSDLocalLogType const _Nonnull PSDLocalLogTypeAPI;
extern PSDLocalLogType const _Nonnull PSDLocalLogTypeEvent;
extern PSDLocalLogType const _Nonnull PSDLocalLogTypeCookie;
extern PSDLocalLogType const _Nonnull PSDLocalLogTypeInterrupt;
extern PSDLocalLogType const _Nonnull PSDLocalLogTypeURLProtocol;

@interface PSDLogger : NSObject
+ (instancetype _Nonnull)shareInstance;
- (void)doLogWithLogId:(NSString *_Nullable)logId params:(NSDictionary *_Nullable)params;

- (void)localLogWithLevel:(nullable PSDLocalLogLevel)level type:(nullable PSDLocalLogType)logType content:(NSString *_Nullable)content;
- (void)localLogWithLevel:(nullable PSDLocalLogLevel)level type:(nullable PSDLocalLogType)logType parentTraceId:(NSString *_Nullable)parentTraceId groupTraceId:(NSString *_Nullable)groupTraceId content:(NSString *_Nullable)content;

@end
