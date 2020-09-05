#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    
     ifstream myReadFile;
 myReadFile.open("example.txt");
 char output[100];
 for(int i=0;i<100;i++)
    output[i]=5;
 if (myReadFile.is_open()) {
 while (!myReadFile.eof()) {
    myReadFile >> output;
    cout<<output<<endl;
 }
}


cout<<"Enter block size "<<endl;
int p;
cin>>p;
cout<<"Enter divisor size same as before "<<endl;
int o;
cin>>o;
int g[o];
cout<<"Enter divisor same as before "<<endl;
for(int i=0;i<o;i++)
cin>>g[i];
int rs=o-1;
int s=0;
while(output[s]!=5)
{
s++;
}
cout<<"no of values are "<<s-1<<endl;
int k9=s/(p+rs);
int m=0;
cout<<k9<<endl;
while(k9>=0)
{
for(int i=m;i<m+p+rs;i++)
    {
    cout<<output[i];
    }
    cout<<endl;
    k9--;
    m=m+p+rs;
    }
    
    int n=0;
while(k9>=0)
{
        int f[20]={0};
        int count=0;
        for(int i=n;i<n+p;i++)
        {
        //cout<<output[i]<<"out"<<endl;
        //cout<<"output[i]  "<<output[i];
	    f[count++]=(int)output[i]-48;
        //cout<<f[i]<<"f"<<endl;
        }
        int temp[20];
        for(int i=0;i<20;i++)
        {
        temp[i]=f[i];
        }
        for(int i=0;i<p+rs;i++)
    {
        int j=0;
        int k=i;
        if (temp[k]>=g[j])
        {
            for(int j=0,k=i;j<o;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    cout<<"\n Reaminder: ";
    int rrem[15];
    for (int i=p,j=0;i<p+rs;i++,j++)
    {
        rrem[j]= temp[i];
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
        cout<<"\n Since Remainder Is 0 Hence Message Transmitted From Sender To Receriver Is Correct ";
    }
    else
    {
        cout<<"\n Since Remainder Is Not 0 Hence Message Transmitted From Sender To Receriver Contains Error ";
    }
    
    
    
    k9--;
n=n+p+rs;
}
myReadFile.close();
}


