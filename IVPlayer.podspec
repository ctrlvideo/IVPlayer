#
# Be sure to run `pod lib lint IVPlayer.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'IVPlayer'
  s.version          = '1.0.0'
  s.summary          = 'Interactive video playback control terminal'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
  Interactive video player tool
                       DESC

  s.homepage         = 'https://github.com/ctrlvideo/IVPlayer'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'guodi1014' => '913252651@qq.com' }
  s.source           = { :git => 'https://github.com/ctrlvideo/IVPlayer.git', :tag => s.version }

  s.ios.deployment_target = '9.0'
  #s.resources = 'IVPlayer.framework/IVResource.bundle'
  s.vendored_frameworks = 'IVPlayer.framework'
  
  s.frameworks = 'AVFoundation','WebKit','Foundation','CoreGraphics','CoreImage','UIKit'
  s.requires_arc = 'true'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-ObjC'}
  s.dependency 'SVGKit'
  s.dependency 'SSZipArchive'
  
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end
