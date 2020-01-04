#ifndef __SPUCK_H__
#define __SPUCK_H__

#include "include.hpp"

class Vector2D;
class Segment2D;

class SPuck
{
  public:    //publicでもいいかも
    Vector2D m_pos;
    Vector2D m_vel;

    Segment2D   tmp;

  public:
    SPuck();
    ~SPuck();
};

#endif //__SPUCK_H__
