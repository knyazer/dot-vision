#include "painter.h"

#include <iostream>
void Painter::show(const char* name, cv::Mat& image)
{
	if (timeFromUpdate.find(name) == timeFromUpdate.end())
		timeFromUpdate[name] = time();
		
	if (time() - timeFromUpdate[name] > itTime)
	{
		timeFromUpdate[name] = time();
		cv::imshow(name, image);
	}
}

void Painter::setFPS(double fps)
{
	if (fps == NO_WINDOW_UPDATES)
		itTime = 1e30;
	itTime = 1.0 / fps;
}
