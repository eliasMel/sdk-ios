//
//  DataManager.h
//  LXProxSeeSDK
//
//  Created by Elie Melki on 2/11/17.
//  Copyright © 2017 Lixar. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LXDataManager <NSObject>

/*
 *  getIdentifierWithCompletionHandler:;
 *
 *  Discussion:
 *      get proxsee device id
 *      The completion handler will return on main thread.
 */

- (void) getIdentifierWithCompletionHandler:(void (^)(NSUUID *identifier))completionHandler;
@end
