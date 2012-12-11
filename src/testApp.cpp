
#include "ofMain.h"
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    camWidth 		= 640;
	camHeight 		= 480;
    
	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(camWidth,camHeight);

	finder.setup("haarcascade_frontalface_default.xml");
	//finder.findHaarObjects(img);
    
    snapCounter = 0;
	bSnapshot = false;
	cooper.loadFont("cooperBlack.ttf", 50);
	phase = 0;
	memset(snapString, 0, 255);		// clear the string by setting all chars to 0
    
    ofSetFrameRate(30);
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i=0; i<finder.blobs.size(); i++) {
        
        balls[i].x = balls[i].x + balls[i].vx;
        balls[i].y = balls[i].y + balls[i].vy;
        
        if (balls[i].x<0 || balls[i].x > ofGetWidth()) {
            balls[i].vx = -balls[i].vx;
        }
        
        if (balls[i].y<0 || balls[i].y > ofGetHeight()) {
            balls[i].vy = -balls[i].vy;
        }
    }
    
    vidGrabber.update();

    
    
}

//--------------------------------------------------------------
void testApp::draw(){
	//img.draw(0, 0);
        vidGrabber.draw(0,0);
    
    //directions
    ofDrawBitmapString("press 'x' twice to draw blobs \n", 200,460);
    
    //blob detection
	for(int i = 0; i < finder.blobs.size(); i++) {
        ofNoFill();
		ofRectangle cur = finder.blobs[i].boundingRect;
		ofRect(cur.x, cur.y, cur.width, cur.height);
	}
    
    //draw balls
    for (int i=0; i<finder.blobs.size(); i++) {
        ofFill();
        ofSetColor(255, 255, 0);
        ofCircle(balls[i].x, balls[i].y, balls[i].radius);
    }
    
    
    //click to freeze
    if (bSnapshot == true){
		img.grabScreen(0,0,640, 480);
		string fileName = "snapshot_"+ofToString(10000+snapCounter)+".png";
		img.saveImage(fileName);
		sprintf(snapString, "saved %s", fileName.c_str());
		snapCounter++;
		bSnapshot = false;
	}
    


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if (key == 'x'){
		bSnapshot = true;
        finder.findHaarObjects(img);
        
    }

    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    //draw balls depending on number of blobs in image
    for (int i=0; i<finder.blobs.size(); i++) {
        balls[i].x = ofRandomWidth();
        balls[i].y = ofRandomHeight();
        balls[i].vx = ofRandom(-10,10);
        balls[i].vy = ofRandom(-10,10);
        balls[i].radius = ofRandom(10,40);
    }
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}


