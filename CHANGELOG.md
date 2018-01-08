# ProxSee SDK for iOS Change Log
All notable changes to this project will be documented in this file.
This project adheres to [Semantic Versioning](http://semver.org/).

## [3.0.1] - 2018-01-08
### Changed
- optimise network calls.
- add bitcode support

## [3.0.0] - 2017-11-29
### Changed
- Change main api interfaces. Please view [3.0.0 Migration Guide](Docs/migration_to_3.0.0.md)  
- Support foreground authorisation 

## [2.5.0] - 2017-08-03
### Changed
- Changes required for ProxSee to work with iOS 10.3.+

## [2.4.3] - 2017-05-16
### Fixed
- Request errors now properly populated

## [2.4.1] - 2017-01-18
### Fixed
- Duplicate metadata requests now fixed

## [2.4.0] - 2017-01-06
### Changed
- Refactored virtual regions detection logic
- Region limitations and implicit checkouts removed
- Intersected regions allowed and reduction in the region minimum limit
- Enhanced beacon detection
- Reduction in false handshakes
- Additional offline support and reduction in the number of requests


## [2.3.2] - 2016-04-02
### Changed
- Bluetooth, location, and SDK-enabled metadata no longer sent

## [2.3.1] - 2016-04-02
### Fixed
- Bluetooth popup alert message removed
- Bluetooth disabled/enabled signals no longer sent to the server on restart

## [2.3.0] - 2016-03-10
### Added
- Offline support for check-ins/check-outs (The SDK will now save any check-in/check-out in offline mode so it can resubmit later when back online)
- Beacon RSSI information now sent with check-in requests

## [2.2.1] - 2016-03-10
### Fixed
- Bluetooth pop-up alert message removed

## [2.2.0] - 2015-11-26
### Added
- Ability to start/stop the SDK
- Capture of device information through metadata such as location, Bluetooth, and starting/stopping of the SDK

### Changed
- Updated documentation 
- Metadata no longer allowed to be sent while the SDK is turned off

### Fixed
- Bug fixes related to stopping/starting monitoring concurently 

## [2.1.0] - 2015-09-16
### Added
- Virtual Beacon Support
    - Virtual beacon entry and exit notifications now use the native geo-fencing capabilities of the iOS. This means that "the user’s location must cross the region boundary, move away from the boundary by a minimum distance, and remain at that minimum distance for at least 20 seconds before the notifications are reported" (in practice, other factors such as the speed of the user may shorten the minimums).
- CocoaPod support [PROXSEE-121]
    - The SDK is now published as a CocoaPod at [https://github.com/proxsee/sdk-ios](#https://github.com/proxsee/sdk-ios) as "ProxSeeSDK" 

### Changed
- Updated documentation [333]
- Various optimizations including:
    - Minimization in the number of threads used
    - Code refactoring

### Fixed
- New URL referenced for querying nearby beacons [167]
