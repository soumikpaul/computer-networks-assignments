//#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
#include<time.h>
#include<stdlib.h>
using namespace std;
int main(){
    cout<<"Enter divisor size:"<<endl;
int o;
cin>>o;
int g[o];
cout<<"Enter divisor :"<<endl;

for(int i=0;i<o;i++)
    cin>>g[i];
    cout<<" Do you want to inject fault:"<<endl;
    cout<<"__________________________________"<<endl;
    cout<<"1.yes"<<endl;
    cout<<"2.no"<<endl;
    cout<<"__________________________________"<<endl;
    int x;
    cin>>x;
    ifstream myReadFile;
    if(x==1)
    {
    	 myReadFile.open("example.txt");
 
char strn[255];
int c=0,c1=0;
while(myReadFile.getline(strn,255))
{
  c++;
  c1=0;
      for(int i=0;strn[i]!='\0';i++)
        {
           c1++;
        }
}
myReadFile.close();
srand ( time(NULL) );
		/* Generate a random number: */
int number = rand() % c ;

srand ( time(NULL) );
		/* Generate a random number: */
int	number2 = rand() % c1 ;
 myReadFile.open("example.txt");
 c=0;
 c1=0;
 ofstream myfile;
  myfile.open ("example2.txt");
while(myReadFile.getline(strn,255))
{
  
  
     c1=0;
      for(int i=0;strn[i]!='\0';i++)
        {
           
           if(c==number &&c1==number2)
           {
           	if(strn[c1]=='0')
           	strn[c1]='1';
           	else if(strn[c1]=='1')
           	strn[c1]='0';
		   }
		   myfile <<strn[i];
		   c1++;
        }
        c++;
      myfile<<endl;
}
cout<<endl<<"Fault is injected in Block No. "<<number+1<<" and at position "<<number2+1<<endl<<endl;

myReadFile.close();
myfile.close();
	}
 myReadFile.open("example2.txt");
char str[255];
while(myReadFile.getline(str,255))
{

   int temp[20]={0};
        int count=0;
        for(int i=0;str[i]!='\0';i++)
        {
       temp[count]=(int)str[i]-48;
        cout<<temp[count];
        count++;
       
        }
      int rs=o-1;
      int p=count-rs;
    cout<<"\n Receiver side : ";
    cout<<"\n Received Frame: ";
   //Division
   for(int i=0;i<p+rs;i++)
    {
        int j=0;
        int k1=i;
        //check whether it is divisible or not
        if(i==p)
        break;
        if (temp[k1]>=g[j])
        {
            for(j=0,k1=i;j<o;j++,k1++)
            {
                if((temp[k1]==1 && g[j]==1) || (temp[k1]==0 && g[j]==0))
                {
                    temp[k1]=0;
                }
                else
                {
                    temp[k1]=1;
                }
            }
        }
    }
 
    cout<<"\n Reaminder: ";
    int rrem[15];
     for(int i=0,j=p;i<rs;i++,j++)
    {
        rrem[i]=temp[j];
    }
    for(int i=0;i<rs;i++)
    {
        cout<<rrem[i];
    }
 
    int flag=0;
	
    for(int i=0;i<rs;i++)
    {
        if(rrem[i]!=0)
        {
            flag=1;
        }
    }
 
    if(flag==0)
    {
        cout<<"\n Since Remainder Is 0 Hence Message received at Receriver Is CORRECT ";
    }
    else
    {
        cout<<"\n Since Remainder Is Not 0 Hence Message received at Receriver CONTAINS ERROR ";
    }
    
 
        cout<<endl<<endl;
}

//cout<<output;
myReadFile.close();

cout<<endl;
//cout<<"output[49] = "<<output[49]<<endl;

}

