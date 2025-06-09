#ifndef IPOLARISMUXERCALLBACK_H
#define IPOLARISMUXERCALLBACK_H

// #include "POLARISRtcInternalDef.h"

// USING_NS_POLARIS
NS_POLARIS_START

// namespace webrtc
// {

// #ifdef WEBRTC_WIN
// #define POLARISMUXER_API __declspec(dllexport)
// #else
// #define POLARISMUXER_API
// #endif //WEBRTC_WIN

class  IPOLARISMuxCb
{
public:
	virtual void onError(int code, const std::string& msg) = 0;
	virtual void onCompleted(int code, const std::string& outfile) = 0;
	virtual void onProgressUpdate(uint64_t duration) = 0;
	virtual void onChangeMediaFormat(const std::string& outfile) = 0;
};

// }
NS_POLARIS_END

#endif // IPOLARISMUXERCALLBACK_H
