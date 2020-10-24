#include "color.h"

Color::Color()
{	
	data = new char**[q];
	for (int i = 0; i < q; i++)
	{
		data[i] = new char*[q];
		for (int j = 0; j < q; j++)
		{
			data[i][j] = new char[q];
			for (int k = 0; k < q; k++)
				data[i][j][k] = 0;
		}
	}
}

void Color::add(cv::Vec<unsigned char, 3>* pix)
{
	set(pix->operator[](0), pix->operator[](1), pix->operator[](2), 1);
}

void Color::set(char r, char g, char b, bool val)
{
	data[r][g][b] = val;
}

bool Color::get(char r, char g, char b)
{
	return data[r][g][b];
}

bool Color::get(cv::Vec<unsigned char, 3>* pix)
{
	return data[pix->operator[](0)][pix->operator[](1)][pix->operator[](2)];
}

void Color::clear(cv::Vec<unsigned char, 3>* pix)
{
	set(pix->operator[](0), pix->operator[](1), pix->operator[](2), 0);
}

void Color::add(std::vector<cv::Vec<unsigned char, 3>*>& vec)
{
	for (auto pix : vec)
		add(pix);
}
