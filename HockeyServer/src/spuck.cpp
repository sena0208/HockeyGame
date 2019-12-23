#ifndef __SPUCK__
#define __SPUCK__

#include <iostream>
#include "../include/spuck.hpp"

SPuck::SPuck()
{
  std::cout << "SPuck constructed!" << std::endl;

  m_pos.x =  0.0;
  m_pos.y =  0.0;

  m_vel.x = -1.0;
  m_vel.y =  1.0;
}

SPuck::~SPuck()
{
  std::cout << "SPuck destructed!" << std::endl;
}

#endif //__SPUCK__
