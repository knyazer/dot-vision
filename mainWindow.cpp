#include "mainWindow.h"

MainWindow::MainWindow(const char* name)
{
	this->name = name;
	//cv::imshow("App", cv::Mat::zeros(1, 1, CV_8U));
	//cv::setMouseCallback(name, eventReceiver, NULL);
	
	calibration = BALL; // Default calibration state
	iter = 0; // Set iterations counter to zero
}

void MainWindow::update(cv::Mat* frame)
{	
	iter++;
	this->frame = frame;
}
