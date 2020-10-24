#include "camera.h"
#include "keyLogger.h"
#include "painter.h"
#include "detector.h"
#include "mainWindow.h"

#include <iostream>
using namespace std;

bool g_EXIT = false;

int main(int, char**)
{
    Camera camera;
	KeyLogger keyLogger;
	Painter painter;
	Detector detector;
	MainWindow window("App");
	cout << "Hello" << endl;
	// Exit shortcut
	keyLogger.addShortcut(27/*ESC*/, [](void){g_EXIT = true;});
	
	// Begin capturing
    camera.open();
	
	// Establish window updates per second (if no updates needed use NO_WINDOW_UPDATES)
	painter.setFPS(15);
	
	
    while (!g_EXIT)
    {
		// Save readed image from camera to camera.frame cv::Mat
		camera.read();
		
		window.update(&camera.frame);
		detector.apply(camera.frame);
		
		painter.show("App", camera.frame);
		//painter.show("Masks", detector.masks[0]);
		keyLogger.update();
	}
    return 0;
}
