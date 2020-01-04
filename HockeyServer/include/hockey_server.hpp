#ifndef __HOCKEYSERVER_H__
#define __HOCKEYSERVER_H__

#include "include.hpp"

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
    double recv[NUM_MALLET * 2];

  public:
    HockeyServer();
    ~HockeyServer();

  public:
    void connectPlayer(int iter);
    void updateAll();
    void outputTimeLog(int const iter) const;

    void tmpMalletPos();

    //puck getter
    Vector2D & getPuckPos() const;
    Vector2D & getPuckVel() const;

    //mallet getter
    Vector2D & getTeamPos(int id) const;
    Vector2D & getTeamVel(int id) const;

  private:
    void TcpSocketSetting();
    void initialMalletSet();
    void zipData();
    void checkPuckPos();
    void updateMallet();
    void updatePuck();
    void reflectMalletTmp();
    bool checkSegmentCross(Segment2D puck, Segment2D mallet);
    void changePuckVelocity(Segment2D puck, Segment2D mallet);
};

#endif //__HOCKEYSERVER_H__
