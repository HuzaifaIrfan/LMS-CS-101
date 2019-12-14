#include<iostream>
#include<fstream>
#include"lib.cpp"
using namespace std;

void admin_panel();
void admin_login();




// ofstream usersof("users.db");
// ofstream booksof("books.db");

vector<string> users={};
vector<string> books={};



void setup(){

users.clear(); 
books.clear(); 

    ifstream usersif("users.db");
    ifstream booksif("books.db");

string line;

while(!usersif.eof()){

   getline(usersif,line);
users.push_back(line);


}

usersif.close();

while(!booksif.eof()){

 getline(booksif,line);
    
books.push_back(line);

}
booksif.close();

}







void listusers(){

 bool notexit=true;

    while(notexit){
        system("clear");

for (auto &user: users) {

cout<<user<<endl;

}



        cout<<"\t1 EXIT\n";

        

        char ch;
        cout << "\t " ;
        cin>>ch;

        switch (ch){
            case '1':
                notexit=false;
                break;
            default:
                cout << "Invalid Choice" << endl;
        }

    }

}





void listbooks(){

 bool notexit=true;

    while(notexit){
        system("clear");

for (auto &book: books) {

cout<<book<<endl;

}



        cout<<"\t1 EXIT\n";

        

        char ch;
        cout << "\t " ;
        cin>>ch;

        switch (ch){
            case '1':
                notexit=false;
                break;
            default:
                cout << "Invalid Choice" << endl;
        }

    }

}
































void admin_login(){

setup();
admin_panel();
    
}



void admin_panel()
{

    bool loginstatus=true;

    while(loginstatus){
        system("clear");
        cout << "\n\t Admin Menu\n" << endl;
        cout << "\t1. Create User" << endl;
        cout << "\t2. Delete User" << endl;
        cout << "\t3. Search User" << endl;
        cout << "\t4. List of existing Users" << endl;
        cout << "\t5. Create Book" << endl;
        cout << "\t6. Delete Book" << endl;
        cout << "\t7. List of books" << endl;
        cout << "\t8. List of existing Books and their status" << endl;
        cout << "\t9. Logout" << endl;

        cout << "\t " ;
	
        char ch;
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
                listusers();
                break;
            case '5':
                //createbook();
                break;
            case '6':
                //deletebook();
                break;
            case '7':
                listbooks();
                break;
            case '8':
                //statusbooks();
                break;
            case '9':
            loginstatus=false;
            break;
            default:
                cout << "Invalid Choice" << endl;
            }



    }

}

