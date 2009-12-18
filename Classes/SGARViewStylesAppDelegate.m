//
//  SGARViewStylesAppDelegate.m
//  SGiPhoneSDK
//
//  Created by Derek Smith on 10/8/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

#import "SGARViewStylesAppDelegate.h"

#import "SGStylesViewController.h"

@implementation SGARViewStylesAppDelegate

@synthesize window;

////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark UIApplication delegate methods 
//////////////////////////////////////////////////////////////////////////////////////////////// 

- (void) applicationDidFinishLaunching:(UIApplication *)application
{
    SGStylesViewController* viewController = [[SGStylesViewController alloc] init];
    [window addSubview:viewController.view];
    
    [window makeKeyAndVisible];
}

- (void) dealloc
{
    [window release];
    
    [super dealloc];
}

@end
