//
//  SGDistressedDamselAnnotationView.h
//  SGiPhoneSDK
//
//  Created by Derek Smith on 10/13/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
//

#import "SGAnnotationView.h"

@interface SGDistressedDamselAnnotationView : SGAnnotationView {

    NSInteger damsel;
    
    @private
    BOOL showingStats;
}

- (void) showStats;

@end
