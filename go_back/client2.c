#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include<unistd.h>
#define PORT 8088
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
    char codeword[10] = {0};
    char ack[1]={0};
    int o;
	scanf("%d",&o);
	srand(o);
	char code[8][10];
	for(int i=0;i<4;i++)
	{
		fscanf(fp,"%s",codeword);
		for(int j=0;j<12;j++)
    	{
    		code[i][j]=codeword[j];
		}
		int r=rand()%3;
		if(r==0)
		codeword[0]='0';
		send(sock , codeword , strlen(codeword) , 0 );//sent codeword
    	printf("\ncodeword sent %d\n",i);
    	printf("%s",codeword);
	}
    for(int i=4;i<8;i++)
    {
    	while(1)
    	{
	    	valread = read(sock , ack, 1);
	    	if(ack[0]==0){
		    	printf("\nACK received %d\n",i-4);
		    	break;
	    	}
	    	else if(ack[0]==2){
	    		printf("\nTime Delay\n");
			}
			else
			{
		    	printf("\nNAK received\n");
		    	for(int j=i-4;j<i;j++)
		    	{
		    		send(sock , code[j] , strlen(code[j]),0);
		    		
		    		printf("\ncodeword sent %d\n",j);
		    		
				}
	    	}
	    	
        }
    	fscanf(fp,"%s",codeword);
    	/////////////////
    	srand((int)(codeword[5])-3);
    	int er=rand()%2;
    	char c;
    	 c=codeword[er];
    	 if(er==1)
    	codeword[6]='0';
    	/////////////////
    	send(sock , codeword , strlen(codeword) , 0 );//sent codeword
    	codeword[er]=c;
    	printf("\ncodeword sent %d\n",i);
    	printf("%s",codeword);
    	
	}
	for(int i=4;i<8;i++)
	{
		while(1)
    	{
	    	valread = read(sock , ack, 1);
	    	if(ack[0]==0){
		    	printf("\nACK received %d\n",i);
		    	break;
	    	}
	    	else if(ack[0]==2){
	    		printf("\nTime Delay\n");
			}
			else
			{
		    	printf("\nNAK-received %d\n",i);
		    	break;
		    	for(int j=i;j<8;j++)
		    	{
		    		send(sock , code[i] , strlen(code[i]), 0 );
				}
	    	}
	    	
        }
	}
	codeword[0]='a';
    send(sock , codeword , strlen(codeword), 0 );
    return 0;
}
