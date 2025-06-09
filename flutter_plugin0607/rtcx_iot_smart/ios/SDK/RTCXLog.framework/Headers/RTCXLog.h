//
//  RTCXLog.h
//  RTCXLog
//
//  Created by Apple on 2024/8/15.
//

#import <Foundation/Foundation.h>
@class RTCXLogRule;
//! Project version number for RTCXLog.
FOUNDATION_EXPORT double RTCXLogVersionNumber;

//! Project version string for RTCXLog.
FOUNDATION_EXPORT const unsigned char RTCXLogVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <RTCXLog/PublicHeader.h>

#import <RTCXLog/RTCXLogCollectMgr.h>
#import <RTCXLog/LoggerClient.h>

/**
 Flag,和 Level 一起协同过滤要输出的日志，每条 log 都有对应的 flag。
 
 */
typedef NS_OPTIONS(NSUInteger, RTCXLogFlag){
    RTCXLogFlagError      = (1 << 0),
    RTCXLogFlagWarning    = (1 << 1),
    RTCXLogFlagInfo       = (1 << 2),
    RTCXLogFlagDebug      = (1 << 3),
    RTCXLogFlagVerbose    = (1 << 4)
};

/**
 Level，日志级别，和 flag 一起协同过滤要输出的日志。
 
 */
typedef NS_ENUM(NSUInteger, RTCXLogLevel){
    RTCXLogLevelOff       = 0,
    RTCXLogLevelError     = (RTCXLogFlagError),
    RTCXLogLevelWarning   = (RTCXLogLevelError   | RTCXLogFlagWarning),
    RTCXLogLevelInfo      = (RTCXLogLevelWarning | RTCXLogFlagInfo),
    RTCXLogLevelDebug     = (RTCXLogLevelInfo    | RTCXLogFlagDebug),
    RTCXLogLevelVerbose   = (RTCXLogLevelDebug   | RTCXLogFlagVerbose),
    RTCXLogLevelAll       = NSUIntegerMax
};

/**
 日志模块，提供客户端统一日志打印，日志等级控制，分模块日志隔离等能力，同时支持拓展日志输出的能力。
 */
@interface RTCXLog : NSObject

/**
 注册需要输出日志的 tag
 
 日志模块以 tag 为维度对日志进行等级控制、隔离等操作，建议使用模块名称作为tag。
 
 @param tag 标签
 */
+ (void)registerTag:(NSString *_Nonnull)tag;


/**
 统一设置所有 tag 的显示日志级别
 
 若 tag 未设置级别，将不会输出对应 tag 的日志。
 
 @param level 日志级别
 */
+ (void)setAllTagsLevel:(RTCXLogLevel) level;


/**
 设置 tag 对应的显示日志级别

 若 tag 未设置级别，将不会输出对应 tag 的日志。
 
 @param level 日志级别
 @param tag 标签
 */
+ (void)setLevel:(RTCXLogLevel)level forTag:(NSString *_Nonnull)tag;


/**
 在控制台打印日志
 
 建议在 release 版本中关闭打印
 
 */
+ (void)showInConsole:(BOOL)show;

/**
 Tag 和 Level 的映射表

 */
+(NSArray <RTCXLogRule *>*_Nullable)tagLevelRules;

@end

/**
 RTCXLogRule 类包含tag和Level的映射关系
 */
@interface RTCXLogRule : NSObject

/**
 tag
 
 用于对日志进行等级控制、隔离等操作，建议使用模块名称作为tag。
 */
@property(nonatomic, copy, readonly) NSString * _Nullable tag;

/**
 日志级别
 
 用于过滤要输出的日志
 */
@property(nonatomic, assign, readonly) RTCXLogLevel  level;
@end
