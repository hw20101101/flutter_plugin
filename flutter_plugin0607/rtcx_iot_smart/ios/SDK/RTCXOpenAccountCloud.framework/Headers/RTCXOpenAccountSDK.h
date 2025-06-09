//
//  RTCXOpenAccountSDK.h
//  RTCXOpenAccountCloud
//
//  Created by Apple on 2024/8/20.
//

#import <Foundation/Foundation.h>

#import <RTCXOpenAccountCloud/RTCXOpenAccountProtocol.h>
#import <RTCXOpenAccountCloud/RTCXOpenAccountParams.h>
#import <RTCXOpenAccountCloud/RTCXGlobalConfigProtocol.h>
#import <RTCXOpenAccountCloud/RTCXGlobalConfigModel.h>
#import <RTCXOpenAccountCloud/RTCXAllRegionProtocol.h>
#import <RTCXOpenAccountCloud/RTCXAllRegionModel.h>
#import <RTCXOpenAccountCloud/RTCXImageUrlMgrProtocol.h>
#import <RTCXOpenAccountCloud/RTCXImageUrlMgrModel.h>

#ifndef RTCXService
#define RTCXService(__protocol__) \
((id<__protocol__>)([[RTCXOpenAccountSDK sharedInstance] getService:@protocol(__protocol__)]))
#endif

@interface RTCXOpenAccountSDK : NSObject

+ (instancetype)sharedInstance;

/**
 获取RTCXOpenAccountSDK的service 实例
 @param protocol service的协议
 @return service实例
 */
- (id)getService:(Protocol *)protocol;

@end

