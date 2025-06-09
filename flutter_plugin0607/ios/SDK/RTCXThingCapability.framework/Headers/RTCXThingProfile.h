//
//  RTCXThingProfile.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/8/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class RTCXThingTslProperty, RTCXThingTslService, RTCXThingTslEvent;

/**
 类：物的 Profile，封装物的 tsl 模型，包含物的属性、事件、服务等信息
 */
@interface RTCXThingProfile : NSObject

@property (nonatomic, strong) NSArray<RTCXThingTslProperty *>*properties;
@property (nonatomic, strong) NSArray<RTCXThingTslService *>*services;
@property (nonatomic, strong) NSArray<RTCXThingTslEvent *>*events;

/**
 获取物的 tsl 模型中，物的所有的属性描述，可以参见 `RTCXThingTslProperty`

 @return 返回物的所有属性队列
 */
- (NSArray<RTCXThingTslProperty *> *) allPropertiesOfModel;


/**
 获取物的 tsl 模型中，物的所有的服务描述，可以参见 `RTCXThingTslService`

 @return 返回物的所有服务队列
 */
- (NSArray<RTCXThingTslService *> *) allServicesOfModel;


/**
 获取物的 tsl 模型中，物的所有的事件描述，可以参见 `RTCXThingTslEvent`

 @return  返回物的所有事件队列
 */
- (NSArray<RTCXThingTslEvent *> *) allEventsOfModel;

@end

NS_ASSUME_NONNULL_END
