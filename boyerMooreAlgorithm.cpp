#include<iostream>
#include<fstream>
#include<string>
#include <bits/stdc++.h> 
#include<cstdio>
using namespace std;
# define d 256  //number of characters
   
void badCharHeuristic( string ptrn, int size,int badchar[d])  
{  
    int i;  
  
    for (i = 0; i < d; i++)
	{
		badchar[i] = -1;
	}
	
    for (i = 0; i < size; i++) 
	{
		badchar[(int) ptrn[i]] = i;
	} 
          
}  
  
void boyerMooreSearch(vector<char> txt, string pattern)  
{  
	int count = 0;
    int m = pattern.size();  
    int n = txt.size();  
  
    int badchar[d];  
  
    badCharHeuristic(pattern, m, badchar); 
	
	ofstream file_;
	file_.open("results.txt", ios::app);
	file_<< "\nBoyer-Moore Algorithm\n" <<endl;
	file_<< "Pattern : " << pattern <<"\n"<<endl; 
  
    int s = 0; 
    
    while(s <= (n - m))  
    {  
        int j = m - 1;  
  
        while(j >= 0 && pattern[j] == txt[s + j]) 
		{
			j--;
		} 
              
        if (j < 0)  
        {  
            cout << "Pattern found at index : " <<  s << endl; 
			 
			file_<< "Pattern found at index : " << s <<endl;
			
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;  
        }  
		else
		{
			s += max(1, j - badchar[txt[s + j]]); 
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
     
    boyerMooreSearch(txt, pattern);  
    
    return 0;  
}  
