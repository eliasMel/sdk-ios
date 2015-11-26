# ProxSee SDK

The ProxSee SDK provides you with a simplified interface to quickly integrate iBeacon™ and geo-fence (virtual beacon) monitoring to your mobile application.

By managing and associating meaningful tags via a central platform, you can reduce the complexities of beacon interaction to simply responding to notifications of tag changes as an end user approaches and departs from beacon/geo-fence regions.

Furthermore, the ProxSee SDK will automatically communicate a check-in/check-out to a central platform to record a user's activities. In addition, you can send additional data about the user that will be associated with their check-ins. All of the resultant data could then be mined according to your needs - e.g. to determine wait times, travel patterns, etc.


## Table of Contents

* [How Does the ProxSee SDK Work?](#how-does-proxsee-sdk-works)
* [Key Concepts](#key-concepts)
    * [Beacon Device](#beacon-device)
    * [Virtual Beacon](#virtual-beacon)
        * [Recommendations](#recommendations)
        * [Limits](#limits)
    * [Mobile API Key](#mobile-api-key)
    * [Locations](#locations) 	
    * [Tags](#tags) 	
    * [Metadata](#metadata)
    * [Check-in/Check-out](#check-in-check-out)
* [Installation](#installation)
* [Usage](#usage)
    * [Launching the SDK](#launching-the-sdk)
    * [Receiving Tag Changeset Notifications](#receive-tags-changeset-notifications)
    * [Turning On/Off Monitoring](#turning-on-off-monitoring)
    * [Updating Metadata](#updating-metadata)


## <a name="how-does-proxsee-sdk-works"></a>How Does the ProxSee SDK Work?

The ProxSee SDK wraps iBeacon™ and geo-fence APIs for easy use and integration. The SDK requires an active Bluetooth service in order to function with iBeacons™ and active Location services in order to function with virtual beacons (geo-fences). It also requires Internet connectivity.

On launching your mobile application, you will need to initialize the ProxSee SDK - for this, you will need a valid Mobile API key (see [Mobile API Key](#mobile-api-key)). Once initialized, the SDK will associate a unique identifier with the end user's device - used in all communications to the central platform. The SDK will start monitoring beacons and will send check-in/check-out information to the central platform whenever a beacon enter or exit event is received. The SDK will also query the main platform for tag information associated with a beacon and will automatically load and cache information about nearby beacons (and geo-fences).

During the course of operation of your application, you can send additional data (see "Updating Metadata" under [Usage](#usage)), the latest version of which will be associated in turn with a user's check-ins. This metadata could include user account information, ids, etc. that you could later use to identify a particular user and his/her device among all of the data collected or data you could otherwise report on.

One of the primary purposes of the SDK, however, is to allow a mobile application to listen for tag changes. As each beacon can have one or more tags associated with it, by acting upon the appearance or disappearance of a tag, you can easily handle approaching and leaving a beacon's region. In this respect, real beacons and virtual beacons (geo-fences) operate nearly identically (more on the differences in Key Concepts). The beacons' associated tags and positional information can be updated on the central platform without a need to update the SDK version nor the physical beacons that have been deployed.

(On the iOS SDK) At any stage of the application lifecycle you can turn on and off the SDK. Turning off the SDK will stop monitoring beacons, broadcasting check-ins/check-outs, notifying of tag changes. updating metadata.

## <a name="key-concepts"></a>Key Concepts

### <a name="beacon-device"></a>Beacon Device

Also referred to as a "real beacon", a "beacon" or an "iBeacon™", this is the physical beacon device that you will have deployed, that the user's device will detect. Unlike location-based services on a mobile device, beacon ranging is fairly precise (essentially serving as "indoor GPS") and low-power, leading to its use indoors and where fine-tuned location context is desired.

### <a name="virtual-beacon"></a>Virtual Beacon

A virtual beacon is a geo-fence - it acts like a broad-ranging real beacon but is based on the user crossing a circular boundary on a map as opposed to nearing a real beacon - as such, it can serve as a less accurate beacon in locations the customer may not have access/permission to add a real beacon device. You are limited to 5 virtual beacons being defined per general Location.

Virtual beacons work in concert with Beacon Devices - In order to work properly, the virtual beacons should be placed on the map in such a way as the user would hit a real beacon before hitting the virtual one. Example:

* Bad: Putting a virtual beacon in the parking lot of a mall and a beacon device inside the mall - would not be able to detect people approaching from the parking lot (the SDK would first begin to notify upon hitting the beacon device in the mall, not in the parking lot)
* Good: Putting a virtual beacon on Rent A Car Rd in Las Vegas and a beacon device inside the arrival area would be able to detect people coming off of the plane and then detect those that went off to the rental area

##### <a name="recommendations"></a>Recommendations
* Select a medium or greater range for your virtual beacon for best results
* Place the virtual beacon in an area a user is likely to remain or traverse for several seconds/minutes
* Do not depend on the triggering of virtual beacons - any number of factors including obstructions in the area, the user's phone capabilities, etc. can interfere with its operation
* Note that check-ins in a virtual beacon are far more likely to occur than check-outs

##### <a name="limits"></a>Limits
* The outer radius of a virtual beacon must be more than 200m in distance from the outer radius of any other beacon (real or virtual) - this is enforced by the main platform
* The accuracy of the virtual beacon may drop significantly in an indoor region
* The virtual beacon sensitivity is limited to the given device's geo-location abilities and the surrounding environment - results may vary. If greater accuracy is required, real beacon devices are recommended
* Virtual beacons will stay resident in a user's device until arriving at a new Location (or a reboot)

### <a name="mobile-api-key"></a>Mobile API Key
  
In order to use the SDK, you will need to generate a Mobile API key.

To generate one, simply:

1. Log in to the central platform
2. Select the "Applications" section
3. Choose "Create Application" and choose "Mobile" as the API Type.
4. Then you can copy the GUID generated.

Normally you will only generate one Mobile API key, but if you had multiple applications, you may wish to generate a unique one for each.

### <a name="locations"></a>Locations

A Location within the ProxSee system establishes a region that groups beacons (real and virtual). It also plays a part in the caching of beacon data and establishes a default tag for all the beacons within.

### <a name="tags"></a>Tags

Tags can be associated with beacons and are in the form of hashtags. By default, each beacon has a tag of "#" + its Location name. You can associate the same tag with multiple beacons (for instance, you may place beacons at all of your exits and tag them "#Exit") or not specify any tags at all.

Whereas, whenever a beacon is seen (or last seen) a check-in/check-out will occur, if a user moves between two beacons with the same tags, it will not result in a new notification in the SDK. Your listening application will only be notified when the tags change (either tags were removed or they were added).

### <a name="metadata"></a>Metadata
Metadata can be used to provide additional information about a user or their device, an example would be their user id within your system, their preferences, etc. The metadata sent will be associated to the unique id given to that user's specific device. When the SDK performs a check-in on seeing a new beacon, the last sent metadata will be associated with that check-in.

While the function used is named "updateMetadata", be aware that this metadata is essentially fully versioned - each update sent will be stored as its own record. As such, it is recommended that you only send metadata when it has changed. If the SDK detects that the metadata has not changed from the previous request, it will not send the metadata again (it will, however, return a successful result to its CompletionHandler).

Note that the key-value pairs will be stored as a JSON object in the central platform and you may wish to design your representation so that it is easily query-able later when you do reporting on it.

### <a name="check-in-check-out"></a>Check-in/Check-out

A checkin-in/check-out forms a tuple for a device event and track beacon region enter and exit events. The majority of information is stored during a check-in including the time, the device's unique id (UUID) and additional system information like the version of the SDK used. The check-out merely updates the check-out time.

Note that it is possible to have a check-in without a check-out time - network interruptions, etc. could cause a missed check-out.

(On the Android SDK) One special type of check-out is the implied check-out for a virtual beacon. This happens when the user's device does not properly detect that it has left a region but has detected a new beacon. Since virtual beacons may not be placed in close proximity with any other beacon, this results in an implied check-out with an additional flag "context.impliedCheckout=true" appearing in its deviceevent record.

## <a name="installation"></a>Installation


1. Add LXProxSeeSDK.framework into your project. 

2. Open your project settings and go to the "Build Phases" tab. In the "Link library with binaries" section click the "+" button and add the following frameworks that are required by ProxSee SDK:
    * CoreLocation.framework
3. Go to "Build Settings", find "Other Linker Flags" and add `-ObjC`.

4. Since iOS 8 and above, ProxSee SDK require NSLocationAlwaysUsageDescription to be enabled for it to work.  You are required to enable location prompt message through your project Info.plist.

   Make sure you add the following key-value to your plist

   ```
   <key>NSLocationAlwaysUsageDescription</key>
   <string>Your location prompt message</string>
   ```

5. At this point, the SDK is ready to use and your project can compile successfully. You will still need to obtain an API key to use the SDK.



## <a name="usage"></a>Usage

### <a name="launching-the-sdk"></a>Launching the SDK


Obtain a Mobile API key (see [Mobile API Key](#mobile-api-key)). Then, on the application didFinishLaunchingWithOptions, initialize the ProxSee SDK with the Mobile API key (replace "YourApiKey" with your Mobile API GUID)

```
#import <LXProxSeeSDK/LXProxSeeSDK.h>

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [LXProxSeeSDKManager launchProxSeeWithApiKey:@"YourApiKey"];
    return YES;
}
```

### <a name="receive-tags-changeset-notifications"></a>Receiving Tag Changeset Notifications

Any object can receive tag changeset notification. Notifications are only sent when tags are changed. The SDK will send you an LXProxSeeNotificationObject which includes the new and previous tags' changeset along with the date captured for each changeset.

To start listening for tag changes, execute the following:

```
#import <LXProxSeeSDK/LXProxSeeSDK.h>

[self addProxSeeNotifcationObserver];  
```

and implement the following method to receive notifications:

```
- (void) didChangeTagsSet:(LXProxSeeNotificationObject *)proximityNotificationObject {
	//execute your code
}
  
```


You also need to make sure to remove the observer before your object is deallocated or your app will crash: 

```
[self removeProxSeeNotificationObserver];
  
```

### <a name="turning-on-off-monitoring"></a>Turning On/Off Monitoring

At any point of the application lifecycle you can turn on or off the sdk which will stop monitoring beacons, stop broadcasting check-ins/check-outs, notifying of tag changes and updating metadata. 

To turn off monitoring:

```
[LXProxSeeSDKManager sharedInstance].isMonitoringEnabled = NO;   
```

To turn on monitoring:
  
```
[LXProxSeeSDKManager sharedInstance].isMonitoringEnabled = YES;   
```

### <a name="updating-metadata"></a>Updating Metadata

Example:

```
[[LXProxSeeSDKManager sharedInstance] updateMetadata:@{ @"key" : @"value" } completionHandler:^(BOOL success, NSError *error) {
        if (!success)
        {
            NSLog(@"Failed to update metadata %@",error);
        }
        else
        {
            NSLog(@"Successfully updated metadata");
        }
    }];
  
```

