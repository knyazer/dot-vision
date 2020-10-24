#include "cameraConfig.h"

CameraConfig::CameraConfig()
{
	for (int i = 0; i < SIZE; i++)
		params[i] = -1;
}

void CameraConfig::setSize(int width, int height)
{
	params[WIDTH]  = width;
	params[HEIGHT] = height;
}

void CameraConfig::apply(cv::VideoCapture& cap)
{
	for (int i = 0; i < SIZE; i++)
		if (params[i] != -1)
			cap.set(i, params[i]);
}
