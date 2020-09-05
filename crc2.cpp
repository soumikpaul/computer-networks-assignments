#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){


    string str;
	ifstream infile;
	infile.open ("data.txt");
        while(!infile.eof()) // To get you all the lines.
        {
	        getline(infile,str); // Saves the line in STRING.
	        cout<<str; // Prints our STRING.
        }
        cout<<str.length()<<endl;
	infile.close();
	cout<<endl;
	int p;
	//while(
	int i;
	//cout<<STRING[0];
	cout<<str[1];
	cin>>p;
	int z=0;
	cout<<str.length()<<endl;
	while(str[i]!=NULL)
	{
	    //z++;
	    for(i;i<p;i++)
	    {
	        cout<<str[i];
	         z++;
	     }   
	        i=i+p;
	}
	
	}
	
