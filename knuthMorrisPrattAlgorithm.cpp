#include<iostream>
#include<fstream>
#include<string>
#include <bits/stdc++.h> 
#include<cstdio>
using namespace std;

void findLPS(string pattern, int m, int lps[])
{
	int i;
	int length = 0;
	lps[0] = 0;     //lps[0] is always 0 as no prefix

	for(i = 1; i<m; i++) 
	{
        if(pattern[i] == pattern[length])
		{
			length++;
			lps[i] = length;    
      	}
		else 
		{
        	if(length != 0)
			{
            	length = lps[length - 1];
            	i--;     
        	}
			else
			{
				lps[i] = 0;
			} 
        }
    }
}

void KMPSearch(vector<char> txt, string pattern) 
{
	int n, m;
	int i = 0;
	int j = 0;
	int count = 0;
   
	n = txt.size();
	m = pattern.size();
   
	ofstream file_;
	file_.open("results.txt", ios::app);
	file_<< "\nKnuth Morris Pratt Algorithm\n" <<endl;
	file_<< "Pattern : " << pattern <<"\n"<<endl;
   
	int lpsArray[m];    
	findLPS(pattern, m, lpsArray);
   
	while(i < n) 
    {
    	if(txt[i] == pattern[j]) 
		{
        	i++;
			j++;
    	}

    	if(j == m) 
		{
			cout << "Pattern found at index : " <<i-j<< endl;
			
        	file_<< "Pattern found at index : " << i-j<<endl;
        	
        	j = lpsArray[j-1];    //get the prefix length from array
    	}
		else if(i < n && pattern[j] != txt[i]) 
		{
        	if(j != 0)
			{
            	j = lpsArray[j-1];
            }
        	else
        	{
        		i++;	
			}
            
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
	
	KMPSearch(txt, pattern);
		
	return 0;
}

