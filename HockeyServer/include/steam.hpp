#ifndef __STEAM_H__
#define __STEAM_H__

#include "include.hpp"

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

    void reflectTmpPos();
};

#endif //__STEAM_H__
