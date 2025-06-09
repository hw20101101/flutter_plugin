//
//  IOTAppSdkLogManager.h
//  IOTSDKFramework
//
//  Created by Apple on 2024/8/20.
//  Copyright © 2024 arcsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCXLogCollectMgr : NSObject

@property (nonatomic, assign) BOOL collectLogEnable; // 收集AppSDK日志开关 YES:开 NO:关

+ (instancetype)sharedInstance;

- (void)collectLogWithLine:(NSUInteger)line method:(NSString *)methodName format:(NSString *)format;

@end

NS_ASSUME_NONNULL_END
