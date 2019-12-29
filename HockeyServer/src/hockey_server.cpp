#ifndef __HOCKEYSERVER__
#define __HOCKEYSERVER__

//#include <iostream>
//#include "../include/hockey_server.hpp"
//#include "steam.cpp"
//#include "spuck.cpp"
#include "include.hpp"


HockeyServer::HockeyServer()
{
  std::cout << "Server constructed!" <<std::endl;
  TcpSocketSetting();
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
  close(client_sockfd);
  close(server_sockfd);
  fclose(fp);
  //delete s_team_2;
}

void HockeyServer::TcpSocketSetting(){
  server_len = sizeof(server_address);
  client_len = sizeof(client_address);

  if( (server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ){
    perror("socket");
  }

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(1234);
  server_address.sin_addr.s_addr = INADDR_ANY;

  if( (bind(server_sockfd, (struct sockaddr* )&server_address, server_len)) < 0 ){
    perror("bind");
  }

  if( (listen(server_sockfd, 5)) < 0 ){
    perror("listen");
  }

  printf("server waiting player...");

  if( (client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len)) < 0 ){
    perror("accept");
  }
}


void HockeyServer::initialMalletSet()
{
  //FILE READ
  s_team_1->s_mallet[0].m_pos.x =  0.0;
  s_team_1->s_mallet[0].m_pos.y = -4.0;
  s_team_1->s_mallet[0].m_vel.x =  0.0;
  s_team_1->s_mallet[0].m_vel.y =  0.0;

  s_team_1->s_mallet[1].m_pos.x =  0.0;
  s_team_1->s_mallet[1].m_pos.y =  4.0;
  s_team_1->s_mallet[1].m_vel.x =  0.0;
  s_team_1->s_mallet[1].m_vel.y =  0.0;
}

//getter
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

//setter
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

//check mallet velocity
bool HockeyServer::isValidVelocity(Vector2D const cm_vel)
{
  if(cm_vel.r() <= MAX_VEL) return true; 
  else                      return false; 
}

//check mallet position
bool HockeyServer::isValidPosition(int id, Vector2D const cm_vel)
{
  Vector2D tmp_pos;
  tmp_pos.x = s_team_1->s_mallet[id].m_pos.x + cm_vel.x * DT;
  tmp_pos.y = s_team_1->s_mallet[id].m_pos.y + cm_vel.y * DT;
  if(tmp_pos.abs_x() <= FIELD_WIDTH && tmp_pos.abs_y() <= FIELD_HEIGHT) return true;
  else    return false; 
}

//update mallet velocity
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

void HockeyServer::checkPuckVel()
{
  Vector2D tmp_pos;
  tmp_pos.x = s_puck->m_pos.x + s_puck->m_vel.x * DT;
  tmp_pos.y = s_puck->m_pos.y + s_puck->m_vel.y * DT;

  //CHECK WALL
  if(tmp_pos.abs_x() > FIELD_WIDTH) s_puck->m_vel.x *= (-1.0);
  if(tmp_pos.abs_y() > FIELD_HEIGHT) s_puck->m_vel.y *= (-1.0);

  //CHECK MALLET
 

}

void HockeyServer::updateAll()
{
  checkPuckVel();
  s_puck->m_pos.x += s_puck->m_vel.x * DT;
  s_puck->m_pos.y += s_puck->m_vel.y * DT;

  for(int id = 0; id < NUM_MALLET; id++){
    s_team_1->s_mallet[id].m_pos.x += s_team_1->s_mallet[id].m_vel.x * DT;
    s_team_1->s_mallet[id].m_pos.y += s_team_1->s_mallet[id].m_vel.y * DT;
  }
}

void HockeyServer::zipData()
{
  send[0]  = s_puck->m_pos.x;
  send[1]  = s_puck->m_pos.y;
  send[2]  = s_puck->m_vel.x;
  send[3]  = s_puck->m_vel.y;
  
  //send[4]  = s_team_1->s_mallet[0].m_pos.x;
  //send[5]  = s_team_1->s_mallet[0].m_pos.y;
  //send[6]  = s_team_1->s_mallet[0].m_vel.x;
  //send[7]  = s_team_1->s_mallet[0].m_vel.y;

  //send[8]  = s_team_1->s_mallet[1].m_pos.x;
  //send[9]  = s_team_1->s_mallet[1].m_pos.y;
  //send[10] = s_team_1->s_mallet[1].m_vel.x;
  //send[11] = s_team_1->s_mallet[1].m_vel.y;

  for(int i = 0; i < NUM_MALLET; i++){
    send[4 + (i * 4)]     = s_team_1->s_mallet[i].m_pos.x;
    send[4 + (i * 4) + 1] = s_team_1->s_mallet[i].m_pos.y;
    send[4 + (i * 4) + 2] = s_team_1->s_mallet[i].m_vel.x;
    send[4 + (i * 4) + 3] = s_team_1->s_mallet[i].m_vel.y;
  }
}

void HockeyServer::unzipData()
{
  //s_team_1->s_mallet[0].m_pos.x = recv[0];
  //s_team_1->s_mallet[0].m_pos.y = recv[1];
  //s_team_1->s_mallet[0].m_vel.x = recv[2];
  //s_team_1->s_mallet[0].m_vel.y = recv[3];

  //s_team_1->s_mallet[1].m_pos.x = recv[4];
  //s_team_1->s_mallet[1].m_pos.y = recv[5];
  //s_team_1->s_mallet[1].m_vel.x = recv[6];
  //s_team_1->s_mallet[1].m_vel.y = recv[7];

  for(int i = 0; i < NUM_MALLET; i++){
    s_team_1->s_mallet[i].m_pos.x = recv[(i * 4)];
    s_team_1->s_mallet[i].m_pos.y = recv[(i * 4) + 1];
    s_team_1->s_mallet[i].m_vel.x = recv[(i * 4) + 2];
    s_team_1->s_mallet[i].m_vel.y = recv[(i * 4) + 3];
  }

}

void HockeyServer::SendToPlayer(int iter)
{
  zipData();
  write(client_sockfd, send, sizeof(send));
  read(client_sockfd, recv, sizeof(recv));
  unzipData();

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
