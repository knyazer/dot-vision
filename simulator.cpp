#include "simulator.h"

Simulator::Simulator(World& world)
{
  factor = 2;
  rescale(world);
}

void Simulator::rescale(World& world)
{
  frame = Mat::zeros(Size(world.field.W * factor, world.field.H * factor), CV_8UC3);
}

void Simulator::drawShape(Mat& frame, World& world, Shape& v, Scalar color, bool infill)
{
  Vec2 c = Vec2(world.field.W, world.field.H) * factor / 2.0 + v.origin;
  double lw = infill ? -1 : world.field.LW * factor;

  for (auto u : v.part)
  {
      if (u.type == SEGMENT)
        line(frame, (u.a * factor + c).cv(), (u.b * factor + c).cv(), color, lw, 0);
      else if (u.type == CURVE)
        ellipse(frame, (u.a * factor + c).cv(), Size(u.r * factor, u.r * factor), 0, u.begin, u.end, color, lw, 0);
  }
}

void Simulator::update(World& world)
{
  frame = Scalar(70, 200, 90);

  drawShape(frame, world, world.field.out, Scalar(240, 240, 240));
  drawShape(frame, world, world.field.border, Scalar(20, 20, 20));

  for (auto robot : world.robot)
    if (robot.exist)
      drawShape(frame, world, robot.shape, Scalar(120, 120, 120, 30), 1);

  drawShape(frame, world, world.self.shape, Scalar(120, 120, 120), 1);
  drawShape(frame, world, world.ball.shape, Scalar(20, 20, 220), 1);
}
