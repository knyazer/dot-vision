#include "camera.h"

Camera::Camera()
{
}

void Camera::open()
{
	cap.open(g_CAMERA_INDEX, cv::CAP_V4L);
	cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));

	if (!isOpened())
	{
		if (!promt(ERROR, "Camera cannot be opened."))
		{
			promt(LOG, "Abort.", 0);
			g_EXIT = true;
		}
		else
		{
			promt(LOG, "Forced fallback into the simulation.", 0);
			g_NO_CAMERA = true;
		}
	}
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
