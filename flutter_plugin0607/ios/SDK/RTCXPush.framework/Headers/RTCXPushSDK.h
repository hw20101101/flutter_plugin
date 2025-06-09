//
//  RTCXPushSDK.h
//  RTCXPush
//
//  Created by Apple on 2024/9/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#ifndef RTCXPushService
#define RTCXPushService(__protocol__) \
((id<__protocol__>)([[RTCXPushSDK sharedInstance] getService:@protocol(__protocol__)]))
#endif

@interface RTCXPushSDK : NSObject
+ (instancetype)sharedInstance;

/**
 获取RTCXPush的service 实例
 @param protocol service的协议
 @return service实例
 */
- (id)getService:(Protocol *)protocol;
@end

NS_ASSUME_NONNULL_END
