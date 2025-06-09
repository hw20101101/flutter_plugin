//
//  RTCXPreConnectMgr.h
//  RTCXMedia
//
//  Created by Apple on 2024/11/14.
//

#import <Foundation/Foundation.h>
#import <RTCXMedia/RTCXPreConnectInfo.h>
NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, RTCXPlayStrategyType) {
    RTCXPlayStrategyType_UNKNOW = 0,
    RTCXPlayStrategyType_CMS = 1,
    RTCXPlayStrategyType_P2P = 2,
    RTCXPlayStrategyType_AUTO =3
};

@interface RTCXPreConnectMgr : NSObject
+ (instancetype)sharedInstance;
// P2P预连接
- (void)preConnectP2P:(RTCXPreConnectInfo *)preConnectInfo;
// 播放策略类型
- (RTCXPlayStrategyType)getStrategyType:(NSString *)strategy;
@end

NS_ASSUME_NONNULL_END
