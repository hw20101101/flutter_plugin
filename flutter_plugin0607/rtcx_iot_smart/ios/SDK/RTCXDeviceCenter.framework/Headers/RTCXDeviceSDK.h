//
//  RTCXDeviceSDK.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/8/21.
//

#import <Foundation/Foundation.h>

#ifndef RTCXDeviceService
#define RTCXDeviceService(__protocol__) \
((id<__protocol__>)([[RTCXDeviceSDK sharedInstance] getService:@protocol(__protocol__)]))
#endif

@interface RTCXDeviceSDK : NSObject

+ (instancetype)sharedInstance;

/**
 获取RTCXDevice的service 实例
 @param protocol service的协议
 @return service实例
 */
- (id)getService:(Protocol *)protocol;
@end

