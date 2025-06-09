//
//  RTCXPreConnectInfo.h
//  RTCXMedia
//
//  Created by Apple on 2024/11/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXPreConnectInfo : NSObject
// 设备型号 如：xLeWcoelZbyOePbJludl 必填
@property (nonatomic, copy) NSString *productKey;
// 设备序列号SN 如：TEST20240820002 必填
@property (nonatomic, copy) NSString *deviceName;
// 平台为设备颁发的ID，设备的唯一标识符 必填
@property (nonatomic, copy) NSString *iotId;
// 设备的昵称 必填
@property (nonatomic, copy) NSString *nickName;
// 设备状态。0（表示未激活）；1（表示在线）；2（表示休眠）；3（表示离线）；8（表示禁用）必填
@property (nonatomic, assign) NSInteger status;
// 播放策略 必填
@property (nonatomic, copy) NSString *playStrategy;
// 设备属性值 必填
@property (nonatomic, strong) NSDictionary *propertyMap;
@end

NS_ASSUME_NONNULL_END
