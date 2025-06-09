
#ifndef POLARIS_RTC_VIDEORENDERER_H_
#define POLARIS_RTC_VIDEORENDERER_H_

#include "POLARISRtcDef.h"
#include "api/video/video_sink_interface.h"
#include "api/video/video_frame.h"
#include "polarisrtcsdk/polarismuxer/polarisv.h"
#include "polarisrtcsdk/POLARISVideoRender/POLARISAIInfoData.h"
#include "polarisrtcsdk/polarismuxer/POLARISRtcRecordDef.h"

#include "DisplayConfigure.h"
#include "GlobalConfiger.h"
#include "POLARISRtcVideoReceiver.h"


#ifdef WEBRTC_WIN
#include "POLARISWinVideoRender.h"
#endif

NS_POLARIS_START

typedef std::function<void(const std::string& channel_type, const webrtc::VideoFrame& frame)>	OnOneFrameCallback;

class CPOLARISRtcVidShower : public VideFrameObserver {
 public:
  CPOLARISRtcVidShower(const std::string& channel_type,  void* parent_obj, std::shared_ptr<CPolarisAllRegionConfMgr> global_configer, const std::string &mid);
  virtual ~CPOLARISRtcVidShower();
  void OnFrame(const webrtc::VideoFrame& frame) override;
  bool IsInterestedMid(const std::string &mid);
  void setOnFrameCb(OnOneFrameCallback cb);
  
private:
  OnOneFrameCallback onFrameCb;
  std::string channel_type_;
  std::mutex _mutex;
  void* parent_object_;
  std::shared_ptr<CPolarisAllRegionConfMgr> global_configer_ = nullptr;
  // 首帧type可能非关键帧 也要当作关键帧处理
  bool is_first_frame_ = true;
  std::string mid_;
};


NS_POLARIS_END
#endif  // POLARIS_RTC_VIDEORENDERER_H_
