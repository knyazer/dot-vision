#ifndef __MAIN_WINDOW_DOT__
#define __MAIN_WINDOW_DOT__

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "color.h"

struct MouseArea
{
public:
	cv::Point begin;
	cv::Point end;
		
	bool inProgress;
	bool completed;
};

class MainWindow
{
public:
	MainWindow(const char* name);
	
	void update(cv::Mat* frame);
	
	int calibration; // Calibration state
	unsigned long long iter; // Iteration counter
	const char* name; // Name of main window
	cv::Mat* frame; // Saved ptr of image
	
	static void eventReceiver(int event, int x, int y, int flags, void* userdata)
	{
		static MouseArea leftMouseArea, rightMouseArea;
		if (event == cv::EVENT_LBUTTONDOWN && !leftMouseArea.inProgress)
		{
			leftMouseArea.begin.x = x;
			leftMouseArea.begin.y = y;
			
			leftMouseArea.inProgress = true;
		}
		
		if (event == cv::EVENT_LBUTTONUP && leftMouseArea.inProgress)
		{
			leftMouseArea.end.x = x;
			leftMouseArea.end.y = y;
			
			leftMouseArea.inProgress = false;
			leftMouseArea.completed  = true;
			
			applyCalibration(leftMouseArea);
		}
	}
	
	static void applyCalibration(MouseArea area)
	{
		std::cout << area.begin.x << " " << area.begin.y << " " << area.end.x << " " << area.end.y << '\n';
	}
};

#endif
