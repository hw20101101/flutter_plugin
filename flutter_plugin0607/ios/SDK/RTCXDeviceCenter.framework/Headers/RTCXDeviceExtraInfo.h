//
//  RTCXDeviceExtraInfo.h
//  RTCXDeviceCenter
//
//  Created by Apple on 2025/2/25.
//

#import <Foundation/Foundation.h>
#import <RTCXDeviceCenter/RTCXCloudServicesModel.h>
NS_ASSUME_NONNULL_BEGIN

@interface RTCXDeviceExtraInfoReq : NSObject
// iotId数组 eg:[xxx]
@property (nonatomic, strong) NSArray *iotIds;

@end

@interface RTCXDeviceExtraInfo : NSObject
// 平台为设备颁发的ID，设备的唯一标识符
@property (nonatomic, copy) NSString *iotId;
// 播放策略
@property (nonatomic, copy) NSString *playStrategy;
// 设备属性值
@property (nonatomic, strong) NSDictionary *propertyMap;
// 设备云存套餐信息
@property (nonatomic, strong) RTCXCloudServicesRsp *cloudServices;
@end

NS_ASSUME_NONNULL_END
