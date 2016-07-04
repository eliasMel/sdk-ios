# iOS SDK Change Log
All notable changes to this project will be documented in this file.
This project adheres to [Semantic Versioning](http://semver.org/).


## [2.4.0] - NOT YET RELEASED

## [2.3.2] - 2016-04-02
### Changed
- Stop sending bluetooth, location and sdk enabled metadata.

## [2.3.1] - 2016-04-02
### Fixed
- Remove bluetooth popup alert message.
- Make sure we dont send bluetooth disabled/enabled signals to the server on restart.

## [2.3.0] - 2016-03-10
### Added
- Offline support for checkin/out. The SDK will now save any checkin/out in offline mode, so it can resubmit later when its back online.
- Sending beacon rssi information with checkin requests.

## [2.2.1] - 2016-03-10
### Fixed
- Remove bluetooth popup alert message

## [2.2.0] - 2015-11-26
### Added
- Ability to start / stop the SDK
- Capturing device information through metadata such as location, bluetooth and starting/stopping of the sdk

### Changed
- Updated documentation 
- You are no longer allowed to send metadata while the sdk is turned off.

### Fixed
- Fixing bugs related when stop/start monitoring concurently. 

## [2.1.0] - 2015-09-16
### Added
- Virtual Beacon support
    - Read more about virtual beacons [here](../features/virtualbeacons.md) - iOS-specific features follow.
    - Virtual beacon entry and exit notifications will use native geo-fencing capabilities of the iOS - this means that "the user’s location must cross the region boundary, move away from the boundary by a minimum distance, and remain at that minimum distance for at least 20 seconds before the notifications are reported" (in practice, other factors such as the speed of the user may shorten the minimums)
- CocoaPod support [PROXSEE-121]
    - SDK is now published as a CocoaPod at https://github.com/proxsee/sdk-ios as "ProxSeeSDK" 

### Changed
- Updated documentation [333]
- Various optimizations including:
    - Minimizing number of threads used
    - Code refactoring

### Fixed
- Reference new URL for querying nearby beacons [167]