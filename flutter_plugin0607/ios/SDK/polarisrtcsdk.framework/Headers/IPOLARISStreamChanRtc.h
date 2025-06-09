#ifndef POLARIS_STREAM_RTC_CHANNEL_H
#define POLARIS_STREAM_RTC_CHANNEL_H
#include "POLARISRtcDef.h"


NS_POLARIS_START

class CPOLARISChanRtcImpl;
class RTCPeerConnFTY;

class POLARIS_RTC_CHANNEL_API IPOLARISStreamChanRtc {
 public:
  typedef std::shared_ptr<IPOLARISStreamChanRtc> Ptr;

  IPOLARISStreamChanRtc() {}

  virtual ~IPOLARISStreamChanRtc() {}

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

  static IPOLARISStreamChanRtc::Ptr createChannel(const POLARISChanCtxRtc& context);

  //param for create offer
  virtual int start(const POLARISRtcConfigOfStrmChn& param) = 0;

  virtual int stop() = 0;

  virtual int setRemoteSdp(const std::string& channel_type, const std::string& remoteSdp) = 0;

  virtual void setIceCandidate(const std::string& iceCandidate) = 0;

  virtual void signallingIncome(int32_t cmdId, const std::string& msg, const std::string& extra) = 0;

  
};

NS_POLARIS_END

#endif  // POLARIS_RTC_CHANNEL_H