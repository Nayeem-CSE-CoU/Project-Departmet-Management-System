#include<bits/stdc++.h>

using namespace std;
void exit_()
{
    cout<<"\nENTER ANY KEY TO EXIT..."<<endl;
    cin.ignore();
    cin.ignore();
}
void set_screen()
{
    system("cls");
    system("color E1");
    cout<<"\n\n\t\t\t\t\t\t\t\t\tDepartment of Computer Science and Engineeing\n";
    for(int i=0; i<197; i++)
        cout<<"-";
    gotoxy(0,40);
    cout<<"\n\n\t\t\t\t\t\t\t\t\tComilla University\n";
     for(int i=0; i<197; i++)
        cout<<"-";
    gotoxy(0,15);
}
class student
{
public:
    map<string,vector<string> > information,temp;
    map<int,string> maped{{1,"NAME"},{2,"FATHER'S NAME"},{3,"MOTHER'S NAME"},{4,"ADDRESS"},{5,"SESSION"},{6,"CGPA"}};
    map<string,set<string> > session_info;
    string id;
    bool flag=1;
    void new_entry()
    {
        cout<<"ENTER NEW ID :";
        cin>>id;
        information[id].resize(6);
        cin.ignore();
        for(int i=1; i<=6; i++)
            {
                cout<<"ENTER "<<maped[i]<<" : ";
                getline(cin,information[id][i-1]);
            }
        session_info[information[id][4]].insert(id);
        cout<<endl;
    }

    void display()
    {
        cin>>id;
        if(information.find(id)==information.end())
            cout<<"ID "<<id<<" is not found!"<<endl,exit_(),flag=0;
        else
            {


                cout.width(23);
                cout<<"ID";
                for(int i=1; i<=6; i++)
                    cout.width(23),cout<<maped[i];
                cout<<endl;

                cout.width(23);
                cout<<id;
                for(auto j:information[id])
                    cout.width(23),cout<<j;
                cout<<endl;
            }
    }
    void display_all(map<string,vector<string> > info)
    {
        if(info.empty())
            {
                cout<<"There is no data!"<<endl;
                return;
            }
        cout.width(23);
        cout<<"ID";
        for(int i=1; i<=6; i++)
            cout.width(23),cout<<maped[i];
        cout<<endl;

        for(auto i:info)
            {
                cout.width(23);
                cout<<i.first;
                for(auto j:i.second)
                    cout.width(23),cout<<j;
                cout<<endl;
            }
    }
    void session_wise(string str)
    {
        cout<<"\t\t\t\t\t\t\t\tSESSION : "<<str<<endl;
        temp.clear();
        for(auto i:session_info[str])
            {
                temp[i]=information[i];
            }
    }

    void all_result(map<string,vector<string> > info)
    {
        if(info.empty())
            {
                cout<<"There is no data!"<<endl;
                return;
            }
        cout.width(23);
        cout<<"ID";
        for(int i=1; i<=6; i+=(i==1)?4:1)
            cout.width(23),cout<<maped[i];
        cout<<endl;

        for(auto i:info)
            {
                cout.width(23);
                cout<<i.first;
                vector<string> temp;
                temp=i.second;
                for(auto j=0; j<6; j+=(j==0)?4:1)
                    cout.width(23),cout<<temp[j];
                cout<<endl;
            }
    }

    void update()
    {
        flag=1;
        string str;
        cout<<"TO UPDATE ENTER ID : ";
        display();
        if(flag)
            {
                cout<<"UPDATE INFORMATION or PRESS ENTER TO SKIP"<<endl;
                cin.ignore();
                for(int i=1; i<=6; i++)
                    {
                        cout<<maped[i]<<" : ";
                        getline(cin,str);
                        if(!all_of(str.begin(),str.end(),[](auto s)
                        {
                            return isspace(s)
                                       ;
                            }))
                        {

                            if(i-1==4)
                            {
                               stringstream ss(str);
                               str.erase();
                               string word;
                               bool x=1;
                               while(getline(ss,word,'-'))
                               {
                                  str+=word;
                                  x^=1;
                                  if(x==0)
                                    str+='-';
                               }
                               session_info[information[id][i-1]].erase(id);
                               session_info[str].insert(id);
                            }

                            information[id][i-1]=str;

                        }

                    }

            }


    }

    void delete_student()
    {
        cout<<"ID TO WIPE : ";
        cin>>id;
        if(information.find(id)==information.end())
            {
                cout<<"ID "<<id<<" is not found in the database!"<<endl;
                Sleep(2000);
                exit_();
            }
        else
            {
                information.erase(id);
                cout<<"Successfully Deleted!"<<endl;
                Sleep(2000);
            }

    }
    void specific_result()
    {
        cin>>id;
        if(information.find(id)==information.end())
            cout<<"ID "<<id<<" is not found!"<<endl,exit_(),flag=0;
        else
            {
                cout.width(23);
                cout<<"ID";
                for(int i=1; i<=6; i+=(i==1)?4:1)
                    cout.width(23),cout<<maped[i];
                cout<<endl;
                cout.width(23);
                cout<<id;
                for(int i=0; i<6; i+=(i==0)?4:1)
                    cout.width(23),cout<<information[id][i];
                cout<<endl;
                exit_();
            }

    }
    void update_result()
    {
        flag=1;
        string str;
        cout<<"TO UPDATE ENTER ID : ";
        specific_result();
        if(flag)
            {
                cout<<"UPDATE INFORMATION"<<endl;
                cin.ignore();
                cin>>information[id][5];
            }
    }

    student()
    {
        ifstream student_data;
        student_data.open("student data.txt");
        string str;
        while(getline(student_data,str))
            {
                stringstream s(str);
                string word,id,name;
                int i=0;
                while(getline(s,word,'~'))
                    {
                        if(i==0)
                            {
                                id=word;
                                information[id].resize(6);
                            }

                        else
                            information[id][i-1]=word;
                        i++;
                    }
                  session_info[information[id][4]].insert(id);

            }

    }

    ~student()
    {
        ofstream student_data;
        student_data.open("student data.txt");
        for(auto i:information)
            {
                student_data<<i.first;
                for(auto j:i.second)
                    student_data<<'~',student_data<<j;
                student_data<<'\n';
            }
        student_data.close();

    }

};
student ob;

void Session(bool skey)
{
    int key=1;
    do
        {
            if(key<=6 && key>=1)
                {
                    set_screen();
                }
            gotoxy(0,15);
            cout<<"\t\t\t\t\t\t\t\t1.Session: 2019-2020\n";
            cout<<"\t\t\t\t\t\t\t\t2.Session: 2018-2019\n";
            cout<<"\t\t\t\t\t\t\t\t3.Session: 2017-2018\n";
            cout<<"\t\t\t\t\t\t\t\t4.Session: 2016-2017\n";
            cout<<"\t\t\t\t\t\t\t\t5.Session: 2015-2016\n";
            cout<<"\t\t\t\t\t\t\t\t6.Back\n";
            cout<<"\t\t\t\t\t\t\t\tSelect your choice..";
            cin>>key;
            set_screen();
            switch(key)
                {
                case 1:
                    ob.session_wise("2019-2020");
                    if(skey)
                        ob.all_result(ob.temp);
                    else
                        ob.display_all(ob.temp);
                    exit_();
                    break;
                case 2:
                    ob.session_wise("2018-2019");
                    if(skey)
                        ob.all_result(ob.temp);
                    else
                        ob.display_all(ob.temp);
                    exit_();
                    break;
                case 3:
                    ob.session_wise("2017-2018");
                    if(skey)
                        ob.all_result(ob.temp);
                    else
                        ob.display_all(ob.temp);
                    exit_();
                    break;
                case 4:
                    ob.session_wise("2016-2017");
                    if(skey)
                        ob.all_result(ob.temp);
                    else
                        ob.display_all(ob.temp);
                    exit_();
                    break;
                case 5:
                    ob.session_wise("2015-2016");
                    if(skey)
                        ob.all_result(ob.temp);
                    else
                        ob.display_all(ob.temp);
                    exit_();
                    break;
                case 6:
                    system("cls");
                    return;
                default:
                    cout<<"\t\t\t\t\t\t\t\tInvalid choice!\n";
                }
        }
    while(key!=6);
    system("cls");

}
void StudentsResult()
{
    int key=1;

    do
        {
            if(key<=5 && key>=1)
                {
                    set_screen();
                }
            gotoxy(0,15);
            cout<<"\t\t\t\t\t\t\t\t1.All Students Result\n";
            cout<<"\t\t\t\t\t\t\t\t2.Specific Students Result\n";
            cout<<"\t\t\t\t\t\t\t\t3.Result According to Session\n";
            cout<<"\t\t\t\t\t\t\t\t4.Update Result\n";
            cout<<"\t\t\t\t\t\t\t\t5.Back\n";
            cout<<"\t\t\t\t\t\t\t\tSelect your choice..";
            cin>>key;
            set_screen();
            switch(key)
                {
                case 1:
                    ob.all_result(ob.information);
                    exit_();
                    break;
                case 2:
                    cout<<"ENTER SPECIFIC STUDENT ID : "<<endl;
                    ob.specific_result();
                    break;
                case 3:
                    Session(1);
                    break;
                case 4:
                    ob.update_result();
                    break;
                case 5:
                    system("cls");
                    return;
                default:
                    cout<<"\t\t\t\t\t\t\t\tInvalid choice!\n";

                }
        }
    while(key!=5);
    system("cls");
}
void StudentsBio()
{
    int key=1;
    do
        {
            if(key<=6 && key>=1)
                {
                    set_screen();
                }
            gotoxy(0,15);
            cout<<"\t\t\t\t\t\t\t\t1.All Students Bio-Data\n";
            cout<<"\t\t\t\t\t\t\t\t2.Specific Students Bio-Data\n";
            cout<<"\t\t\t\t\t\t\t\t3.Bio-Data According to Session\n";
            cout<<"\t\t\t\t\t\t\t\t4.Update Bio-Data\n";
            cout<<"\t\t\t\t\t\t\t\t5.Delete Student Data\n";
            cout<<"\t\t\t\t\t\t\t\t6.Back\n";
            cout<<"\t\t\t\t\t\t\t\tSelect your choice..";
            cin>>key;
            set_screen();
            switch(key)
                {
                case 1:
                {
                    ob.display_all(ob.information);
                    exit_();
                    break;

                }

                case 2:
                    cout<<"ENTER ID : ";
                    ob.display();
                    exit_();
                    break;
                case 3:
                    Session(0);
                    break;
                case 4:
                    ob.update();
                    break;
                case 5:
                    ob.delete_student();
                    break;
                case 6:
                    system("cls");
                    return;
                default:
                    cout<<"\t\t\t\t\t\t\t\tInvalid choice!\n";

                }
        }
    while(key!=6);
    system("cls");
}

void Students()
{

    int key=1;

    do
        {
            if(key<=4 && key>=1)
                {
                    set_screen();
                }
            //gotoxy(0,15);
            cout<<"\t\t\t\t\t\t\t\t1.Students Bio-Data\n";
            cout<<"\t\t\t\t\t\t\t\t2.Students Result\n";
            cout<<"\t\t\t\t\t\t\t\t3.New Student Entry\n";
            cout<<"\t\t\t\t\t\t\t\t4.Back\n";
            cout<<"\t\t\t\t\t\t\t\tSelect your choice..";
            cin>>key;
            switch(key)
                {
                case 1:
                    StudentsBio();
                    break;
                case 2:
                    StudentsResult();
                    break;
                case 3:
                    ob.new_entry();
                    break;
                case 4:
                    system("cls");
                    return;
                default:
                    cout<<"\t\t\t\t\t\t\t\tInvalid choice!\n";

                }
        }
    while(key!=4);
    system("cls");
}
void start()
{
    gotoxy(80,15);
    system("color F1");
    cout<<"DEPARTMENT MANAGEMENT SYSTEM";
    gotoxy(80,17);
    cout<<"Developed by: FRIDAY SQUAD";
    Sleep(2000);
    system("cls");
}
