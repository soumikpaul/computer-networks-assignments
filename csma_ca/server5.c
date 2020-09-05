// Server side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include<time.h>
#include <pthread.h>
 #include<unistd.h>
#define PORT 8074
int f=0;
int func(char str[])
{
	int d=19;
		int div=0;
		int n=10;
		for(int i=0;i<10;i++)
		{
			if(str[i]=='1')
			div+=(1<<(n-i-1));
		}
		if(div%19==0)
		return 0;
		else
		return 1;
}
void *myThreadFun(void *vargp)
{
	f=1;
    for(int i=0;i<5;i++)
    {
    	printf("Thread is working\n");
    	sleep(1);
	}
	f=0;
}
int main(int argc, char const *argv[])
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[11] = {0};
	char *hello = "Hello from server";
	FILE *fp=fopen("codeword.txt","r");
	pthread_t tid;
	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	
	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR ,&opt, sizeof(opt)))
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
	char* chr;
	int i;
	printf("CodeWord:\n");
	printf("data:\n");
	pthread_create(&tid, NULL, myThreadFun, (void *)i);
    while(1)
    {
    	sleep(1);
    	valread=read(new_socket,buffer,11);
    	if(buffer[0]=='a')
    	break;
    	if(buffer[0]=='r')
    	{
    		char a[1];
    		if(f==0)
    		a[0]='y';
    		else
    		a[0]='n';
    		send(new_socket , a , 1 , 0 );
		}
		else
		{
			if(f==0)
			{
				printf("%s received\n",buffer);
				char a[1]={0};
				send(new_socket , a , 1 , 0 );
			}
			else
			{
				char a[1]={1};
				send(new_socket , a , 1 , 0 );
			}
		}
	}
    pthread_exit(NULL);
//	int p=0;
//	while(1)
//	{
//		//scanf("%d",&p);
//		//srand(p);
//		int p1=rand()%2;
//		int a[1]={0};
//		valread = read( new_socket , buffer, 11);
//		if(buffer[0]=='a')
//		break;
//		//printf("%c",buffer[i]);
//		for(int j=0;j<10;j++)
//		{
//			printf("%c",buffer[j]);
//		}
//		printf(" ");
//		if(func(buffer)==1)
//		a[0]=1;
//		else if(p1==1)
//		{
//			//a[0]=2;
//		}
//		printf("\ncodeword received\n");
//		send(new_socket , a , 1 , 0 );
//		printf("ack sent\n");
//	}
	//printf("Hello message sent\n");
	return 0;
}
