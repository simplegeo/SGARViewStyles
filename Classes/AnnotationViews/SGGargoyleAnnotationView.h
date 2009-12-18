//
//  SGGargoyleAnnotationView.h
//  SGiPhoneSDK
//
//  Created by Derek Smith on 10/22/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

#import "SGAnnotationView.h"

#import <CoreLocation/CoreLocation.h>


@interface SGGargoyleAnnotationView : SGAnnotationView {

    CLLocationManager* anchorManager;

    @private
    int count;
    
    BOOL up;
    BOOL left;
}

@property (nonatomic, retain) CLLocationManager* anchorManager;

@end
