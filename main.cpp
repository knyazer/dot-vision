#include "gHeader.h"
#include "asker.h"
#include "camera.h"
#include "keyLogger.h"
#include "painter.h"
#include "detector.h"
#include "mainWindow.h"
#include "functionality.h"
#include "world.h"
#include "simulator.h"

#include <iostream>
using namespace std;

World world;

int main(int, char**)
{
  Camera camera;
  KeyLogger keyLogger;
  Painter painter;
  Detector detector;
  MainWindow window("App");
  Simulator sim(world);
  // Exit shortcut
  keyLogger.addShortcut(27/*ESC*/, [](void){g_EXIT = true;});

  keyLogger.addShortcut('w', [](void){world.self.shape.origin = world.self.shape.origin + Vec2(1, 0);});

  // Begin capturing
  // camera.setResolution(640, 480);
  camera.open();

	// Establish window updates per second (if no updates needed use NO_WINDOW_UPDATES)
	painter.setFPS(1000);

  while (!g_EXIT)
  {
    if (!g_NO_CAMERA)
    {
  		// Save readed image from camera to camera.frame cv::Mat
		  camera.read();

		  window.update(&camera.frame);
		  detector.apply(camera.frame);

		  painter.show("Camera", camera.frame);
    }

    sim.update(world);
    painter.show("World", sim.frame);

		//painter.show("Masks", detector.masks[0]);
		keyLogger.update();
	}

  return 0;
}
