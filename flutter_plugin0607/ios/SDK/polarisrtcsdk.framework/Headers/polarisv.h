#ifndef POLARISV_H
#define POLARISV_H

#include "polarisrtcsdk/POLARISRtcInternalDef.h"

#define POLARISV_MAX_STREAM_NUM 2

NS_POLARIS_START

enum POLARISPacketType {
    POLARIS_PACKET_TYPE_UNKNOWN = 0,
    POLARIS_PACKET_TYPE_AUDIO = 1,
    POLARIS_PACKET_TYPE_VIDEO = 2,
    POLARIS_PACKET_TYPE_AUDIO_PARAM = 3,
    POLARIS_PACKET_TYPE_VIDEO_PARAM = 4,
};

struct POLARISPacketHeader {
    uint8_t pkt_type;
    uint8_t is_sync;
    uint16_t time_span;
    uint32_t pkt_size;
    int64_t start_time;
    uint32_t sequence_num;
};

NS_POLARIS_END

#endif //POLARISV_H
