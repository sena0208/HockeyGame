#ifndef __PPUCK_H__
#define __PPUCK_H__

#include <iostream>
#include "vector_2d.hpp"

class PPuck
{
  public:
    Vector2D m_pos;
    Vector2D m_vel;

  public:
    PPuck();
    ~PPuck();
};

#endif //__PPUCK_H__
