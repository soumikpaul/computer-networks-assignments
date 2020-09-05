// Server side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
int main(int argc, char const *argv[])
{
	
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
      
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
   int mx=rand()%4;
   printf("\nmx %d \n",mx);
	while(1){
char buffer[1024] = {0};
 valread = read( new_socket , buffer, 1024);

int x=rand()%5;
printf("\nx= %d \n",x);
//sleep(x);
if(x<5 || mx>0){
//sleep(2);
    printf("%s\n	ack sent\n",buffer );
char hello[256]="ack";
	//scanf("%s",hello);
    send(new_socket , hello , strlen(hello) , 0 );
}
  else{
mx=rand()%4;
printf("\nmx %d \n",mx);
int i;
//sleep(2);
for(i=0;i<mx;i++) printf("%c",buffer[i]);
char c='0'+mx;
printf("\nsend again from %c\n",c);
	char hello[256]="";
	hello[0]=c;
	//scanf("%s",hello);
    send(new_socket , hello , strlen(hello) , 0 );
} 
mx--; 
    //printf("Hello message sent\n");
	}
    return 0;
}
