#ifndef __SPUCK__
#define __SPUCK__

//#include <iostream>
//#include "../include/spuck.hpp"
#include "include.hpp"

SPuck::SPuck()
{
  std::cout << "SPuck constructed!" << std::endl;

  m_pos.x =  0.0;
  m_pos.y =  0.0;

  m_vel.x =  2.0;
  m_vel.y =  2.0;
}

SPuck::~SPuck()
{
  std::cout << "SPuck destructed!" << std::endl;
}

#endif //__SPUCK__
