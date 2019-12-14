#include<iostream>
#include<fstream>
#include <sstream>
#include <string>
#include"lib.cpp"
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

void admin_panel();
void admin_login();






vector<string> users={};
vector<string> books={};



void setup(){

    users.clear(); 
    books.clear(); 

        ifstream usersif("users.db");
        ifstream booksif("books.db");

    string line;

    getline(usersif,line);
    while(!usersif.eof()){

    getline(usersif,line);
    users.push_back(line);


    }

    usersif.close();

    getline(booksif,line);
    while(!booksif.eof()){

    getline(booksif,line);
        
    books.push_back(line);

    }
    booksif.close();

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





void saveusers(){
    ofstream usersof("users.db");

    for (auto &user: users) {
        usersof<<"\n";
        usersof<<user;
                
        }

}

void savebooks(){
    
    ofstream booksof("books.db");

        for (auto &book: books) {
            booksof<<"\n";
            booksof<<book;
        }

}





void adduser(){


    system("clear");

    string idstr;

    for (auto &user: users) {
            vector<string> uservect;
            tokenize(user,'|', uservect);
            idstr=uservect[0];
    }

    int idint=strtoint(idstr)+1;

    idstr=inttostr(idint);


    
    string name;
    string books="0";

        cout<<"Enter Your Name\n";
        cin>>name;

    string user=idstr+"|"+name+"|"+books;

    users.push_back(user);
    saveusers();







        cout<<name << " created..\n";





                cout<<"\t0. EXIT\n";

                

                char ch;
                cout << "\t " ;
                cin>>ch;


    setup();

}





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


void deleteuser(){


    system("clear");

    string username;
    cout<<"Enter Username to Delete\n";
    cin>>username;






    string idstr;

    for (int i =0; i<users.size(); i++) { 

        string user= users[i];
           vector<string> uservect;
           tokenize(user,'|', uservect);
            string name=uservect[1];

            if(name==username){
                cout<<"Deleting "<<name<<endl;
                cout<<i+2<<endl;
                delete_line("users.db",i+2); 

            }
     }




                cout<<"\t0. EXIT\n";

                

                char ch;
                cout << "\t " ;
                cin>>ch;


    setup();

}




void searchuser(){


    system("clear");


    string username;
    cout<<"Enter Username to Search\n";
    cin>>username;


    bool nf=true;



   for (auto &user: users) {

           vector<string> uservect;
           tokenize(user,'|', uservect);

    string name =uservect[1];

            if(name==username){
                nf=false;
                cout<<"\tUser Found "<<endl;
                cout<<"\tID : "<<uservect[0]<<endl;
                cout<<"\tUserName : "<<name<<endl;

    if(uservect[2]!="0"){

                    vector<string> userbooksvect;
                     tokenize(uservect[2],'&',  userbooksvect);

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

        // cout<<"Outstanding book"<<endl;

        cout<<"Book Name :"<< bookvect[1]<<endl;
        cout<<"Days Passed from due date : "<< passed<<endl;
    }



                            }


                        }


        }

    }else{
         cout<<"\tNo Books"<<endl;
    }


            }


     }

            if(nf==true){
                cout<<"\tUser Not Found "<<endl;
            }


                cout<<"\t0. EXIT\n";

                

                char ch;
                cout << "\t " ;
                cin>>ch;

}







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


void listusers(){

    bool notexit=true;

        while(notexit){
            system("clear");

            vector<string> usernamelst;

            for (auto &user: users) {
    vector<string> uservect;
    tokenize(user,'|', uservect);
    usernamelst.push_back(uservect[1]);
            }

    usernamelst=alphabaticallySort(usernamelst);

    cout<<"\t   USERS \n";

            for (auto &username: usernamelst) {
                cout<<"\t"<<username<<endl;
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





void statusbooks(){

    bool notexit=true;

        while(notexit){
            system("clear");



    for (auto &book: books) {

        vector<string> bookvect;

        tokenize(book,'|', bookvect);

    cout<<"Id : "<<bookvect[0]<<endl;
    cout<<"Name : "<<bookvect[1]<<endl;
    cout<<"Author : "<<bookvect[2]<<endl;

    if(bookvect[3]=="0"){
    cout<<"Status : Not Loaned"<<endl;
    }else{
    


    for (auto &user: users) {
        vector<string> uservect;
        tokenize(user,'|', uservect);

        if(uservect[0]==bookvect[3]){
    cout<<"Status : Loaned by "<<uservect[1]<<endl;
        }

    }



    }


    cout<<endl;

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

        vector<string> bookvect;

        tokenize(book,'|', bookvect);

    cout<<"Id : "<<bookvect[0]<<endl;
    cout<<"Name : "<<bookvect[1]<<endl;
    cout<<"Author : "<<bookvect[2]<<endl<<endl;


    }


    cout<<endl;





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
        cout << "\t5. List of books" << endl;
        cout << "\t6. List of existing Books and their status" << endl;
        cout << "\t7. Logout" << endl;

        cout << "\t " ;
	
        char ch;
        cin>>ch;

            switch (ch)
            {
            case '1':
            adduser();
                break;
            case '2':
                deleteuser();
                break;
            case '3':
                searchuser();
                break;
            case '4':
                listusers();
                break;
            case '5':
                listbooks();
                break;
            case '6':
                statusbooks();
                break;
            case '7':
            loginstatus=false;
            break;
            default:
                cout << "Invalid Choice" << endl;
            }



    }

}

