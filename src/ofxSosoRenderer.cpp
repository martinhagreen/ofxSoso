#include <iostream>
#include "ofxSosoRenderer.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

ofxSosoRenderer::ofxSosoRenderer(bool useShapeColor, bool useOrthographic):ofGLRenderer(useShapeColor)
{
  orthographic = useOrthographic;
}

ofxSosoRenderer::~ofxSosoRenderer(){}

void ofxSosoRenderer::setupScreen()
{
  setupScreenPerspective();
}

void ofxSosoRenderer::setupScreenPerspective(float width, float height, ofOrientation orientation, bool vFlip, float fov, float nearDist, float farDist) {
  
  /*
  ofRectangle currentViewport = getCurrentViewport();
  
	float viewW = currentViewport.width;
	float viewH = currentViewport.height;
  
	float eyeX = viewW / 2;
	float eyeY = viewH / 2;
	float halfFov = PI * fov / 360;
	float theTan = tanf(halfFov);
	float dist = eyeY / theTan;
	float aspect = (float) viewW / viewH;
  
	if(nearDist == 0) nearDist = dist / 10.0f;
	if(farDist == 0) farDist = dist * 10.0f;
  
  
	matrixMode(OF_MATRIX_PROJECTION);
	ofMatrix4x4 persp;
	persp.makePerspectiveMatrix(fov, aspect, nearDist, farDist);
	loadMatrix( persp );
  
	matrixMode(OF_MATRIX_MODELVIEW);
	ofMatrix4x4 lookAt;
	lookAt.makeLookAtViewMatrix( ofVec3f(eyeX, eyeY, dist),  ofVec3f(eyeX, eyeY, 0),  ofVec3f(0, 1, 0) );
	loadMatrix(lookAt);
  */
  
  
	if(width == 0) width = ofGetWidth();
	if(height == 0) height = ofGetHeight();
  
	float viewW = ofGetViewportWidth();
	float viewH = ofGetViewportHeight();
  
	float eyeX = viewW / 2;
	float eyeY = viewH / 2;
	float halfFov = PI * fov / 360;
	float theTan = tanf(halfFov);
	float dist = eyeY / theTan;
	float aspect = (float) viewW / viewH;
  
	if(nearDist == 0) nearDist = dist / 10.0f;
	if(farDist == 0) farDist = dist * 10.0f;
  
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
  if(orthographic) glOrtho(-width/2, width/2, -height/2, height/2, nearDist, farDist);
  else gluPerspective(fov, aspect, nearDist, farDist);
  
  
	//glMatrixMode(GL_MODELVIEW);       //from ofGLRenderer
	//glLoadIdentity();                 //from ofGLRenderer
	//gluLookAt(eyeX, eyeY, dist, eyeX, eyeY, 0, 0, 1, 0);  //from ofGLRenderer
  
  gluLookAt(0, 0, dist, 0, 0, 0, 0, 1, 0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  
  
}
