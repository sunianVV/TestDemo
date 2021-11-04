//
//  H5ViewControllerEvent.h
//  NebulaBiz
//
//  Created by theone on 16/2/25.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>

@interface H5WebViewEvent : PSDEvent
@property(nonatomic, weak) WKWebView *webView;
+ (instancetype)webViewReloadEvent:(WKWebView *)webview;
@end
