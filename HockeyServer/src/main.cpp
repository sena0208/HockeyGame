#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "include.hpp"

int main(void){

  HockeyServer server;
  //Player player1;

  Vector2D puck_pos;
  Vector2D puck_vel;
  Vector2D mallet_pos[NUM_MALLET];
  Vector2D mallet_vel[NUM_MALLET];

  std::cout << "*** Game Start! ***" << std::endl;

  for(int iter = 0; iter < 5; iter++){
    //1. get all information
    //値を取り出す作業はまとめて一つの関数にしたい
    puck_pos = server.getPuckPos();
    puck_vel = server.getPuckVel();

    for(int id = 0; id < NUM_MALLET; id++){
      mallet_pos[id] = server.getTeamPos(id);   //Vector2D
      mallet_vel[id] = server.getTeamVel(id);   //Vector2D
    }

    //ここでサーバーから取り出したデータはすべて外部ファイルに保存していき、それを後々参照してもいいかもしれない

    //2. calculate velocity
    //mallet_vel.x = 0.5;
    //mallet_vel.y = 0.5;

    //3. send velocity
    CommandResult result[NUM_MALLET];
    for(int id = 0; id < NUM_MALLET; id++) result[id] = server.sendMalletVel(id, mallet_vel[id]);

    server.SendToPlayer(iter);
    //4. update server
    server.updateAll();
    
    //5. output date
    server.outputTimeLog(iter);

  }
  std::cout << "*** Game Finish! ***" << std::endl;

  return 0;
}
