//
//  MPNebulaAdapterInterface.h
//  MPNebulaAdapter
//
//  Created by yangwei on 2019/2/12.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NebulaAppManager/NebulaAppManager.h>
#import <NebulaSDK/NebulaSDK.h>

@protocol MPNebulaAdapterInterfaceConfigProtocol <NSObject>
@optional
// 返回自定义开关
- (NSDictionary *)nebulaCustomConfig;
@end

NS_ASSUME_NONNULL_BEGIN

@interface MPNebulaAdapterInterface : NSObject

+(instancetype)shareInstance;

/**
 初始化Nebula容器
- 必须在 DTFrameworkInterface 的 - (void)application:(UIApplication *)application beforeDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions 中或更早的时机如 +(void)load 中进行初始化
 */
+ (void)initNebula;

/**
 初始化Nebula容器
 - 必须在 DTFrameworkInterface 的 - (void)application:(UIApplication *)application beforeDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions 中或更早的时机如 +(void)load 中进行初始化
 
 @param customPresetApplistPath 自定义预置离线包信息文件路径，如 [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"MPCustomPresetApps.bundle/NebulaApplist.plist"] ofType:nil]
 @param customPresetAppPackagePath 自定义预置离线包的包路径，如 [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"MPCustomPresetApps.bundle"] ofType:nil]
 @param customPluginsJsapisPath 自定义 plugins、jsapis 信息文件路径，如 [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"Poseidon-UserDefine-Extra-Config.plist"] ofType:nil]
 **/
+ (void)initNebulaWithCustomPresetApplistPath:(NSString *)customPresetApplistPath customPresetAppPackagePath:(NSString *)customPresetAppPackagePath customPluginsJsapisPath:(NSString *)customPluginsJsapisPath;

/**
 基于Nebula容器创建的H5页面的VC基类，默认为 H5WebViewController。若需定制H5页面所在的VC，可自定义VC后设置此属性
 注意：自定义的基类必须继承 'H5WebViewController'
 */
@property (nonatomic, strong) Class nebulaVeiwControllerClass;

/**
 基于Nebula容器创建的H5页面嵌入的webview基类，默认为 WKWebView。若需定制H5页面的webview，可自定义webview后设置此属性
 */
@property (nonatomic, strong) Class nebulaWebViewClass;

/**
 设置是否使用WKWebView加载离线包页面，默认为YES
 */
@property (nonatomic, assign) BOOL nebulaUseWKArbitrary;

/**
 设置当前应用所有基于Nebula容器创建的H5页面的 UserAgent
 */
@property (nonatomic, strong) NSString *nebulaUserAgent;

/**
离线包是否验签，默认为YES，即Nebula容器默认对下载的离线包验签。调试期间如需要关闭验签，此属性设置为 NO
 */
@property (nonatomic, assign) BOOL nebulaNeedVerify;

/**
 离线包验签的公钥路径，默认为nil。若离线包验签开关为YES，此处必须设置对应的公钥，否则本地验签不通过导致离线包加载失败
 */
@property (nonatomic, strong) NSString *nebulaPublicKeyPath;

/**
 全局资源包列表
 */
@property (nonatomic, strong) NSArray *nebulaCommonResourceAppList;

/**
 当H5页面加载失败时展示的html错误页路径，默认读取 MPNebulaAdapter.bundle/error.html
 */
@property (nonatomic, strong) NSString *errorHtmlPath;

/**
 开启新链路，11.3 及以上系统采取新拦截方式
 */
@property (nonatomic, assign) BOOL nebulaUseNewInterceptLink;

/**
 设置自定义开关 delegate，灰度函数范围自定义开关，开关优先级为 APConfig > 此处自定义开关 > 默认内置开关
 */
@property(nonatomic, weak) id<MPNebulaAdapterInterfaceConfigProtocol> configDelegate;

/**
 设置全局离线包请求更新频率。默认为1800，单位：秒，上限为24小时
*/
@property(nonatomic, assign) NSTimeInterval nebulaUpdateReqRate;

/**
是否忽略SSL 强校验，默认为 NO。若需要容器支持加载http，可在 beforeDidFinishLaunch方法中，初始化容器后设置此值为YES。
 注意：此开关仅为了支持在开发阶段容器支持加载http，强烈建议此仅在开发阶段打开，不要带上线
 */
@property (nonatomic, assign) BOOL nebulaCanIgnoreSSLWhenDebug;

/**
设置wkwebview容器回调delegate。delegate优先级为：此处自定义delegate > 容器默认内置delegate
*/
@property(nonatomic, weak) id<MPMpaaSWKNavigationDelegateProtocol> nebulaMPaaSWKNavigationDelegate;

//wkwebview本地离线实现失败时是否停止请求vhost地址，默认为NO
@property (nonatomic, assign) BOOL nebulaShouldStopRequestVhostWhenOfflineFail;

/**
 *  基于在线url，创建一个H5容器，并自动push打开
 *
 *  @param params H5容器的启动参数，必填参数：url，其他可选参数参考文档 https://tech.antfin.com/docs/2/85001
 *
 */
- (void)startH5ViewControllerWithParams:(NSDictionary *)params;

/**
 *  基于传入的离线包信息，创建一个H5容器，并自动push打开
 *
 *  @param params H5容器的启动参数，必填参数：appId，其他可选参数参考文档 https://tech.antfin.com/docs/2/85001
 *
 */
- (void)startH5ViewControllerWithNebulaApp:(NSDictionary *)params;

/**
 *  基于传入的url信息，创建一个H5容器，并返回创建的H5容器实例。一般用在首页tab页面
 *
 *  @param params H5容器的启动参数，必填参数：url，其他可选参数参考文档 https://tech.antfin.com/docs/2/85001
 *
 *  @return 创建的H5容器vc实例
 */
- (UIViewController *)createH5ViewController:(NSDictionary *)params;

/**
 *  基于传入的离线包信息，创建一个H5容器，并返回创建的H5容器实例。一般用在首页tab页面
 *
 *  @param params H5容器的启动参数，必填参数：appId，其他可选参数参考文档 https://tech.antfin.com/docs/2/85001
 *
 *  @return 创建的H5容器vc实例
 */
- (UIViewController *)createH5ViewControllerWithNebulaApp:(NSDictionary *)params;

/**
 打开小程序包
 
 @param appId 小程序 ID
 @param params 小程序参数
 */
+ (void)startTinyAppWithId:(NSString*)appId params:(NSDictionary*)params;

/**
打开小程序包

@param appId 小程序 ID
@param params 小程序参数
*
*  @return 小程序微应用打开结果，判断结果不代表小程序是否成功打开
*/
+ (BOOL)startTinyAppGetReturnWithId:(NSString*)appId params:(NSDictionary*)params;

/**
 扫描 mPaaS 小程序IDE 预览/调试 二维码，进行预览和远程调试
 
 @param qrCode mPaaS 小程序IDE 预览/调试 二维码 字符串
 */
+ (void)startDebugTinyAppWithUrl:(NSString*)qrCode;


/**
扫描 mPaaS 小程序IDE 预览/调试 二维码，进行预览和远程调试

@param qrCode mPaaS 小程序IDE 预览/调试 二维码 字符串
@param params 小程序参数，不能与二维码解析成字典中的key相冲突，否则相同key部分小程序参数会被覆盖
*/
+ (void)startDebugTinyAppWithUrl:(NSString*)qrCode params:(NSDictionary*)params;

/**
 *  全量更新本地离线包信息
 *
 *  @param finish 完成回调
 *
 */
- (void)requestAllNebulaApps:(NAMRequestFinish)finish;

/**
 *  单个应用请求
 *
 *  注:
 *      9.9.9前: 请求成功后Wifi下自动下载离线包,非Wifi只下载auto_install为YES的离线包
 *      9.9.9及之后: 可针对每个应用配置下载时机, 通过服务端配置, 默认WIFI下载
 *
 *  @param params   请求列表 格式:{appid:version},可传多个appid,不指定version时传空传,默认取最高版本
 *                支持版本号模糊匹配 e.g. '*' 匹配最高版本号 '1.*' 匹配1开头的版本号总最高版本号等,最长4位
 *  @param finish 完成回调
 */
- (void)requestNebulaAppsWithParams:(NSDictionary *)params finish:(NAMRequestFinish)finish;


/**
 *  全量下载包信息池中的离线包
 *
 *
 */
- (void)downLoadAllNebulaApps;

/**
 *  批量下载指定的离线包
 *
 *  @param params 字典{appId:version},指定要下载的appId和版本号,从包管理池中读取并下载
 */
- (void)downLoadNebulaAppsWithParams:(NSDictionary *)params;

/**
 *  安装离线包
 *
 *  @param app         离线包信息，可通过findApp：查找
 *  @param process   安装过程回调, 过程包含: 异步下载离线包->解压离线包
 *  @param finish       安装完成的回调
 */
- (void)installNebulaApp:(NAMApp *)app
                 process:(NAMAppInstallProcess)process
                  finish:(NAMAppInstallFinish)finish;

/**
 * 查询所有应用的 appId 列表
 *
 * @param array 数组 [appId,appId...]
 */
- (NSArray *)allAppIds;

/**
 * 获取指定应用的包信息
 *
 * @param appId 指定应用Id数组
 * @return NSDictionary 所有APP的实例 {appId:[NAMApp, ...], ...}
 */
- (NSDictionary *)allAppsForAppId:(NSArray *)arrAppId;

/**
 * 获取已安装应用的包信息
 *
 * @param list 字典 {appId:version}，传nil时返回已安装的所有包信息
 */
- (NSDictionary *)installedApps:(NSDictionary *)list;

/**
 *  @brief 删除本地指定应用的信息(包括包信息、amr以及安装目录)
 *
 *  @param appId  应用的appId
 *
 *  @return
 */
-(void)clearAllAppInfo:(NSString *)appId;


// 自定义 plugins、jsapis 配置文件路径
@property (nonatomic, strong, readonly) NSString *customPluginsJsapisPath;

/**
*  开启隐私权限弹框控制时，请在 afterDidFinishLaunchingWithOptions 方法中手动初始化容器Context，否则容器加载失败
*
*/
+ (void)setNBContextWhenEnablePrivacyAuth;

@end

NS_ASSUME_NONNULL_END
