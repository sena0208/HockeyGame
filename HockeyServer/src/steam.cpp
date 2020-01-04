#ifndef __STEAM__
#define __STEAM__

//#include <iostream>
//#include "../include/steam.hpp"
//#include "smallet.cpp"
#include "include.hpp"

STeam::STeam()
{
  std::cout << "STeam constructed!" << std::endl;
  s_mallet = new SMallet[NUM_MALLET];

  for(int id = 0; id < NUM_MALLET; id++){
    s_mallet[id].m_pos.x = 0.0;
    s_mallet[id].m_pos.y = 0.0;

    s_mallet[id].m_vel.x = 0.0;
    s_mallet[id].m_vel.y = 0.0;
  }
}

STeam::~STeam()
{
  std::cout << "STeam destructed!" << std::endl;
  delete[] s_mallet;
}

Vector2D & STeam::getMalletPos(int id)
{
  return s_mallet[id].m_pos;
}

Vector2D & STeam::getMalletVel(int id)
{
  return s_mallet[id].m_vel;
}

void STeam::reflectTmpPos()
{
  for(int j = 0; j < NUM_MALLET; j++){
    s_mallet[j].m_pos = s_mallet[j].tmp_pos;
  }
}

#endif //__STEAM__
