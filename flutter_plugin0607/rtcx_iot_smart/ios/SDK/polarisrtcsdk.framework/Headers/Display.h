#ifndef __DISPLAY_ADATPTER_H__
#define __DISPLAY_ADATPTER_H__

#include "DisplayCommon.h"

#ifdef WEBRTC_ANDROID

#define WEBRTC_USE_H264
#include "modules/video_coding/codecs/h264h265/h264h265_android_decoder_impl.h"

#endif

#ifdef __APPLE__

@interface ViewSizeObserver: NSObject

@end

#endif

NS_POLARIS_START

namespace POLARISShow
{

class Display: public DisplayConfigureTool
{
public:
  Display(DisplayConfigure* config, CPolarisAllRegionConfMgr* global_config, void* parent_obj);

    int doEventSyncronize(const std::function<int()>& callback);
    
    CPolarisAllRegionConfMgr* getGlobalConfigure() { return global_config_; }

    ~Display();

private:    
    std::thread _renderThread;
    std::recursive_mutex _mutex;
    std::thread::id _threadId;
    std::condition_variable_any _condition;
    std::condition_variable_any _versyncCondition;
    int _isExit = 0;
    int _isUpdata = 0;
    std::atomic_int _isFlush = ATOMIC_VAR_INIT(0);

    int _isWait = 0;
    std::vector<std::function<int()>> _eventArray;
    std::condition_variable_any _waitCondition;

    float _contentsScale = 1.0f;

    GLint _width = 0;
    GLint _height = 0;
    
    int _displayWidth = 0;
    int _displayHeight = 0;
    int _frameWidth = 0;
    int _frameStride = 0;
    int _frameHeight = 0;

    int _renderMode = 0;
    
    std::unique_ptr<uint8_t[]> _convertBuffer;
    size_t _convertBufferSize = 0;
    
    Texture _texture;

    std::shared_ptr<Render> _render = nullptr;

    CPolarisAllRegionConfMgr* global_config_ = nullptr;

    bool _first_video = true;

    void* parent_object_;

    int run();
    int init();

#ifndef __APPLE__

    int unInit(int isRelease);

#else

    int unInit();

#endif

    int makeCurrent();
    int flipBuffer();
    int updata();
    int render();
    int onWindowInstance(DisplayConfigure& config, DisplayConfigureUserData& userData);
    int onRenderYUV420PData(DisplayConfigure& config, DisplayConfigureUserData& userData);
    int onFlush(DisplayConfigure& config, DisplayConfigureUserData& userData);
    int onGetSnap(DisplayConfigure& config, DisplayConfigureUserData& userData);
    int onRenderModeChange(DisplayConfigure& config, DisplayConfigureUserData& userData);
    
    void firstVideoCallback( );

#ifdef __APPLE__

    GLuint _frameBuffer = 0;
    GLuint _renderBuffer = 0;
    GLuint _depthRender = 0;

    GLKView* _view = nil;
    EAGLContext* _glContext = nil;
    CAEAGLLayer* _glEAGLLayer = nil;
    CVOpenGLESTextureRef _textureRef[2] = {0};
    CVOpenGLESTextureCacheRef _textureCache = nullptr;
    
    ViewSizeObserver* _viewSizeObserver = nil;
    
    CVImageBufferRef _iosHardImage = nullptr;

    int cleanLastIOSTexture();
    int setEAGLayerParam();
    int bindFrameBuffer();
    int onRenderIOSData(DisplayConfigure& config, DisplayConfigureUserData& userData);
    int onWindowSizeChange(DisplayConfigure& config, DisplayConfigureUserData& userData);
    GLuint imageBufferToTexure(CVImageBufferRef image, int index, GLint format, size_t width, size_t height);

#else

    EGLDisplay _eglDisplay = 0;
	EGLSurface _eglSurface = 0;
	EGLConfig _eglConfig = 0;
	EGLContext _eglContext = 0;
    EGLContext _eglSharedContext = 0;
    GLuint _hardTexture = 0;
    void initRender();

#ifdef WEBRTC_ANDROID

    ANativeWindow* _view = nullptr;
    jobject _surface = nullptr;

    int onRenderAndroidData(DisplayConfigure& config, DisplayConfigureUserData& userData);

    int _currentTextureSize = 0;
    int _currentReadeTextureSize = 0;

    std::shared_ptr<webrtc::H264H265AndroidDecoderImpl> _surfaceHold = nullptr;
#else

    void* _view = nullptr;

#endif

#endif
};

}

NS_POLARIS_END

#endif
