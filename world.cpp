#include "world.h"

World::World()
{
  self.shape.origin = Vec2(0, 0);

  robot[0].exist = true;
  for (int i = 1; i < 3; i++)
    robot[i].exist = false;

  robot[0].shape.origin = Vec2(60, 10);
  ball.shape.origin = Vec2(30, 30);
}
