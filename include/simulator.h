#ifndef __SIMULATOR_DOT__
#define __SIMULATOR_DOT__

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "world.h"

using namespace cv;

class Simulator
{
public:
  Simulator(World& field);

  void update(World& world);
  void rescale(World& world);
  void drawShape(Mat& frame, World& world, Shape& v, Scalar color, bool infill=false);

  Mat frame;
  double factor;
};

#endif
