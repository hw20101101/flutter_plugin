#ifndef POLARISMUXER_H
#define POLARISMUXER_H

#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <string>
#include <memory>
#include <vector>
#include <condition_variable>

#ifdef POLARIS_DEBUG
#include <fstream>
#endif // POLARIS_DEBUG

extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/opt.h>
#include <libavfilter/avfilter.h>
}

#include "polarisvtypedef.h"
#include "IPOLARISMuxCb.h"

NS_POLARIS_START

// namespace webrtc
// {

// #ifdef WEBRTC_WIN
// #define POLARISMUXER_API __declspec(dllexport)
// #else
// #define POLARISMUXER_API
// #endif //WEBRTC_WIN

struct StreamContext;
struct FilteringContext;

using StreamContextPtr = std::shared_ptr<StreamContext>;
using FilteringContextPtr = std::shared_ptr<FilteringContext>;

static const int POLARIS_SUCCESS = 0;
static const int POLARIS_CODE_BASE = 10000;
static const int POLARIS_EINIT = 10001;
static const int POLARIS_ENOTINIT = 10002;
static const int POLARIS_EPERM = 10003;
static const int POLARIS_EINVAL = 10004;
static const int POLARIS_EUNINIT = 10005;
static const int POLARIS_EFILTER = 10006;
static const int POLARIS_EFONTPATH = 10007;

#define POLARIS_FUNC_TRACE tracer token(MODULE_TAG, __func__)
#define POLARIS_MEM_FUNC_TRACE tracer mem_token(MODULE_TAG, __func__, this)

// struct tracer
// {
// 	std::stringstream ss_;

// 	tracer(const std::string& tag, const std::string& func, const void *ptr = nullptr)
// 	{
// 		if (ptr) {
// 			ss_ << "[" << tag << "(" << ptr << ")" << "]::" << func;
// 		} else {
// 			ss_ << "[" << tag << "]::" << func;
// 		}
// 		//POLARIS_LOGD("%s enter <<<<<<\n", ss_.str().c_str());
// 	}

// 	~tracer()
// 	{
// 		//POLARIS_LOGD("%s leave >>>>>>\n", ss_.str().c_str());
// 	}
// };


class POLARISMuxer
{
public:
	using POLARISPacketPtr = std::shared_ptr<POLARISPacket>;

    POLARISMuxer(const std::string &output_media_path, POLARISCodecID video_type, POLARISCodecID audio_type,
             bool enable_time_watermark = false, int64_t time_watermark_ts = 0, const std::string &font_file = "",
             uint32_t sample_rate = 8000, uint32_t channels = 1, bool has_video = true, bool has_audio = true);

    ~POLARISMuxer();

    int start();

    int stop();

    int send_packet(POLARISPacketPtr pkt);

    int send_packet(POLARISPacketType type, uint64_t timestamp, bool is_sync, const uint8_t *data, size_t data_size);

    void set_callback(IPOLARISMuxCb *cb);

    const char* outfile_name() const;

    static void callback_avlog(void *avcl, int level, const char * fmt, va_list ap);

	void set_osd_pts(int64_t watermark_pts){ time_watermark_ts_ = watermark_pts; };
private:
    int init_output_fmt_ctx();

    int uninit_output_fmt_ctx();

    bool is_media_config_pkt(POLARISPacketType t);

    int parse_media_config(const POLARISPacketPtr &pkt);

    int parse_audio_codecpar(const POLARISPacketPtr &pkt);

    int parse_video_codecpar(const POLARISPacketPtr &pkt);

    int parse_gop_duration(const POLARISPacketPtr &pkt);

    int add_input_stream(AVFormatContext **ifmt_ctx, AVCodecParameters *codecpar);

    void init_packet(AVPacket *packet);

    int init_input_frame(AVFrame **frame);

    int decode_audio_frame(AVFrame *frame, AVPacket *input_packet, AVCodecContext *input_codec_context, int *data_present, int *finished);

    int encode_audio_frame(AVFrame *frame, AVFormatContext *output_format_context, AVCodecContext *output_codec_context, int *data_present);

    int init_output_frame(AVFrame **frame, AVCodecContext *output_codec_context, int frame_size);

    int to_av_pkt(POLARISPacketPtr viv_pkt, AVPacket *av_pkt, int st_idx);

    AVCodecID to_avcodec_id(POLARISCodecID codec_type);

    int process_frame(const POLARISPacketPtr &pkt);

    int write_frame(const POLARISPacketPtr &pkt);

    int write_frame(AVPacket *pkt);

    int flush();

    void loop();

    void onProgressUpdate(int st_idx);

    int onError(int code, const char *msg = nullptr);

    template <typename T>
    std::string to_string(T value);

    static void log(const char *tag, const char *func, const char *fmt, ...);

    int64_t ts_now();

    bool has_suffix(const std::string &path, const std::string &suffix);

    int init_filter(FilteringContextPtr fctx, AVCodecContext *dec_ctx, AVCodecContext *enc_ctx, const char *filter_spec);

    int filter_encode_write_frame(AVFrame *frame, unsigned int stream_index);

    int encode_write_frame(AVFrame *filt_frame, unsigned int stream_index, int *got_frame);

private:
    IPOLARISMuxCb *callback_;
    AVFormatContext *ifmt_ctx_;
    AVFormatContext *ofmt_ctx_;
    AVOption *opt_;
    AVCodecParameters *input_audio_codecpar_;
    AVCodecParameters *input_video_codecpar_;
    //AVCodecContext *audio_decoder_ctx_;
    //AVCodecContext *audio_encoder_ctx_;
    std::vector<StreamContextPtr> stream_ctx_;
    std::vector<FilteringContextPtr> filter_ctx_;
    int video_st_idx_;
    int audio_st_idx_;
    int major_st_idx_;
    std::string outfile_name_;
    std::string output_media_path_;
    POLARISPacketPtr decoded_audio_;
    uint64_t encoded_audio_pts_;
    uint64_t prev_video_pts_;
    uint64_t curr_video_pts_;
    uint64_t prev_keyframe_pts_;
    uint64_t video_pts_offset_;
    uint64_t video_duration_;
    uint64_t gop_duration_;
    int framerate_;
    POLARISCodecID video_type_;
    POLARISCodecID audio_type_;
    bool enable_time_watermark_;
    int64_t time_watermark_ts_;
    std::string font_file_;
    bool cache_buffer_start_;

    std::queue<POLARISPacketPtr> pkts_;
    std::mutex pkts_mutex_;
    std::condition_variable_any pkts_cv_;
    std::unique_ptr<std::thread> muxer_thread_ = nullptr;

    volatile bool running_;
    volatile bool prepared_;
    
    int error_code_;
#ifdef POLARIS_DEBUG
    std::ofstream audio_decoder_outfile_;
#endif // POLARIS_DEBUG

    int transcode(const POLARISPacketPtr &pkt);

    bool is_transcoding(AVCodecParameters *codecpar);

    int init_codec(StreamContextPtr &stream_ctx, AVCodecParameters *codecpar);

    bool is_filtering(AVCodecParameters *codecpar);

    void avfilterFontPathReplace(char* dst, const char* src, int len)
    {
        for (int i = 0, dstOffset = 0; i != len; ++i)
        {
            if (src[i] == ':' || src[i] == '\\')
            {
                dst[dstOffset++] = '\\';
            }
            dst[dstOffset++] = src[i];
        }
    }

    int64_t get_filter_pts(unsigned int stream_index);

    int64_t get_pkt_pts(unsigned int stream_index, bool is_sync);

    uint64_t gop_duration();
};

// }
NS_POLARIS_END

#endif //POLARISMUXER_H
