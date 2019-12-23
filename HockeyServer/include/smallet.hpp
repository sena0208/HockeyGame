#ifndef __SMALLET_H__
#define __SMALLET_H__
#include <iostream>
#include "../../common_include/vector_2d.hpp"
#include "../../common_include/param.hpp"

class SMallet
{
  public:    //publicでもいいかも
    Vector2D m_pos;
    Vector2D m_vel;
    
    int idNumber;

  public:
    SMallet();
    ~SMallet();
};
#endif //__SMALLET_H__
