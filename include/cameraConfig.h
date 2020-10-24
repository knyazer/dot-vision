#ifndef __CAMERA_CONFIG_DOT__
#define __CAMERA_CONFIG_DOT__

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

class CameraConfig
{
public:
	CameraConfig();
	
	void setSize(int width, int height);
	void apply(cv::VideoCapture& cap);

private:
	static const uint8_t SIZE = 20;
	int params[SIZE];
	const uint8_t WIDTH = cv::CAP_PROP_FRAME_WIDTH, HEIGHT = cv::CAP_PROP_FRAME_HEIGHT;
};


#endif
