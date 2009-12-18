//
//  SGForestAnnotationView.h
//  SGiPhoneSDK
//
//  Created by Derek Smith on 10/13/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

#import "SGAnnotationView.h"

@interface SGForestAnnotationView : SGAnnotationView {

    BOOL big;
    
    @private
    NSInteger forestCreature;
    
    UIImage* creatureImage;
}

@property (nonatomic, assign) BOOL big;

@end
