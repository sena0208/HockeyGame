#ifndef __SMALLET__
#define __SMALLET__

#include <iostream>
#include "../include/smallet.hpp"

SMallet::SMallet()
{
  std::cout << "SMallet constructed!" << std::endl;
}

SMallet::~SMallet()
{
  std::cout << "SMallet destructed!" << std::endl;
}

#endif //__SMALLET__
