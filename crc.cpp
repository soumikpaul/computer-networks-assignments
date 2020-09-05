//#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    
     ifstream myReadFile;
 myReadFile.open("data.txt");
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
  //myfile << "Writing this to a file.\n";
  

cout<<output;
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
int k9=s/p;
int q=s%p;
//cout<<"q "<<q<<endl;
if(q!=0){
cout<<endl<<q<<" bits are padded to make multiple of "<<p<<endl;
for(int i=0;i<q;i++)
{
output[s+i-1]=48;
}

}
cout<<endl;
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
k9=s/p;

cout<<"Enter divisor size"<<endl;
cin>>o;
int g[o];
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
        //cout<<output[i]<<"out"<<endl;
        //cout<<"output[i]  "<<output[i];
	    f[count++]=(int)output[i]-48;
        //cout<<f[i]<<"f"<<endl;
        }
//cout<<n<<" n"<<endl;
        
        //cout<<endl;
        //k--;
        //n=n+p;
        //cout<<f[0]<<"  " <<f[1]<<"   "<<f[2]<<endl;
    for (int i=p;i<p+rs;i++)
    {
        //cout<<i<<"  I  "<<endl;
        f[i]=0;
    }
    //cout<<f[4]<<"  " <<f[5]<<"   "<<f[6]<<endl;
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
   /* for(int i=0; i<p+rs;i++)
    {
        temp[i]=f[i];
    }*/

      /*  for(int i=0; i<p+rs;i++)
    {
        cout<<temp[i];
    }*/
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
	
 
    cout<<"\n Receiver side : ";
    cout<<"\n Received Frame: ";
    for(int i=0;i<p+rs;i++)
    {
        cout<<tf[i];
    }
 
    for(int i=0;i<p+rs;i++)
    {
        temp[i]=tf[i];
    }
 
    //Division
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
n=n+p;
}
myfile.close();
}

