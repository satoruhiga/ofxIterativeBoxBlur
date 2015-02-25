#include "ofMain.h"

#include "ofxIterativeBoxBlur.h"

class ofApp : public ofBaseApp
{
public:
	
	ofxIterativeBoxBlur blur;
	ofImage in_image;
	ofFbo out_fbo;
	
	void setup()
	{
		ofSetFrameRate(0);
		ofSetVerticalSync(false);
		ofBackground(127);
		
		in_image.loadImage("lonerider2.jpg");
		
		out_fbo.allocate(in_image.getWidth(), in_image.getHeight());
	}
	
	void update()
	{
		float s = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 200, true);
		blur.setRadius(s);
		
		blur.process(in_image.getTextureReference(), out_fbo);
	}
	
	void draw()
	{
		out_fbo.draw(0, 0);
		
		stringstream ss;
		ss << "fps: " << ofToString(ofGetFrameRate(), 2) << endl;
		ss << "radius: " << blur.getRadius() << endl;
		ofDrawBitmapString(ss.str(), 10, 20);
	}

	void keyPressed(int key)
	{
		if (key == '1')
			blur.setDownsampleScale(1);
		if (key == '2')
			blur.setDownsampleScale(0.5);
		if (key == '3')
			blur.setDownsampleScale(0.25);
	}

	void keyReleased(int key)
	{
	}
	
	void mouseMoved(int x, int y)
	{
	}

	void mouseDragged(int x, int y, int button)
	{
	}

	void mousePressed(int x, int y, int button)
	{
	}

	void mouseReleased(int x, int y, int button)
	{
	}
	
	void windowResized(int w, int h)
	{
	}
};


int main(int argc, const char** argv)
{
	ofSetupOpenGL(500, 375, OF_WINDOW);
	ofRunApp(new ofApp);
	return 0;
}
