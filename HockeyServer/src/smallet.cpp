#ifndef __SMALLET__
#define __SMALLET__

#include <iostream>
#include "include.hpp"

SMallet::SMallet()
{
  std::cout << "SMallet constructed!" << std::endl;
}

SMallet::~SMallet()
{
  std::cout << "SMallet destructed!" << std::endl;
}

void SMallet::reflectTmp()
{
  m_pos = tmp_pos;
}

void SMallet::setSegment()
{
  tmp.assign(m_pos, tmp_pos);
}

#endif //__SMALLET__
