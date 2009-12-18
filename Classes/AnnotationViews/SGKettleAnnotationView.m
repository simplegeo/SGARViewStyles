//
//  SGKettleAnnotationView.m
//  SGiPhoneSDK
//
//  Created by Derek Smith on 10/14/09.
//  Copyright 2009 SimpleGeo. All rights reserved.
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

- (id) initAtPoint:(CGPoint)pt reuseIdentifier:(NSString *)identifier
{
    if(self = [super initAtPoint:pt reuseIdentifier:identifier]) {
        
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
    x = rand() % 2;
    y = rand() % 2;
    z = rand() % 2;
    
    rotation = rand() % 360;    
}

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
