#include<conio.h>
#include<process.h>
#include<string.h>
#include<fstream.h>
#include<stdio.h>
#include<dos.h>
#include<time.h>
/*--------------------------------  files used ----------------------------------*/ 
fstream blist,mlist,issfile; 
/*----------------------------------- STRUCTURES -----------------------------------*/ 
  struct udat
  {
	  int day;
	  int mon;
	  int year;
  };
  struct bdata
  {
	  int  bcode;
	  char bname [50];
	  char auth [50];
	  char publ [50];
	  int price;
	  int copies;
  }book;

struct mdata
 { 
int  mcode      ;
char mname [20] ;
int  std        ;
char contact[15]; }member;
struct issdet
{ 
int  mcode      ;
char mname [20] ;  
int  mbcode     ; 
udat issue      ; 
udat retdat     ;
 }
idet;
 struct Chemical
{ 
 int  Sno       ;  
int  Nos       ;  
int  Vol       ;  
int  Conc      ;
 char Name [30] ;
 char DOE  [30] ;
 }chem;
struct system
{
  int  no        ;
  int  mry       ; 
 int  ram       ;          
 char prcs [30] ; 
char os   [30] ; 
 char cmpy [30] ; 
 long cost      ; }
pc;
struct Instruments
{
 int  Sno           ;
 int  numb_inst     ;
 int  cost          ; 
 char type     [30] ;  char name_inst[30] ;  
char company  [30] ; }Inst;
struct Specimen
{
  int  cost         ;   int  number       ;   int  Sno          ;
  char cname   [50] ;     
 char type    [30] ;   
char sname   [50] ;   
char DOE     [20] ; 
}spec;
struct member
{   int  pcode        ;
  char pname   [40] ;
  long fine         ;
}pm;
 /*------------------------------- function prototypes ---------------------------------*/ void welcome   (); void interface (); void password  (); void library   (); void labs      ();
/*----------------------------basic info for student -----------------------------*/ class basic
{ public :
char name[80]; char dob[15]; char father_name[80]; char mother_name[80]; char address[80]; char contact[15]; char religion[20]; char nationalty[20]; char language[50]; char current_stat[10]; int  pday,pmonth,pyear; // date on when fee was paid..
void getvalues1();
};
/*-----------------------------adv info for student --------------------------------*/ class advstu : public basic
{ public :  
 int admin_no;   
int std;   
char fee_stat[20];   
void getvalues2();
}s1;
/*------------------------------------bassic info for teacher -----------------------------------------*/ class advteach : public basic
{ public : 
int staff_no; 
char salary_stat[30]; 
void getvalues3();
}t1;
/*-------------------------  class menu for library  --------------------------*/
class libmenu
{   public:
int  day, mon, year;
void duedate   (int,int,int) ; void updatecopies  (int,int) ;
void mainmenu  ();
void issue     ();
void returnbook(); void memopt(); void mdetails(); void memlist(); void issuedet(); void bookopt(); void booklist(); void addbooks(); void writebook(); void bdetails(); void bmodify();
}libr;
/*-------------------------- class for office -----------------------------*/ class office_function
{ public:
           void display_adv_student(); void display_basic_student(); void display_basic_teacher(); void display_adv_teacher(); void modify_student();
           void add_student ();
           void modify_teacher();
               void add_teacher();
             void display_student(); 
             void display_teacher();
              int size_student(); 
             int size_teacher(); 
            void display_all_students(); void fee();
           void fee_check();
void pay_fee(int); 
void credict_salary(int); void salary_check();
 void salary();
void display_all_teachers(); void menu_student(); 
 void menu_teacher();
void menu_main();
}ff;
/*---------------------------date for officee------------------------------*/
time_t theTime = time(NULL);
struct tm *aTime = localtime(&theTime);
int day = aTime->tm_mday;
int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
int year = aTime->tm_year + 1900;  // Year is # years since 1900
/*---------------------------- FEE for student -------------------------------*/ class feedate  { public: int day,month,year ;
 }f;
/*----------------------- Lab Files ---------------------------*/ void phylab(); void chemlab(); void complab(); void biolab();
/*-------------------------------
 CLASS FOR LABORATORY -----------------------------------*/
class Working
{ public:
    void broken()               ;
 int sizeof_chem()           ; 
void Add_Chemical()         ; 
void Available_chemicals()  ; 
void Show_chemical_detail() ; 
void Modify_Chemical()      ; 
int sizeof_system()         ; 
void Add_system()           ; 
void System_present()       ;
 void Show_system_detail()   ;
 void Modify_system()        ;
 int sizeof_inst(int)        ;
 void Add_inst(int)          ;
 void Show_inst(int)         ;
int sizeof_spec()          ;
void Add_spec()             ; 
void Available_specimen()   ; 
void Show_spec_details()    ;
void Modify_specimen()      ;
}W;
/*-------------------------------  function for welcome screen   --------------------------------*/ void welcome()
{  clrscr();
 cout<<"\n";
 cout<<"\t\t  ******************************************\n";  cout<<"\t\t  **   S C H O O L  M A N A G E M E N T   **\n";  cout<<"\t\t  ******************************************\n";  gotoxy(3,24);

 cout<<"WELCOME TO ROSEMARY PUBLIC SCHOOL";  gotoxy(16,10);
 cout<<"THIS GUIDES  TO  INFORMATION  ACCESS  REGARDING";  gotoxy(16,12);
 cout<<"ADMINISTRATION,LIBRARY AND LABORATORY MANGEMENT";  gotoxy(20,14);
 cout<<"THIS CAN ACCESED ONLY BY ADMINISTRATORS";  gotoxy(24,19);  password(); }
/*----------------  function for password   -------------------*/
void password()
 {
  char inpass[5];   cout<<"Enter password : ";   for(int i=0;i<4;i++)
  {
 inpass[i]= (char)getch();  cout<<"*";
  }
  if(inpass[0]=='r'&& inpass[1]=='m'&& inpass[2]=='p'&& inpass[3]=='s')
  {
clrscr();
interface();
  }
  else
  {
clrscr();
gotoxy(28,11);
cout<<"ACCESS DENIED!!!";
getch();
exit(1);
  }
 }
/*--------------  main menu -----------------*/
void interface() {
 clrscr();
 cout<<"\n\n\n";
 cout<<"\t\t\t        M  E  N  U             \n";  cout<<"\t\t\t       ~~~~~~~~~~~~\n";  gotoxy(5,24);
 cout<<"SELECT YOUR CHOICE";
 cout<<"\t\t\t\t\t\t < 0 > for EXIT ";  gotoxy(25,10);  cout<<"1. O F F I C E ";  gotoxy(25,12);  cout<<"2. L I B R A R Y ";  gotoxy(25,14);  cout<<"3. L A B O R A T O R Y";  int ms;  gotoxy(30,18);  cout<<"Enter your choice: ";  cin>>ms;  switch (ms)
 {
case 1 :
ff.menu_main();  break; case 2 :  library();  break; case 3 :   labs();  break; case 0 :  welcome();  break; default:  gotoxy(30,19);
 cout<<"WRONG CHOICE";
  }
 }
/*-----------------------------------  office main menu -------------------------------------*/
void office_function:: menu_main()
{   int ch;   clrscr();   while(1) {   clrscr();
  cout<<"\n\n\n";
  cout<<"\t\t      WELCOME TO ROSE MARY PUBLIC SCHOOL             \n";
  cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
  cout<<"\t\t                ADMINISTRATION                 \n";   cout<<"\t\t               ~~~~~~~~~~~~~~~~~~~~~             ";   gotoxy(33,12);
  cout<<"1. STUDENT INFO";
  gotoxy(33,14);
  cout<<"2. TEACHER INFO";
  gotoxy(33,16);   cout<<"0. EXIT";   gotoxy(30,20);   cout<<"Enter the choice : ";   cin>>ch;   clrscr();
  switch(ch)
  {
case 1:
menu_student(); break; case 2:
menu_teacher(); break; case 0:
interface();
  }
  getch();
}
}
/*----------------------------------- size of student --------------------------------------*/ 
int office_function ::  size_student()
{ int no; int pos; int size; fstream out;
out.open("DATA.dat",ios::in|ios::out); out.seekg(0,ios::end); pos=out.tellp(); size=sizeof(s1); no=pos/size; no++; out.close();
return no;
}
/*---------------------------------
student menu -----------------------------------*/ void office_function:: menu_student() {   int ch;   while(1)
  {
 clrscr();
 cout<<"\n\n\n";
 cout<<"\t\t\t      S T U D E N T  I N F O             \n";  cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 gotoxy(30,8);
 cout<<"1. ENROLL A STUDENT";
 gotoxy(30,10);
 cout<<"2. DISPLAY A STUDENT ";  gotoxy(30,12);  cout<<"3. MODIFY ";  gotoxy(30,14);  cout<<"4. FEE DETAILS ";  gotoxy(30,16);  cout<<"0. EXIT";
 gotoxy(25,20);
 cout<<"ENTER YOUR CHOICE : ";
 //textbackground(WHITE);  //textcolor(CYAN+BLINK);
 cin>>ch;
 switch(ch)
 {
  case 1:
	s1.getvalues2();
	break;
  case 2:
	display_student();
	break;
  case 3:
	modify_student();
	break;
  case 4:
	fee();
	break;
  case 0:
 menu_main();
 }
 getch();
  }
}
/*---------------------------------get student data -----------------------------------*/ void basic:: getvalues1()
{
clrscr(); pday=0; pmonth=0; pyear=0;
cout<<"\n\t\t      E N T E R   I N F O R M A T I O N             "; cout<<"\n\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(10,24);
cout<<"PLEASE ENTER THE DETAILS ONLY IN CAPTIAL LETTERS";
gotoxy(25,5); cout<<"NAME           : "; gotoxy(25,6); cout<<"DATE OF BIRTH  : "; gotoxy(25,7); cout<<"FATHER NAME    : "; gotoxy(25,8); cout<<"MOTHER NAME    : "; gotoxy(25,9); cout<<"ADDRESS        : "; gotoxy(25,10); cout<<"CONTACT        : "; gotoxy(25,11); cout<<"RELIGION       : "; gotoxy(25,12); cout<<"NATIONALITY     : "; gotoxy(25,13); cout<<"LANGUAGE       : "; gotoxy(25,14); cout<<"STATUS(IN/OUT) : "; gotoxy(43,5); gets(name); gotoxy(43,6); gets(dob); gotoxy(43,7); gets(father_name); gotoxy(43,8); gets(mother_name); gotoxy(43,9);
gets(address); gotoxy(43,10); gets(contact); gotoxy(43,11); gets(religion); gotoxy(43,12); gets(nationalty); gotoxy(43,13); gets(language); gotoxy(43,14); gets(current_stat);
}
/*---------------------------------get adv student data -----------------------------------*/ void advstu ::getvalues2()
{   getvalues1();   gotoxy(25,15);   cout<<"CLASS          : ";   gotoxy(25,16);   cout<<"FEE STATUS     : ";   gotoxy(25,17);   cout<<"(PAID/NOT PAID)  ";   gotoxy(43,15);   cin>>std;   gotoxy(43,16);
  gets(fee_stat);   ff.add_student();
}
/*---------------------------------------add student
--------------------------------------------*/ void office_function:: add_student()
{ clrscr(); char ch;
cout<<"\n\n";
cout<<"\t\t\t      A D M I S S I O N                        \n"; cout<<"\t\t\t    ~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(20,10);
cout<<"DO YOU WANT TO SAVE THIS RECORD (Y/N) : "; cin>>ch;
if(ch=='y'||ch=='Y')
{ gotoxy(20,12);
cout<<"PLEASE NOTE DOWN THE ADMISSION NO .. ";
s1.admin_no=size_student(); cout<<"\n\n\t\t\t\t"<<s1.admin_no; ofstream out;
out.open("data.dat",ios::app,ios::out); out.write((char*)&s1,sizeof(s1)); out.close();
//lib.
ofstream mlist; member.mcode=s1.admin_no; strcpy(member.mname,s1.name); member.std=s1.std; strcpy(member.contact,s1.contact); mlist.open("memlist.dat",ios::app|ios::out); mlist.write((char*)&member,sizeof(member)); mlist.close();
  // lab
  ofstream plist;
  pm.pcode=s1.admin_no; strcpy(pm.pname,s1.name); pm.fine=0;
plist.open("member.dat",ios::app|ios::out); plist.write((char*)&pm,sizeof(pm)); plist.close();
  }
  else
  {
 menu_main();
  }
};
/*---------------------------------------- display menu - student --------------------------------------------*/
void office_function:: display_student()
{ int ch1;
clrscr();
cout<<"\n\n\n";
cout<<"\t\t\t    S T U D E N T  D I S P L A Y             \n"; cout<<"\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(30,8);
cout<<"1.BASIC INFORMATION  ";
gotoxy(30,10);
cout<<"2.ADVANCE INFORMATION  ";
gotoxy(30,12); cout<<"3.DISPLAY ALL";
gotoxy(30,14); cout<<"0.EXIT"; gotoxy(25,18); cout<<"Enter the choice : "; cin>>ch1; clrscr(); switch(ch1)
{ case 1: display_basic_student(); break; case 2: display_adv_student(); break; case 3: display_all_students(); break;
case 0:
welcome();
}
}
/*---------------------------------------display student --------------------------------------------*/
void office_function ::  display_basic_student()
{  clrscr(); int rn;
cout<<"\n\n\n";
cout<<"\t\t\t      S T U D E N T  I N F O             \n"; cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(30,8);
cout<<"ENTER THE ADMIN NO : "; cin>>rn; clrscr();
cout<<"\n\n\n";
cout<<"\t\t\t      S T U D E N T  I N F O             \n"; cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~\n"; ifstream in; in.open("data.dat"); in.seekg(0); while(!in.eof())
{ in.read((char*)&s1,sizeof(s1)); if(s1.admin_no==rn)
	{	gotoxy(30,8);
cout<<"Admin no      : "<<s1.admin_no; gotoxy(30,10);
cout<<"Name          : "<<s1.name; gotoxy(30,12);
cout<<"Date of birth : "<<s1.dob; break;
}
}   if(getche())
  {
 display_student();
  }
}
/*---------------------------------------display student --------------------------------------------*/ void office_function:: display_adv_student()
{ int rn;
cout<<"\n\n\n";
cout<<"\t\t\t      S T U D E N T  I N F O             \n"; cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(30,8);
cout<<"ENTER THE ADMIN NO : "; cin>>rn; clrscr();
cout<<"\n\n\n";
cout<<"\t\t\t      S T U D E N T  I N F O             \n"; cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~\n"; ifstream in; in.open("data.dat"); in.seekg(0); while(!in.eof())
{ in.read((char*)&s1,sizeof(s1));
if(s1.admin_no==rn)
{ gotoxy(30,8);
cout<<"ADMIN NO       : "<<s1.admin_no; gotoxy(30,9);
cout<<"NAME           : "<<s1.name; gotoxy(30,10);
cout<<"DATE OF BIRTH  : "<<s1.dob; gotoxy(30,11);
cout<<"FATHER NAME    : "<<s1.father_name; gotoxy(30,12);
cout<<"MOTHER NAME    : "<<s1.mother_name; gotoxy(30,13);
cout<<"ADDRESS        : "<<s1.address; gotoxy(30,14);
cout<<"CONTACT        : "<<s1.contact; gotoxy(30,15);
cout<<"NATIONALITY     : "<<s1.nationalty; gotoxy(30,16);
cout<<"LANGUAGE       : "<<s1.language; gotoxy(30,17);
cout<<"FEE STATUS     : "<<s1.fee_stat; gotoxy(30,18);
cout<<"FEE PAID ON    : "<<s1.pday<<" "<<s1.pmonth<<" "<<s1.pyear; break;
} getch();
}
if(getche())
{
 display_student();
}
}
/*---------------------------------------display all student
--------------------------------------------*/ void office_function:: display_all_students()
{ int x=8;
clrscr();
cout<<"\n\n\n";
cout<<"\t\t\t      S T U D E N T  I N F O             \n"; cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~\n";
cout<<"\n------------------------------------------------------------------------------";
cout<<"\n    ADMIN            STUDENT NAME               CONTACT                               FEE STATUS   ";
cout<<"--------------------------------------------------------------------------------"; fstream file;
file.open("data.dat",ios::out|ios::in); while(1)
{ file.read((char*)&s1,sizeof(s1)); if(file.eof()) break;
for(int i=0;i<100;i++)
{
if(s1.admin_no==i) {  x=x+2;
gotoxy(7,x); cout<<s1.admin_no; gotoxy(22,x); cout<<s1.name; gotoxy(48,x); cout<<s1.contact; gotoxy(70,x); cout<<s1.fee_stat;
}
}
} file.close(); getch();
}
/*----------------------------------------modify student------------------------------------------*/
void office_function:: modify_student()
{  char newname[80],newfather[80],newmother[80],newaddress[120],newdob[12],newcontact[10];
clrscr(); cout<<"\n\n\n";
cout<<"\t\t\t    M O D I F Y  S T U D E N T               \n"; cout<<"\t\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; fstream fio("DATA.dat",ios::in|ios::out|ios::binary); int rn;
cout<<"\tENTER THE ADMIN NO : "; cin>>rn; gotoxy(20,24);
cout<<" < . > to retain the values "; while(!fio.eof())
{ 	fio.read((char*)&s1,sizeof(s1)); if(s1.admin_no==rn)
{ gotoxy(10,8);
cout<<"ADMIN NO      : "<<s1.admin_no; gotoxy(10,9);
cout<<"NAME          : "<<s1.name;
gotoxy(10,10);
cout<<"DATE OF BIRTH : "<<s1.dob;
gotoxy(10,11);
cout<<"FATHER NAME   : "<<s1.father_name; gotoxy(10,12);
cout<<"MOTHER NAME   : "<<s1.mother_name; gotoxy(10,13);
cout<<"ADDRESS       : "<<s1.address; gotoxy(10,14);
cout<<"CONTACT       : "<<s1.contact; gotoxy(10,15);
cout<<"NATIONALITY    : "<<s1.nationalty; gotoxy(10,16);
cout<<"LANGUAGE      : "<<s1.language;
gotoxy(50,9); gets(newname); gotoxy(50,10); gets(newfather); gotoxy(50,11); gets(newmother); gotoxy(50,12); gets(newaddress); gotoxy(50,13); gets(newcontact);
if(strcmp(newname,".")!=0)
{
strcpy(s1.name,newname);
}
if(strcmp(newfather,".")!=0)
{ strcpy(s1.father_name,newfather);
}
if(strcmp(newmother,".")!=0)
{
strcpy(s1.mother_name,newmother);
}
if(strcmp(newaddress,".")!=0)
{
strcpy(s1.address,newaddress);
}
if(strcmp(newcontact,".")!=0)
{ strcpy(s1.contact,newcontact);
} char ch; gotoxy(10,20);
cout<<"Want to Apply the Changes (y/n)"; cin>>ch; if(ch=='y'||ch=='Y')
{
fio.seekp(fio.tellg() - sizeof(s1)); fio.write((char*)&s1,sizeof(s1)); fio.close();
gotoxy(10,21);
cout<<"MODIFIED";
break; }
 } } getch(); }
/*----------------------------------  teacher menu -------------------------------------*/
void office_function:: menu_teacher()
{  int ch;  while(1)
 {
clrscr();
cout<<"\n\n\n";
cout<<"\t\t\t      T E A C H E R   I N F O             \n"; cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(30,8);
cout<<"1. ENROLL A TEACHER";
gotoxy(30,10); cout<<"2. DISPLAY A TEACHER"; gotoxy(30,12); cout<<"3. MODIFY "; gotoxy(30,14); cout<<"4. SALARY STATUS"; gotoxy(30,16); cout<<"0. EXIT";
gotoxy(25,20);
cout<<"ENTER YOUR CHOICE : "; cin>>ch; switch(ch)
{  case 1: t1.getvalues3(); break;
case 2:   display_teacher();   break; case 3:   modify_teacher();   break; case 4:   salary();   break; case 0:
 menu_main();
  }
  getch();
 }
}
/*---------------------------------------size of techer --------------------------------------------*/ int  office_function::size_teacher()
{ int no; int pos; int size; fstream out;
out.open("DATA1.dat",ios::in|ios::out); out.seekg(0,ios::end); pos=out.tellp(); size=sizeof(t1); no=pos/size; no++; out.close();
return no;
}
/*---------------------------------------get info techer --------------------------------------------*/ void advteach::getvalues3()
{ getvalues1(); gotoxy(25,15); cout<<"Salary Details : "; gotoxy(25,17);
cout<<"(CREDICTED/NOT CREDICTED)  ";
gotoxy(41,15); gets(salary_stat); ff.add_teacher();
}
/*---------------------------------------add teacher--------------------------------------------*/
void office_function:: add_teacher()
{  char ch; clrscr();
cout<<"\n\n";
cout<<"\t\t\t      A D M I S S I O N                        \n"; cout<<"\t\t\t    ~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(20,10);
cout<<"DO YOU WANT TO SAVE THIS RECORD (Y/N) : "; cin>>ch;; if(ch=='y'||ch=='Y')
{ gotoxy(20,12);
cout<<"PLEASE NOTE DOWN YOUR STAFF NO ...";
t1.staff_no=size_teacher(); cout<<"\n\n\t\t\t\t"<<t1.staff_no; ofstream out;
out.open("data1.dat",ios::app); out.write((char*)&t1,sizeof(t1)); out.close();
} else {
getch(); menu_main();
}
}
/*-----------------------------------DISPLAY MENU-------------------------------------*/
void office_function:: display_teacher()
{ int ch1;
clrscr();
cout<<"\n\n\n";
cout<<"\t\t\t    T E A C H E R  D I S P L A Y             \n"; cout<<"\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(30,8);
cout<<"1.BASIC INFORMATION  ";
gotoxy(30,10);
cout<<"2.ADVANCE INFORMATION  ";
gotoxy(30,12); cout<<"3.DISPLAY ALL";
gotoxy(30,14); cout<<"0.EXIT :"; gotoxy(25,18); cout<<"Enter the choice : "; cin>>ch1; clrscr(); switch(ch1)
{ case 1: display_basic_teacher(); break; case 2: display_adv_teacher(); break; case 3:
display_all_teachers(); case 0:
welcome();
}
}
/*---------------------------------------display teacher --------------------------------------------*/
void office_function:: display_basic_teacher()
{  clrscr(); int rn;
cout<<"\n\n\n";
cout<<"\t\t\t      T E A C H E R  I N F O             \n"; cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(30,8);
cout<<"Enter the STAFF NO to be searched : "; cin>>rn;
clrscr();
cout<<"\n\n\n";
cout<<"\t\t\t      T E A C H E R  I N F O             \n"; cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~\n"; ifstream in; in.open("data1.dat"); in.seekg(0); while(!in.eof())
{ in.read((char*)&t1,sizeof(t1)); if(t1.staff_no==rn)
	{	gotoxy(30,8);
cout<<"STAFF NO      : "<<t1.staff_no; gotoxy(30,9);
cout<<"NAME          : "<<t1.name; gotoxy(30,10);
cout<<"DATE OF BIRTH : "<<t1.dob; break;
}  getch();
};
}
/*---------------------------------------display of techer --------------------------------------------*/ void office_function:: display_adv_teacher()
{ 	int rn;
cout<<"\n\n\n";
cout<<"\t\t\t      T E A C H E R  I N F O             \n"; cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(30,8);
cout<<"Enter the admin no to be searched : "; cin>>rn; clrscr();
cout<<"\n\n\n";
cout<<"\t\t\t      T E A C H E R  I N F O             \n"; cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~\n"; ifstream in; in.open("data1.dat"); in.seekg(0); while(!in.eof())
{ in.read((char*)&t1,sizeof(t1)); if(t1.staff_no==rn)
{ gotoxy(30,8);
cout<<"STAFF NO      : "<<t1.staff_no; gotoxy(30,9);
cout<<"NAME          : "<<t1.name; gotoxy(30,10);
cout<<"DATE OF BIRTH : "<<t1.dob; gotoxy(30,11);
cout<<"FATHER NAME   : "<<t1.father_name; gotoxy(30,12);
cout<<"MOTHER NAME   : "<<t1.mother_name; gotoxy(30,13);
cout<<"ADDRESS       : "<<t1.address;
gotoxy(30,14);
cout<<"CONTACT       : "<<t1.contact; gotoxy(30,15);
cout<<"NATIONALITY    : "<<t1.nationalty; gotoxy(30,16);
cout<<"LANGUAGE      : "<<t1.language; gotoxy(30,17);
cout<<"SALARY STATUS :"<<t1.salary_stat; gotoxy(30,18); cout<<"SALARY ";
gotoxy(30,19);
cout<<"CREDICTED ON ";
gotoxy(46,19);
cout<<t1.pday<<" "<<t1.pmonth<<" "<<t1.pyear; break;
} getch();
};
}
/*---------------------------------------display all teacher --------------------------------------------*/ void office_function:: display_all_teachers()
{ int x= 10;
clrscr();
cout<<"\n\n\n";
cout<<"\t\t\t       T E A C H E R  I N F O             \n";
cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~\n";
cout<<"\n-------------------------------------------------------------------------------";
cout<<"\n    ADMIN            TEACHER NAME              CONTACTSALARY STATUS   ";
cout<<"--------------------------------------------------------------------------------"; fstream file;
file.open("data1.dat",ios::out|ios::in); while(1)
{ file.read((char*)&t1,sizeof(s1)); if(file.eof()) break;
for(int i=0;i<100;i++)
{
if(t1.staff_no==i) {  x=x+2;
gotoxy(7,x); cout<<t1.staff_no; gotoxy(22,x); cout<<t1.name; gotoxy(48,x); cout<<t1.contact; gotoxy(70,x); cout<<t1.salary_stat;
}
}
} file.close();
getch();
}
/*-------------------------------
 MODIFY TEACHER
-----------------------------------*/
void office_function:: modify_teacher()
{  char 
newname[80],newfather[80],newmother[80],newaddress[120],newdob[12],newcontact[10];
clrscr();
fstream fio("DATA1.dat",ios::in|ios::out|ios::binary); int rn,pos;
gotoxy(30,5);
cout<<"ENTER THE ADMIN NO : "; cin>>rn; clrscr(); while(!fio.eof())
{
fio.read((char*)&t1,sizeof(t1)); if(t1.staff_no==rn) { gotoxy(10,5); cout<<"ADMIN NO : "<<t1.staff_no; gotoxy(10,6); cout<<"NAME : "<<t1.name; gotoxy(10,7);
cout<<"DATE OF BIRTH : "<<t1.dob;
gotoxy(10,8);
cout<<"FATHER NAME : "<<t1.father_name;
gotoxy(10,9);
cout<<"MOTHER NAME : "<<t1.mother_name; gotoxy(10,10); cout<<"ADDRESS : "<<t1.address; gotoxy(10,11); cout<<"CONTACT : "<<t1.contact; gotoxy(10,13);
cout<<"LANGUAGE : "<<t1.language;
gotoxy(50,6); cin>>newname; gotoxy(50,8); cin>>newfather; gotoxy(50,9); cin>>newmother; gotoxy(50,10); cin>>newaddress; gotoxy(50,11); cin>>newcontact;
if(strcmp(newname,".")!=0)
{
strcpy(t1.name,newname);
}
if(strcmp(newfather,".")!=0)
{ strcpy(t1.father_name,newfather);
}
if(strcmp(newmother,".")!=0)
{
strcpy(t1.mother_name,newmother);
}
if(strcmp(newaddress,".")!=0)
{ strcpy(t1.address,newaddress);
}
if(strcmp(newcontact,".")!=0)
{ strcpy(t1.contact,newcontact);
}
 }
char ch; clrscr();
gotoxy(10,13);
cout<<"WANNA APPLY THE CHANGES (y/n)";
cin>>ch; if(ch=='y'||ch=='Y')
{
fio.seekp(fio.tellg() - sizeof(t1)); fio.write((char*)&t1,sizeof(t1)); fio.close(); gotoxy(10,15); cout<<"MODIFIED";
break; } else
{ break;
} } getch(); }
void office_function:: salary()
{  //int feedate,feemonth,feeyear;
clrscr();
int ch,rn;
gotoxy(30,5); cout<<"1.)SET SALARY  DATE  ";
gotoxy(30,6); cout<<"2.)PAY SALARY "; gotoxy(30,7); cout<<"YOUR CHOICE : ";
cin>>ch;
switch(ch)
{ case 1:
{ clrscr(); fstream file; file.open("SALARY.dat",ios::in|ios::out); while(1) {
file.read((char*)&f,sizeof(f)); if(file.eof()) break;
gotoxy(30,2);
cout<<"CURRENT SALARY DATE";
cout<<" "<<f.day<<" "<<f.month<<" "<<f.year;
} file.close();
gotoxy(30,5);
cout<<"ENTER SALARY DATE (dd mm yyyy) : ";
cin>>f.day>>f.month>>f.year; file.open("SALARY.dat",ios::in|ios::out); file.write((char*)&f,sizeof(f)); file.close();
break;} case 2: clrscr(); int rn;
gotoxy(30,12);
cout<<"ENTER THE STAFF NO : ";
cin>>rn; credict_salary(rn); break;
}
}
void office_function:: credict_salary(int rn)
{     clrscr();
gotoxy(30,12);
cout<<"PRESS ENTER TO CREDICT"; getch(); fstream change;
change.open("DATA1.dat",ios::in|ios::out); while(!change.eof())
{ change.read((char*)&s1,sizeof(t1));
if(t1.staff_no==rn)
{
if(strcmp(t1.salary_stat,"NOT CREDICTED")==0)
{
t1.pday=day; t1.pmonth=month; t1.pyear=year;
strcpy(t1.salary_stat,"CREDICTED");
change.seekp(change.tellg() - sizeof(t1)); change.write((char*)&t1, sizeof(t1)); change.close();
gotoxy(30,13);
cout<<"CREDICTED...PRESS ENTER TO CONTINUE";
getch(); break;
}
if(strcmp(t1.salary_stat,"CREDICTED")==0)
{ clrscr();
gotoxy(20,10);
cout<<"SALARY IS ALREADY CREDICTED";
getch();
break;
}
 }
if(change.eof())break;
} getch();
}
void office_function:: salary_check()
{  int pos; fstream file; fstream change; file.open("SALARY.dat",ios::in|ios::out); change.open("DATA1.dat",ios::in|ios::out); while(!change.eof()&&!file.eof())
{
file.read((char*)&f,sizeof(f));
if(f.day==day && f.month==month && f.year==year)
{
while(!change.eof())
{
if(change.eof()) break;
change.read((char*)&t1,sizeof(t1)); cout<<t1.pday;
if(t1.pday==day&&t1.pmonth==month&&t1.pyear)
{
cout<<"CHECKED";
getch(); break; } else
{
strcpy(t1.salary_stat,"NOT CREDICTED"); change.seekp(change.tellg() - sizeof(t1)); change.write((char*)&t1, sizeof(t1));
}
}
getch();
}
} change.close(); file.close();
 }
void office_function:: fee()
{  int feedate,feemonth,feeyear; clrscr(); int ch,rn; gotoxy(30,5); cout<<"1.)SET FEE DATE  "; gotoxy(30,6); cout<<"2.)PAY FEE "; gotoxy(30,7); cout<<"YOUR CHOICE : "; cin>>ch;
switch (ch) { case 2:
 { clrscr();
gotoxy(30,5);
cout<<"ENTER THE ADMIN NO : "; cin>>rn; clrscr(); ifstream in; in.open("data.dat"); in.seekg(0); while(!in.eof())
{ in.read((char*)&s1,sizeof(s1));
if(s1.admin_no==rn)
{  clrscr(); if(s1.std<=6)
{  clrscr();
gotoxy(30,5);
cout<<"***YOU HAVE TO PAY***";
gotoxy(30,7); cout<<"TUTION FEE : 600 RS";
gotoxy(30,8);
cout<<"COMPUTER FEE : 150 RS"; gotoxy(30,9); cout<<"TOTAL : 750"; gotoxy(30,10); pay_fee(rn); getch();
} else {  clrscr();
gotoxy(30,5);
cout<<"***YOU HAVE TO PAY***";
gotoxy(30,7); cout<<"TUTION FEE : 600 RS";
gotoxy(30,8);
cout<<"COMPUTER FEE : 600 RS"; gotoxy(30,9); cout<<"TOTAL : 1200"; pay_fee(rn); getch();
}
}
} break; }//end of case
case 1:
{ clrscr(); fstream file;
file.open("FEEDATE.dat",ios::in|ios::out); while(1)
{
file.read((char*)&f,sizeof(f)); if(file.eof()) break;
gotoxy(30,2);
cout<<"CURRENT FEE DATE";
cout<<" "<<f.day<<" "<<f.month<<" "<<f.year;
} file.close();
gotoxy(30,5);
cout<<"ENTER FEE DATE (dd mm yyyy) : "; cin>>f.day>>f.month>>f.year; file.open("FEEDATE.dat",ios::in|ios::out); file.write((char*)&f,sizeof(f)); file.close(); break;
}
}
}
void office_function:: pay_fee(int rn)
{     gotoxy(30,12);
cout<<"PRESS ENTER TO PAY";
getch(); fstream change;
change.open("DATA.dat",ios::in|ios::out); while(!change.eof())
{
change.read((char*)&s1,sizeof(s1));
if(s1.admin_no==rn)
{
if(strcmp(s1.fee_stat,"UNPAID")==0)
{
s1.pday=day; s1.pmonth=month; s1.pyear=year; strcpy(s1.fee_stat,"PAID");
change.seekp(change.tellg() - sizeof(s1)); change.write((char*)&s1, sizeof(s1)); change.close();
gotoxy(30,13);
cout<<"PAID...PRESS ENTER TO CONTINUE";
getch(); break; }
if(strcmp(s1.fee_stat,"PAID")==0)
{ clrscr();
gotoxy(20,10);
cout<<"FEE IS ALREADY PAID";
getch();
break;
}
 }
if(change.eof())break;
} getch();
}
void office_function:: fee_check()
{  clrscr(); int pos; fstream file; fstream change;
file.open("FEEDATE.dat",ios::in|ios::out); change.open("DATA.dat",ios::in|ios::out);
while(!change.eof()&&!file.eof())
{
file.read((char*)&f,sizeof(f));
if(f.day==day&&f.month==month&&f.year==year)
{
while(!change.eof())
{ if(change.eof()) break;
change.read((char*)&s1,sizeof(s1));
cout<<s1.pday;
if(s1.pday==day&&s1.pmonth==month&&s1.pyear)
{
cout<<"CHECKED";
getch(); break; } else
{
strcpy(s1.fee_stat,"UNPAID"); change.seekp(change.tellg() - sizeof(s1)); change.write((char*)&s1, sizeof(s1));
}
}
getch();
}
} change.close(); file.close();
 }
/*--------------------------------Library Intro
-------------------------------*/
void library()
{ clrscr(); cout<<"\n\n\n";
cout<<"\t\t      WELCOME TO ROSEMARY LIBRARY     \n";
cout<<"\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(13,9);
cout <<"    ROSEMARY LIBRARY HAS A WIDE ARRAY  OF";
gotoxy(13,11);
cout<<"    NOVELS ,REFERENCES AND  OTHER KNOWLEDGE SOURCES";
gotoxy(13,13);
cout <<"    LIBRARY IS WELL EQUIPPED LIBRARY WITH E-BOOK SERVICES";
gotoxy(13,15);
cout<<"THIS APPLICATION WILL GUIDE YOU TO THE LIBRARIAN'S DESK.";
gotoxy(27,21);
cout<<"PRESS TO CONTINUE....." ;
if(getche())
{
 libr.mainmenu();
}
}
/*----------------------------------  function to show menu for library   ----------------------------------*/
void libmenu::mainmenu()
  {
int lmch; clrscr();
cout<<"\n\n";
cout<<"\t\t\t       L I B R A R Y             \n"; cout<<"\t\t\t      ~~~~~~~~~~~~~~~\n"; gotoxy(5,24);
cout<<" LIBRARIAN: LAVANYA \t\t\t\t < 0 > for EXIT "; gotoxy(30,7);
cout<<"1. INTRODUCTION";
gotoxy(30,9); cout<<"2. ISSUE BOOK" ; gotoxy(30,11);
cout<<"3. RETURN BOOK";
gotoxy(30,13); cout<<"4. MEMBERS "; gotoxy(30,15); cout<<"5. BOOKS "; gotoxy(24,19); cout<<"ENTER THE CHOICE: ";
cin>>lmch; switch (lmch)
{ case 1 : library(); break;
case 2 : issue(); break;
case 3 :
returnbook(); break;
case 4 :
memopt(); break;
case 5 :
bookopt(); break;   case 0 :   interface();   break;
  default:
 gotoxy(30,21);
 cout<<"WRONG CHOICE";
 if(getche())
 {
mainmenu();
 }
  }
 }
/*------------------------- duedate calculator  --------------------------*/
void libmenu ::duedate(int d1, int m1, int y1)
{ static int month[] = {31,29,31,30,31,30,31,31,30,31,30,31} ; for (int i=1; i<=15; i++)
{ d1++ ;
if ((d1 > month[m1-1]) || (y1%4 != 0 && m1 == 2 && d1 > 28))
{ d1 = 1 ; m1++ ;
}
if (m1 > 12)
{ m1 = 1 ; y1++ ;
}
} day  = d1 ; mon  = m1 ; year = y1 ;
}
void libmenu::issue()
 {
int  tbcode,tmcode; char tmname[20]; 
date d; 
getdate(&d); 
int day = d.da_day ; 
int mon = d.da_mon  ; int year= d.da_year ; clrscr();
cout<<"Date: "<<day<<"/"<<mon<<"/"<<year; cout<<"\n\n";
cout<<"\t\t\t       I S S U E  B O O K           \n"; cout<<"\t\t\t      ~~~~~~~~~~~~~~~~~~~~\n";
gotoxy(5,8) ;
cout <<"Enter Code of the Book to be issued : " ; cin>>tbcode;
blist.open("booklist.dat",ios::in); while(!blist.eof())
{
 blist.read((char*)&book,sizeof(book));  if(book.bcode==tbcode)
 {
cout<<"\n\t"<<book.bcode; cout<<"\t\t"<<book.bname; cout<<"\t\t"<<book.auth; break;
 }
} blist.close(); gotoxy(5,12);
cout <<"Enter Code of the Member to be issued : " ; cin>>tmcode;
mlist.open("memlist.dat",ios::in); while(!mlist.eof())
{
mlist.read((char*)&member,sizeof(member)); if(member.mcode==tmcode)
{
  {
cout<<"\n\t"<<member.mcode; cout<<"\t\t"<<member.mname;
strcpy(tmname,member.mname);
}
}
} mlist.close(); char wch ; gotoxy(30,20); cout<<"WANT TO ISSUE (y/n) : "; cin>>wch; if(wch=='y'||wch=='Y')
{
 issfile.open("issdet.dat",ios::out|ios::in|ios::app);  idet.mcode=tmcode;  strcpy(idet.mname,tmname);  idet.mbcode=tbcode;
 idet.issue.day       = day           ;  idet.issue.mon       = mon           ;  idet.issue.year      = year          ;
 duedate(day,mon,year) ;
 idet.retdat.day      = libr.day      ;  idet.retdat.mon      = libr.mon      ;  idet.retdat.year     = libr.year     ;  issfile.write((char*)&idet,sizeof(idet));  issfile.close();  mainmenu();
}  else
{
 mainmenu();
}
 }
 /*-----------------------------  function to return book   -------------------------------*/
void libmenu::returnbook()
{ 
long rpos ; int rmcode; date d; getdate(&d); int day = d.da_day ;
int mon = d.da_mon  ; int year= d.da_year ; clrscr();
cout<<"Date: "<<day<<"/"<<mon<<"/"<<year; cout<<"\n\n";
cout<<"\t\t\t     R E T U R N   B O O K           \n"; cout<<"\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(5,8) ;
cout <<"Enter Code of the Member to be return : " ; cin>>rmcode;
issfile.open("issdet.dat",ios::in|ios::out); while(!issfile.eof())
{ rpos=issfile.tellg();
issfile.read((char*)&idet,sizeof(idet)); if(idet.mcode==rmcode)
{  gotoxy(20,10);
 cout<<"MEMBER CODE      : "<<idet.mcode;  gotoxy(20,11);  cout<<"MEMBER NAME      : ";  puts(idet.mname);  gotoxy(20,12);
 cout<<"BOOK CODE        : "<<idet.mbcode;  gotoxy(20,13);  cout<<"ISSUE DATE       :"<<idet.issue.day<<"/"<<idet.issue.mon<<"/"<<idet.issue.year;  gotoxy(20,14);
 cout<<"RETURN DATE       :"<<idet.retdat.day<<"/"<<idet.retdat.mon<<"/"<<idet.retdat.year;  idet.mcode          = 0 ;  strcpy(idet.mname," ")  ;  idet.mbcode         = 0 ;  idet.issue.day      = 0 ;  idet.issue.mon      = 0 ;  idet.issue.year     = 0 ;  idet.retdat.day     = 0 ;  idet.retdat.mon     = 0 ;  idet.retdat.year    = 0 ;  break;
 }
} {
 issfile.seekg(rpos);
 issfile.write((char*)&idet,sizeof(idet));  issfile.close();  if(getche());
 mainmenu();
}
 }
 /*-----------------------------  function to show member option  -------------------------------*/ void libmenu::memopt()
 {
int opt;
clrscr();
cout<<"\n\n";
cout<<"\t\t\t        M E M B E R S            \n"; cout<<"\t\t\t      ~~~~~~~~~~~~~~~~\n"; gotoxy(60,24); cout<<" < 0 > for EXIT ";
gotoxy(30,9);
cout<<"1. VIEW MEMBERS LIST" ; 
gotoxy(30,11);
cout<<"2. MEMBERS DETAILS";
gotoxy(30,13);
 cout<<"3. ISSUED DETAILS"; gotoxy(24,18);
cout<<"ENTER THE CHOICE: "; cin>>opt; switch (opt) { case 1 :
{
 memlist(); break;
} case 2 : mdetails() ; break; case 3 : issuedet(); break;
case 0 :   library();   break;
  default:
 gotoxy(30,21);
 cout<<"WRONG CHOICE";
 if(getche())
 {
memopt();
 }
  }
 }
 /*-----------------------------  function to show book option  -------------------------------*/
 void libmenu::memlist()
 {   clrscr();   gotoxy(28,3);
  cout<<" L I S T  O F  M E M B E R S  ";   gotoxy(28,4);
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  
cout<<"\n\n\n-------------------------------------------------------------------------------";
cout<<"\n    C O D E           N A M E               C L A S S            C O N T A C T  ";
cout<<"--------------------------------------------------------------------------------";
mlist.open("memlist.dat",ios::in) ;   mlist.seekg(0);   int r=10;
  while(1)
  {
mlist.read((char*)&member,sizeof(member)); if(mlist.eof())
{  break; }
for(int i=0;i<100;i++)
{
 if(member.mcode==i)
 {
 gotoxy(7,r);  cout<<member.mcode;  gotoxy(20,r);
 cout<<member.mname;
 gotoxy(48,r);  cout<<member.std;  gotoxy(64,r);  cout<<member.contact;  r++;
 }
}
  }
  cout<<"\n\n\n\n\t\t\t\tPRESS ANY KEY ...";
 mlist.close();
 if(getche())
 {
memopt();
 }
}
 /*-----------------------------  function to show memberdetails  -------------------------------*/
 void libmenu :: mdetails()
 {
  clrscr();   gotoxy(28,3);
  cout<<" M E M B E R S  D E T A I L S";   gotoxy(28,4);
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";   int mdetcode;
  cout<<"\n\n\n\t\tENTER A MEMBER CODE: ";
  cin>>mdetcode;
  mlist.open("memlist.dat",ios::in) ;   while(!mlist.eof())
{
mlist.read((char*)&member,sizeof(member)); if(member.mcode==mdetcode)
{  gotoxy(26,10);
 cout<<"CODE        : "<<member.mcode;  gotoxy(26,12);  cout<<"NAME        : ";  puts(member.mname);  gotoxy(26,14);  cout<<"CLASS       : ";  cout<<member.std;  gotoxy(26,16);  cout<<"CONTACT     : ";
 puts(member.contact);
}
 }
 mlist.close();
 if(getche())
 {
memopt();
 }
 }
/*------------------------------
 FUNCTION TO SHOW ISSUE DETAILS
--------------------------------*/ void libmenu:: issuedet()
{
  clrscr();   
gotoxy(28,3);
  cout<<" I S S U E   D E T A I L S";   gotoxy(28,4);
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~";   int isscode,found=0;
  cout<<"\n\n\n\t\tENTER A MEMBER CODE: ";   cin>>isscode;   gotoxy(12,18);
  cout<<"If return date and Issue date are zero the record is last issued";   issfile.open("issdet.dat",ios::in);   while(!issfile.eof())
{ issfile.read((char*)&idet,sizeof(idet)); if(idet.mcode==isscode)
{
 found=1;  gotoxy(26,10);
 cout<<"MEMBER CODE        : "<<idet.mcode;  gotoxy(26,12);
 cout<<"MEMBER NAME        : ";  puts(idet.mname);  gotoxy(26,14);
 cout<<"BOOK               : "<<idet.mbcode;
 gotoxy(26,15);
 cout<<"ISSUE  DATE        :"<<idet.issue.day<<"/"<<idet.issue.mon<<"/"<<idet.issue.year ;  gotoxy(26,16);  cout<<"RETURN DATE        : "<<idet.retdat.day<<"/"<<idet.retdat.mon<<"/"<<idet.retdat.year;  gotoxy(26,18);
} break;
  }
  issfile.close();
  if(found==0)
  {
gotoxy(26,12);
cout<<"No Books Issued...";
  }
  if(getche())
 {
memopt();
 }
}
 /*-----------------------------  function to show book option  -------------------------------*/
void libmenu::bookopt()
 {
int opt;
clrscr();
cout<<"\n\n";
cout<<"\t\t\t         B O O K S            \n"; cout<<"\t\t\t      ~~~~~~~~~~~~~~~\n"; gotoxy(60,24);
cout<<" < 0 > for EXIT "; gotoxy(30,8); 
cout<<"1. ADD BOOK"; gotoxy(30,10); 
cout<<"2. VIEW BOOK LIST" ; gotoxy(30,12); 
cout<<"3. BOOK DETAILS"; gotoxy(30,14);
 cout<<"4. MODIFY";
gotoxy(24,19);
cout<<"ENTER THE CHOICE: "; cin>>opt; switch (opt)
 {
 case 1 :
addbooks(); break;
case 2 : booklist(); break;
case 3 : bdetails(); break;
case 4 :
bmodify(); break;
case 0 :   library();   break;   default:
 gotoxy(30,21);
 cout<<"WRONG CHOICE";
 if(getche())
 {
clrscr();
bookopt();
 }
  }
 }
 /*------------------------  function to add books  --------------------------*/
void libmenu::addbooks()
 {   int size;
  blist.open("booklist.dat",ios::out|ios::in|ios::ate) ;   blist.seekg(0,ios::end);   long pos=blist.tellg();   size=sizeof(book);   blist.close();   clrscr();   gotoxy(28,3);   cout<<"A D D   B O O K S";   gotoxy(28,4);   cout<<"~~~~~~~~~~~~~~~~~~";   book.bcode++;
  gotoxy(26,7);   cout<<"CODE        :";   gotoxy(26,9);   cout<<"NAME        :";   gotoxy(26,11);   cout<<"AUTHOR      :";   gotoxy(26,13);
  cout<<"PUBLICATION :";
  gotoxy(26,15);
  cout<<"NO OF COPIES:";
  gotoxy(26,17);   cout<<"PRICE       : Rs.";   gotoxy(45,7);   book.bcode=(pos/size)+1;   cout<<book.bcode;   gotoxy(45,9);   gets(book.bname);   gotoxy(45,11);   gets(book.auth);   gotoxy(45,13);   gets(book.publ);   gotoxy(45,15);   cin>>book.copies;   gotoxy(45,17);   cin>>book.price;   char wch;
  gotoxy(30,20);   cout<<"WANT TO SAVE (y/n) : ";   cin>>wch;
  if(wch=='y'||wch=='Y')
  {
writebook();
book.bcode++;
  }
  else
  {
bookopt();
  }
}
/*----------------------------------  write book  to file ----------------------------------*/
void libmenu::writebook()
{
 blist.open("booklist.dat",ios::out|ios::in|ios::ate) ;  blist.write((char*)&book,sizeof(book));  blist.close();
 bookopt(); }
 /*---------------------  function to show booklist  ------------------------*/  void libmenu::booklist()
 {   clrscr();   gotoxy(28,3);
  cout<<"  L I S T  O F  B O O K S  ";   gotoxy(28,4);
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  
cout<<"\n\n\n-------------------------------------------------------------------------------";
cout<<"\n  C O D E         N A M E               A U T H O R        P U B L I S H E R   ";
cout<<"--------------------------------------------------------------------------------";
  blist.open("booklist.dat",ios::in) ;   blist.seekg(0);   int r=10;
  while(1)
  {
blist.read((char*)&book,sizeof(book)); if(blist.eof())
{  break; }
for(int i=0;i<100;i++)
{
 if(book.bcode==i)
 {
 gotoxy(5,r);  cout<<book.bcode;  gotoxy(16,r);  cout<<book.bname;  gotoxy(42,r);  cout<<book.auth;  gotoxy(65,r++);  cout<<book.publ;
 if(book.copies>0)
 {
  gotoxy(63,r);
  cout<<"Status: Avail";
 }
 else
 {
  gotoxy(63,r);
  cout<<"Status: N/A";
 }
 r=r+2;
 }
}
  }
  cout<<"\n\n\n\n\t\t\t\tPress any key ...";  blist.close();
 if(getche())
 {
bookopt();
 }
}
 /*---------------------  function to show bookdetails  ------------------------*/
 void libmenu::bdetails()
 {
  clrscr();   gotoxy(28,3);
  cout<<" B O O K S  D E T A I L S";   gotoxy(28,4);
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  int bdetcode;
  cout<<"\n\n\n\t\tENTER A BOOK CODE: ";
  cin>>bdetcode;   blist.open("booklist.dat",ios::in) ;   while(!blist.eof())
{ blist.read((char*)&book,sizeof(book));
if(book.bcode==bdetcode)
{  gotoxy(26,10);
 cout<<"CODE        : "<<book.bcode;  gotoxy(26,12);  cout<<"NAME        : ";  puts(book.bname);  gotoxy(26,14);
 cout<<"AUTHOR      : ";  puts(book.auth);
 gotoxy(26,16);  cout<<"PUBLICATION : ";  puts(book.publ);
 gotoxy(26,18);
 cout<<"NO OF COPIES: "<<book.copies;
 gotoxy(26,20);
 cout<<"PRICE       : "<<book.price;  if(book.copies>0)
  {
gotoxy(26,22);
cout<<"STATUS      : Avail";
  }
 else
  {
gotoxy(26,22); cout<<"STATUS      : N/A ";
  }
}
  }
 blist.close();
 if(getche())
 {
bookopt();
 }
 }
/*------------------
Modify a book --------------------*/
void libmenu::bmodify()
{
char newbname[30]; char newauth [30]; char newpubl [80]; int  newcopies; int  newprice ; clrscr();
blist.open("booklist.dat",ios::in|ios::out|ios::binary); long curpos; gotoxy(28,3);
cout<<"M O D I F Y   B O O K S";
gotoxy(26,4);
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"; int modcode;
cout<<"\n\n\n\t\tENTER A BOOK CODE: "; cin>>modcode;
while(!blist.eof())
{  curpos=blist.tellg(); blist.read((char*)&book,sizeof(book)); if(book.bcode == modcode)
{ 
           gotoxy(12,10);
 cout<<"CODE        : "<<book.bcode;  gotoxy(12,12);
 cout<<"NAME        : ";  puts(book.bname);  gotoxy(12,14);  cout<<"AUTHOR      : ";  puts(book.auth);
 gotoxy(12,16);  cout<<"PUBLICATION : ";  puts(book.publ);
 gotoxy(12,18);
 cout<<"NO OF COPIES: "<<book.copies;
 gotoxy(12,20);
 cout<<"PRICE       : Rs."<<book.price;  gotoxy(20,23);  cout<<"Retype to retain the values";  gotoxy(46,12);  gets(newbname);  gotoxy(46,14);  gets(newauth);  gotoxy(46,16);  gets(newpubl);  gotoxy(46,18);  cin>>newcopies;  gotoxy(46,20);  cin>>newprice;
 strcpy(book.bname,newbname);  strcpy(book.auth,newauth);  strcpy(book.publ,newpubl);  book.copies=newcopies;  book.price=newprice;
 break ;
 }
} {
 blist.seekg(curpos);
 blist.write((char*)&book,sizeof(book));  blist.close();  bookopt();
}
}
/*---------------------------------------
LABS
-----------------------------------------*/   void labs()
 {
int ch; while(1) 
{
clrscr();
gotoxy(32,2);
cout<<" CHOOSE A LABORATORY";
gotoxy(20,8);
cout<<" 1. PHYSICS LABORATORY";
gotoxy(20,11);
cout<<" 2. CHEMISTRY LABORATORY";
gotoxy(20,14);
cout<<" 3. COMPUTER LABORATORY";
gotoxy(20,17);
cout<<" 4. BIOLOGY LABORATORY";
gotoxy(70,25); cout<<" 0. EXIT";
gotoxy(10,4);
cout<<" CHOOSE YOUR CHOICE:-   ";
cin>>ch; switch(ch)
{       
           case 1: phylab(); break;
case 2: chemlab(); break;
case 3: complab(); break;
case 4: biolab(); break;
case 0: exit(0); default:
cout<<"ENTER A VALID CHOICE";
  }
getch();
}
}
/*---------------------------------------
PHYSICS LAB
---------------------------------------*/   void phylab()
{
        int ch;
cout<<" WELCOME TO PHYSICS LABORATORY"; while(1)
{ clrscr();
gotoxy(20,8);
cout<<"1. ENTER NEW INSTRUMENTS";
gotoxy(20,10);
cout<<"2. DISPALY INSTRUMENTS";
gotoxy(20,14); cout<<"0. GO BACK"; gotoxy(15,5);;
cout<<"ENTER A CHOICE:-   ";
cin>>ch;
switch(ch)
{ case 1:
W.Add_inst(1); break;
case 2:
W.Show_inst(1); break;
case 0: labs();
default:
cout<<"ENTER A VALID CHOICE";
} getch();
}
}
/*---------------------------------------
CHEMISTRY LAB
---------------------------------------*/ void chemlab()
{ int ch,n;
  cout<<"~~~~~~~~ W E L C O M E   TO   C H E M I S T R Y   L A B ~~~~~~~~";         while(1)
        {             clrscr();
gotoxy(20,8);
            cout<<"1. ADD A NEW CHEMICAL";
            gotoxy(20,10);
            cout<<"2. ADD A ACCESSORY"; gotoxy(20,12);
            cout<<"3. SHOW AVAILABLE CHEMICAL";
            gotoxy(20,14);
            cout<<"4. CHEMICAL DETAILS "; gotoxy(20,16);
            cout<<"5. INSTRUMENTS DETAILS";
            gotoxy(20,18);             cout<<"6. MODIFY";
gotoxy(20,20);
            cout<<"0. BACK";
            gotoxy(15,5);
            cout<<"ENTER A CHOICE:-   "; cin>>ch;
            switch(ch)
            {                 case 1:
 W.Add_Chemical();
                break;
                case 2:
 W. Add_inst(2);
                break;
                case 3:
 W.Available_chemicals();
                break;
                case 4:
 W.Show_chemical_detail();
                break;
                case 5:
 W.Show_inst(2);
                break;
                case 6:
 W.Modify_Chemical();
                break;
                case 0:
 labs();
                default:
                cout<<"ENTER A VALID CHOICE";
}
            getch();
        }
 }
/*---------------------------------------
COMPUTER LAB
---------------------------------------*/ void complab()
{  int ch,n;
    cout<<"WELCOME TO COMPUTER LABORATORY";     while(1)
    {
clrscr();
gotoxy(20,8);
cout<<"1. ADD A NEW SYSTEM";
gotoxy(20,10);
cout<<"2. ADD A ACCESSORY";
gotoxy(20,12);
cout<<"3. SHOW AVAILABLE SYSTEM";
gotoxy(20,14); cout<<"4. SYSTEM DETAILS "; gotoxy(20,16);
cout<<"5. INSTRUMENTS DETAILS";
gotoxy(20,18); cout<<"6. MODIFY"; gotoxy(20,20); cout<<"0. BACK";
gotoxy(15,5);
cout<<"ENTER A CHOISE:-   "; cin>>ch; switch(ch)
{
 case 1:
    W. Add_system();     break;
 case 2:
    W. Add_inst(3);     break;
 case 3:
    W.System_present();     break;
 case 4:
    W.Show_system_detail();
    break;
 case 5:
    W.Show_inst(3);     break;
  case 6:
        W.Modify_system();
        break;
 case 0:
        labs();
default:
cout<<"ENTER A VALID CHOICE";
} getch();
    }
}
/*-------------------------------
BIOLOGY LAB
-----------------------------------*/  void biolab()   //Bioloy Lab Menu
{ int n,ch;
cout<<" WELCOME TO BIOLOGY LABORATORY"; while(1)
{ clrscr();
gotoxy(20,8);
cout<<"1. ADD A NEW SPECIMEN";
gotoxy(20,10);
cout<<"2. ADD A INSTRUMENT";
gotoxy(20,12);
cout<<"3. SHOW AVAILABLE SPECIMEN";
gotoxy(20,14);
cout<<"4. SPECIMEN DETAILS "; gotoxy(20,16);
cout<<"5. INSTRUMENTS DETAILS";
gotoxy(20,18); cout<<"6. MODIFY"; gotoxy(20,20); cout<<"0. BACK";
gotoxy(15,5); cout<<"ENTER A CHOICE:-   "; cin>>ch; switch(ch)
{ case 1:
W.Add_spec() ; break;
case 2:
W. Add_inst(4); break;
case 3:
W.Available_specimen(); break;
case 4:
W.Show_spec_details() ; break;
case 5:
W.Show_inst(4); break;
case 6:
W.Modify_specimen();
break;
case 0: labs();
default:
cout<<"ENTER A VALID CHOICE";
} getch();
}
}
/*-------------------------------
SIZEOF CHEMISTRYLAB
-----------------------------------*/
int Working ::sizeof_chem()
{     ifstream fin;
    int no;
 fin.open("Chemical.dat",ios::in);
    fin.seekg(0,ios::end);     long pos=fin.tellg();  no=pos/sizeof(chem);  no++;
    fin.close();     return no; }
/*-------------------------------
ADD CHEMICALS
-----------------------------------*/
void Working::Add_Chemical()
{
    clrscr();     ofstream fo;
    fo.open("Chemical.dat",ios::out|ios::app);  cout<<"\n\t\t      A D D   C H E M I C A L             ";
cout<<"\n\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    while(1)
        {
chem.Sno=sizeof_chem();
            gotoxy(25,5);
            cout<<"SERIAL NUMBER  : ";
            gotoxy(25,6); cout<<"CHEMICAL NAME  : ";
            gotoxy(25,7);             cout<<"volume         : ";             gotoxy(25,8); cout<<"CONCENTRATION  : ";
            gotoxy(25,9);
            cout<<"DATE OF EXPITY : ";
            gotoxy(25,10);
cout<<"NUMBER OF ITEMS: ";
            gotoxy(43,5);             cout<<chem.Sno;             gotoxy(43,6); gets(chem.Name);
            gotoxy(43,7);             cin>>chem.Vol;
            gotoxy(43,8); cin>>chem.Conc;
            gotoxy(43,9);             gets(chem.DOE);
            gotoxy(43,10);
cin>>chem.Nos;
            fo.write((char*)&chem,sizeof(chem));
            cout<<"\n\n\n\t\t\t~~~~SAVING~~~~";             break;
  }
        fo.close(); }
/*-------------------------------
AVAILABLE CHEMICALS
-----------------------------------*/ void Working ::Available_chemicals()
{     clrscr();  fstream fin;
    gotoxy(28,4);
    cout<<" C H E M I C A L    P R E S E N T ";     gotoxy(25,5);
 cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    
cout<<"\n\n\n--------------------------------------------------------------------------";
    cout<<" \n S.NO                      N A M E                    C O N C.                ";
    
cout<<"----------------------------------------------------------------------------";
fin.open("Chemical.dat",ios::in);
fin.seekg(0);     int r=12;     while(1)
 {
        fin.read((char*)&chem,sizeof(chem));         if(fin.eof())             break;
                gotoxy(5,r);                 cout<<chem.Sno;
                gotoxy(28,r);  cout<<chem.Name;
                gotoxy(57,r);
                cout<<chem.Conc;
                r=r+2;
 }
    cout<<"\n\n\n\n\t\t\t\tPress any key ...";     fin.close();
}
/*-------------------------------
CHEMICALS DETAILS
-----------------------------------*/
void Working :: Show_chemical_detail()
{     clrscr(); int n; cout<<"\n";
cout<<"\t\t\t      C H E M I C A L   D E T A I L            \n"; cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(30,6);
cout<<"ENTER THE SERIAL NUMBER : "; cin>>n; ifstream fin;
fin.open("Chemical.dat",ios::in); fin.seekg(0); while(!fin.eof())
{   fin.read((char*)&pc,sizeof(pc));
    if(chem.Sno==n)
        {
            gotoxy(30,8); cout<<"SERIAL NO        : "<<chem.Sno; gotoxy(30,9);
cout<<"CHEMICAL NAME    : "<<chem.Name; gotoxy(30,10);
cout<<"CONCENTRATION    : "<<chem.Conc; gotoxy(30,11);
cout<<"VOLUME           : "<<chem.Vol; gotoxy(30,12);
cout<<"DATE OF EXPIRY   : "<<chem.DOE;
gotoxy(30,13);
cout<<"NUMBER OF ITEMS  : "<<chem.Nos; cout<<"\n\n\n\n\t\t\t\tPRESS ANY KEY ..."; break;
        }
} fin.close();
}
/*-------------------------------
MODIFY CHEMICALS
-----------------------------------*/
void Working :: Modify_Chemical()
    {
clrscr();
int newconc,newvol,newnos;
char newcname[30],newDOE[30]; fstream sys;
sys.open("Chemical.dat",ios::in|ios::out|ios::binary); long curpos; cout<<"\n";
cout<<"\t\t\t      M O D I F Y   C H E M I C A L            \n"; cout<<"\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; int modcode;
gotoxy(30,6);
cout<<"ENTER THE SERIAL NUMBER : "; cin>>modcode;
while(!sys.eof())
{
    curpos=sys.tellg();
    sys.read((char*)&chem,sizeof(chem));  if(chem.Sno == modcode)
    {
        gotoxy(20,8); cout<<"SERIAL NO            : "<<chem.Sno; gotoxy(20,9);
cout<<"CHEMICAL NAME        : "<<chem.Name; gotoxy(20,10);
cout<<"CONCENTRATION        : "<<chem.Conc; gotoxy(20,11);
cout<<"VOLUME ( IN LITRES)  : "<<chem.Vol; gotoxy(20,12);
cout<<"DATE OF EXPIRY       : "<<chem.DOE; gotoxy(20,13);
cout<<"NUMBER OF ITEMS     : "<<chem.Nos;
            gotoxy(15,20);
            cout<<"ENTER '.' TO RETAIN THE VALUES OF CHARACTER"; gotoxy(15,21);
            cout<<"RETYPE THE NUMBER TO RETAIN";             gotoxy(55,9);
            gets(newcname);  gotoxy(55,10);
    cin>>newconc;     gotoxy(55,11);     cin>>newvol ; gotoxy(55,12);
            gets(newDOE);             gotoxy(55,13);             cin>>newnos;
if(strcmp(newcname,".")!=0)
                strcpy(chem.Name,newcname);             if(strcmp(newDOE,".")!=0)
                strcpy(chem.DOE,newDOE);
 chem.Nos=newnos;
                chem.Conc=newconc;
                chem.Vol=newvol;
                break ;
 }
     	}     sys.seekg(curpos);
    sys.write((char*)&chem,sizeof(chem));  sys.close();
    }
/*-------------------------------
SIZE-OF SYSTEM
-----------------------------------*/
int Working :: sizeof_system()
    {
        ifstream fin;   int no;
    fin.open("system_pc.dat",ios::in);     fin.seekg(0,ios::end);     long pos=fin.tellg();  no=pos/sizeof(pc);
    no++;     fin.close();
    return no;
 }
void Working :: Add_system()   //To add the values of New_system
    {
clrscr(); int n; char ch; ofstream fo;
fo.open("system_pc.dat",ios::out|ios::app);
    cout<<"\n\t\t      A D D   S Y S E M     ";     cout<<"\n\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; while(1) {
    pc.no=sizeof_system();
        gotoxy(25,5);
        cout<<"SERIAL NUMBER     : ";   gotoxy(25,6);
        cout<<"PROCESSOR         : ";         gotoxy(25,7);
        cout<<"OPERATING SYSTEM  : ";   gotoxy(25,8);
        cout<<"COMPANY           : ";         gotoxy(25,9);
        cout<<"HARD DISK(IN GB)  : ";   gotoxy(25,10);
        cout<<"R.A.M ( in GB)    : ";
        gotoxy(25,11);         cout<<"COST (IN RS)      : ";   gotoxy(43,5);
        cout<<pc.no;         gotoxy(43,6);         gets(pc.prcs);   gotoxy(43,7);         gets(pc.os);         gotoxy(43,8);         gets(pc.cmpy);   gotoxy(43,9);
        cin>>pc.mry;         gotoxy(43,10);         cin>>pc.ram;   gotoxy(43,11);         cin>>pc.cost;         fo.write((char*)&pc,sizeof(pc));         cout<<"\n\n\n\t\t\t~~~~SAVING~~~~";   break;
 }
 fo.close();
}
/*-------------------------------
 SYSTEM(S) PRESENT -----------------------------------*/ void Working :: System_present()
{  clrscr();
    fstream fin;     gotoxy(28,4);
    cout<<" S Y S T E M    P R E S E N T ";  gotoxy(25,5);
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    
cout<<"\n\n\n-------------------------------------------------------------------------------";
    cout<<"\n  S.NO                      C O M P A N Y                      O S                ";
 
cout<<"------------------------------------------------------------------------------";     fin.open("system_pc.dat",ios::in);     fin.seekg(0);     int r=12;  while(1)
    {
        fin.read((char*)&pc,sizeof(pc));         if(fin.eof())
break;
                gotoxy(5,r);
                cout<<pc.no;
 gotoxy(28,r);
                cout<<pc.cmpy;                 gotoxy(57,r);                 cout<<pc.os;  r=r+2;
    }
    cout<<"\n\n\n\n\t\t\t\tPRESS ANY KEY ...";     fin.close();  getch();
    complab();
}
/*-------------------------------
SYSTEM DETAILS -----------------------------------*/
void Working::Show_system_detail()  //To display the value of New_system
    {
clrscr(); int n; cout<<"\n";
cout<<"\t\t\t      C H E M I C A L   D E T A I L            \n"; cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(30,6);
cout<<"ENTER THE SERIAL NUMBER : "; cin>>n; ifstream fin;
fin.open("system_pc.dat",ios::in); fin.seekg(0); while(!fin.eof())
{
     fin.read((char*)&pc,sizeof(pc));
if(pc.no==n)
        {
            gotoxy(30,8); cout<<"SERIAL NO            : "<<pc.no; gotoxy(30,9);
cout<<"PROCESSOR            : "<<pc.prcs; gotoxy(30,10);
cout<<"OPERATING SYSTEM     : "<<pc.os; gotoxy(30,11);
cout<<"COMPANY              : "<<pc.cmpy; gotoxy(30,12);
cout<<"HARD DISK ( IN GB)   : "<<pc.mry; gotoxy(30,13);
cout<<"R.A.M in GB  )       : "<<pc.ram; gotoxy(30,14);
cout<<"COST ( in Rs )       : "<<pc.cost;
cout<<"\n\n\n\n\t\t\t\tPress any key ...";
            break;
        }
} fin.close();
}
/*-------------------------------
MODIFY SYSTEM -----------------------------------*/
void Working :: Modify_system()
 {
clrscr();
int newmry,newram,newcost;
char newprcs[30],newos[30],newcmpy[30]; fstream sys;
sys.open("system_pc.dat",ios::in|ios::out|ios::binary); long curpos;
cout<<"\n";
cout<<"\t\t\t      M O D I F Y   S Y S T E M            \n"; cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; int modcode;
gotoxy(30,6);
cout<<"ENTER THE SERIAL NUMBER : "; cin>>modcode;
while(!sys.eof())
{  curpos=sys.tellg();
    sys.read((char*)&pc,sizeof(pc));     if(pc.no == modcode)
    {
  gotoxy(20,8);
cout<<"SERIAL NO            : "<<pc.no; gotoxy(20,9);
cout<<"PROCESSOR            : "<<pc.prcs; gotoxy(20,10);
cout<<"OPERATING SYSTEM     : "<<pc.os; gotoxy(20,11);
cout<<"COMPANY              : "<<pc.cmpy; gotoxy(20,12);
cout<<"HARD DISK ( IN GB)   : "<<pc.mry; gotoxy(20,13);
cout<<"R.A.M ( in GB  )     : "<<pc.ram; gotoxy(20,14);
cout<<"COST ( in Rs )       : "<<pc.cost;
            gotoxy(15,20);
            cout<<"ENTER '.' TO RETAIN THE VALUES OF CHARACTER"; gotoxy(15,21);
            cout<<"RETYPE THE NUMBER TO RETAIN";             gotoxy(55,9);
            gets(newprcs);
gotoxy(55,10);
            gets(newos);             gotoxy(55,11);
            gets(newcmpy);
gotoxy(55,12);
            cin>>newmry;             gotoxy(55,13);
            cin>>newram; gotoxy(55,14);
            cin>>newcost;
            if(strcmp(newprcs,".")!=0)
                strcpy(pc.prcs,newprcs);
if(strcmp(newos,".")!=0)
                strcpy(pc.os,newos);             if(strcmp(newcmpy,".")!=0)
                strcpy(pc.cmpy,newcmpy);
 pc.mry=newmry;
                pc.ram=newram;                 pc.cost=newcost;
            break ;
 } }     sys.seekg(curpos);     sys.write((char*)&pc,sizeof(pc));  sys.close();
    complab();
    }
/*-------------------------------
SIZE OF INSTRUMENTS
-----------------------------------*/ int Working :: sizeof_inst(int n)
{     ifstream fin;
        int no;
  if(n==1)             fin.open("phy_inst.dat",ios::in);         if(n==2)
            fin.open("chem_inst.dat",ios::in);   if(n==3)
            fin.open("comp_inst.dat",ios::in);         if(n==4)
            fin.open("bio_inst.dat",ios::in);  fin.seekg(0,ios::end);
    long pos=fin.tellg();  no=pos/sizeof(Inst);
    no++;  fin.close();     return no;
}
/*-------------------------------
ADD INSTRUMENTS -----------------------------------*/
void Working :: Add_inst(int n)    // To add new instruments/accessories
{
    clrscr();  char ch;
    ofstream fo;
    cout<<"\n\t\t      A D D   I N S T R U M E N T S      ";
        cout<<"\n\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";  if(n==1)
            fo.open("phy_inst.dat",ios::out|ios::app);         if(n==2)
            fo.open("chem_inst.dat",ios::out|ios::app);   if(n==3)
            fo.open("comp_inst.dat",ios::out|ios::app);         if(n==4)
            fo.open("bio_inst.dat",ios::out|ios::app);
        while(1)
        {
            Inst.Sno=sizeof_inst(n); gotoxy(25,5);
            cout<<"SERIAL NUMBER  : ";
            gotoxy(25,6);
            cout<<"TYPE           : ";
gotoxy(25,7);
            cout<<"NAME           : ";             gotoxy(25,8);             cout<<"COMPANY        : "; gotoxy(25,9);
            cout<<"NUMBER OF ITEMS: ";
            gotoxy(25,10);             cout<<"COST ( in Rs)  : ";
gotoxy(43,5);
            cout<<Inst.Sno;             gotoxy(43,6);
            gets(Inst.type);
gotoxy(43,7);
            gets(Inst.name_inst);             gotoxy(43,8);
    gets(Inst.company);  gotoxy(43,9);
    cin>>Inst.numb_inst ;
            gotoxy(43,10);     cin>>Inst.cost; fo.write((char*)&Inst,sizeof(Inst));
            cout<<"\n\n\n\t\t\t~~~~Saving~~~~";             break;
    }
 fo.close();
}
/*-------------------------------
INSTRUMENTS DETILS
-----------------------------------*/
void  Working ::Show_inst(int n)//To display the values of instruments/accessories
{ clrscr(); char ch; ifstream fin; if(n==1)
    fin.open("phy_inst.dat",ios::in,ios::app); if(n==2)
    fin.open("chem_inst.dat",ios::in,ios::app); if(n==3)
    fin.open("comp_inst.dat",ios::in,ios::app); if(n==4)
    fin.open("bio_inst.dat",ios::in,ios::app); int m; cout<<"\n";
cout<<"\t\t\t      I N S T R U M E N T S  D E T A I L S     \n"; cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; gotoxy(30,6);
cout<<"ENTER THE SERIAL NUMBER : "; cin>>m;
fin.seekg(0); while(!fin.eof())
{
    fin.read((char*)&Inst,sizeof(Inst));     if(Inst.Sno==m)
{ clrscr();
 gotoxy(30,8); cout<<"SERIAL NO            : "<<Inst.Sno; gotoxy(30,9);
cout<<"TYPE                 : "<<Inst.type; gotoxy(30,10);
cout<<"NAME                 : "<<Inst.name_inst; gotoxy(30,11);
cout<<"COMPANY              : "<<Inst.company; gotoxy(30,12);
cout<<"NUMBER OF ITEMS      : "<<Inst.numb_inst; gotoxy(30,13);
cout<<"COST ( in Rs )       : "<<Inst.cost; cout<<"\n\n\n\n\t\t\t\tPress ANY KEY ...";
   }
   }
fin.close();
} int Working ::sizeof_spec()
{
    ifstream fin;
    int no;
 fin.open("Specimen.dat",ios::in);
    fin.seekg(0,ios::end);     long pos=fin.tellg();  no=pos/sizeof(spec);  no++;
    fin.close();     return no;
}
/*-------------------------------
ADD SPECIMEN
-----------------------------------*/
void Working::Add_spec()
    {
clrscr();
    cout<<"\n\t\t      A D D   S P E C I M E N             ";
 cout<<"\n\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 ofstream fo;
fo.open("Specimen.dat",ios::out|ios::app);
while(1)
{         spec.Sno=sizeof_spec(); gotoxy(25,5);         cout<<"SERIAL NUMBER      : ";   gotoxy(25,6);         cout<<"COMMON NAME        : ";
	gotoxy(25,7);
	cout<<"SCIENTIFIC NAME    : ";   gotoxy(25,8);
	cout<<"TYPE               : ";         gotoxy(25,9);
	cout<<"NUMBER OF ITEMS    : ";   gotoxy(25,10);
	cout<<"COST( IN RS)       : ";         gotoxy(43,5);         cout<<spec.Sno;   gotoxy(43,6);         gets(spec.cname);         gotoxy(43,7);         gets(spec.sname);   gotoxy(43,8);         gets(spec.type);         gotoxy(43,9);         cin>>spec.number;   gotoxy(43,10);         cin>>spec.cost;     fo.write((char*)&spec,sizeof(spec));     cout<<"\n\n\n\t\t\t~~~~SAVING~~~~";
	getch();
	break;
} fo.close();
    }
/*------------------------------- SPECIMENS AVAILABLE -----------------------------------*/
void Working ::Available_specimen()
{  clrscr();
    fstream fin;     gotoxy(28,4);
    cout<<" S P E C I M E N   P R E S E N T";  gotoxy(25,5);
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    
cout<<"\n\n\n---------------------------------------------------------------------------";
    cout<<" \n S.NO                     C. N A M E                   S. N A M E                ";
 
cout<<"----------------------------------------------------------------------------";     fin.open("Specimen.dat",ios::in);     fin.seekg(0);     int r=12;  while(1)
    {
        fin.read((char*)&spec,sizeof(spec));         if(fin.eof())
break;
                gotoxy(5,r);
                cout<<spec.Sno;
 gotoxy(28,r);
                cout<<spec.cname;                 gotoxy(57,r);                 cout<<spec.sname;
 r=r+2;
    }
    cout<<"\n\n\n\n\t\t\t\tPress any key ...";     fin.close();
}
/*-------------------------------
SPECIMEN DETAILS
-----------------------------------*/
void Working :: Show_spec_details()
{   clrscr();
        int n;         cout<<"\n";
        cout<<"\t\t\t     S P E C I M E N   D E T A I L S           \n";   cout<<"\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        gotoxy(30,6);
        cout<<"ENTER THE SERIAL NUMBER : ";         cin>>n;   ifstream fin;
        fin.open("Specimen.dat",ios::in);         fin.seekg(0);         while(!fin.eof())
  {
            fin.read((char*)&spec,sizeof(spec));             if(spec.Sno==n)
            {
 gotoxy(30,8);
                cout<<"SERIAL NO         : "<<spec.Sno;                 gotoxy(30,9);
                cout<<"COMMON NAME       : "<<spec.cname;                 gotoxy(30,10);
                cout<<"SCIENTIFIC NAME   : "<<spec.sname;                 gotoxy(30,11);
                cout<<"TYPE              : "<<spec.type;                 gotoxy(30,12);
                cout<<"NUMBER OF ITEMS  : "<<spec.number;                 gotoxy(30,13);
                cout<<"COST              : "<<spec.cost;  cout<<"\n\n\n\n\t\t\t\tPRESS ANY KEY ...";
                break;
             }         }
  fin.close();
 }
/*-------------------------------
MODIFY SPECIMEN
-----------------------------------*/
void Working :: Modify_specimen()
 {
clrscr(); int newcost, newnos;
char newcname[30],newsname[30], newtype[30]; fstream sys;
sys.open("Specimen.dat",ios::in|ios::out|ios::binary); long curpos; cout<<"\n";
cout<<"\t\t\t      M O D I F Y   S P E C I M E N            \n"; cout<<"\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; int modcode;
gotoxy(30,6);
cout<<"ENTER THE SERIAL NUMBER : "; cin>>modcode;
while(!sys.eof())
{
    curpos=sys.tellg();
    sys.read((char*)&spec,sizeof(spec));  if(chem.Sno == modcode)
    {
        gotoxy(20,8); cout<<"SERIAL NO            : "<<spec.Sno; gotoxy(20,9);
cout<<"COMMON NAME          : "<<spec.cname; gotoxy(20,10);
cout<<"SCIENTIFIC NAME      : "<<spec.sname; gotoxy(20,11);
cout<<"TYPE                 : "<<spec.type; gotoxy(20,12);
cout<<"NUMBER OF ITEMS      : "<<spec.number; gotoxy(20,13);
cout<<"COST                 : "<<spec.cost; gotoxy(15,20);
cout<<"ENTER '.' TO RETAIN THE VALUES OF CHARACTER";
gotoxy(15,21);
cout<<"RETYPE THE NUMBER TO RETAIN"; gotoxy(55,9);
            gets(newcname); gotoxy(55,10); gets(newsname); gotoxy(55,11);
gets(newtype);
gotoxy(55,12);
            cin>>newnos; gotoxy(55,13);
            cin>>newcost;             if(strcmp(newcname,".")!=0)  strcpy(spec.cname,newcname);
            if(strcmp(newsname,".")!=0)                 strcpy(spec.sname,newsname);
if(strcmp(newtype,".")!=0)
                strcpy(spec.type,newtype);
 spec.number=newnos;
                spec.cost=newcost;
 break ;
 } }
 sys.seekg(curpos);
 sys.write((char*)&spec,sizeof(spec));  sys.close();
 }
/*--------------------------------  main function
 -----------------------------------*/ void main()
{
    welcome();
	getch();
}
