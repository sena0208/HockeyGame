#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
  int sockfd;
  socklen_t len;
  struct sockaddr_in address;
  int result;
  int ch[2];
  int ans[3];
  int num[2];

  double data[4];

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

  for(int i = 0; i < 5; i++){
    read(sockfd, data, sizeof(data));   //GETTER

    /* procedure */
    printf("receive:\n");
    printf("(%d)  %f\n", i, data[0]);
    sleep(1);


    printf("send:\n");
    printf("(%d)  %f\n", i, data[0]);
    write(sockfd, data, sizeof(data));  //SETTER

  }
  close(sockfd);;
  return 0;
}
