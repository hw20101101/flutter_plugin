#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint flutter_plugin0607.podspec` to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'flutter_plugin0607'
  s.version          = '0.0.1'
  s.summary          = 'A new Flutter plugin project.'
  s.description      = <<-DESC
A new Flutter plugin project.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }
  s.source           = { :path => '.' }
  s.static_framework = true 
  s.source_files = 'Classes/**/*'
  s.public_header_files = 'Classes/**/*.h'
  s.dependency 'Flutter'
  s.platform = :ios, '12.0'

  # 需要链接的系统库列表
  # s.libraries = ‘xml2’, ‘z’, ‘sqlite3’, ‘c++’

  # 需要链接的系统框架列表
  # s.frameworks = ‘QuartzCore’, ‘CoreData’, ‘MobileCoreServices’, ‘CFNetwork’, ‘CoreGraphics’

  # vendored_frameworks, 随Pod一起提供的框架捆绑包的路径
  # s.vendored_frameworks = 'SDK/*.framework'

  s.dependency 'WechatOpenSDK' 

  # Flutter.framework does not contain a i386 slice.
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386' }
end
