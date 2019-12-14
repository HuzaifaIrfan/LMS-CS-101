#include<iostream>

using namespace std;


void user_panel();
void user_login();








void user_login()
{
   user_panel();
}


void user_panel()
{

    bool loginstatus=true;

    while(loginstatus){
        system("clear");
      
	char ch;
		cout << "\n\t User Panel" << endl;
		cout << "\n\t1. My Books" << endl;
		cout << "\t2. Loan a book" << endl;
		cout << "\t3. Deposit book" << endl;
		cout << "\t4. Logout" << endl;
  cout << "\t " ;
cin>>ch;
		switch (ch)
		{
		case '1':
			// my_books();
		case '2':
			//book_loan();
			break;
		case '3':
			//book_deposit();
			break;
		case '4':
        loginstatus=false;
			break;
		default:
			cout << "Invalid choice::Please try again!!" << endl;
		}




    }

}

