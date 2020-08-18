#include<iostream>
#include<fstream>
#include<string>
#include <bits/stdc++.h> 
#include<cstdio>
using namespace std;

//Naive String Matching
void naiveSearch(string pattern,vector<char> txt)
{
	int m=pattern.length();
	int n=txt.size();
	int i,j,find=0;
	
	ofstream file_;
	file_.open("results.txt", ios::app);
	file_<< "\nNaive String Matching Algorithm\n" <<endl;
	file_<< "Pattern : " << pattern <<"\n"<<endl;
	
	for(i=0;i<n-m+1;i++)
	{
		j=0;
		while(j<m)
		{
			if(pattern[j]==txt[i+j])
			{
				j++;
			}
			else
			{
				break;
			}
		}	
		if(j==m)
		{
			cout<<"Pattern found at index "<<i<<endl;
			
			file_<< "Pattern found at index : " << i <<endl;
		}	
	}
	file_.close();
}

int main()
{
	vector<char> txt;
	int count = 0; 
	
	string line;
	
	ifstream file;
	file.open("pi.txt");
	
	if(file.fail())                   
	{
		cout<<"File cannot open"<<endl;
		file.close();
	}

	while(!file.eof())
	{
		int i=0, j=0;
		getline(file,line);
		count ++;

		if(count>21)
		{
			string s = line;
			int size = s.length();
			//to remove space
			while(s[i]) 
		    	{ 
		        if (s[i] != ' ') 
		        {
		        	s[j++] = s[i]; 
				}
		        i++; 
		    } 
		    s[j] = '\0';
		    //to store every line in one vector
		    if(s.length()>0)
		    {
		    	for(i=0;i<50;i++)
		    	{
		    		txt.push_back(s[i]);
				}	
			}
		}
		
	}
	
	file.close();
	
	string pattern = "971220";
	
	naiveSearch(pattern,txt);
	
	return 0;
}
	

