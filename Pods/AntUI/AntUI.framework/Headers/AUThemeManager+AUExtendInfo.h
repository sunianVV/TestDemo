//
//  AUThemeManager+AUExtendInfo.h
//  AntUI
//
//  Created by 莜阳 on 2017/6/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//


@interface AUThemeManager (AUExtendInfo)

/* 支付宝客户端存在默认主题，独立App可修改该默认值
 * 在该方法中只需返回与默认主题不同的键值对即可，key请使用AUTheme.h中定义好的key
 */
+ (NSDictionary *)au_defaultTheme_extraInfo;

/* 自定义小程序中下拉刷新的lottie图标，请返回lottie文件的路径。
*  默认文件为 APCommonUI.bundle/lottie/refresh_default.json文件
*/
+ (NSString *)au_defaultTheme_refresh_lottie_path;

@end


/*   举个栗子
 *   + (NSDictionary *)au_defaultTheme_add_Info
 *   {
 *       NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
 *       dict[TITLEBAR_BACKGROUND_COLOR] = AU_COLOR_APP_GREEN;             // AUTitleBar背景色
 *       dict[TITLEBAR_TITLE_TEXTCOLOR] = [UIColor redColor];              // AUTitleBar标题色
 *       ...
 *       return dict;
 *   }
 */
