// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include<unistd.h>
#define PORT 8074
#define P 5
int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *str1;
    FILE * fp; 
    
    fp = fopen("codeword1.txt", "r");
    
	
 	char *hello = "Hello from client";
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
  
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    /////////////////////////////////////////////////////////////////////////////////////
    char codeword[11] = {0};
    char ack[1]={0};
    int o;
	scanf("%d",&o);
	srand(o);
	char code[4][11];
    for(int i=0;i<4;i++)
    {
    	fscanf(fp,"%s",code[i]);
    }
    int in=0;
    int flag=0;
    while(in<4)
    {
    	sleep(1);
		flag=0;    	
    	codeword[0]='r';
    	send(sock , codeword , strlen(codeword), 0);
    	char a[1];
    	valread=read(sock,a,1);
    	if(a[0]=='y'){
    		printf("channel is free\n");
    		    	flag=1;
		}
    	else
    	{
    		printf("server is busy\n");
		}
    	
    	if(flag==1){
    		while(1){
    		int p=rand()%10;
    		printf(" %d\n",p);
	    		if(p>=P){
		    		send(sock , code[in] , strlen(code[in]), 0);
		    		char a[1];
		    		valread=read(sock,a,1);
		    		if(a[0]==0)
		    		in++;
		    		else
		    		printf("server is busy again\n");
		    		break;
	    		}
	    		else
	    		printf(" p<P \n");
    		}
    	}
	}
	codeword[0]='a';
    send(sock , codeword , strlen(codeword), 0 );
    return 0;
}
