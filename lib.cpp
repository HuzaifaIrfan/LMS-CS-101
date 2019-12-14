
#include<iostream>
#include<string>
#include <vector>
using namespace std;


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
