//
//  SGKettleAnnotationView.m
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

#import "SGKettleAnnotationView.h"

#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

#import "teapot.h"

#define kTeapotScale        100.0f

@interface SGKettleAnnotationView (Private)

- (void) resetGround;

@end

@implementation SGKettleAnnotationView

- (id) initWithFrame:(CGRect)frame reuseIdentifier:(NSString *)identifier
{
    if(self = [super initWithFrame:frame reuseIdentifier:identifier]) {
        self.enableOpenGL = YES;
        self.isCapturable = NO;
        glEnable(GL_NORMALIZE);
        
        [self resetGround];
    }
    
    return self;
}

- (void) prepareForReuse
{
    [super prepareForReuse];
    [self resetGround];
}

- (void) resetGround
{
    // This will judge which axises
    // to rotate about.
    x = rand() % 2;
    y = rand() % 2;
    z = rand() % 2;
    
    // The initial amount of rotation
    // of the teapot.
    rotation = rand() % 360;    
}

/*
 * There are probably more effecient ways of going about this.
 */
- (void) drawAnnotationView
{
    glPushMatrix();
    glEnable(GL_DEPTH_TEST);
    
    glVertexPointer(3 ,GL_FLOAT, 0, teapot_vertices);
    glNormalPointer(GL_FLOAT, 0, teapot_normals);    
	glScalef(kTeapotScale, kTeapotScale, kTeapotScale);
    
    rotation++;
    glRotatef(rotation, x, y, z);
	for(int i = 0; i < num_teapot_indices; i += new_teapot_indicies[i] + 1)
		glDrawElements(GL_TRIANGLE_STRIP, new_teapot_indicies[i], GL_UNSIGNED_SHORT, &new_teapot_indicies[i+1]);
        
    glDisable(GL_DEPTH_TEST);
    glPopMatrix();
}

@end
