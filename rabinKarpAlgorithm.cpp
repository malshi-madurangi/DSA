#include<iostream>
#include<fstream>
#include<string>
#include <bits/stdc++.h> 
#include<cstdio>
using namespace std;
#define d 256

void rabinKarpSearch(string pattern, vector<char> txt, int q)  
{  
	int i, j;
	int count = 0;
	
    int m = pattern.length();  
    int n = txt.size();  
      
    int hashP = 0; // hash value for pattern  
    int hashT = 0; // hash value for txt  
    int h = 1; 
	
	ofstream file_;
	file_.open("results.txt", ios::app);
	file_<< "\nRabin Karp Algorithm\n" <<endl;
	file_<< "Pattern : " << pattern <<"\n"<<endl; 
  
    for (i = 0; i < m - 1; i++)
	{
		h = (h * d) % q; 
	}  
          
    for (i = 0; i < m; i++)  
    {  
        hashP = (d * hashP + pattern[i]) % q;  
        hashT = (d * hashT + txt[i]) % q;  
    }  
  
    for (i = 0; i <= n - m; i++)  
    {  
        if ( hashP == hashT )  
        {  
            for (j = 0; j < m; j++)  
            {  
                if (txt[i+j] != pattern[j])  
                break;  
            }  
            if (j == m)  
            {
            	cout<<"Pattern found at index : "<< i <<endl;
            	
            	file_<< "Pattern found at index : " << i <<endl;
					
			}  
        }   
        if ( i < n-m )  
        {  
            hashT = (d*(hashT - txt[i]*h) + txt[i+m])%q;  
   
            if (hashT < 0)
			{
				hashT = (hashT + q);
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
		    //to store every non empty line in one vector
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
	
	int prime = 131; 
	
	string pattern = "971220"; 
	  
    rabinKarpSearch(pattern,txt,prime);  
    
    return 0;
	 
}  
