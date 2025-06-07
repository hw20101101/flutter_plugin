//
//  RTCXIotSmart.h
//  RTCXIotSmart
//
//  Created by Apple on 2024/8/15.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//! Project version number for RTCXIotSmart.
FOUNDATION_EXPORT double RTCXIotSmartVersionNumber;

//! Project version string for RTCXIotSmart.
FOUNDATION_EXPORT const unsigned char RTCXIotSmartVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <RTCXIotSmart/PublicHeader.h>

/***
 该枚举类型用于确定app的使用范围，app跟设备分为国内跟海外两套环境，而且彼此隔离。
 如app连接国内服务器时，无法添加海外出货的设备，反之国内连接海外服务器时，国内出货的设备也无法添加。
 基于此，在app初始化IoT SDKs，需要明确app是只工作在国内还是会在国内跟海外之间进行切换。
 */
typedef enum {
    REGION_CHINA_ONLY,/// 当前APP只支持连接中国大陆服务器, 当未设置config时会默认使用此值
    REGION_ALL /// 当前APP既支持连接中国大陆服务器，又支持连接海外服务器，海外连接哪个region，取决于 账号注册时所选国家。
} RTCXRegionType;
/**
 APP开发时存在两种形式，分别是测试版跟正式版
 */
typedef NS_ENUM(NSInteger, RTCXAppType) {
    APP_TYPE_PRODUCTION,///正式版APP
    APP_TYPE_DEVELOP, ///测试版APP
};

@interface RTCXIotCountry : NSObject
/// 国家（地区）名称
@property (nonatomic, copy, nonnull) NSString* areaName;
/// 国家（地区）区号
@property (nonatomic, copy, nonnull) NSString* code;
/// 国家（地区）名称的拼音
@property (nonatomic, copy, nonnull) NSString* pinyin;
/// ISO Country Code - 标准国家码
@property (nonatomic, copy, nonnull) NSString* isoCode;
/// 标准国家码简写
@property (nonatomic, copy, nullable) NSString* domainAbbreviation;
@end
/// sdk配置项
@interface RTCXIotSmartConfig : NSObject

@property (nonatomic, copy) NSString* _Nonnull appKey;
@property (nonatomic, copy) NSString* _Nonnull appSecret;
@property (nonatomic, assign) RTCXAppType appType;  ///APP是测试版还是正式版，当不设置时，默认取值为正式版。
@property (nonatomic, assign) RTCXRegionType regionType;/// region 类型，参见枚举  `RTCXRegionType`
@end

@interface RTCXIotSmart : NSObject
/**
 SDK运行时的配置 ，请在调用 sdk API  [application:didFinishLaunchingWithOptions:] 前调用此方法完成初始化配置，参见`RTCXIotSmartConfig`。
 */
@property (nonatomic, strong, nullable) RTCXIotSmartConfig *  config;
/**
 SDK初始化完成Block回调
 */
@property (nonatomic, copy) void (^ _Nullable sdkInitCompletedCallback)(void);
/**
 单例方法
 */
+ (instancetype _Nonnull )sharedInstance;
/**
 是否打开调试开关，打开时会开启底层sdk的log, 需要排查bug时，建议打开
 @param turnOndebug YES表示打开Log，No：表示关闭
 */
- (void)setDebug:(bool)turnOndebug;
/**
 @remark 获取当前SDK版本
 
 @return version 字符串
 */
+ (nonnull NSString *)getCurrentSDKVersion;
/**
 SDK初始化是否完成
 
 @return 是否完成 YES: 完成 NO:未完成
 */
- (BOOL)sdkInitializationCompleted;
/**
 当应用使用的语言变化时，调用此api设置IoT sdks使用的语言，当未设置过语言时，SDK默认取值是'跟随系统语言'。当调用此api设置过语言后，sdkl内部会固化保存，下次app启动，自动读取上次设置的语言。
 sdk需要使用的语言,目前支持：中文简体、英文、法语、德语、日语、韩语、西班牙语、俄语、印度语、意大利语、土耳其语、中文繁体。对应的取值：zh-CN、en-US、fr-FR、de-DE、ja-JP、ko-KR、es-ES、ru-RU、hi-IN、it-IT, tr-TR, zh-Hant.
 @param language  要切换的语言种类，取值范围[zh-CN、en-US、fr-FR、de-DE、ja-JP、ko-KR、es-ES、ru-RU、hi-IN、it-IT, tr-TR, zh-TW.]
 */
- (void)setLanguage:(NSString*_Nonnull)language;
/**
 获取当前设置的语言， 参见 [setLanguage:]里的说明
 */
- (NSString*_Nonnull)getLanguage;
@end

/**
setCountry 回调接口，用于通知设置了国家(地区)
 @param country 国家
 @param error 如果发生错误，传递错误信息
*/
typedef void (^RTCXIotSmartAfterSetCountry)(NSError* _Nullable error, RTCXIotCountry* _Nullable country);

@interface RTCXIotSmart (country)
/**
 用户选中某个国家(地区）后，调用这个接口设置国家(地区)，sdk内部会持久化保存设置，无需每次重启app都做设置。
 @param country RTCXIotCountry 待设置的国家(地区)
 @param callback 回调接口 切换国家(地区)
 */
- (void)setCountry:(RTCXIotCountry* _Nonnull)country callback:(RTCXIotSmartAfterSetCountry _Nonnull) callback;
/**
 获取国家列表
 @return 国家列表
 */
- (NSArray<RTCXIotCountry*> *_Nonnull)getCountryList;
/**
 返回上次调用setCountry后sdk内部持久化保存的国家(地区)
 */
- (RTCXIotCountry*_Nullable)getCountry;
@end
