//
//  RTCXGlobalConfigProtocol.h
//  RTCXOpenAccountCloud
//
//  Created by Apple on 2024/12/12.
//

#import <Foundation/Foundation.h>
#import <RTCXOpenAccountCloud/RTCXGlobalConfigModel.h>
NS_ASSUME_NONNULL_BEGIN

typedef void (^RTCXGlobalConfigOnSuccess)(id _Nullable data, id _Nullable rawData);;
typedef void (^RTCXGlobalConfigOnError)(NSError * _Nullable error);

@protocol RTCXGlobalConfigProtocol <NSObject>
/**
 *  获取用户全局配置
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getGlobalConfigWithReq:(nonnull RTCXGlobalConfigReq *)req onSuccess:(nullable RTCXGlobalConfigOnSuccess)onSuccess onError:(nullable RTCXGlobalConfigOnError)onError;
/**
 *  获取全局配置
 */
- (RTCXGlobalConfigRsp *)getGlobalConfig;
/**
 *  获取国际化数据
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getI18NWithReq:(nonnull RTCXI18NReq *)req onSuccess:(nullable RTCXGlobalConfigOnSuccess)onSuccess onError:(nullable RTCXGlobalConfigOnError)onError;
/**
 *  用户获取全局属性（未登录）
 *
 *  @param req        请求参数对象
 *  @param onSuccess  成功回调
 *  @param onError   失败回调
 */
- (void)getGlobalAttrReq:(nonnull RTCXGlobalAttrReq *)req onSuccess:(nullable RTCXGlobalConfigOnSuccess)onSuccess onError:(nullable RTCXGlobalConfigOnError)onError;
@end

NS_ASSUME_NONNULL_END
