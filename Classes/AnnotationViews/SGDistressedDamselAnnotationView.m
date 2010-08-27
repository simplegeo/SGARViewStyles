//
//  SGDistressedDamselAnnotationView.m
//  SGARViewStyles
//
//  Copyright (c) 2009-2010, SimpleGeo
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions are met:
//
//  Redistributions of source code must retain the above copyright notice, 
//  this list of conditions and the following disclaimer. Redistributions 
//  in binary form must reproduce the above copyright notice, this list of
//  conditions and the following disclaimer in the documentation and/or 
//  other materials provided with the distribution.
//  
//  Neither the name of the SimpleGeo nor the names of its contributors may
//  be used to endorse or promote products derived from this software 
//  without specific prior written permission.
//   
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS 
//  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
//  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
//  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
//  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//  Created by Derek Smith.
//

#import "SGDistressedDamselAnnotationView.h"

@interface SGDistressedDamselAnnotationView (Private)

- (UIImage*) imageForDamsel:(SGDamsel)desiredDamsel;
- (void) assignDamsel;

@end

@implementation SGDistressedDamselAnnotationView

- (id) initWithFrame:(CGRect)frame reuseIdentifier:(NSString *)identifier
{
    if(self = [super initWithFrame:frame reuseIdentifier:identifier]) {             
        [self.radarTargetButton setImage:[UIImage imageNamed:@"YellowExclamationMark.png"] forState:UIControlStateNormal];
        [self.closeButton addTarget:self action:@selector(closeView:) forControlEvents:UIControlEventTouchUpInside];
        
        self.titleLabel.text = @"Help!!!";
        self.titleLabel.textColor = [UIColor redColor];
        
        // Put the view at ~eye-level
        self.altitude = 1.7344;
        
        [self assignDamsel];
    }
    
    return self;
}

- (void) prepareForReuse
{
    [super prepareForReuse];
    [self assignDamsel];
}

- (void) assignDamsel
{
    damsel = rand() % kSGDamsel_Amount;
    self.targetImageView.image = [self imageForDamsel:damsel];    
}

- (UIImage*) imageForDamsel:(SGDamsel)desiredDamsel
{
    NSString* damselImageName = @"";
    switch (desiredDamsel) {            
        case kSGDamsel_Meg:
            damselImageName = @"Meg.png";
            break;
        case kSGDamsel_SnowWhite:
            damselImageName = @"SnowWhite.png";
            break;
        case kSGDamsel_Cinderella:
            damselImageName = @"Cinderella.png";
            break;
        case kSGDamsel_Jasmine:
            damselImageName = @"Jasmine.png";
            break;            
        default:
            break;
    }
    
    return [UIImage imageNamed:damselImageName];
}

- (void) layoutSubviews
{
    [super layoutSubviews];
    self.closeButton.hidden = YES;
}

@end
