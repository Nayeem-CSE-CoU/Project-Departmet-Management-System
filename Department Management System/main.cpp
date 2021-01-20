#include<bits/stdc++.h>
#include<windows.h>
#include "cursorPlace.cpp"
#include "Students.cpp"
using namespace std;
int main()
{
    start();
    int key=1;
    do
    {
        if(key<=4 && key>=1)
        {
        system("color F1");
        cout<<"\n\n\t\t\t\t\t\t\t\t\tDepartment of Computer Science and Engineeing\n";
        for(int i=0;i<197;i++)
            cout<<"-";
        }
       gotoxy(0,15); //Set a position on window to display
       cout<<"\t\t\t\t\t\t\t\t1.Teachers\n";
       cout<<"\t\t\t\t\t\t\t\t2.Students\n";
       cout<<"\t\t\t\t\t\t\t\t3.Staff\n";
       cout<<"\t\t\t\t\t\t\t\t4.Exit\n";
       cout<<"\t\t\t\t\t\t\t\tSelect your choice..";
       cin>>key;
       switch(key)
       {
       case 1:
       //Teachers();
       break;
       case 2:
       Students();
       break;
       case 4:
        exit(0);
       default:
        cout<<"\t\t\t\t\t\t\t\tInvalid choice!\n";

       }
    }
    while(key!=4);
    return 0;
}
