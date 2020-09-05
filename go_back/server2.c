// Server side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include<time.h>
#include <unistd.h>
#define PORT 8088
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
int main(int argc, char const *argv[])
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[10] = {0};
	char *hello = "Hello from server";
	
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
	
	int l;
	
	printf("CodeWord:\n");
	printf("data:\n");
	int p=0;
	int c[8][1];
	int f=0;
	for(int i=0;i<4;i++)
	{
		int a[1]={0};
		valread = read( new_socket , buffer, 10);
		if(func(buffer)==1)
		a[0]=1;
		if(a[0]==1)
		f=1;
		printf("%s %d",buffer,a[0]);
		c[i][0]=a[0];
		int r=rand()%2;
		if(a[0]==1)
		printf(" Code Discarded");
		else
		printf(" Code Accepted");
		printf("\n");
	}
	f=0;
	for(int i=0;i<4;i++)
	{
		send(new_socket , c[i] , 1 , 0 );
		printf("ack sent\n");
		if(c[i][0]==1)
		{
			for(int j=0;j<4;j++)
			{
				valread = read(new_socket , buffer, 10);
				c[j][0]=0;
				if(func(buffer)==1)
				c[j][0]=1;
				printf("\ncodeword received %d\n",i+j);
				
			}
		}
		int p1;
		int a[1]={0};
		valread = read( new_socket , buffer, 10);
		if(buffer[0]=='a')
		break;
		if(func(buffer)==1)
		a[0]=1;
		else if(p1==1)
		{
			a[0]=2;
		}
		for(int j=0;j<10;j++)
		{
			printf("%c",buffer[j]);
		}
		printf(" %d",a[0]);
		if(a[0]==1)
		f=1;
		c[i+4][0]=a[0];
		printf("\ncodeword received %d",i+4);
		if(f==1)
		{
			printf(" codeword discarted");
		}
		printf("\n");
		
	}
	for(int i=4;i<8;i++)
	{
		send(new_socket , c[i] , 1 , 0 );
		printf("ack sent\n");
		if(c[i][0]==1)
		{
			for(int j=i;i<8;j++)
			{
				valread = read(new_socket , buffer, 10);
				if(buffer[0]=='a')
				break;
				
			}
		}
	}
	return 0;
}
