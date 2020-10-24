#ifndef __COLOR_DOT__
#define __COLOR_DOT__

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

const int FIELD_OBJECTS_COUNT = 3;
const int BALL = 0, YELLOW = 1, BLUE = 2;

class Color
{
public:
	Color();
	
	void set(char r, char g, char b, bool val);
	bool get(char r, char g, char b);
	bool get(cv::Vec<unsigned char, 3>* pix);
	void clear(cv::Vec<unsigned char, 3>* pix);
	void add(cv::Vec<unsigned char, 3>* pix);
	void add(std::vector<cv::Vec<unsigned char, 3>*>& vec);

private:
	const int q = 255;
	char*** data;

};

#endif
