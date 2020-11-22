#ifndef __WORLD_DOT__
#define __WORLD_DOT__

#include <iostream>
#include <vector>
#include <opencv2/core.hpp>

using namespace std;

struct Vec2
{
  double x, y;

  Vec2(double x, double y)
  {
    this->x = x;
    this->y = y;
  }

  Vec2()
  {
    x = 0;
    y = 0;
  }

  Vec2 operator+(Vec2 other)
  {
    return Vec2(x + other.x, y + other.y);
  }

  Vec2 operator+(double other)
  {
    return Vec2(x + other, y + other);
  }

  Vec2 operator-(double other)
  {
    return Vec2(x - other, y - other);
  }

  Vec2 operator-(Vec2 other)
  {
    return Vec2(x - other.x, y - other.y);
  }

  Vec2 operator*(double factor)
  {
    return Vec2(x * factor, y * factor);
  }

  Vec2 operator/(double factor)
  {
    return Vec2(x / factor, y / factor);
  }



  inline cv::Point cv()
  {
    return cv::Point(x, y);
  }
};

inline int SEGMENT = 1;
inline int CURVE = 2;

struct ShapePart
{
  Vec2 a, b;
  double r, begin, end;

  int type = -1;
};

struct Segment : ShapePart
{
  Segment(Vec2 p1, Vec2 p2)
  {
    a = p1;
    b = p2;

    type = SEGMENT;
  }
};

struct Curve : ShapePart
{
  Curve(Vec2 center, double r, double begin, double end)
  {
    a = center;
    this->begin = begin;
    this->end = end;
    this->r = r;

    type = CURVE;
  }
};

struct Shape
{
  vector<ShapePart> part;
  Vec2 origin;

  void add(auto element)
  {
    part.push_back(element);
  }
};

struct Field
{
  Shape out, border, goal[2];
  double W, H, LW;

  Field()
  {
    /* Constants section */
    W = 243;
    H = 182;
    LW = 1.5;

    /* Out section */
    double w = (183 - LW) / 2.0, h = (122 - LW) / 2.0,
      gh = (70 - LW) / 2.0, gw = 30 - LW;
    out.add(Segment(Vec2(-w, -h), Vec2(w, -h)));
    out.add(Segment(Vec2(w, -h),  Vec2(w, -gh)));

    out.add(Segment(Vec2(w, -gh), Vec2(w - gw / 2, -gh)));
    out.add(Curve(Vec2(w - gw / 2, gh - gw / 2), gw / 2, 90, 180));
    out.add(Segment(Vec2(w - gw, -gh + gw / 2), Vec2(w - gw, gh - gw / 2)));
    out.add(Curve(Vec2(w - gw / 2, -gh + gw / 2), gw / 2, 180, 270));
    out.add(Segment(Vec2(w, gh),  Vec2(w - gw / 2, gh)));

    out.add(Segment(Vec2(w, gh),  Vec2(w, h)));

    out.add(Segment(Vec2(w, h),   Vec2(-w, h)));
    out.add(Segment(Vec2(-w, h),  Vec2(-w, gh)));

    out.add(Segment(Vec2(-w, gh),   Vec2(-w + gw / 2, gh)));
    out.add(Curve(Vec2(-w + gw / 2, gh - gw / 2), gw / 2, 0, 90));
    out.add(Segment(Vec2(-w + gw, gh - gw / 2), Vec2(-w + gw, -gh + gw / 2)));
    out.add(Curve(Vec2(-w + gw / 2, -gh + gw / 2), gw / 2, 270, 360));
    out.add(Segment(Vec2(-w, -gh),  Vec2(-w + gw / 2, -gh)));

    out.add(Segment(Vec2(-w, -gh),  Vec2(-w, -h)));

    /* Border section */
    double hw = (W - LW) / 2, hh = (H - LW) / 2;
    border.add(Segment(Vec2(-hw, -hh), Vec2(hw, -hh)));
    border.add(Segment(Vec2(hw, -hh), Vec2(hw, hh)));
    border.add(Segment(Vec2(hw, hh), Vec2(-hw, hh)));
    border.add(Segment(Vec2(-hw, hh), Vec2(-hw, -hh)));

  }
};

inline double ROBOT_RADIUS = 11;
inline double BALL_RADIUS = 3.3;

struct WorldObject
{
  Vec2 vel;
  Shape shape;
};

struct Robot : WorldObject
{
  Robot()
  {
    shape.add(Curve(Vec2(0, 0), ROBOT_RADIUS, 0, 360));
  }

  bool exist = true;
};

struct SelfRobot : Robot
{
  double rot;
};

struct Ball : WorldObject
{
    Ball()
    {
      shape.add(Curve(Vec2(0, 0), BALL_RADIUS, 0, 360));
    }
};

class World
{
public:
  World();

  Robot robot[3];
  SelfRobot self;
  Field field;
  Ball ball;

};


#endif
