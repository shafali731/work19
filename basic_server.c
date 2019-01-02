#include "pipe_networking.h"
#include <signal.h>


static void sighandler(int signo){
  if (signo == SIGINT) {
    remove("to_server");
    exit(0);
  }
}

int main() {

  int to_client;
  int from_client;

  signal(SIGINT,sighandler);

  while(1){
    from_client = server_handshake( &to_client );
      char mess[BUFFER_SIZE];
      char send_to_c[BUFFER_SIZE];
      while(read(from_client, mess, BUFFER_SIZE)){
        printf("The message recieved from client: %s\n",mess);

        int i=0;
        strcpy(send_to_c, mess);
        //transforms: makes every other letter into a -
        while (send_to_c[i]){
          if(i%2 == 0){
            send_to_c[i] = '-';
          }
          i++;
        }

      write(to_client,send_to_c,BUFFER_SIZE);
  }
}
}
