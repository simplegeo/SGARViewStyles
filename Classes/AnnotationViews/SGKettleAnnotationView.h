//
//  SGKettleAnnotationView.h
//  ARViewStyles
//
//  Created by Derek Smith on 10/14/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

#import "SGAnnotationView.h"


@interface SGKettleAnnotationView : SGAnnotationView {
    
    /* Axes of rotation */
    float x, y, z;
    
    /* The amount to rotate the tea pot */
    float rotation;
}

@end
