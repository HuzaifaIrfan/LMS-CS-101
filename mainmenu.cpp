#include<iostream>
#include"adminpanel.cpp"
#include"userpanel.cpp"
using namespace std;








void mainmenu(){

    bool notexit=true;


    while(notexit){
screenclear();

cout<<"\n\t Library Management System \n";


        cout<<"\n\t Main Menu\n\n";
        cout<<"\t1 Login to Admin Panel\n";
        cout<<"\t2 Login to User Panel\n";
        cout<<"\t0 EXIT\n";

        
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
            case '0':
                notexit=false;
                break;
            default:
                exitter("Invalid Choice");
        }

    }

}