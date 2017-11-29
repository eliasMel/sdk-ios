//
//  TagsManager.h
//  LXProxSeeSDK
//
//  Created by Elie Melki on 2/11/17.
//  Copyright © 2017 Lixar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LXTags.h"
/*
 *  LXTagsReceiver
 *
 *  Discussion:
 *      Notification handler protocol
 */

@protocol LXTagsReceiver <NSObject>

@optional

/*
 *  didChangeTagsSet:
 *
 *  Discussion:
 *      Fire when tags changes.
 */
- (void) didChangeTagsSet:(LXTags *)tags;





@end


@protocol LXTagsManager <NSObject>

/*
 *  registerReceiver:;
 *
 *  Discussion:
 *      Register a tags reciever, you need to make sure you unregister. Each register needs to have a metaching unregister,
 *
 */

- (void) registerReceiver:(id<LXTagsReceiver>)handler;

/*
 *  unregisterReceiver:;
 *
 *  Discussion:
 *      unregister a tags reciever. You need to be registered in order to unregister.
 *
 */
- (void) unregisterReceiver:(id<LXTagsReceiver>)handler;

/*
 *  getDetectedTagsWithCompletionHandler:;
 *
 *  Discussion:
 *      get the detected tags and pass a id<LXTagsChangeSet> in completionHandler.
 *      The completion handler will return on main thread.
 */

- (void) getDetectedTagsWithCompletionHandler:(void (^)(id<LXTagsChangeSet> tagsChangeSet))completionHandler;
@end
