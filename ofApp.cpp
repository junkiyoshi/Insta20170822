#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	this->cap.open(1);

	this->frame_img.allocate(this->cap.get(CV_CAP_PROP_FRAME_WIDTH), this->cap.get(CV_CAP_PROP_FRAME_HEIGHT), OF_IMAGE_COLOR);
	this->frame = cv::Mat(this->frame_img.getHeight(), this->frame_img.getWidth(), CV_MAKETYPE(CV_8UC3, this->frame_img.getPixels().getNumChannels()), this->frame_img.getPixels().getData(), 0);

	this->edge_img.allocate(this->cap.get(CV_CAP_PROP_FRAME_WIDTH), this->cap.get(CV_CAP_PROP_FRAME_HEIGHT), OF_IMAGE_GRAYSCALE);
	this->edge = cv::Mat(this->edge_img.getHeight(), this->edge_img.getWidth(), CV_MAKETYPE(CV_8U, this->edge_img.getPixels().getNumChannels()), this->edge_img.getPixels().getData(), 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (!this->cap.isOpened()) { return; }

	this->cap >> this->frame;

	if (this->frame.empty()) { return; }

	cv::cvtColor(this->frame, this->frame, CV_RGB2BGR);
	cv::flip(this->frame, this->frame, 1);

	cv::Canny(this->frame, this->edge, 50, 200);
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();

	if (ofGetKeyPressed()){
		this->frame_img.update();
		this->frame_img.draw(-this->frame_img.getWidth() / 2, -this->frame_img.getHeight() / 2);
	} else {
		this->edge_img.update();
		this->edge_img.draw(-this->edge_img.getWidth() / 2, -this->edge_img.getHeight() / 2);
	}

	this->cam.end();

	// cv::waitKey(1);
	// cv::imshow("view", this->frame);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
