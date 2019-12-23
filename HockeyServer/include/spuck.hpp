#ifndef __SPUCK_H__
#define __SPUCK_H__

#include <iostream>
#include "../../common_include/vector_2d.hpp"
#include "../../common_include/param.hpp"

class SPuck
{
  public:    //publicでもいいかも
    Vector2D m_pos;
    Vector2D m_vel;

  public:
    SPuck();
    ~SPuck();
};

#endif //__SPUCK_H__
