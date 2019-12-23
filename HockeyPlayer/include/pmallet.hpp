#ifndef __PMALLET_H__
#define __PMALLET_H__

#include <iostream>
#include "vector_2d.hpp"

class PMallet
{
  public:
    Vector2D m_pos;
    Vector2D m_vel;

  public:
    PMallet();
    ~PMallet();
};

#define //__PMALLET_H_
