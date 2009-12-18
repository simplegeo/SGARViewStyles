//
//  SGGargoyleAnnotationView.h
//  ARViewStyles
//
//  Created by Derek Smith on 10/22/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

#import "SGAnnotationView.h"

#import <CoreLocation/CoreLocation.h>


@interface SGGargoyleAnnotationView : SGAnnotationView {

    // We want reference to the location manager so
    // we can get an accurate reading of the device's
    // current location.
    CLLocationManager* anchorManager;

    @private
    
    // The current direction of the moving view.
    BOOL up;
    BOOL left;
}

@property (nonatomic, retain) CLLocationManager* anchorManager;

@end
