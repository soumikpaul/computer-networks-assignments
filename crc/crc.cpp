//#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    
 ifstream myReadFile;
 myReadFile.open("t.txt");
 char output[100];
 for(int i=0;i<100;i++)
    output[i]=5;
 if (myReadFile.is_open()) {
 while (!myReadFile.eof()) {
    myReadFile >> output;
    //cout<<output;
 }
}
ofstream myfile;
  myfile.open ("example.txt");
  myReadFile.close();
cout<<endl<<"enter block size"<<endl;
int p;
cin>>p;
int s=0;
while(output[s]!=5)
{
s++;
}
cout<<"no of values are "<<s-1;
//vector <int> v(std::begin(output),std::end(output));
int m=0;
int k9=(s-1)/p;
int q=(s-1)%p;
//if(p-q<=q)
q=p-q;
if(q!=0){
for(int i=0;i<q;i++)
{
output[s-1+i]=48;
}
}
cout<<endl;
//cout<<"output[49] = "<<output[49]<<endl;
while(k9>=0){
for(int i=m;i<m+p;i++)
    {
    cout<<output[i];
    }
    cout<<endl;
    k9--;
    m=m+p;
    }
//return 0;

int o;
k9=(s-1)/p;

cout<<"Enter divisor size:"<<endl;
cin>>o;
int g[o];
cout<<"Enter divisor :"<<endl;
for(int i=0;i<o;i++)
    cin>>g[i];

//Append 0's
    int rs=o-1;
    cout<<"\n Number of 0's to be appended: "<<rs<<endl;
int n=0;
while(k9>=0)
{
        int f[20]={0};
        int count=0;
        for(int i=n;i<n+p;i++)
        {
        
	if(i==s)
	{break;}
	
        f[count++]=(int)output[i]-48;
         }
    for (int i=p;i<p+rs;i++)
    {
        
        f[i]=0;
    }
    cout<<"\n Message after appending 0's :";
    for(int i=0; i<p+rs;i++)
    {
        cout<<f[i];
    }
    cout<<endl;
    int temp[20];
	for(int i=0;i<p+rs;i++)
	{
	temp[i]=f[i];
}
cout<<"temp"<<endl;
for(int i=0;i<p+rs;i++)
{
cout<<temp[i];
}
    cout<<endl;
    //Division
    for(int i=0;i<p;i++)
    {
        int j=0;
        int k1=i;
        //check whether it is divisible or not
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
        for(int i=0; i<p+rs;i++)
    {
        cout<<temp[i];
    }

    int crc[15];
    for(int i=0,j=p;i<rs;i++,j++)
    {
        crc[i]=temp[j];
    }
 
    cout<<"\n CRC bits: ";
    for(int i=0;i<rs;i++)
    {
        cout<<crc[i];
    }
 
    cout<<"\n Transmitted Frame: ";
    int tf[15];
    for(int i=0;i<p;i++)
    {
        tf[i]=f[i];
    }
    for(int i=p,j=0;i<p+rs;i++,j++)
    {
        tf[i]=crc[j];
    }
    for(int i=0;i<p+rs;i++)
    {
        cout<<tf[i];
	myfile <<tf[i];
    }
myfile<<endl;
cout<<endl<<endl;
	
 
       
    
    
    k9--;
n=n+p;
}
myfile.close();
}

