//
//  LXProximitySDKManager.h
//  LXProximitySDK
//
//  Created by ELie Melki on 1/24/15.
//  Copyright (c) 2015 Lixar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LXProxSeeBeacon.h"
#import "LXMetadataManager.h"
#import "LXBeaconManager.h"
#import "LXTagsManager.h"
#import "LXDataManager.h"

/*
 *  LXProxSeeSDKManager
 *
 *  Discussion:
 *    LXProxSeeSDKManager object is a singleton object which manage the SDK.
 */

@interface LXProxSeeSDKManager : NSObject

/*
 *  sharedInstance:
 *
 *  Discussion:
 *      returns SDK Manager shared instance.
 */

+ (LXProxSeeSDKManager *) sharedInstance;


/*
 *  initializeWithApiKey:
 *
 *  Discussion:
 *      This MUST be called on application: didFinishLaunchingWithOptions:.
 *      In order for SDK to work your need pass an API key which you obtain from the server.
 */

+ (void) initializeWithApiKey:(NSString *)apiKey;



- (id<LXTagsManager>) tagsManager;

- (id<LXBeaconManager>) beaconManager;

- (id<LXDataManager>) dataManager;

- (id<LXMetadataManager>) metadataManager;

/*
 *  enable
 *
 *  Discussion:
 *      enable ProxSee sdk
 */

- (void) enable;

/*
 *  disable
 *
 *  Discussion:
 *      disable ProxSee sdk.
 */

- (void) disable;

/*
 *  isEnabled
 *
 *  Discussion:
 *      Determines whether Proxsee is enabled  or disabled.
 */

@property (nonatomic, readonly) BOOL isEnabled;




@end



