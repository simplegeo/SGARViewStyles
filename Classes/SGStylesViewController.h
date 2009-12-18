//
//  SGStylesViewController.h
//  ARViewStyles
//
//  Created by Derek Smith on 10/8/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

#import "SGGargoyleAnnotationView.h"

#import "SimpleGeo.h"

@interface SGStylesViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, SGAnnotationViewDelegate> {

    @private
    UITableView* stylesTableView;
    
    SGARNavigationViewController* arNavController;
    
    CLLocationManager* locationManager;
    
    NSMutableArray* locationPoints;
    NSMutableArray* annotations;
    
    NSInteger currentStyle;
                                                    
    NSInteger numberOfAnnotations;
 
    NSMutableArray* gargoyles;
                                                    
    SGAnnotationViewContainer* safeZone;
}

@end
