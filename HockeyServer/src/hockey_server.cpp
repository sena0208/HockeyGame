#ifndef __HOCKEYSERVER__
#define __HOCKEYSERVER_

#include <iostream>
#include "../include/hockey_server.hpp"
#include "steam.cpp"
#include "spuck.cpp"


HockeyServer::HockeyServer()
{
  std::cout << "Server constructed!" <<std::endl;
  s_puck = new SPuck();
  s_team_1 = new STeam();
  //s_team_2 = new Team();
  initialMalletSet();
  fp = fopen("result/out.dat", "w");
}

HockeyServer::~HockeyServer()
{
  std::cout << "Server destructed!" <<std::endl;
  delete s_puck;
  delete s_team_1;
  fclose(fp);
  //delete s_team_2;
}

void HockeyServer::initialMalletSet()
{
  //FILE READ
  s_team_1->s_mallet[0].m_pos.x = -1.0;
  s_team_1->s_mallet[0].m_pos.y =  0.0;
  s_team_1->s_mallet[0].m_vel.x =  0.0;
  s_team_1->s_mallet[0].m_vel.y =  1.0;

  s_team_1->s_mallet[1].m_pos.x =  1.0;
  s_team_1->s_mallet[1].m_pos.y =  0.0;
  s_team_1->s_mallet[1].m_vel.x =  0.0;
  s_team_1->s_mallet[1].m_vel.y = -1.0;
}

Vector2D & HockeyServer::getPuckPos() const
{
  return s_puck->m_pos;
}

Vector2D & HockeyServer::getPuckVel() const
{
  return s_puck->m_pos;
}

Vector2D & HockeyServer::getTeamPos(int id) const
{
  return s_team_1->getMalletPos(id);
}

Vector2D & HockeyServer::getTeamVel(int id) const
{
  return s_team_1->getMalletVel(id);
}

void HockeyServer::setMalletVel(int id, Vector2D cm_vel)
{
  s_team_1->s_mallet[id].m_vel.x = cm_vel.x;
  s_team_1->s_mallet[id].m_vel.y = cm_vel.y;
}

void HockeyServer::setMalletVelZero(int id)
{
  s_team_1->s_mallet[id].m_vel.x = 0.0;
  s_team_1->s_mallet[id].m_vel.y = 0.0;
}

bool HockeyServer::isValidVelocity(Vector2D const cm_vel)
{
  if(cm_vel.r() <= MAX_VEL) return true; 
  else                      return false; 
}

bool HockeyServer::isValidPosition(int id, Vector2D const cm_vel)
{
  Vector2D tmp_pos;
  tmp_pos.x = s_team_1->s_mallet[id].m_pos.x + cm_vel.x * DT;
  tmp_pos.y = s_team_1->s_mallet[id].m_pos.y + cm_vel.y * DT;
  if(tmp_pos.abs_x() <= FIELD_WIDTH && tmp_pos.abs_y() <= FIELD_HEIGHT) return true;
  else    return false; 
}

CommandResult HockeyServer::sendMalletVel(int id, Vector2D const cm_vel)
{
  if(isValidVelocity(cm_vel) == true){
    if(isValidPosition(id, cm_vel) == true){
      setMalletVel(id, cm_vel);
      return SUCCESS;
    }else{
      //setMalletVelWall();
      setMalletVelZero(id);
      return LIMITED;
    }
  }else{
    //setMalletVelMax();
    setMalletVelZero(id);
    return FAIL;
  }
}

void HockeyServer::checkPuckVelWall()
{
  Vector2D tmp_pos;
  tmp_pos.x = s_puck->m_pos.x + s_puck->m_vel.x * DT;
  tmp_pos.y = s_puck->m_pos.y + s_puck->m_vel.y * DT;

  if(tmp_pos.abs_x() > FIELD_WIDTH) s_puck->m_vel.x *= (-1.0);
  if(tmp_pos.abs_y() > FIELD_HEIGHT) s_puck->m_vel.y *= (-1.0);
}

void HockeyServer::updateAll()
{
  checkPuckVelWall();
  s_puck->m_pos.x += s_puck->m_vel.x * DT;
  s_puck->m_pos.y += s_puck->m_vel.y * DT;

  for(int id = 0; id < NUM_MALLET; id++){
    s_team_1->s_mallet[id].m_pos.x += s_team_1->s_mallet[id].m_vel.x * DT;
    s_team_1->s_mallet[id].m_pos.y += s_team_1->s_mallet[id].m_vel.y * DT;
  }
}

void HockeyServer::outputTimeLog(int const iter) const
{
  std::cout << "Iter = " << iter << std::endl;
  for(int id = 0; id < NUM_MALLET; id++){
    std::cout << "Mallet[" << id << "] Position = (" << s_team_1->s_mallet[id].m_pos.x << ", " << s_team_1->s_mallet[id].m_pos.y << ")" <<std::endl;
    fprintf(fp, "%f %f\n", s_team_1->s_mallet[id].m_pos.x, s_team_1->s_mallet[id].m_pos.y);
  }
  fprintf(fp, "%f %f\n", s_puck->m_pos.x, s_puck->m_pos.y);
  fprintf(fp, "\n\n");

  std::cout << "Puck Position      = (" << s_puck->m_pos.x << ", " << s_puck->m_pos.y << ")" <<std::endl;
  std::cout << "-------------------------------------" << std::endl;
}

#endif //__HOCKEYSERVER__
