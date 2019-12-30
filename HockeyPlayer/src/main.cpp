#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "include.hpp"

int main(){
  int sockfd;
  socklen_t len;
  struct sockaddr_in address;
  int result;

  double data[4 + (NUM_TEAM * NUM_MALLET * 4)];
  
  //data[0] puck pos x
  //data[1] puck pos y
  //data[2] puck vel x
  //data[3] puck vel y

  //data[4] mallet 1 pos x
  //data[5] mallet 1 pos y
  //data[6] mallet 1 vel x
  //data[7] mallet 1 vel y

  //data[8] mallet 2 pos x
  //data[9] mallet 2 pos y
  //data[10] mallet 2 vel x
  //data[11] mallet 2 vel y

  double new_data[NUM_MALLET * 2];

  if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ){
    perror("socket");
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  address.sin_port = htons(1234);

  len = sizeof(address);

  result = connect(sockfd, (struct sockaddr *)&address, len);

  if(result == -1){
    perror("oops:client3");
    return -1;
  }

  for(int i = 0; i < 1000; i++){
    read(sockfd, data, sizeof(data));   //GETTER


    //mallet 1
    new_data[0] = data[6];   //vel x
    new_data[1] = data[7];   //vel y
    //mallet 2
    new_data[2] = data[10];
    new_data[3] = data[11];

    //sleep(1);
    write(sockfd, new_data, sizeof(new_data));  //SETTER

  }
  close(sockfd);;
  return 0;
}
