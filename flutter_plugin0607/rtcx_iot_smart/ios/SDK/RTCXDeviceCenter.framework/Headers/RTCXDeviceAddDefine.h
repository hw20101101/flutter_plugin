//
//  RTCXDeviceAddDefine.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/8/22.
//

#ifndef RTCXDeviceAddDefine_h
#define RTCXDeviceAddDefine_h

/// 设备入网模式
typedef NS_ENUM(NSUInteger, RTCXDeviceAddType) {
    /// 通用添加（默认）
    RTCXDeviceAddType_Common,
    /// 二维码添加
    RTCXDeviceAddType_QR,
    /// 有线添加
    RTCXDeviceAddType_WR,
    /// AP添加
    RTCXDeviceAddType_AP,
    /// 蓝牙添加
    RTCXDeviceAddType_BT,
    /// 快速添加(测试设备专用)
    RTCXDeviceAddType_QUICK,
};

/// 配网过程中的状态
typedef NS_ENUM(NSUInteger, RTCXDeviceAddStatus) {
    /// 就绪，可以发起添加
    RTCXDeviceAddStatus_Prepared = 1,
    /// 成功 回调新添加的设备信息Model
    RTCXDeviceAddStatus_Success,
    /// 失败 错误信息见代理回调方法deviceAddListener中返回的error
    RTCXDeviceAddStatus_Failed,
};


#endif /* VIoTDeviceAddDefine_h */
