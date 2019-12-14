#include<iostream>
using namespace std;


void user_panel();
void user_login();

string username;
string userid;
string userbooks;
vector<string> userbooksvect;

vector<string> myvect;


string bookid;
string bookname;
string bookauthor;


void saveuser(){

	string usrstr="\n"+userid+"|"+username+"|"+userbooks;
				  ofstream out("users.db", ios::app);
  				out << usrstr;

}


void setupuser(){
	for (auto &user: users) {
           vector<string> uservect;
           tokenize(user,'|', uservect);
    		string name =uservect[1];
            if(username==name){
							userid=uservect[0];
							userbooks=uservect[2];

           tokenize(uservect[2],'&', userbooksvect);
							
				   for (auto &vectitem: uservect) {
					   myvect.push_back(vectitem);
					   cout<<vectitem<<endl;
				   }
			
			}
		}
}



void my_books(){

    system("clear");
    if(myvect[2]!="0"){

                    vector<string> userbooksvect;
                     tokenize(myvect[2],'&',  userbooksvect);

            for (auto &bookid: userbooksvect) {


                        for (auto &abook: books) {

                                vector<string> bookvect;
                                tokenize(abook,'|',  bookvect);

                            if(bookid==bookvect[0]){


                                //outstanding books

    int duedays=5;


    time_t now = time(0);
    int timenow=now ;
    int timedue=strtoint(bookvect[4]) ;

    // cout<<"\t"<<timenow<<endl;
    // cout<<"\t"<<timedue<<endl;

    int difference=timenow-timedue;

    if(difference > (86400*duedays)){
       
 int passed=difference/86400;
        //  cout<<"Outstanding book"<<endl;

        cout<<"Book Name :"<< bookvect[1]<<endl;
        cout<<"Days Passed from due date : "<< passed<<endl<<endl;
    }
	else{

 	int remaining=((difference)/86400);
		        cout<<"Book Name :"<< bookvect[1]<<endl;
				cout<<"Days Remaining till due date : "<< remaining<<endl<<endl;
	}



                            }


                        }


        }

    }else{
         cout<<"\tNo Books"<<endl;
    }


         

     



                cout<<"\t0. EXIT\n";
                char ch;
                cout << "\t " ;
                cin>>ch;


}



void book_loan(){

   system("clear");
	cout<< "\tAvailable Books"<<endl;

	for (auto &abook: books) {
                                vector<string> bookvect;
                                tokenize(abook,'|',  bookvect);

								if(bookvect[3]=="0"){
									cout<<"Book ID :"<< bookvect[0]<<endl;
									cout<<"Book Name :"<< bookvect[1]<<endl<<endl;
								}
	}


                cout<<"\tEnter Book ID to Loan\n";
                string inpbookid;
                cout << "\t " ;
                cin>>inpbookid;



	bool idmatch=false;




    for (int i =0; i<books.size(); i++) { 

        string abook= books[i];
           vector<string> bookvect;
           tokenize(abook,'|', bookvect);



            if(bookvect[0]==inpbookid){
				idmatch=true;


		   	bookid=bookvect[0];
            bookname=bookvect[1];
			bookauthor=bookvect[2];
			string bookuser=userid;
			// cout<<bookuser<<endl;

			    time_t now = time(0);
    			int timenow = now ;

			string bookdue= inttostr(timenow);

                delete_line("books.db",i+2); 

	string bookstr="\n"+bookid+"|"+bookname+"|"+bookauthor+"|"+bookuser+"|"+bookdue;
				  ofstream out("books.db", ios::app);
  				out << bookstr;






    for (int j =0; j<users.size(); j++) { 

        string auser= users[j];
           vector<string> uservect;
           tokenize(auser,'|', uservect);

  if(uservect[0]==userid){


	delete_line("users.db",j+2);

	userbooks= userbooks+"&"+bookid;

	saveuser();

  }



	}




            }


     }



	cout<<"\n\n\n";


	if(idmatch==false){
	cout<<"\tInvalid Book ID\n";
	}else{
			cout<<"\t" << bookname <<" loaned to "<<username<<endl;
	}

















                cout<<"\t0. EXIT\n";
                char ch;
                cout << "\t " ;
                cin>>ch;

				setup();
				setupuser();

}


void book_deposit(){

	
}




void user_login()
{

	username="huzaifa";
	// cout<<"Enter Your name??\n";
	// cin>>name;

	setup();
	setupuser();
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
			my_books();
		case '2':
			book_loan();
			break;
		case '3':
			book_deposit();
			break;
		case '4':
        loginstatus=false;
			break;
		default:
			cout << "Invalid choice::Please try again!!" << endl;
		}




    }

}

