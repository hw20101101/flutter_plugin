

#ifndef POLARIS_RTC_STATS_CALLBACK_H
#define POLARIS_RTC_STATS_CALLBACK_H

#include "api/stats/rtc_stats_collector_callback.h"
#include "api/stats/rtc_stats_report.h"
#include "POLARISRtcInternalDef.h"

NS_POLARIS_START

class CPOLARISStatsCbRtc : public webrtc::RTCStatsCollectorCallback
{
public:
  CPOLARISStatsCbRtc(const POLARISChanCtxRtc& context, STATS_TYPE stats_type = POLARIS_STATS_PLAY_VIDEO);
  virtual ~CPOLARISStatsCbRtc() {}
  void OnStatsDelivered( const rtc::scoped_refptr<const webrtc::RTCStatsReport>& report) override;

private:
    const POLARISChanCtxRtc rtc_channel_context_;
    int64_t last_play_timestamp_us_;
    uint32_t last_play_width_;
    uint32_t last_play_height_;
    uint64_t last_received_bytes_;
    double last_play_frame_rate_;

    int64_t last_push_timestamp_us_;
    uint32_t last_push_width_;
    uint32_t last_push_height_;
    uint64_t last_sent_bytes_;
    double last_push_frame_rate_;

    STATS_TYPE stats_type_;
};

NS_POLARIS_END

#endif