
#import <Foundation/Foundation.h>

#ifdef __cplusplus
extern "C" {
#endif

NS_ASSUME_NONNULL_BEGIN

#define COMMON_PRINTF(format, ...)   IOT_LoggerPrintf("IOT-Common", 0, __FILE__, __FUNCTION__, __LINE__, format, ## __VA_ARGS__)
#define HTTP_PRINTF(format, ...)   IOT_LoggerPrintf("IOT-HTTP", 0, __FILE__, __FUNCTION__, __LINE__, format, ## __VA_ARGS__)
#define PLAYER_PRINTF(format, ...)   IOT_LoggerPrintf("IOT-Player", 0, __FILE__, __FUNCTION__, __LINE__, format, ## __VA_ARGS__)
#define SESSION_PRINTF(format, ...)   IOT_LoggerPrintf("IOT-Session", 0, __FILE__, __FUNCTION__, __LINE__, format, ## __VA_ARGS__)
#define SMARTLINK_PRINTF(format, ...)   IOT_LoggerPrintf("IOT-SmartLink", 0, __FILE__, __FUNCTION__, __LINE__, format, ## __VA_ARGS__)

#ifdef DEBUG
#define NSLog(format, ...)              IOT_LoggerPrintf("IOT-NSLog", 0, __FILE__, __FUNCTION__, __LINE__, format, ## __VA_ARGS__)
#else
#define NSLog(format, ...)
#endif

extern void IOT_LoggerSwitch(bool isPrintf);

extern void IOT_LoggerPrintf(const char* module, int npid, const char* file, const char* function, int line, NSString *format,...);

NS_ASSUME_NONNULL_END

#ifdef __cplusplus
};
#endif
