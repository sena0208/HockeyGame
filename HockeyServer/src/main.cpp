//#include <iostream>
//#include <stdio.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>

#include "include.hpp"

int main(void){

  HockeyServer server;
  //Player player1;

  std::cout << "*** Game Start! ***" << std::endl;

  for(int iter = 0; iter < 1000; iter++){

    //プレイヤーに情報を送信し、自チームのマレットの速度を受信する
    server.connectPlayer(iter);
    //マレットの速度を検査し、マレットとパックの位置を更新する
    server.updateAll();
    
    //位置をアウトプットする
    server.outputTimeLog(iter);

  }
  std::cout << "*** Game Finish! ***" << std::endl;

  return 0;
}
