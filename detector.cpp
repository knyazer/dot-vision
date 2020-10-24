#include "detector.h"

Detector::Detector()
{
}

void Detector::apply(cv::Mat& frame)
{
	for (int i = 0; i < FIELD_OBJECTS_COUNT; i++)
		masks[i] = cv::Mat::zeros(frame.rows, frame.cols, CV_8U);
	
	for (int x = 0; x < frame.rows; x++)
	{
		for (int y = 0; y < frame.cols; y++)
		{
			for (int i = 0; i < FIELD_OBJECTS_COUNT; i++)
			{
				*masks[i].ptr(x, y) = (objColor[i].get(frame.ptr<cv::Vec3b>(x, y)) << 8);
			}
		}
	}	
}
