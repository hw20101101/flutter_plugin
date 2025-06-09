//
//  RTCXDeviceAddDelegate.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/8/22.
//

#import <Foundation/Foundation.h>
@class RTCXDeviceAddDefine;
@protocol RTCXDeviceAddDelegate <NSObject>

// 设备添加状态代理回调方法，回调过程中状态、数据、错误信息
- (void)deviceAddListener:(RTCXDeviceAddStatus)status callbackData:(nullable id)data error:(nullable NSError *)error;

@end

