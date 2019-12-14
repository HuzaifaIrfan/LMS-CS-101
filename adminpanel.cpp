#include<iostream>

using namespace std;


void admin_panel()
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
	//adduser();
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
	//logout();
    break;
	default:
		cout << "Invalid Choice" << endl;

	}

}

