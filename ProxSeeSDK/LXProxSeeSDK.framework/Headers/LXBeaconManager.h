//
//  BeaconManager.h
//  LXProxSeeSDK
//
//  Created by Elie Melki on 2/11/17.
//  Copyright © 2017 Lixar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LXProxSeeBeacon.h"

@protocol LXBeaconManager <NSObject>
/*
 *  getDetectedBeaconsWithCompletionHandler:;
 *
 *  Discussion:
 *      get the detected Beacons and pass a set of LXProxSeeBeacon in completionHandler
 *      The completion handler will return on main thread.
 */

- (void) getDetectedBeaconsWithCompletionHandler:(void (^)(NSSet<LXProxSeeBeacon *> *beacons))completionHandler;

@end
