//
//  SGForestAnnotationView.m
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

#import "SGForestAnnotationView.h"

@interface SGForestAnnotationView (Private)

- (void) makeCreature;
- (NSString*) makeCreatureChoice;

@end


@implementation SGForestAnnotationView

@dynamic big;

- (id) initAtPoint:(CGPoint)pt reuseIdentifier:(NSString *)identifier
{
    if(self = [super initAtPoint:pt reuseIdentifier:identifier]) {
        
        self.inspectorType = kSGAnnotationViewInspectorType_Photo;
        
        [self prepareForReuse];
        
        [self setBig:NO];
    }
    
    return self;
}

////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Accessor methods 
//////////////////////////////////////////////////////////////////////////////////////////////// 

/*
 * We want to be able to update the detailedLabel with the correct
 * distance of the device's location to the annotation.
 *
 * Since we know that this method is called everytime in order to properly
 * display the view in the AR environment, we can update the label here.
 */
- (id<MKAnnotation>) annotation
{
    self.detailedLabel.text = [NSString stringWithFormat:@"%.1fm", self.distance / 10.0];
    
    // Calling this method will assure the label is reload
    // with the proper text in the AR environment.
    [self setNeedsLayout];
    
    // Make sure to return the annotation associated with this view.
    return [super annotation];
}

- (void) setBig:(BOOL)newBig
{
    big = newBig;
    
    self.closeButton.hidden = !big;
    
    if(big) {
     
        self.photoImageView.image = creatureImage;
        self.targetImageView.image = nil;
        self.inspectorType = kSGAnnotationViewInspectorType_Photo;
        
    } else {
        
        self.photoImageView.image = nil;
        self.targetImageView.image = creatureImage;
        self.inspectorType = kSGAnnotationViewInspectorType_Message;
    }
    
    [self setNeedsLayout];
}

- (BOOL) big
{
    return big;
}

- (void) prepareForReuse
{
    [super prepareForReuse];
        
    [self makeCreature];
    [self inspectView:YES];        
}

- (void) makeCreature
{
    NSString* creatureName = [self makeCreatureChoice];
    
    if(creatureImage)
        [creatureImage release];
    
    creatureImage = [[UIImage imageNamed:[creatureName stringByAppendingString:@".png"]] retain];
    
    self.photoImageView.image = creatureImage;
    [self.radarTargetButton setImage:[UIImage imageNamed:[creatureName stringByAppendingString:@"Mini.png"]]
                            forState:UIControlStateNormal];
    
    
    // Layout the title label differently becuase the default implementation
    // will indent it based on the size of the targetImageView.
    self.titleLabel.text = [@"The " stringByAppendingString:creatureName];
    
    self.messageLabel.text = [NSString stringWithFormat:@"This is a %@. A what? A %@. A what? A %@. Oh a %@!",
                              creatureName, creatureName, creatureName, creatureName];
}

- (NSString*) makeCreatureChoice
{
    forestCreature = rand() % kSGForestCreature_Amount;
    
    NSString* imageFile = nil;
    switch (forestCreature) {
        case kSGForestCreature_Bat:
            imageFile = @"Bat";
            break;
        case kSGForestCreature_Dog:
            imageFile = @"Dog";            
            break;
        case kSGForestCreature_Duck:
            imageFile = @"Duck";            
            break;
        case kSGForestCreature_Elephant:
            imageFile = @"Elephant";            
            break;
        case kSGForestCreature_Fox:
            imageFile = @"Fox";            
            break;
        case kSGForestCreature_Frog:
            imageFile = @"Frog";            
            break;
        case kSGForestCreature_Kitty:
            imageFile = @"Kitty";            
            break;
        case kSGForestCreature_Lion:
            imageFile = @"Lion";            
            break;
        case kSGForestCreature_Panda:
            imageFile = @"Panda";            
            break;
        case kSGForestCreature_Penguin:
            imageFile = @"Penguin";            
            break;
        case kSGForestCreature_Rat:
            imageFile = @"Rat";            
            break;
        case kSGForestCreature_Tuqui: 
            imageFile = @"Tuqui";            
            break;
        default:
            break;
    }

    return imageFile;
}

@end
