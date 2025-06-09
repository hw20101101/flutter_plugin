
#ifndef POLARIS_RTC_DEF_H
#define POLARIS_RTC_DEF_H

#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <map>

#ifdef __OBJC__

#import <UIKit/UIKit.h>

#else 

#define UIImage void

#endif

#ifndef NS_POLARIS_START
#define NS_POLARIS_START namespace polaris {
#endif  // !NS_POLARIS_START

#ifndef NS_POLARIS_END
#define NS_POLARIS_END }
#endif  // !NS_POLARIS_END

#ifndef USING_NS_POLARIS
#define USING_NS_POLARIS using namespace polaris;
#endif  // !USING_NS_POLARIS

NS_POLARIS_START

#define POLARIS_EVENT_TOUCH_UP 0
#define POLARIS_EVENT_TOUCH_DOWN 1
#define POLARIS_EVENT_TOUCH_MOVE 2
#define POLARIS_EVENT_DOUBLE_TAP 3

#if  (defined(_WIN32) || defined(_WIN64))
#define attribute_deprecated __declspec(deprecated)
#else
#define attribute_deprecated __attribute__((deprecated))
#endif

#if (defined(_WIN32) || defined(_WIN64))
#ifdef POLARIS_RTC_CHANNEL_EXPORT
#define POLARIS_RTC_CHANNEL_API __declspec(dllexport)
#else
#define POLARIS_RTC_CHANNEL_API __declspec(dllimport)
#endif
#else
#define POLARIS_RTC_CHANNEL_API __attribute__((visibility("default")))
#endif

enum POLARISRtcStatusCode {
  POLARIS_RTC_SUCCESS = 0,
  POLARIS_RTC_START_BUFFERING = 1,
  POLARIS_RTC_STOP_BUFFERING = 2,
  POLARIS_RTC_PUSH_SUCCEEDED = 10000,
  // RTC_PLAYBACK_SUCCESS = 10001,
  // RTC_AUDIO_TALK_SUCCESS = 10002,
  POLARIS_RTC_PEER_CONNECTION_FAILED_CREATE = -1,
  POLARIS_RTC_CONNECT_FAILED = -2,
  POLARIS_RTC_SDP_CREATE_FAILED = -3,
  POLARIS_RTC_SDP_SET_FAILED = -4,
  POLARIS_RTC_CONNECT_SUCCESS = -10,
  POLARIS_RTC_RESUORCE_NOT_ENOUGH = -10000, //资源不足（播放达到最大个数）

  POLARIS_RTC_NO_RECORDED_FILE = -10001, //找不到录像文件

  POLARIS_RTC_SPEED_UNSUPPORTED = -10002, //不支持的速率

  POLARIS_RTC_CMS_ADDRESS_GET_FAILED = -10003, //获取cms地址失败

  POLARIS_RTC_CMS_CONNECT_FAILED = -10004, //连接cms失败

  POLARIS_RTC_AUDIO_TALK_BUSY = -10005, //camera 正在对讲中

  POLARIS_RTC_P2P_MAX_CLIENT_COUNT = -10006, //p2p连接上限

  POLARIS_RTC_VIDEO_TALK_BUSY = -10007 //双向视频通话busy（资源不足）
};

enum LoggingSeverity {
  LS_VERBOSE,
  LS_INFO,
  LS_WARNING,
  LS_ERROR,
  LS_NONE,
  INFO = LS_INFO,
  WARNING = LS_WARNING,
  LERROR = LS_ERROR
};

enum STATS_TYPE {
  POLARIS_STATS_PLAY_VIDEO = 0,
  POLARIS_STATS_PUSH_VIDEO
};


#define  CHANNEL_P2P  "P2P"
#define  CHANNEL_CMS  "cms"

enum POLARISCodecID {
    POLARIS_CODEC_ID_NONE = 'none',
    POLARIS_CODEC_ID_H264 = '264 ',
    POLARIS_CODEC_ID_H265 = 'hevc',
    POLARIS_CODEC_ID_AAC = 'aac ',
    POLARIS_CODEC_ID_PCM_ALAW = '711a',
    POLARIS_CODEC_ID_PCM_MULAW = '711u',
    POLARIS_CODEC_ID_G726 = '726 ',
	  POLARIS_CODEC_ID_OPUS = 'opus'
};

typedef std::function<void(int32_t)> SwitchCameraCompletion;
typedef std::map<std::string, std::string> TraceMsg;

//trace point
struct MsgTraceData {
    std::string cmdType;
    std::string traceId;
    uint64_t ts;
    TraceMsg polarismsg;
};

//所有回调都需要异步处理
class IPOLARISChanEvtRtcMgr {
 public:
  virtual ~IPOLARISChanEvtRtcMgr() {}

  //localSdp eg:{"type":"offer", "sdp":"sdp-content","natType":1,"stream":"stream-id", "app":"app-id"}
  virtual void OnLocalSdpReady(const std::string& channelType, const std::string& localSdp) = 0;

  virtual void OnStatus(POLARISRtcStatusCode code, const std::string& msg) = 0;

#ifdef __APPLE__
    
  virtual void OnSnapshotTaken(int32_t errorCode, UIImage* image) {}
    
#else

  virtual void OnSnapshotTaken(int32_t errorCode, const std::string& filePath) {}

  virtual void OnSnapshotTaken(int32_t errorCode, const uint8_t* data, int width, int heigh) {}
    
#endif

  //边播边录回调中不要执行耗时操作，或者访问UI
  //stopRecord触发后，回调录制进度recordtime(ms), stopRecord之后，是否录制完成(completed)
  virtual void OnRecordProgressCb(int32_t recordtime, bool completed) = 0;

   //录制完成，回调录制文件的路径
  virtual void OnPathOfRecordedFile(std::string& filePath) = 0;

    //录制过程中出现错误时回调
  virtual void OnRecordErrorCb(int32_t errorCode,
                             const std::string& errorString) = 0;
  //如果不调用 setupRemoteVideo，将不会进行渲染，而是通过该接口回调解码后的yuv数据
  virtual void OnYUVData(const uint8_t* ydata, const uint8_t* udata, const uint8_t* vdata, uint32_t width, uint32_t heigth) {};
  
  virtual void OnPlayDuration(uint32_t duration) {};
  
  virtual void OnPlayCurrentUTC(uint64_t utc_position) {};

  //resolution changed callback for play mode, and getStats be invoked for push mode
  virtual void OnChangeResolution(STATS_TYPE stats_type, uint32_t width, uint32_t height) {};

  //Async callback after getStats be invoked
  //bitrate( bps )
  virtual void OnUpdateBitrate(STATS_TYPE stats_type, uint32_t bitrate) {};
  
  //Async callback after getStats be invoked
  //frame rate ( fps ）
  virtual void OnUpdateFrameRate(STATS_TYPE stats_type, double frame_rate) {};

  virtual void OnIceCandidate(const std::string& candidate) {};

  virtual void OnChannelCurrent(const std::string& channelType) {};

  virtual void OnSignallingOutCb(const std::string& channelType, int32_t cmdId, const std::string& msg, const std::string& extra) {};

  virtual void OnQosInfo(const std::string& qos_info) {};
  
  //recorded_time 回调音频的时间长度
  //recorded_size 音频数据的长度
  //recorded_data 音频数据
  virtual void OnRecordAudioDataCb( uint32_t recorded_time, uint32_t recorded_size, const uint8_t* recorded_data ) {};
    
  // 埋点信息回调
  virtual void OnTracePointMsg(const MsgTraceData& data) {}
  
  // 获取 traceid
  virtual void OnTraceId(std::string& traceid) {};
};

extern POLARIS_RTC_CHANNEL_API int birthdayType;
extern POLARIS_RTC_CHANNEL_API int birthdayCount;

class POLARISChanCtxRtc {
 public:
  IPOLARISChanEvtRtcMgr* eventHandler;
  bool receiveVideo; //for play video
  bool receiveAudio; //for play audio
  bool sendVideo; //for push video
  bool sendAudio; //for push audio
  int width;  // push video width
  int height; // push video height
  int fps;  // push video fps
  int videoMaxBitrate; // bitrate of send video（kbps）
  bool disableP2pMute;
  std::string strategy; //播放通道策略
  std::string tracePointStrategy;  //QoS埋点策略
  bool isElectron;
  int birthdayType = 0;
  int birthdayCount = 400;
  int isBirthdaySet = 0;
  int videoTrackNum;
  int audioTrackNum;
  std::string mid;
  POLARISChanCtxRtc()
      : eventHandler(NULL),
        receiveVideo(false),
        receiveAudio(false),
        sendVideo(false),
        sendAudio(false),
        isElectron(false),
        width(240),
        height(320),
        fps(10),
        videoMaxBitrate(0),
        disableP2pMute(false),
        videoTrackNum(1),
        audioTrackNum(1)
        {
          this -> birthdayType = ::polaris::birthdayType;
          this -> birthdayCount = ::polaris::birthdayCount;
        }
  virtual ~POLARISChanCtxRtc() {}
};

enum LOGO_WATERMARK_POS{
	RtcDefault_Pos,
	RtcLeft_Top,
	RtcRight_Top,
	RtcRight_Bottom,
	RtcLeft_Bottom,
};


struct WatermarkParam{
  std::string time_osd_font_path; // 时间水印固定在左上角
  std::string logo_osd_logo_path; //logo图片所在文件夹
	LOGO_WATERMARK_POS osd_pos; //logo贴图位置
};

enum POLARISRTC_STREAM_TYPE {
  POLARIS_LIVE_PULL = 0,
  POLARIS_SDCARD_PLAYBACK,
  POLARIS_CLOUD_PLAYBACK,
  POLARIS_LIVE_PUSH
};

struct POLARISRtcConfigOfStrmChn
{
  POLARISRTC_STREAM_TYPE streamType;
  std::string deviceId;
  std::string channelId;
  int lensId;
	int64_t startTime;
  int64_t endTime;
  float speed;
  int videoTrackNum;
  int audioTrackNum;
  std::string traceId; //for QoS
  POLARISRtcConfigOfStrmChn()
	{
    lensId = 0;
    startTime = 0;
    endTime = 0;
    speed = 1.0;
    videoTrackNum = 1;
    audioTrackNum = 1;
	}
};

NS_POLARIS_END

#endif
