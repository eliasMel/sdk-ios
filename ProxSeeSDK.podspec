Pod::Spec.new do |s|
  s.name         = "ProxSeeSDK"
  s.version      = "3.0.1"
  s.summary      = "iOS library"
  s.homepage     = "http://www.proxsee.io"
  s.author       = { "Lixar, Inc" => "contact@lixar.com" }
  s.platform     = :ios
  s.source       = { :git => "https://github.com/proxsee/sdk-ios.git" , :tag => "3.0.1" }
  s.vendored_frameworks = 'ProxSeeSDK/LXProxSeeSDK.framework'
  s.ios.deployment_target = '7.0'
  s.frameworks = 'UIKit', 'Foundation',  'CoreLocation'
  s.requires_arc = true
  s.xcconfig  =  { 'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/ProxSeeSDK"',
                   'OTHER_LDFLAGS' => '-ObjC'
                 }
  s.license      = 'MIT'
end
