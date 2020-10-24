#ifndef __PAINTER_DOT__
#define __PAINTER_DOT__

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <map>
#include "functionality.h"

const double NO_WINDOW_UPDATES = 0;

class Painter
{
public:
	void show(const char* name, cv::Mat& image);
	void setFPS(double fps);

private:
	std::map<const char*, double> timeFromUpdate;
	double itTime = 0.05;
};

#endif
