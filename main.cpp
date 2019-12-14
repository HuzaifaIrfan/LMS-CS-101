#include<iostream>
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










void admin_menu()
{
	system("clear");
    char ch;
	cout << "\n\t Admin Menu" << endl;
	cout << "\t1. Create User" << endl;
	cout << "\t2. Delete User" << endl;
	cout << "\t3. Search User" << endl;
	cout << "\t4. List of existing Users" << endl;
	cout << "\t5. Create Book" << endl;
	cout << "\t6. Delete Book" << endl;
	cout << "\t7. List of books" << endl;
	cout << "\t8. List of existing Books and their status" << endl;
	cout << "\t9. Return" << endl;

cout << "\t " ;
cin>>ch;

	switch (ch)
	{
	case '1':

		break;
	case '2':
		//deleteuser();
		break;
	case '3':
		//searchuser();
		break;
	case '4':
		//listusers();
		break;
	case '5':
		//createbook();
		break;
	case '6':
		//deletebook();
		break;
	case '7':
		//listbooks();
		break;
	case '8':
		//statusbooks();
		break;
	case '9':
	default:
		cout << "Invalid Choice" << endl;

	}

}



/*


                                                                                Main                                                


*/
int main(){

admin_menu();





    return 0;
}