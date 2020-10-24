#include "camera.h"

Camera::Camera()
{
}

void Camera::open()
{
	cap.open(1, cv::CAP_ANY);
	
	if (!isOpened())
		std::cerr << "Camera cannot be opened" << std::endl;
}

bool Camera::isOpened()
{
	return cap.isOpened();
}

void Camera::read()
{
	cap.read(frame);
}

void Camera::setResolution(int width, int height)
{
	config.setSize(width, height);
	config.apply(cap);
}
