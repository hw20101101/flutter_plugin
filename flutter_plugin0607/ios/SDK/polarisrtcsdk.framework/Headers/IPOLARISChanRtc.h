#ifndef POLARIS_RTC_CHANNEL_H
#define POLARIS_RTC_CHANNEL_H
#include "POLARISRtcDef.h"
#include "IPOLARISStreamChanRtc.h"

#ifdef WEBRTC_ANDROID
#include "sdk/android/native_api/video/video_source.h"
#endif

NS_POLARIS_START

class POLARIS_RTC_CHANNEL_API IPOLARISChanRtc {
 public:
  typedef std::shared_ptr<IPOLARISChanRtc> Ptr;

  IPOLARISChanRtc() {}

  virtual ~IPOLARISChanRtc() {}

  //stunUrl eg:stun:172.26.18.112:12334
  static int initialize(const std::string& stunUrl);

  attribute_deprecated
  static int  uninitialize();

  //set log level
  static void setLoggingSeverity(LoggingSeverity min_sev);

  //set log level
  static void setLoggingSeverity(LoggingSeverity min_sev, const std::string& log_path, int log_size);

  //get rtcsdk version
  static int getVersion(std::string& version);

  //set UIView/Surfaceview/Wnd for push video display 
  virtual int setupLocalVideo(void* localView) = 0;

  //set UIView/Surfaceview/Wnd for play video display
  virtual int setupRemoteVideo(void* remoteView) = 0;

  static IPOLARISChanRtc::Ptr createChannel(const POLARISChanCtxRtc& context, const std::shared_ptr<IPOLARISStreamChanRtc> p2pChannel = nullptr,
                                            const std::shared_ptr<IPOLARISStreamChanRtc> cmsChannel = nullptr);

  //param for playback
  virtual int start(const POLARISRtcConfigOfStrmChn& param) = 0;

  //seek for playback, not implement
  virtual int seek(const POLARISRtcConfigOfStrmChn& param) = 0;

  //预连开始流传输
  virtual int startStream(const POLARISRtcConfigOfStrmChn& param) = 0;

  //预连结束流传输
  virtual int stopStream() = 0;

  virtual int stop() = 0;

  virtual int setRemoteSdp(const std::string& channel_type, const std::string& remoteSdp) = 0;

  //start record when playing
  virtual int startRecord(const std::string& filePath,
                           bool bWithWaterMark = false) = 0;
  //stop record                           
  virtual int stopRecord() = 0;

  //mute push video
  virtual int muteLocalVideoStream(bool mute) = 0;

  //mute push audio
  virtual int muteLocalAudioStream(bool mute) = 0;

  //mute play audio
  virtual int muteRemoteAudioStream( bool mute) = 0;

  //mute play video
  virtual int muteRemoteVideoStream(bool mute) = 0;

  //snapshot
  virtual int takeSnapshot(const bool with_watermark, const std::string& filePath = "") = 0;

  // volume : 0-100 only for windows
  virtual int setVolume(uint32_t volume) = 0;

// volume : 0-100 only for windows
  virtual int getVolume(uint32_t& volume) =0;

  //switch front camera and back camera
  virtual void switchCamera(SwitchCameraCompletion onCompletion) = 0;

  virtual void remoteViewPinchTouch(float fZoomRate, float fMidPointX, float fMidPointY) = 0;

  virtual void remoteViewMoveTouch(float fTouchPointStartX, float fTouchPointStartY, float fTouchPointEndX, float fTouchPointEndY) = 0;

  virtual void remoteViewByDoubleTap(float fMidPointX, float fMidPointY) = 0;

  //stats info will callback in OnUpdateBitrate/OnUpdateFrameRate
  virtual void getStats() = 0;

  //video logo  for display
  virtual void setVideoOsd(std::string bmpPath, const float* posCoord) = 0;

  //distortion params for video display
  virtual void setParamDistortion(double* dblArrParamData, int length) = 0;

  //feature tracking param
  virtual void setParamFeatureTracking(bool is_featrue_tracking, uint32_t smooth_param) = 0;

  virtual void setParamWatermark(const WatermarkParam& watermark_param) = 0;

  virtual void setIceCandidate(const std::string& iceCandidate) = 0;

  virtual void signallingIncome(const std::string& channelType, int32_t cmdId, const std::string& msg, const std::string& extra) = 0;
  
  static std::vector<std::string> enumerateVideoDevices();

  //virtual void updateBitrate( long maxBitrate ) = 0;
#ifdef WEBRTC_ANDROID
  virtual rtc::scoped_refptr<webrtc::JavaVideoTrackSourceInterface> getVideoDevice() = 0;
#endif
    
   virtual void setBackgroundColor(uint32_t color) = 0;

   virtual void startTalk(const POLARISCodecID& codec, bool callback_data = true) = 0;

   virtual void stopTalk() = 0;

   //only for iOS
   virtual void setBackgroundRender(bool enable) = 0;

};

NS_POLARIS_END

#endif  // POLARIS_RTC_CHANNEL_H
