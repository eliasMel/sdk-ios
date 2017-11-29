//
//  AppDelegate.m
//  LXProxSeeSDKSample
//
//  Created by ELie Melki on 3/28/15.
//  Copyright (c) 2015 Lixar. All rights reserved.
//

#import "AppDelegate.h"
#import  <LXProxSeeSDK/LXProxSeeSDK.h>

@interface AppDelegate () <LXTagsReceiver>

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  
    if ([application respondsToSelector:@selector(registerUserNotificationSettings:)])
    {
        UIUserNotificationSettings* notificationSettings = [UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert | UIUserNotificationTypeBadge | UIUserNotificationTypeSound categories:nil];
        [[UIApplication sharedApplication] registerUserNotificationSettings:notificationSettings];
    }
    
#warning You need to provide ProxSee Api Key.
    [LXProxSeeSDKManager initializeWithApiKey:@""];
    [[[LXProxSeeSDKManager sharedInstance] tagsManager] registerReceiver:self];
    
   
    [[[LXProxSeeSDKManager sharedInstance] metadataManager] updateMetadata:@{ @"key" : @"value" } completionHandler:^(BOOL success, NSError *error) {
        if (!success)
        {
            NSLog(@"Failed to update metadata %@",error);
        }
        else
        {
            NSLog(@"Successfully updated metadata");
        }
    }];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

- (void) didChangeTagsSet:(LXTags *)nObject
{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    formatter.dateFormat = @"HH:mm:ss";
    NSString *tags = [NSString stringWithFormat:@"Last Seen:%@",[formatter stringFromDate:nObject.previousTagsChangeSet.lastSeen]];
    
    for (NSString *tag in nObject.currentTagsChangeSet.tags)
    {
        tags = [tags stringByAppendingFormat:@" %@",tag];
    }
    
    NSString *message =  [NSString stringWithFormat:@"Tags Around Me: (%@)", tags];

    [self fireLocalNotificationWithStateWithMessage:message];
}

- (void) fireLocalNotificationWithStateWithMessage:(NSString *)message
{
    if ([[UIApplication sharedApplication] applicationState] == UIApplicationStateBackground)
    {
        UILocalNotification *notification = [[UILocalNotification alloc] init];
        notification.soundName = UILocalNotificationDefaultSoundName;
        notification.alertBody = message;
        [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
    }
    else
    {
        //DO nothing
    }
}

@end
