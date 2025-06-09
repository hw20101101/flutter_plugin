//
//  RTCXDeviceAddReq.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/8/22.
//

#import <Foundation/Foundation.h>
#import <RTCXDeviceCenter/RTCXDeviceAddDefine.h>
@interface RTCXDeviceAddReq : NSObject
// 设备型号 如：xLeWcoelZbyOePbJludl
@property (nonatomic, copy, nonnull) NSString *productKey;
// 设备序列号SN 如：TEST20240820002
@property (nonatomic, copy, nonnull) NSString *deviceName;
// 设备添加方式，必选（默认RTCXDeviceAddType_Common）
@property (nonatomic, assign, readonly) RTCXDeviceAddType deviceAddType;
// 超时时间 默认 120s，可选
@property (nonatomic, assign) NSTimeInterval timeout;

@end

@interface RTCXDeviceAddInitReq : NSObject

@end
/** 二维码绑定 */
@interface RTCXDeviceAddQRReq : RTCXDeviceAddReq
// 需要连接的wifi名，必选
@property (nonatomic, copy, nonnull) NSString *ssid;
// 需要连接的wifi密码，必选
@property (nonatomic, copy, nonnull) NSString *wifiPwd;

@end
/** 有线绑定（如：4G、有线设备） */
@interface RTCXDeviceAddWRReq : RTCXDeviceAddReq

@end
/** 测试设备快速绑定（测试设备专用，请勿用于线上设备） */
@interface RTCXDeviceAddQKReq : RTCXDeviceAddReq

@end
