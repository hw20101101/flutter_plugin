//
//  RTCXDeviceAddProtocol.h
//  RTCXThingCapability
//
//  Created by Apple on 2024/8/22.
//

#import <Foundation/Foundation.h>
@class RTCXDeviceAddDefine;
@class RTCXDeviceAddReq;
@protocol RTCXDeviceAddDelegate;

typedef void (^RTCXDeviceCompletionBlock)(BOOL result, id _Nullable response, NSError *_Nullable error);

@protocol RTCXDeviceAddProtocol <NSObject>

#pragma mark - 设备添加步骤
/**
 *  准备添加设备，成功才可以进行下一步
 *
 *  @param addType  添加类型
 */
- (void)prepareAddDevice:(RTCXDeviceAddType)addType;
/**
 *  开始添加设备，成功才可以进行下一步
 *
 *  @param req  配网模式对应入参
 */
- (void)startAddDevice:(nullable RTCXDeviceAddReq *)req;
/**
 *  停止添加设备
 *
 */
- (void)stopAddDevice;

#pragma mark -- 其他特殊接口 --
/**
 *  准备设备添加之前初始化参数
 *
 *  @param req  初始化参数
 */
- (void)initDeviceAddParams:(nullable RTCXDeviceAddInitReq *)req;
/**
 *  注册设备添加状态回调代理对象
 *
 *  @param delegate  代理对象
 */
- (void)registerDelegate:(id<RTCXDeviceAddDelegate>_Nullable)delegate;
/**
 *  生成二维码字符串数组
 *
 *  @param req  RTCXDeviceAddQRReq
 */
- (nullable NSArray <NSString *> *)getQRCodeData:(nullable RTCXDeviceAddQRReq *)req;
/**
 *  获取配网所需随机数
 */
- (nullable NSString *)getBindToken;
/**
 获取当前regionId（海外设备配网需要）
 */
- (nullable NSNumber *)getRegionId;
@end
