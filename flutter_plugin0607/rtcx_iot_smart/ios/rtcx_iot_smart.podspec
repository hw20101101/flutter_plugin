#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint rtcx_iot_smart.podspec` to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'rtcx_iot_smart'
  s.version          = '1.0.0'
  s.summary          = 'Flutter plugin for RTCXIotSmart SDK'
  s.description      = <<-DESC
A Flutter plugin that wraps RTCXIotSmart iOS SDK for IoT device management.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*'
  s.public_header_files = 'Classes/**/*.h'
  s.dependency 'Flutter'
  s.platform = :ios, '12.0'

  # RTCXIotSmart framework dependency
  # 假设 RTCXIotSmart 作为静态库或框架提供，你需要根据实际情况调整
  # 如果是 CocoaPods 管理的库：
  # s.dependency 'RTCXIotSmart'
  
  # 如果是本地框架：
  s.vendored_frameworks = 'SDK/*.framework'
  
  # 需要链接的系统库列表
  # s.libraries = 'libiconv'

  # 需要链接的系统框架列表
  s.frameworks = 'VideoToolbox', 'AudioToolbox', 'AVFoundation', 'CoreMedia', 'SystemConfiguration'

  # 如果是静态库：
  # s.vendored_libraries = 'Libraries/libRTCXIotSmart.a'
  
  # Flutter.framework does not contain a i386 slice.
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386' }
  s.swift_version = '5.0'
end