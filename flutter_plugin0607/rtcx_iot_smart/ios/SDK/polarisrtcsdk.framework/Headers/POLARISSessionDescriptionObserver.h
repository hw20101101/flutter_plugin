#ifndef POLARIS_SESSIONDESCRIPTIONOBSERVER_H_
#define POLARIS_SESSIONDESCRIPTIONOBSERVER_H_

#include "api/peer_connection_interface.h"
#include "POLARISRtcInternalDef.h"

NS_POLARIS_START

class CPOLARISChanRtcImpl;

class POLARISOfferSdpCreateObsv : public webrtc::CreateSessionDescriptionObserver {
 public:
  explicit POLARISOfferSdpCreateObsv(CPOLARISChanRtcImpl* channel);

  void OnSuccess(webrtc::SessionDescriptionInterface* desc) override;
  void OnFailure(webrtc::RTCError error) override;

 private:
  CPOLARISChanRtcImpl* rtc_channel_;
};

class POLARISRemoteSdpObsv
    : public webrtc::SetRemoteDescriptionObserverInterface {
 public:
  void OnSetRemoteDescriptionComplete(webrtc::RTCError error) override;
};

class POLARISLocalSdpObsv
    : public webrtc::SetSessionDescriptionObserver {
 public:
  void OnSuccess() override;
  void OnFailure(webrtc::RTCError error) override;
};

NS_POLARIS_END
#endif
