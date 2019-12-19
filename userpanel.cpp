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
	    myvect.clear(); 
		userbooksvect.clear(); 
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
				   }
			
			}
		}
}



void my_books(){

   screenclear();
    if(myvect[2]!="0"){

                    vector<string> userbooksvect;
                     tokenize(myvect[2],'&',  userbooksvect);


            for (auto &bookid: userbooksvect) {


                        for (auto &abook: books) {

                                vector<string> bookvect;
                                tokenize(abook,'|',  bookvect);

                            if(bookid==bookvect[0]){


                                //outstanding books

    int duedays=1;


    time_t now = time(0);
    int timenow=now ;
    int timedue=strtoint(bookvect[4]) ;

    // cout<<"\t"<<timenow<<endl;
    // cout<<"\t"<<timedue<<endl;

    int difference=timenow-timedue;




	   		 cout<<"Book ID : "<< bookvect[0]<<endl;
        cout<<"Book Name : "<< bookvect[1]<<endl;

    if(difference > (86400*duedays)){
 	int passed=difference/86400;
        //  cout<<"Outstanding book"<<endl;
        cout<<"Days Passed from due date : "<< passed<<endl<<endl;
    }
	else{

 	int remaining=(timedue-timenow)/86400;
				cout<<"Days Remaining till due date : "<< remaining<<endl<<endl;
	}



                            }


                        }


        }

    }else{
         cout<<"\tNo Books"<<endl;
    }

}




void showmybooks(){

	my_books();

 exitter("");
}



void book_loan(){

   screenclear();

if(userbooksvect.size()>=4){


cout<<"You cannot loan more than 3 books\n";


}else{

	cout<< "\tAvailable Books"<<endl;


bool booksavailable=false;

	for (auto &abook: books) {
                                vector<string> bookvect;
                                tokenize(abook,'|',  bookvect);

								if(bookvect[3]=="0"){
									booksavailable=true;
									cout<<"Book ID :"<< bookvect[0]<<endl;
									cout<<"Book Name :"<< bookvect[1]<<endl<<endl;
								}

	}


if(booksavailable==false){

cout<<"\tNo Books Available in the Library\n";

}else{



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

	int duedays=5;

	int duetime=duedays*86400;

			string bookdue= inttostr(timenow+duetime);

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

	setup();
	setupuser();


}

}


 exitter("");



}


void removebookid(string abookid){

	string temp="0";



  for (int i =1; i<userbooksvect.size(); i++) { 

        string abook= userbooksvect[i];

		if(abook!=abookid){
			temp= temp+ "&"+abook;
		}


  }
	userbooks=temp;
}


void book_deposit(){

	my_books();


                cout<<"\tEnter Book ID to Return\n";
                string inpbookid;
                cout << "\t " ;
                cin>>inpbookid;



	bool idmatch=false;

  for (auto &abookid: userbooksvect) {
	if(abookid==inpbookid){
	idmatch=true;
	}
  }









	cout<<"\n\n\n";


	if(idmatch==false){
	cout<<"\tInvalid Book ID\n";
	}else{







  for (int i =0; i<books.size(); i++) { 

        string abook= books[i];
           vector<string> bookvect;
           tokenize(abook,'|', bookvect);


            if(bookvect[0]==inpbookid){
				idmatch=true;


		   	bookid=bookvect[0];
            bookname=bookvect[1];
			bookauthor=bookvect[2];
			string bookuser="0";
			string bookdue=bookvect[4];


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

				removebookid(bookid);

				saveuser();

			}



	}










			}



  }








			cout<<"\t" << bookname <<" returned by "<<username<<endl;
	}



	setup();
	setupuser();


 exitter("");

}




void user_login(){

	username="huzaifa";
	cout<<"Enter Your name??\n";
	cin>>username;

	bool loginstate=false;

   for (auto &user: users) {
           vector<string> uservect;
           tokenize(user,'|', uservect);

			if(uservect[1]==username){

				loginstate=true;
		setup();
		setupuser();

			}

	}

	if(loginstate==true){



		user_panel();
	}else{
		 exitter("Wrong Username");
	}







	if(loginstate==true){
		user_panel();
	}



}


void user_panel()
{

    bool loginstatus=true;

    while(loginstatus){
       screenclear();
      
	char ch;
	cout << "\n\t Logged in as "<<username << endl;
		cout << "\n\t User Panel" << endl;
		cout << "\n\t1. My Books" << endl;
		cout << "\t2. Loan a book" << endl;
		cout << "\t3. Deposit book" << endl;
		cout << "\t0. Logout" << endl;
  cout << "\t " ;
cin>>ch;
		switch (ch)
		{
		case '1':
			showmybooks();
			break;
		case '2':
			book_loan();
			break;
		case '3':
			book_deposit();
			break;
		case '0':
		exitter("Logging out");
        loginstatus=false;
			break;
		default:
			 exitter( "Invalid choice::Please try again!!\n" );
		}




    }

}

