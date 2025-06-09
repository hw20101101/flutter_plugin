//
//  RTCXConfiguration.h
//  RTCXApiClient
//
//  Created by Apple on 2024/8/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 API 通道服务器环境
 */
typedef NS_ENUM(NSInteger, RTCXServerEnviroment) {
    RTCXServerRelease = 0,         ///< 线上
    RTCXServerPreRelease = 1,      ///< 预发，供内部调试使用，外部开发者只能用 RTCXServerRelease
};

@interface RTCXDomain : NSObject
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *domain;
@property (nonatomic, copy) NSString *protocol;
@property (nonatomic, copy) NSString *desc;
@end

/**
 API 通道配置信息
 */
@interface RTCXConfiguration : NSObject

@property (nonatomic, assign) NSInteger appKeyIndex;

/**
 安全图片的 authCode，不指定时默认为 "07e8"；
 该值必须和安全图片 yw_1222_xxx.jpg 的 xxx 部分一致
 */
@property (nonatomic, copy) NSString *authCode;

/**
 移动应用 appKey，该值自动从安全图片中读取
 */
@property (nonatomic, copy, readonly) NSString *appKey;



@property (nonatomic, copy) NSString *appSecret;

/**
 API 通道官方服务器域名
 */
@property (nonatomic, copy) NSString *host;

/**
 API 通道请求支持的语言，格式标准为：[language designator]-[region designator]，当前支持：en-US，zh-CN，未指定默认使用 zh-CN
 */
@property (nonatomic, copy) NSString *language;

/**
 API 通道服务器环境，不指定时默认为线上
 */
@property (nonatomic, assign, readonly) RTCXServerEnviroment serverEnv;

/**
 API 通道请求超时时间，单位为秒，默认请求超时时间为10秒
 */
@property (nonatomic, assign) NSUInteger timeoutInterval;

///全量降级成HTTP请求
@property (nonatomic, assign, getter=isDemote2Http) BOOL demote2Http;

/**
 API 通道DNS域名
 */
@property (nonatomic, copy, readonly) NSString *dnsDomain;
/**
 region类型 0：国内；1：海外
 */
@property (nonatomic, assign) NSInteger regionType;

@property (nonatomic, strong) NSArray<RTCXDomain*> *domains;

/**
 初始化 API 通道配置信息
 @param host 指定 API 通道服务器域名
 @param serverEnv 指定 API 通道服务器环境
 */
+ (void)initWithHost:(NSString *)host serverEnv:(RTCXServerEnviroment)serverEnv;

+ (void)initWithHost:(NSString *)host serverEnv:(RTCXServerEnviroment)serverEnv appKeyIndex:(NSInteger)appKeyIndex;

+ (void)initWithHost:(NSString *)host serverEnv:(RTCXServerEnviroment)serverEnv appKeyIndex:(NSInteger)appKeyIndex appKey:(NSString*)appKey appSecret:(NSString*)appSecret regionType:(NSInteger )regionType;

/**
 获取 API 通道配置信息单例，需要先调用方法 `initWithHost:serverEnv:` 进行初始化
 
 @return API 通道配置信息实例
 */
+ (instancetype)sharedInstance;
// 读写regionId
- (void)saveRegionIdToCache:(NSNumber *)regionId;
- (NSNumber *)getCacheRegionId;
@end

NS_ASSUME_NONNULL_END
