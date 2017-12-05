# Migration Guide to ProxSee SDK 3.0.0


Please follow this guide to upgrade to 3.0.0

## ProxSeeSDKManager api changes

### Changed
- `launchProxSeeWithApiKey` has changed to `initializeWithApiKey`
- `(BOOL) isMonitoringEnabled` has changed to `(BOOL) isEnabled`
- `(void) isMonitoringEnabled:(BOOL)` has changed to `(void) enable`
- `(void) isMonitoringEnabled:(BOOL)` has changed to `(void) disable`
- `updateMetadata:completionHandler:` has been removed. You can now use  `metadataManager()` instead to update metadata
- `fetchDetectedBeaconsWithCompletionHandler:` has been removed. You can now use `beaconsManager()` to get detected beacons
- `fetchDeviceIdWithCompletionHandler` has been removed. You can now use `dataManager()` to get device identifier
- You can no longer use `[self addProxSeeNotifcationObserver];` and `[self removeProxSeeNotificationObserver];`. You can now use `tagsManager()` for register/unregister.

### Added
- `tagsManager()` is added which returns `LXTagManager` protocol. You query `- (void) registerReceiver:(id<LXTagsReceiver>)handler;`/`- (void) unregisterReceiver:(id<LXTagsReceiver>)handler;` on `LXTagManager` to register/unregister for tags.
- `beaconsManager()` is added which returns `LXBeaconsManager` protocol. You query `getDetectedBeaconsWithCompletionHandler:^(NSSet<LXProxSeeBeacon *> *beacons) {}` on `LXBeaconsManager` to get detected beacons.
- `dataManager()` is added which returns `LXDataManager` protocol. You query `getIdentifierWithCompletionHandler:^(NSUUID *deviceId) {}`  on `LXDataManager` to get data such as Identifier.
- `metadataManager()` is added which returns `LXMetadataManager` protocol. You query  `updateMetadata:@{ @"key" : @"value" } completionHandler:^(BOOL success, NSError *error) {}` on `LXMetadataManager` to update metadata.

## Register for tags changes

In earlier versions we used an NSObject category to register/unregister for tags. An example:

```
#import <LXProxSeeSDK/LXProxSeeSDK.h>

...
[self addProxSeeNotifcationObserver];
...

- (void) didChangeTagsSet:(LXProxSeeNotificationObject *)proximityNotificationObject {
//execute your code
}
...

[self removeProxSeeNotificationObserver];

```

You can no longer use this, but instead, do something similar:

```
#import <LXProxSeeSDK/LXProxSeeSDK.h>
...
@interface YourObject : NSObject<LXTagsReceiver> {
...

[[[LXProxSeeSDKManager sharedInstance] tagsManager] registerReceiver:self];

...

- (void) didChangeTagsSet:(LXTags *)tags {
//execute your code
}

[[[LXProxSeeSDKManager sharedInstance] tagsManager] unregisterReceiver:self];

...
```

Also:
- `LXProxSeeNotificationObject` is removed and we use ``LXTags``


