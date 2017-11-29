//
//  MetadataManager.h
//  LXProxSeeSDK
//
//  Created by Elie Melki on 2/11/17.
//  Copyright © 2017 Lixar. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LXMetadataManager <NSObject>

/*
 *  updateMetadata:
 *
 *  Discussion:
 *      Metadata are used to add more descriptive information per device which can be used later for reporting.
 *      Updating metadata with the same data more than once will only make one Api call.
 *      In other terms if you keep executing the above providing the same data it will hit the server once.
 *      Only when you change the date it hit the server.
 *      No Metadata is send if proxsee is turned off.
 *      The completion handler will return on main thread.
 */

- (void) updateMetadata:(NSDictionary *)object completionHandler:(void (^)(BOOL success, NSError *error))completionHandler;

@end
