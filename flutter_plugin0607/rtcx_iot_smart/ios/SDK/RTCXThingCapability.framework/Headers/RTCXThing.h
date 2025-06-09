//
//  RTCXThing.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/8/30.
//

#import <Foundation/Foundation.h>
#import <RTCXThingCapability/RTCXThingActions.h>
#import <RTCXThingCapability/RTCXThingProfile.h>
NS_ASSUME_NONNULL_BEGIN

/**
 物的状态变更、属性变更、事件触发的观察者类
 */
@protocol RTCXThingObserver <NSObject>

@optional
/**
 物的状态变更回调，如上线，离线等
 @param iotId 物的 iotId
 @param params 描述具体状态
 */
- (void)onStatusChange:(NSString *)iotId params:(NSDictionary *)params;

/**
物有事件触发，如提示，告警等

 @param iotId 物的 iotId
 @param params 描述具体事件
 */
- (void)onEventHappen:(NSString *)iotId params:(NSDictionary *)params;

/**
物的属性发生变化

 @param iotId 物的 iotId
 @param params 描述属性内容
 */
- (void)onPropertyChange:(NSString *)iotId params:(NSDictionary *)params;

/**
设备被解绑通知
 @param iotId 物的 iotId
 @param params 描述属性内容
 */
- (void)onDeviceUnbind:(NSString *)iotId params:(NSDictionary *)params;

/**
设备WIFI状态通知
 @param iotId 物的 iotId
 @param params 描述当前设备的WIFI状态  @{@"status":value of DeviceWifiStatusType}
 */
- (void)onDeviceWifiStatus:(NSString *)iotId params:(NSDictionary*)params;

/**
物的 tsl 模板解析完毕，后续可以用 [self getThingProfile] 拿到详细的 tsl 模型数据
 */
- (void)didThingTslLoad:(NSString *)iotId;

@end

@interface RTCXThing : NSObject
/**
 获取物的 iotId

 @return 返回物的 iotId
 */
- (NSString *)iotId;


/**
 获取物的 productKey
 
 @return 返回物的 productKey
 */
- (NSString *)getProductKey;


/**
 获取物的 deviceName
 
 @return 返回物的 deviceName
 */
- (NSString *)getDeviceName;

/**
返回物的 mac地址
 @return 返回物的 mac
 */
- (NSString *)mac;

/**
 获取物的控制操作类实例，具体参见 `RTCXThingActions`
 包括物的属性获取、设置；物的事件记录获取；调用物的服务
 @return 返回物的控制操作类实例
 */
- (id<RTCXThingActions>)getThingActions;



/**
 注册物的状态、属性变化或者事件触发的 observer, Thing 类只会 Weak 持有此 observer，
 调用者需要自行保证 observer 的生命周期，如果 dealloc 了，将不再有效

 @param observer 观察者，具体参见 `RTCXThingObserver`
 */
- (void)registerThingObserver:(id<RTCXThingObserver>)observer;


/**
 反注册物的状态、属性变化或者事件触发的 observer

 @param observer 观察者，具体参见 `RTCXThingObserver`
 */
- (void)unregisterThingObserver:(id<RTCXThingObserver>)observer;




/**
 获取物的 Profile，在 Profile 中包含了物的模型信息； 具体参见 `RTCXThingProfile`
 
 @return 返回物的模型信息，开发者可以借此来做 UI 展示
 */
- (RTCXThingProfile *)getThingProfile;
@end

NS_ASSUME_NONNULL_END
