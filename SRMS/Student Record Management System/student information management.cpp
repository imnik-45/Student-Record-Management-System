///******************************STUDENT INFORMATION MANAGEMENT************************

#include<iostream>                                              ///for cout,cin
#include<string.h>                                               ///for string Handling
#include<conio.h>                                                /// for getch() funtion
#include<fstream>                                              ///for making Permanent file
#include<stdlib.h>                                               ///for exit and system function
#include<iomanip>                                                ///for setw operations
#include<windows.h>                                           /// for console colour
#include<time.h>                                                 ///for displaying time and seeding value to random
using namespace std;

struct student                                                      ///structure to implement the records
{
public:

int  id;                                                                   ///for storing roll no
int admn_no;                                                       ///for storing admisssion no.
char name[45];                                                   ///for storing name
char Class[45];                                                         ///for storing class
char contact[45];                                                ///for storing contact
char stream[45];                                               ///for storing stream of student
char address[50];                                          ///for storing address
char date[10];                                               ///for storing d_o_b
};
student obj;                                                   ///for accessing structure variable's

int getid()                                                      ///to get roll no
{
int id=0;
ifstream file("student.dat",ios::binary);
student obj;
obj.id=0;
while(file)
{
file.read((char *)&obj,sizeof(obj));
if(file.eof())
break;
id=obj.id;
}
return (id+1);
}

///************************** DATABASE CREATION MODULE *******************************

void readdata()                                                                      ///to take values from user
{
 system("color 4E");
        cout<<"\t\t\t\t\t::ENTER THE RECORDS::\n";
          cout<<"\t\t\t\t\t_____________________\n";
        cin.ignore();
        cout<<"\n\t-ENTER THE NAME->\t\t";
        cin.getline(obj.name,45);
        cout<<"\n\t-ENTER THE ADMISSION N0.->\t";
       cin>>obj.admn_no;
       cin.ignore();
        cout<<"\n\t-ENTER THE CLASS->\t";
       cin.getline(obj.Class,45);
       cout<<"\n\t-ENTER THE STREAM(PCM/B,COMM)->\t";
       cin.getline(obj.stream,45);
       cout<<"\n\t-ENTER THE ADDRESS->\t\t";
       cin.getline(obj.address,50);
       cout<<"\n\t-ENTER THE D_O_B->\t\t";
       cin.getline(obj.date,10);
        cout<<"\n\t-ENTER THE CONTACT->\t";
       cin.getline(obj.contact,45);
       obj.id=getid();
}
void add()                                                                                          ///to add data to file
{
readdata();
ofstream file("student.dat",ios::binary|ios::app);
file.write((char *)&obj,sizeof(obj));
file.close();
}

///************************* DISPLAY DATABASE MODULES ********************************

void display(int a)                                                                              ///to show values in file
{
cout<<" \n\n\t\t\t:: STUDENT RECORD ::";
cout<<"\n\n ROLL"<<setw(10)<<"ADMN NO"<<setw(15)<<"NAME "<<setw(15)<<"CLASS"<<setw(15)<<"STREAM"<<setw(15)<<"ADDRESS"<<setw(15)
       <<"D_O_B"<<setw(14)<<"CONTACT";
}
void display(student obj)                                                                   ///to show values in file
{
cout<<"\n\n"<<obj.id<<setw(10)<<obj.admn_no<<setw(15)<<obj.name<<setw(15)<<obj.Class<<setw(15)<<obj.stream
      <<setw(15)<<obj.address<<setw(16)<<obj.date<<setw(16)<<obj.contact;
}
void display()                                                                                     ///to show values to user
{
system("color 0E");
system("cls");
cout<<" \n\n\t\t\t\t\t :: STUDENT RECORD :: \n\n";
cout<<"\t\t\t\t\t______________________\n";
cout<<"\n\n ROLL"<<setw(10)<<"ADMN NO"<<setw(15)<<"NAME "<<setw(15)<<"CLASS"<<setw(15)<<"STREAM"<<setw(15)<<"ADDRESS"<<setw(15)<<"D_O_B"<<setw(14)<<"CONTACT";
ifstream file("student.dat",ios::binary|ios::in);
while(file)
{
file.read((char *)&obj,sizeof(obj));
if(file.eof())
break;
cout<<"\n\n "<<obj.id<<setw(10)<<obj.admn_no<<setw(18)<<obj.name<<setw(15)<<obj.Class<<setw(15)
      <<setw(15)<<obj.stream<<setw(15)<<obj.address<<setw(16)<<obj.date<<setw(16)<<obj.contact;
}
}

///##############Deleting By Admission Number Module ##################

void delete1()
{
    system("cls");
    system("color 1C");
    cout<<"\n\n\n\t\t::DELETITION MODULE::";
    cout<<"\n\t\t_______________________\n";
    ifstream file("student.dat",ios::binary);
    if(!file)
        {
        cout<<"\n\n\t SORRY! NO DATA CREATED \n\n\t FIRST CREATE RECORD";
        getch();
        return ;
        }
    int found=0;
    char con='n';
int admn_no;
    cout<<"\n\n\t\t-->PLEASE ENTER THE ADMISSION NUMBER....->>";
cin>>admn_no;
ofstream fl("temp.dat",ios::binary|ios::out);
while(file)
{
    file.read((char *)&obj,sizeof(obj));
    if(file.eof())
        break;
    if(admn_no==obj.admn_no)
    {
        found=1;
        cout<<" \n\n\t DO YOU WANT TO DELETE(Y/N)..!!!";
        cin>>con;
        if(con=='n'||con=='N')
            fl.write((char *)&obj,sizeof(obj));
        break;
    }
    else
     fl.write((char *)&obj,sizeof(obj));
}
if(found==1)
{
    while(file)
    {
        file.read((char *)&obj,sizeof(obj));
        if(file.eof())
            break;
        fl.write((char *)&obj,sizeof(obj));
    }
    fl.close();
    file.close();
    remove("student.dat");
    rename("temp.dat","student.dat");
    cout<<"\n\n\t DATA DELETED SUCCESSFULLY...................";
}
else
{
    remove("temp.dat");
    cout<<"DATA NOT FOUND..?????";
}
cout<<" \n\n\n\t PRESS ANY KEY TO CONTINUE..............";
getch();
}

///#####################  Searching Module ######################

///####################Searching by Admission number Module ###########

void search_admn_no()
{
student obj;
int admn_no;
cout<<" \n\n\t->PLEASE ENTER THE ADMISSION NUMBER.....->>\t\t";
cin>>admn_no;
display(1);
int f=0;
ifstream file("student.dat");
while(file)
{
    file.read((char *)&obj,sizeof(obj));
    if(file.eof())
        break;
    if(obj.admn_no==admn_no)
    {
       f=1;
        cout<<endl;
        display(obj);
        break;
    }
}
if(f==0)
    cout<<"\n\n\n SORRY! NO DATA FOUND";

}

///########################## Search By Name Module########################

void search_name()
{
student obj;
char name[45];
cin.ignore();
cout<<" \n\n\t->PLEASE ENTER THE NAME.......->>\t ";
cin.getline(name,45);
int f=0;
display(1);
ifstream file("student.dat",ios::binary);
while(file)
{
    file.read((char *)&obj,sizeof(obj));
    if(file.eof())
        break;
    if(strcmpi(name,obj.name)==0)
    {
        f=1;
            cout<<endl;
        display(obj);
}
}
if(f==0)
    cout<<"\n\n\n SORRY! NO DATA FOUND....?????";
}

///############### Search By Class Module #############################

void search_Class()
{
student obj;
char Class[45];
cin.ignore();
cout<<" \n\n\t PLEASE ENTER THE CLASS...->>\t";
cin.getline(Class,45);
int f=0;
display(1);
ifstream file("student.dat",ios::binary);
while(file)
{
    file.read((char *)&obj,sizeof(obj));
    if(file.eof())
        break;
    if(strcmpi(Class,obj.Class)==0)
    {
        f=1;
        cout<<endl;
        display(obj);
    }
}
if(f==0)
    cout<<"\n\n\n SORRY! NO DATA FOUND....????";
}

///###################### Main Search Menu Program ##################

void search()
{
system("cls");
cout<<" \n\n\t\t :::::SEARCHING RECORD:::::";
  cout<<"\n\t\t_____________________________\n";
char i='0';
while(i!='4')
{
    cout<<"\n\n\n";

    cout<<"\n\n\t 1->SEARCH BY ADMISSION_NO";
    cout<<"\n\n\t 2->SEARCH BY NAME ";
    cout<<"\n\n\t 3->SEARCH BY CLASS";
    cout<<"\n\n\t 4->EXIT ";
    cout<<"\n\n\t\tENTER YOUR CHOICE-->\t";
    cin>>i;
    switch(i)
    {
    case '1':
     search_admn_no();
        break;
    case '2':
       search_name();
        break;
    case '3':
      search_Class();
        break;
    case '4':
        break;
    default:
            cout<<"\n\n\t\tWRONG CHOICE TRY AGAIN\n\n\t\t PRESS ANY KEY TO CONTINUE.....!!!!";
            getch();
}
}
cout<<"\n\n\t PRESS ANY KEY TO CONTINUE..............!!!";
getch();
}

///################ Update Module #######################

void update()
{
    student obj;
    int id,f=0;
    char con='n';
    system("cls");
    system("color 4E");
    cout<<"\n\t\t\t :::::UPDATATION MODULE:::::";
    cout<<"\n\t\t\t_____________________________\n";
    cout<<"\n\n\t\t\->ADMISSION NUMBER AND D_O_B CANNOT BE CHANGED.....\n\n";
    cout<<"\n\n\n\t-->ENTER THE ID =>\t ";
    cin>>id;
    fstream file("student.dat",ios::binary|ios::in|ios::out);
    int sp=0;
    while(file)
    {
        sp=file.tellg();
        file.read((char *)& obj,sizeof(obj));
        if(obj.id==id)
            {
            f=1;
        break;
            }
    }
if(f==1)
{
        cin.ignore();
       cout<<"\n\t-ENTER THE NAME...->\t";
       cin.getline(obj.name,45);
       cout<<"\n\t-ENTER THE CLASS->\t\t";
       cin.getline(obj.Class,45);
       cout<<"\n\t-ENTER THE STREAM(PCM/PCB/COMM../ARTS)->";
       cin.getline(obj.stream,45);
       cout<<"\n\t-ENTER THE ADDRESS->\t\t";
       cin.getline(obj.address,50);
       cout<<"\n\t-ENTER THE CONTACT->\t";
       cin.getline(obj.contact,45);

    file.seekg(sp);
    file.write((char *)&obj,sizeof(obj));
    cout<<"\n\n\t DATA UPDATED SUCESSFULLY......!!!!!!!!";
}
else
cout<<"\n\n\t NO SUCH RECORD FOUND...??????";
cout<<"\n\n\t PRESS ANY KEY TO CONTINUE.............";
getch();
}

///#################### About Us Function ################

void about_us()
{
system("color 4D ");
cout<<"\t\t\t\t\t~~~ABOUT US~~~\n";
cout<<"\t\t\t__________________________________________\n";
cout<<"\n\t*> NAME-STUDENT INFORMATION MANAGEMENT";
cout<<"\n\n\t*> SESSION-2015-2016";
cout<<"\n\n\t*> VERSION: S1";
cout<<"\n\n\t*> AUTHOR: NIKHIL SINGH";
cout<<"\n\n\t*> COURTSEY: SIR VIKAS SIRVATAVA";
cout<<"\n\n\t*> SCHOOL: LITTLE FLOWER SCHOOL";
cout<<"\n--------------------------------------------------------------------------------------------\n";
cout<<"\n\t\t\t~DEVELOPER OF THE PROGRAM~\n";
cout<<"\t\t\t__________________________\n";
cout<<"\n\t\t\t*>NIKHIL SINGH -PROJECT & PROGRAMMING LEADER";
cout<<"\n\t\t\t*>AMIT KUMAR SINGH-SENIOR-DEVELOPER";
cout<<"\n\t\t\t*>ABHISHIEK PANDEY-TECH-SUPPORT";
cout<<"\n____________________________________________________________________________________________";
cout<<"\n\t\t\t*>COURTESY & SPECIAL THANKS TO :- SIR VIKAS SIRVASTAVA";
cout<<"\n____________________________________________________________________________________________";
cout<<"\n\n\t\t\t*>SOFT-COPY AVAILABLE UNDER:- SIR VIKAS & DEVELPOPERS";
cout<<"\n\n\t\t\t*>LITTLE FLOWER SCHOOL,GIDA";
cout<<"\n____________________________________________________________________________________________";
}
///************************************** MAIN FUNCTION*************************************
int main()
{
time_t tim;
time(&tim);
char i;
while(i!='6')
{
        system("cls");
         system("color 1D ");
        cout<<"\t\t\t\t________________________\n\n";
         cout<<"\t\t\t\t   "<<ctime(&tim);
        cout<<"\t\t\t_____________________________________________\n\n";
        cout<<"\t\t\t\t:: STUDENT INFORMATION MANAGEMENT ::\n\n";
        cout<<"\t\t\t_____________________________________________\n";
        cout<<"\n\n\t\t 1-> TO CREATE STUDENTS  RECORD";
        cout<<"\n\n\t\t 2-> TO DISPLAY STUDENTS RECORD";
        cout<<"\n\n\t\t 3-> TO SEARCH STUDENTS RECORD";
        cout<<"\n\n\t\t 4-> TO UPDATE STUDENTS RECORD";
        cout<<"\n\n\t\t 5-> TO DELETE STUDENTS RECORD";
        cout<<"\n\n\t\t 6-> ABOUT US";
        cout<<"\n\n\t\t 7-> TO EXIT FROM MODULE";
        cout<<"\n\n\t\t____________________________________\n";
        cout<<"\n\n\t\t --> ENTER YOUR CHOICE=";
        cin>>i;
        system("cls");
        switch(i)
        {
          case '1':
            add();

            break;

        case '2':
            display();
            getch();
            break;

        case '3':
        search();
            break;

        case '4':
            update();
            break;

              case '5':
        delete1();
            break;

           case '6':
           about_us();
           break;

           case '7':
            exit(0);
            break;
            default:
            cout<<"\n\n\t\t\t Wrong choice Try Again!! \n\n\t\t Press Any key to continue.....";
            getch();
} }  }
