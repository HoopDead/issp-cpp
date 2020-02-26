#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	struct planets {
		float x;
		float y;
		float radius;
		float r, g, b, vRotation;
	};
	struct stars {
		float x, y, radius;
	};
	typedef struct comet {
		float x, y, endx, endy, vx, vy;
	} Comet;
	vector<planets> planetsVector;
	vector<stars> starsVector;
	ofPolyline cometLine;
	void drawPlanets();
	float rotation;
};