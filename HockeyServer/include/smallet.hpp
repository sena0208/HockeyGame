#ifndef __SMALLET_H__
#define __SMALLET_H__

#include "include.hpp"

class SMallet
{
  public:    //publicでもいいかも
    Vector2D m_pos;
    Vector2D m_vel;

    Vector2D tmp_pos;

    Segment2D tmp;
    
    int idNumber;

  public:
    SMallet();
    ~SMallet();
    void reflectTmp();
    void setSegment();
};
#endif //__SMALLET_H__
