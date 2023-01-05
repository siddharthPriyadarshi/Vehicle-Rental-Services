/* PROJECT NAME : VEHICLE RENTAL SERVICES

GROUP MEMBERS:
1. SIDDHARTH PRIYADARSHI - 25
2. ANISH KUMAR SINGH     - 04
3. MANTU KUMAR		 - 07

PROJECT ABSTRACT: THIS S/W HELPS IN MANAGING THE RECORDS OF THE USER DETAILS WHO RENTED THE VEHICLES..

*/
////////////////////////////////////////////////////////////////////////////
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip.h>
#include<fstream.h>

int pk=0;

//////////////////////////FUNCTION PROTOTYPE////////////////////////////
void login();
void newuser();
void mainmenu();
void usermenu();
void myprofile();
void clientmenu();
void editprofile();
void transaction();
void bookvehicles();

//////////////////// U S E R   I N F O    C L A S S ////////////////////////

class userinfo
{
	private:
		int usrid;
		char usrname[30];
		int age;
		char password[20];
	public:
		void getusrdetail();
		void showusrdetail();


		userinfo()             //Default CTOR
		{
		}
		userinfo(int uid,char *name,int ag,char *pas)   //PCTOR
		{       usrid=uid;
			strcpy(usrname,name);
			age=ag;
			strcpy (password,pas);
		}



		int getusrid()         //Accessor Function   //user ID
		{
			return usrid;
		}
		char *getpassword()    //ACCESSOR Function    //PASSWORD
		{
			return password;
		}
		char *getusername()    //accessor Fuction     //username
		{
			return usrname;
		}
		int getusrage()         //Accessor Function   //user AGE
		{
			return age;
		}
}ob;


//////////////////// V E H I C L E  I N F O  C L A S S /////////////////////
class vehicle
{
	private:
		int uid,duration;
		char vehiclename[15];
		float rate,amount;
	public:
		vehicle()
		{
		}

		vehicle (int u,int d, char *v, float r,float a)
		{
			uid=u;
			duration=d;
			strcpy(vehiclename,v);
			rate=r;
			amount=a;
		}

		int getuid()        //Accessor Function //UID
		{return uid;}

		int getvday()       //Accessor Function //days or duration
		{return duration;}

		char *getvname()    //Accessor Function //vehicle name
		{return vehiclename;}

		float getvrate()    //Accessor Function //Rate on per day
		{return rate;}                         //basis

		float getvamount()  //Accessor Function //  Amount
		{return amount;}
}vob;

//////////////// T R A N S A C T I O N   D E T A I L S /////////////////////
void transaction()
{       clrscr();
	cout<<"\n\t\t\t\t\t***************"<<endl;
	cout<<"\t\t\t\t\tBOOKED VEHICLES"<<endl;
	cout<<"\t\t\t\t\t***************"<<endl;
	ifstream infile("vehicle.dat",ios::in | ios::binary);
	if(!infile)
	{       clrscr();
		cout<<"\n\n\n\n\n\n\t\t\t\t\tNo records found!";delay(900);
	}
	else
	{
		 while(infile)
		 {
			infile.read((char*)&vob,sizeof(vob));
			if(pk==vob.getuid())
				cout<<"User ID : "<<vob.getuid()<<endl;
				cout<<"Vehicle : "<<vob.getvname()<<endl;
				cout<<"Rate    : "<<vob.getvrate()<<endl;
				cout<<"Days    : "<<vob.getvday()<<endl;
				cout<<"Amount  : "<<vob.getvamount()<<endl<<endl;
		}
	}
	infile.close();	getch();
}

////////////////////// B O O K   V E H I C L E S  /////////////////////
void bookvehicles()
{       int choice;
	clrscr();
	cout<<"\t\t\t*************"<<endl;
	cout<<"\t\t\tBOOK VEHICLES"<<endl;
	cout<<"\t\t\t*************"<<endl<<endl;
	cout<<"\t\t|"<<setw(4)<<"SNO"<<"|"<<setw(15)<<"Gaddi da naam"<<"|"<<setw(19)<<"rate per day basis"<<"|"<<endl;
	cout<<"\t\t|----|---------------|-------------------|"<<endl;
	cout<<"\t\t|"<<setw(4)<<"1."<<"|"<<setw(15) <<"MINI CAR"     <<"|"<<setw(19)<<" Rs. 500  "	<<"|"<<endl;
	cout<<"\t\t|"<<setw(4)<<"2."<<"|"<<setw(15) <<"MOTORCYCLE"   <<"|"<<setw(19)<<" Rs. 200  "	<<"|"<<endl;
	cout<<"\t\t|"<<setw(4)<<"3."<<"|"<<setw(15) <<"CHHOTA HAATHI"<<"|"<<setw(19)<<" Rs. 1000 "	<<"|"<<endl;
	cout<<"\t\t|"<<setw(4)<<"4."<<"|"<<setw(15) <<"BOLERO"       <<"|"<<setw(19)<<" Rs. 800  "        <<"|"<<endl;
	cout<<"\t\t|"<<setw(4)<<"5."<<"|"<<setw(15) <<"HERO CYCLE"   <<"|"<<setw(19)<<" Rs. 100  "        <<"|"<<endl;
	cout<<"\t\t|----|---------------|-------------------|"<<endl;
	cout<<"\nSelect your desired option: ";
	cin>>choice;

	float amount=0;
	int days=0,flag=0,rate;
	char vehname[15];

	switch(choice)
	{
		case 1:{rate=500;  flag=1;strcpy(vehname,"MINI CAR");}	break;
		case 2:{rate=200;  flag=1;strcpy(vehname,"MOTORCYCLE");}	break;
		case 3:{rate=1000; flag=1;strcpy(vehname,"CHHOTA HAATHI");}	break;
		case 4:{rate=900;  flag=1;strcpy(vehname,"BOLERO");}	break;
		case 5:{rate=100;  flag=1;strcpy(vehname,"HERO CYCLE");}	break;
		default: { clrscr();
			   cout<<"\n\n\n\n\n\n\t\t\t\tTRY AGAIN";
			   delay(600);
			 }
	}
	if(flag)
	{
		cout<<"\nEnter the nos of days(int value): ";
		cin>>days;
		amount =(rate * days);
		cout<<"Calculated Amount :"<<amount;
	}
	vehicle vob1(pk,days,vehname,rate,amount);
	ofstream outfile("vehicle.dat",ios::out | ios::binary| ios::app);
	if(!outfile)
	{       clrscr();
		cout<<"\n\n\n\n\n\t\t\tBooking process is not available..";
		delay(900);
	}
	else
		outfile.write((char *)&vob1, sizeof(vob1)) ;

	outfile.close();
	getch();
}



//////////////////////E D I T   P R O F I L E /////////////////////////////
void editprofile()
{
		char choice;
		clrscr();
		cout<<"\t\t\t\t************"<<endl;
		cout<<"\t\t\t\tEDIT PROFILE"<<endl;
		cout<<"\t\t\t\t************"<<endl;
		ob.showusrdetail();
		cout<<"\n\nDo you want to modify[y/n]: ";
		cin>>choice;
		choice=tolower(choice);
		if(choice=='y')
		{       char name[30],pas[20];
			int age;
			cout<<"\n1. Enter name(. to skip)    : ";
			gets(name);
			cout<<"\n2. Enter Age(0 to skip)     : ";
			cin>>age;
			cout<<"\n3. Enter Password(. to skip): ";
			gets(pas);

			if(strcmp(name,".")==0)
				strcpy(name,ob.getusername());
			if(age==0)
				age=ob.getusrage();
			if(strcmp(pas,".")==0)
				strcpy(pas,ob.getpassword());

			 userinfo temp(pk,name,age,pas);//temporary object
			//keep the values that were altered

			 fstream file("userdata.dat",ios::binary | ios::in | ios::out );

			 if(!file)
			 {
				cout<<"File can't be open";
				exit(1);
			 }
			 else
			 {
				while(file.read((char*)&ob,sizeof(ob)))
					if(pk==ob.getusrid())
					{
						int pos=(-1)*sizeof(ob);
						file.seekg(pos,ios::cur);
						file.write((char*)&temp,sizeof(temp));
					}
			 }
			  file.close();
		}
}

//////////////////////// M Y  P R O F I L E /////////////////////////////////
void myprofile()
{       clrscr();
	cout<<"\t\t\t\t**********"<<endl;
	cout<<"\t\t\t\tMY PROFILE"<<endl;
	cout<<"\t\t\t\t**********"<<endl;
	ifstream infile("userdata.dat",ios::in);
	if(!infile)
	{
		clrscr();
		cout<<"\n\n\n\n\n\t\t\t\t\tTRY AGAIN ";delay(900);
	}
	else
	{
		while(infile.read((char*)&ob,sizeof(ob)))
			if(pk==ob.getusrid())
				break;
		ob.showusrdetail();
	}
	infile.close();
	getch();
}

/////////////////////////// GET & SHOW DETAIL ///////////////////////////////
void userinfo::getusrdetail()
{
	cout<<setw(18)<<"1. Enter User ID  "<<": ";
	cin>>usrid;
	cout<<setw(18)<<"2. Enter Name     "<<": ";
	gets(usrname);
	cout<<setw(18)<<"3. Enter your age "<<": ";
	cin>>age;
	cout<<setw(18)<<"4. Enter password "<<": ";
	cin>>password ;
}

void userinfo::showusrdetail()
{
	clrscr();
	cout<<"\t\t\t\tUSER DETAILS"<<endl;
	cout<<"USER ID	:"<<usrid<<endl;
	cout<<"USER NAME:"; puts(usrname);
	cout<<"USER AGE :"<<age;
}


/////////////////////////////// SIGNING IN MENU ///////////////////////////
void menu()
{       clrscr();
	int choice;
	cout<<"1. New User"<<endl;
	cout<<"2. Log in"<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1: newuser(); break;
		case 2: login(); break;
		default: cout<<"\n\nTRY AGAIN";
	}
}

//////////////////////////////NEW USER//////////////////////////
void newuser()
{
clrscr();
cout<<"\t\t\t\t\t********"<<endl;
cout<<"\t\t\t\t\tNEW USER"<<endl;
cout<<"\t\t\t\t\t********"<<endl;
ofstream outfile("userdata.dat",ios::out | ios::app);  //Opening of file
	if(!outfile)               //Validation
	{	clrscr();
		cout<<"\n\n\n\n\n\t\t\t\t\tTRY AGAIN..to GAIN";	delay(300);
	}
	else
	{
		ob.getusrdetail();
		outfile.write((char*)&ob,sizeof(ob));
		clrscr();
		cout<<"\n\n\n\n\n\t\t\t\tNew User Added!";delay(1000);
	}
outfile.close();     //closing of file
}

/////////////////////////// LOG IN ///////////////////////////
void login()
{
	clrscr();
	char username[30],pas[20];
	ifstream infile("userdata.dat",ios::in | ios::binary);   //opening
	if(!infile)//validation
	{       clrscr();
		cout<<"\n\n\n\n\n\n\t\t\t\tPlease Try After Some Interval";delay(800);
	}
	else
	{
		infile.seekg(0,ios::beg);
		cout<<"\t\t\t\t***********"<<endl;
		cout<<"\t\t\t\tLOGIN PANEL"<<endl;
		cout<<"\t\t\t\t***********"<<endl;
		cout<<"\n\n";
		cout<<"1. USERNAME	:";
		gets(username);
		cout<<"2. PASSWORD	:";
		gets(pas);
		int flag=0;
		while(infile.read((char*)&ob,sizeof(ob)))
			if(strcmp(ob.getpassword(),pas)==0 && strcmp(ob.getusername(),username)==0)
			{  flag=1;
			   pk=ob.getusrid();
			   break;
			}
			else
			{
				clrscr();
				cout<<"\n\n\n\n\t\t\t\tENTER CORRECT ID or PAS!";delay(900);
			}
		infile.close();
		if(flag==1)
			clientmenu();
	}//Ending Braces
}

////////////////////////////////////MAIN MENU///////////////////////////

void mainmenu()
{       int choice;
	do{clrscr();
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\tSHARE MARKET"<<endl;
	cout<<"\t\t\t\t************"<<endl<<endl;
	cout<<"\t\t\t\t1. CLIENT MENU\n\t\t\t\t2. EXIT \n\n\n\t\t\t\tEnter choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1: {
				clrscr();
				menu();
				break;
			}


		case 2: {       clrscr();

				exit(1);
			}
		default:{	clrscr();
				cout<<"\n\n\n\n\n\n\t\t\t\t TRY AGAIN ";
				getch();
			}
	}
	}while(choice!=3);
	getch();
}

/////////////////////////// C L I E N T   M E N U /////////////////////////
void clientmenu()
{

	int choice;

	do{
	clrscr();
	cout<<"\t\t\t\t***********"<<endl;
	cout<<"\t\t\t\tCLIENT MENU"<<endl;
	cout<<"\t\t\t\t***********"<<endl<<endl;

	cout<<"1. MY PROFILE";
	cout<<"\t\t\t\t\t\t2. EDIT PROFILE"<<endl<<endl;
	cout<<"3. BOOK VEHICLES";
	cout<<"\t\t\t\t\t4. TRANSACTION DETAILS"<<endl;
	cout<<"\t\t\t\t5. LOG OUT"<<endl<<endl;

	cout<<"\n\t\t\t\tSelect Choice   : ";
	cin>>choice;

	switch(choice)
	{
		case 1: {
				clrscr();
				myprofile();
				break;
			}
		case 2: {
				clrscr();
				editprofile();
				break;
			}
		case 3: {       clrscr();
				bookvehicles();
				break;
			}
		case 4: {       clrscr();
				transaction();
				break;
			}
		case 5: {
				clrscr();
				cout<<"\n\n\n\n\n\t\t\t\tLogging Out";
				delay(1000);
			}
		default:{	clrscr();
				//cout<<"\n\n\n\n\n\n\t\t\t\t TRY AGAIN ";
			}
	}
	}while(choice!=5);
}
////////////////////////////// V O I D  M A I N /////////////////////////////
void main()
{ clrscr();
  cout<<"\n\t\t\t***********************";
  cout<<"\n\t\t\tVEHICLE RENTAL SERVICES";
  cout<<"\n\t\t\t***********************"<<endl;
  cout<<"\n\n\t\t Group Members : 1. ANISH KR SINGH(04) \n\t\t\t\t 2. SIDDHARTH PRIYADARSHI(25) \n\t\t\t\t 3. MANTU KUMAR(07) \n\t\t\t\t";
  cout<<"\n\n\n\n\n\t\t\t\t\t\t Press Enter to continue....";
  getch();
  clrscr();
  mainmenu();
}