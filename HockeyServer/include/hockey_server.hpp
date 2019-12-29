#ifndef __HOCKEYSERVER_H__
#define __HOCKEYSERVER_H__

#include <iostream>
#include "vector_2d.hpp"
#include "param.hpp"
#include "steam.hpp"
#include "spuck.hpp"

class HockeyServer
{
  private:
    SPuck* s_puck;
    STeam*  s_team_1;
    //Team*  s_team_2;
    FILE* fp;

    //TCP SOCKET
  private:
    int server_sockfd;
    int client_sockfd;

    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    socklen_t server_len;
    socklen_t client_len;

    double send[4 + (NUM_TEAM * NUM_MALLET * 4)];
    double recv[NUM_MALLET * 4];

  public:
    HockeyServer();
    ~HockeyServer();

  public:
    void SendToPlayer(int iter);
    //puck getter
    Vector2D & getPuckPos() const;
    Vector2D & getPuckVel() const;

    //mallet getter
    Vector2D & getTeamPos(int id) const;
    Vector2D & getTeamVel(int id) const;

  private:
    void TcpSocketSetting();
    void zipData();
    void unzipData();
    void initialMalletSet();
    //assign command velocity
    void setMalletVel(int id, Vector2D const cm_vel);
    void setMalletVelZero(int id);
    //void setMalletVelWall(Vector2D const cm_vel);
    bool isValidVelocity(Vector2D const m_vel);
    bool isValidPosition(int id, Vector2D const cm_vel);
    void checkPuckVel();

  public:
    CommandResult sendMalletVel(int id, Vector2D const cm_vel);
    void updateAll();
    void outputTimeLog(int const iter) const;

};

#endif //__HOCKEYSERVER_H__
