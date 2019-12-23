#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "vector_2d.hpp"

class Player
{
  private:
    PTeam* my_team;
    PTeam* oppo_team;

    PPuck* p_puck;

  public:
    Player();
    ~PLayer();
};

#endif //__PLAYER_H__
