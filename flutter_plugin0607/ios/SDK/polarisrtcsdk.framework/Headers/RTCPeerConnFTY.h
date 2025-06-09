
#ifndef RTC_SDK_RTCPEERCONNECTIONFACTORY_H_
#define RTC_SDK_RTCPEERCONNECTIONFACTORY_H_

#include <memory>
#include <mutex>
#include "api/peer_connection_interface.h"
#include "POLARISRtcDef.h"

#include "POLARISRtcVideoRenderer.h"
//#include "test/win/d3d_renderer.h"
#ifdef WEBRTC_ANDROID
#include "sdk/android/native_api/video/video_source.h"
#endif
#include "POLARISRtcRecordAudioCallback.h"
#include <fstream>

#ifndef WEBRTC_ANDROID
#include "POLARISRtcVideoCapture.h"
#endif

NS_POLARIS_START

struct CPolarisEncodedAudioFrame {

  std::unique_ptr<uint8_t[]> _data;
  uint32_t _data_size = 0;
  uint32_t _recorded_time = 0;

  CPolarisEncodedAudioFrame(uint8_t* dataPtr,
                     uint32_t dataSize,
                     uint32_t recordedTime
                     )
      : _data(dataPtr),
        _data_size(dataSize),
        _recorded_time(recordedTime)
	 {}
};

class RTCPeerConnFTY : public webrtc::IPOLARISRecAudCbRtc{
 public:

  ~RTCPeerConnFTY();

  int createTrack(bool enableLocalVideo,  bool enableLocalAudio);

  rtc::scoped_refptr<webrtc::VideoTrackInterface> getVideoTrack() {
    return video_track_;
  }

  rtc::scoped_refptr<webrtc::AudioTrackInterface> getAudioTrack() {
    return audio_track_;
  }

#ifdef WEBRTC_ANDROID
  rtc::scoped_refptr<webrtc::JavaVideoTrackSourceInterface> getVideoDevice() {
    return video_device_;
  }
#endif

  void setVideoSettings( int width, int height, int fps );
  
  rtc::scoped_refptr<webrtc::PeerConnectionFactoryInterface>
  getPeerConnectionFactory() {
    return peer_connection_factory_;
  }

  RTCPeerConnFTY(bool enableLocalVideo, bool enableLocalAudio, void* parent_obj);

  int setupLocalVideo(std::shared_ptr<CPOLARISRtcVidShower> renderer, void* local_view);
  
  int muteLocalVideoStream(bool mute) ;

  int muteLocalAudioStream(bool mute) ;

  void addRef() const ;

  rtc::RefCountReleaseStatus release() const ;

  void startTalk(const POLARISCodecID& codec, bool callback_data, IPOLARISChanEvtRtcMgr* event_handler);

  void stopTalk();

  void OnAudioFrameEncode(const int16_t* data, uint32_t size, int sample_rate_hz, size_t num_channels) override ;

  void setSpeakerMute(bool bEnable);

  void enableAudioRecord(bool bEnable);

  void switchCamera(SwitchCameraCompletion onCompletion);

  void reset();

 private:
  void setSpeakerMuteInternal(bool bEnable);
  void DispatchRecordedAudio();



 protected:

  rtc::scoped_refptr<webrtc::PeerConnectionFactoryInterface>
      peer_connection_factory_;

  rtc::scoped_refptr<webrtc::VideoTrackInterface> video_track_;
  rtc::scoped_refptr<webrtc::AudioTrackInterface> audio_track_;

  std::unique_ptr<rtc::Thread> network_thread_;
  std::unique_ptr<rtc::Thread> worker_thread_;
  std::unique_ptr<rtc::Thread> signaling_thread_;

  void* local_video_view_;


#ifdef WEBRTC_ANDROID
  rtc::scoped_refptr<webrtc::JavaVideoTrackSourceInterface> video_device_;
  std::unique_ptr<rtc::VideoSinkInterface<webrtc::VideoFrame>> local_renderer_ = nullptr;
#else
  rtc::scoped_refptr<webrtc::VideoTrackSourceInterface> video_device_;
  std::shared_ptr<CPOLARISRtcVideoReceiver> local_renderer_;
#endif
  
  CPolarisAllRegionConfMgr* global_config_ = nullptr;
    
private:
  mutable webrtc::webrtc_impl::RefCounter ref_count_{0};

  std::ofstream dump_audio_;

  bool callback_data_;

  POLARISCodecID audio_codec_;

  IPOLARISChanEvtRtcMgr* event_handler_;

  void* parent_object_;

  std::unique_ptr<std::thread> set_speeaker_mute_thread_ptr_ = nullptr;
    
  std::mutex mutex_set_speeaker_mute_;

  std::vector<CPolarisEncodedAudioFrame> lst_encoded_audio_frame_;
	std::unique_ptr<std::thread> record_dispatch_thread_ptr_ = nullptr;   
	bool exit_record_;
  std::condition_variable cond_recorder_callback_;
  std::mutex mutex_recorder_callback_;
  bool enable_local_video_;
  bool enable_local_audio_;
  bool enable_audio_recording_;
  int width_;
  int height_;
  int fps_;
};

NS_POLARIS_END

#endif  // RTC_SDK_RTCPEERCONNECTIONFACTORY_H_
