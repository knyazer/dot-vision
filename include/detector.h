#ifndef __DETECTOR_DOT__
#define __DETECTOR_DOT__

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "color.h"

class Detector
{
public:
	Detector();
	void apply(cv::Mat& frame);
	
	//Vector position[FIELD_OBJECTS_COUNT];
	
	cv::Mat masks[FIELD_OBJECTS_COUNT];
private:
	Color objColor[FIELD_OBJECTS_COUNT];
};

#endif
