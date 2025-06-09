//
//  RTCXThingManager.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/8/30.
//

#import <Foundation/Foundation.h>
#import <RTCXThingCapability/RTCXThing.h>
NS_ASSUME_NONNULL_BEGIN

#define kRTCXThingManager [RTCXThingManager sharedManager]

@interface RTCXThingManager : NSObject
/**
 返回单例

 @return 单例
 */
+ (instancetype)sharedManager;


/**
 创建 Thing 对象，该对象会被加入管理者维护的物的队列中

 @param iotId 物的唯一标识符， 该 id 是物在注册绑定时由云端颁发
 @return 返回 Thing 对象
- (RTCXThing *)buildThing:(NSString *)iotId  DEPRECATED_API;
*/

/**
 销毁 Thing 对象，在 Thing 不再需要时调用此方法
可以将其从 管理者维护的物的队列中删除
 @param thing Thing 的对象
 */
- (void)destroyThing:(RTCXThing *)thing;



/**
 创建 Thing 对象，该对象会被加入管理者维护的物的队列中
 
 @param productKey 物在iot平台注册的产品型号
 @param deviceName 物的deviceName
 @param iotId 物的iotId
 @return 返回 Thing 对象
 */
- (RTCXThing*)buildThing:(NSString *)productKey
             deviceName:(NSString *)deviceName
                  iotId:(NSString *)iotId;

@end

NS_ASSUME_NONNULL_END
