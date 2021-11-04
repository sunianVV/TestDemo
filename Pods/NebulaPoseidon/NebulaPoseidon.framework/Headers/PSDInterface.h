//
//  PSDInterface.h
//  NebulaPoseidon
//
//  Created by yangwei on 2020/11/4.
//  Copyright © 2020 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MPMpaaSNSURLConnectionDataDelegate <NSObject>
@optional

// webview ssl正式校验
- (void)connection:(NSURLConnection *)connection willSendRequestForAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;

@end

@interface PSDInterface : NSObject

// 是否调过容器对base64补充content-type的逻辑，默认为NO，即容器默认会补充content-type
@property(nonatomic, assign) BOOL shouldSkipAddBase64ContentTypeWithFormData;

// 打开上述开关的页面url 字符串数组
@property(nonatomic, strong) NSArray *whiteUrls;

// 设置wkwebview容器权限校验回调delegate。
@property(nonatomic, weak) id<MPMpaaSNSURLConnectionDataDelegate> mPaaSNSURLConnectionDelegate;

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
