//
//  LXProxSeeTagsChangeSet.h
//  LXProxSeeSDK
//
//  Created by ELie Melki on 4/25/15.
//  Copyright (c) 2015 Lixar. All rights reserved.
//

#import <Foundation/Foundation.h>



/*
 *  LXTagsChangeSet
 *
 *  Discussion:
 *    LXTagsChangeSet object which has a set of tags
 */

@protocol LXTagsChangeSet <NSObject>

/*
 *  tags
 *
 *  Discussion:
 *    a set of tags of NSString type.
 */

@property (nonatomic, strong, readonly) NSSet *tags;


/*
 *  lastSeen
 *
 *  Discussion:
 *    When the tags where captured.
 */
@property (nonatomic, strong, readonly) NSDate *lastSeen;

@end


