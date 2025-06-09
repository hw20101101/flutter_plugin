#ifndef POLARISV_TYPEDEF_H
#define POLARISV_TYPEDEF_H

#include <memory>
#include "POLARISBuffer.h"
#include "polarisv.h"

NS_POLARIS_START

struct POLARISPacket;
typedef POLARISBuffer<uint8_t> POLARISPacketBuffer;
typedef std::shared_ptr<POLARISPacket> POLARISPacketPtr;

struct POLARISPacket {
    POLARISPacket(POLARISPacketHeader h = {0 }, size_t data_size = 0)
            : header(h),
              buffer(data_size)
    {

    }

    POLARISPacketHeader header;
    POLARISPacketBuffer buffer;
};

NS_POLARIS_END

#endif // POLARISV_TYPEDEF_H