//
//  LXTags.h
//  LXProxSeeSDK
//
//  Created by ELie Melki on 4/23/15.
//  Copyright (c) 2015 Lixar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LXTagsChangeSet.h"

/*
 *  LXTags
 *
 *  Discussion:
 *    LXTags object passed when a tags change is detected.
 *    It contains the previous and current changeset
 */

@interface LXTags : NSObject

- (id) initWithPreviousTagsChangeSet:(id<LXTagsChangeSet>)previousTagsChangeSet currentTagsChangeSet:(id<LXTagsChangeSet>)currentTagsChangeSet;

@property (nonatomic, strong, readonly) id<LXTagsChangeSet> previousTagsChangeSet;
@property (nonatomic, strong, readonly) id<LXTagsChangeSet> currentTagsChangeSet;

@end
