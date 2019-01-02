#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  while(1){

    printf("Input a message:\n");
    char * buff = calloc(BUFFER_SIZE, sizeof(char *));
    fgets(buff,BUFFER_SIZE,stdin);

    write(to_server,buff,BUFFER_SIZE);
    read(from_server,buff,BUFFER_SIZE);
    printf("Recieved from server: %s",buff);
  }
}
