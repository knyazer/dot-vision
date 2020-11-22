#ifndef __CAMERA_DOT__
#define __CAMERA_DOT__

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "cameraConfig.h"
#include "asker.h"
#include "gHeader.h"

class Camera
{
public:
	Camera();

	void open();
	bool isOpened();
	void read();
	void setResolution(int width, int height);

	cv::Mat frame;
	CameraConfig config;
private:
	cv::VideoCapture cap;
};

#endif
