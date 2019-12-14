#include<iostream>
#include<fstream>
#include <sstream>
#include <string>
#include <ctime>
#include<string>
#include <vector>
#include <bits/stdc++.h>
#include <cstdio>
#include <stdlib.h>
using namespace std;



void delete_line(const char *file_name, int n) { 
    // open file in read mode or in mode 
    ifstream is(file_name); 
  
    // open file in write mode or out mode 
    ofstream ofs; 
    ofs.open("temp.txt", ofstream::out); 
  
    // loop getting single characters 
    char c; 
    int line_no = 1; 
    while (is.get(c)) 
    { 
        // if a newline character 
        if (c == '\n') 
        line_no++; 
  
        // file content not to be deleted 
        if (line_no != n) 
            ofs << c; 
    } 
  
    // closing output file 
    ofs.close(); 
  
    // closing input file 
    is.close(); 
  
    // remove the original file 
    remove(file_name); 
  
    // rename the file 
    rename("temp.txt", file_name); 
} 





//sortting

bool mycomp(string a, string b){
	//returns 1 if string a is alphabetically 
	//less than string b
	//quite similar to strcmp operation
	return a<b;
}

vector<string> alphabaticallySort(vector<string> a){
	int n=a.size();
	//mycomp function is the defined function which 
	//sorts the strings in alphabatical order
	sort(a.begin(),a.end(),mycomp);
	return a;
}




int strtoint(string str){
    string idstr= str;
    int inte;
    istringstream iss (idstr);
    iss >> inte;
    return inte;
}


string inttostr(int inte){

    string out_string;
    stringstream ss;
    ss << inte;
    out_string = ss.str();
    return out_string;
}





void tokenize(string const &str, const char delim, vector<string> &out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}




void LowerCase(string & str){
	int len = str.length();

	for( int i = 0; i < len; i++ ) 
	{
		if ( str[i] >= 'A' && str[i] <= 'Z' ) 
		{
			str[i] -= 'A' - 'a';
		}
	}

}
