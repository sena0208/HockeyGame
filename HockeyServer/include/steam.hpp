#ifndef __STEAM_H__
#define __STEAM_H__

#include <iostream>
#include "smallet.hpp"
#include "param.hpp"

class STeam
{
  public:
    SMallet* s_mallet;
    int field;    //どっちの陣地か

  public:
    STeam();
    ~STeam();
    Vector2D & getMalletPos(int id);
    Vector2D & getMalletVel(int id);
};

#endif //__STEAM_H__
