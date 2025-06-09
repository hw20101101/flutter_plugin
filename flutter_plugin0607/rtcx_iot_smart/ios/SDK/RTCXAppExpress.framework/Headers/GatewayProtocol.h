//
//  GatewayProtocol.h
//  RTCXAppExpress
//
//  Created by Apple on 2025/2/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GatewayProtocol <NSObject>
/**
 设置子设备对应的网关Id
 */
- (void)setGatewayId:(NSString *)gatewayId forIotId:(NSString *)iotId;
/**
 获取子设备对应的网关Id
 */
- (NSString *)getGatewayIdForIotId:(NSString *)iotId;
/**
 设置设备对应的region
 */
- (void)setRegion:(NSString *)region forIotId:(NSString *)iotId;
/**
 获取设备对应的region
 */
- (NSString *)getRegionForIotId:(NSString *)iotId;
@end

NS_ASSUME_NONNULL_END
