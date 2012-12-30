//
//  OpenGLView.h
//  Tutorial11
//
//  Created by kesalin@gmail.com on 12-12-24.
//  Copyright (c) 2012 年 http://blog.csdn.net/kesalin/. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import "GLESMath.h"

//
// OpenGLView interface
//
@interface OpenGLView : UIView 
{
    CAEAGLLayer* _eaglLayer;
    EAGLContext* _context;
    GLuint _colorRenderBuffer;
    GLuint _depthRenderBuffer;
    GLuint _frameBuffer;
    
    GLuint _programHandle;
    GLuint _positionSlot;
    GLuint _modelViewSlot;
    GLuint _projectionSlot;
    
    KSMatrix4 _modelViewMatrix;
    KSMatrix4 _projectionMatrix;
    
    // For light
    //
    GLuint _normalMatrixSlot;
    GLuint _lightPositionSlot;
    GLint _normalSlot;
    GLint _ambientSlot;
    GLint _diffuseSlot;
    GLint _specularSlot;
    GLint _shininessSlot;
    
    KSVec3 _lightPosition;
    KSColor _ambient;
    KSColor _specular;
    KSColor _diffuse;
    GLfloat _shininess;
    
    // For texture
    //
    GLuint _textureForStage0;
    GLuint _textureForStage1[4];
    
    GLint _textureCoordSlot;
    GLint _sampler0Slot;
    GLint _sampler1Slot;
    GLint _blendModeSlot;
    GLint _alphaSlot;
    
    NSUInteger _textureIndex;
    NSUInteger _blendMode;
    GLfloat _alpha;
}

@property (nonatomic, assign) KSVec3 lightPosition;
@property (nonatomic, assign) KSColor ambient;
@property (nonatomic, assign) KSColor specular;
@property (nonatomic, assign) KSColor diffuse;
@property (nonatomic, assign) GLfloat shininess;
@property (nonatomic, assign) NSUInteger blendMode;
@property (nonatomic, assign) NSUInteger textureIndex;
@property (nonatomic, assign) GLfloat alpha;

- (void)render;
- (void)cleanup;
- (void)setCurrentSurface:(int)index;
- (NSString *)currentBlendModeName;

@end
