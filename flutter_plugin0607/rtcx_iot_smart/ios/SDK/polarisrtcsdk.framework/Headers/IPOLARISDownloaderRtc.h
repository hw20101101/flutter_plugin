#ifndef POLARIS_RTC_DOWNLOAD_H
#define POLARIS_RTC_DOWNLOAD_H
#include "POLARISRtcDef.h"

#if (defined(_WIN32) || defined(_WIN64))
#ifdef POLARIS_RTC_DOWNLOAD_EXPORT
#define POLARIS_RTC_DOWNLOAD_API __declspec(dllexport)
#else
#define POLARIS_RTC_DOWNLOAD_API __declspec(dllimport)
#endif
#else
#define POLARIS_RTC_DOWNLOAD_API __attribute__((visibility("default")))
#endif

NS_POLARIS_START

class POLARIS_RTC_DOWNLOAD_API IPOLARISDownloaderRtc {
 public:
  typedef std::shared_ptr<IPOLARISDownloaderRtc> Ptr;

  IPOLARISDownloaderRtc() {}

  virtual ~IPOLARISDownloaderRtc() {}

  static int  initDownloadByStunUrl(const std::string& stunUrl);
  
  attribute_deprecated
  static int  uninitDownload();
  
  static void setLoggingSeverity(LoggingSeverity min_sev);

  virtual void setParamWatermark(const WatermarkParam& watermark_param) = 0;

  static IPOLARISDownloaderRtc::Ptr downloadCreate(const POLARISChanCtxRtc& context);

  virtual int setDownloadRemoteSdp(const std::string& channel_type, const std::string& remoteSdp) = 0;

  virtual int startDownload(const POLARISRtcConfigOfStrmChn& param, const std::string& filePath,
                           bool bWithWaterMark = false) = 0;
  virtual int stopDownload() = 0;

  virtual void setIceCandidate(const std::string& iceCandidate) = 0;
  
  virtual void signallingIncome(const std::string& channelType, int32_t cmdId, const std::string& msg, const std::string& extra) = 0;
};

NS_POLARIS_END

#endif  // POLARIS_RTC_DOWNLOAD_H