#include<iostream>
#include"adminpanel.cpp"
#include"userpanel.cpp"
using namespace std;

void mainmenu(){

    bool notexit=true;


    while(notexit){
        system("clear");
        cout<<"\n\t Main Menu\n\n";
        cout<<"\t1 Login to Admin Panel\n";
        cout<<"\t2 Login to User Panel\n";
        cout<<"\t3 EXIT\n";

        
        char ch;
        cout << "\t " ;
        cin>>ch;

        switch (ch){
            case '1':
                admin_login();
                break;
            case '2':
               user_login();
                break;
            case '3':
                notexit=false;
                break;
            default:
                cout << "Invalid Choice" << endl;
        }

    }

}