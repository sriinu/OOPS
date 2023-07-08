#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct patientdata
{
    int wardno, bedno;
	string first_name;
	string last_name;
	int age;
    long long ID;
	char blood[100];
	char gender;
    patientdata*next;
};
class Hospital
{
	patientdata *head,*last;
	public:
	Hospital() //default constructor
	{
		head=NULL;
		last=NULL;
	}
    patientdata input();
    void insertatend();
    void insertatbeg();
    void getpatientoperate();
    void getpatienttoout();
    void listofpatients();
    int search(int);
    char departmentname[50];
};
int Hospital :: search(int item)
{
	 if(head==NULL)
     return false;
     else
     {
     int flag=0;
     patientdata*p=new patientdata();
     p=head;

     while( p->next!=NULL && p->ID!=item )
     {
        p=p->next;
     }
     if(p->ID==item)
     {
	 	flag=1;
	 	return true;
     }
     if(flag==0)
     return false;
     }
}

int readnumber()
{
   char b[20];
   cin.getline(b, sizeof(b));
   return atoi(b);
}

patientdata Hospital :: input()
{
    int flag=0;
   patientdata *p=new patientdata();
   cout << "\n   Please enter data for patient\n";
   cout<<"\n   First name            : ";
   getline(cin,p->first_name);
   cout << "   Last name             : ";
   getline(cin,p->last_name);
   again :
   cout << "   Blood Group           : ";
   cin>>p->blood;
   if((strcmp(p->blood,"A+")==0)||(strcmp(p->blood,"a+")==0)||(strcmp(p->blood,"A-")==0)||(strcmp(p->blood,"a-")==0)||
      (strcmp(p->blood,"B+")==0)||(strcmp(p->blood,"b+")==0)||(strcmp(p->blood,"B-")==0)||(strcmp(p->blood,"b-")==0)||
      (strcmp(p->blood,"O+")==0)||(strcmp(p->blood,"o+")==0)||(strcmp(p->blood,"O-")==0)||(strcmp(p->blood,"o-")==0)||
      (strcmp(p->blood,"AB+")==0)||(strcmp(p->blood,"ab+")==0)||(strcmp(p->blood,"AB-")==0)||(strcmp(p->blood,"ab-")==0))
             flag=1;
    if(flag==0)
    {
        cout<<"\n   Invalid Blood Group Try Again..\n\n";
        goto again;

    }
   cout<<"   Gender(M/F)           :- ";
   cin>>p->gender;
   cout<<"   Age                   :- ";
   cin>>p->age;
   cout<<"   Mobile number         :- ";
   cin>>p->ID;
   cout<<"   Enter the ward number :-";
   cin>>p->wardno;
   cout<<"   Enter the bed number  :-";
   cin>>p->bedno;


	if(search(p->ID))
	{
		p->ID=0;
		cout << "\n   Data not valid. Operation cancelled.";
	}
	return *p;
}
void output(patientdata *p)
{
	cout<<"\n  *********************************************************";
	cout<<"\n   Patient data:\n";
	cout<<"\n   First Name         : "<<p->first_name;
	cout<<"\n   Last Name          : "<<p->last_name;
	cout<<"\n   Gender             : "<<p->gender;
	cout<<"\n   Age                : "<<p->age;
	cout<<"\n   Blood Group        : "<<p->blood;
	cout<<"\n   Mobile Number      : "<<p->ID;
    cout<<"\n   ward number        : "<<p->wardno;
	cout<<"\n   Bed number         : "<<p->bedno;
	cout<<"\n\n *********************************************************";
}
void Hospital :: insertatbeg()
{
     patientdata*p=new patientdata();
     *p=input();
     if(p->ID==0)
     return;

     if(head==NULL)

     {
         head=p;
         last=p;
         p->next=NULL;
     }
     else
     {
        p->next=head;
        head=p;
     }
     system("cls");
     cout << "\n\tPatient added:";
     output(p);
}
void Hospital:: insertatend()
{
     patientdata*p=new patientdata();
     *p=input();
     if(p->ID==0)
     return;

     if(head==NULL)
     {
     	head=p;
        last=p;
        p->next=NULL;
     }
     else
     {
     	p->next=NULL;
        last->next=p;
        last=p;
     }
     system("cls");
     cout<<"\n  *****************************************************\n";
     cout<<"\n  ||      -- HOSPITAL MANAGEMENT SYSTEM --           ||";
     cout<<"\n  *****************************************************\n";
     cout <<"\n  ----------PATIENT ADDED SUCCESSFULY -----------";
     output(p);
}
void Hospital :: getpatientoperate()
{
	 system("cls");
     if(head==NULL)
     {
     	cout<<"\n  No Patient to operate";
     }
     else
     {
     	patientdata*p=new patientdata();
     	p=head;
     	head=head->next;
 	    cout << "\n  Patient to operate:";
        output(p);
        int initial_payment=5000;
        cout<<"\nPlease pay your initial payment :"<<endl;
        cout<<"\nYour initial bill is: "<<initial_payment<<endl;
 	 }
}
void Hospital :: listofpatients()
{
     if(head==NULL)
     {
     	cout<<"\n  No patient";
 	 }
 	      system("cls");
     cout<<"\n  ********************************************\n";
     cout<<"\n  ||   -- HOSPITAL MANAGEMENT SYSTEM --     ||";
     cout<<"\n  ********************************************\n";
     patientdata*p=new patientdata;
     p=head;
     while(p!=NULL)
     {
        cout<<"\n   Patient data:\n";
		cout<<"\n   First Name       : "<<p->first_name;
		cout<<"\n   Last Name        : "<<p->last_name;
		cout<<"\n   Gender           : "<<p->gender;
        cout<<"\n   Age              : "<<p->age;
        cout<<"\n   Blood Group      : "<<p->blood;
		cout<<"\n   Mobile Number    : "<<p->ID;
        cout<<"\n   ward number      : "<<p->wardno;
		cout<<"\n   Bed number       : "<<p->bedno;
		cout<<"\n\n  **************************************************\n"<<endl;
        p=p->next;
     }
     cout<<"\n";
}
void Hospital :: getpatienttoout()
{
    system("cls");
     if(head==NULL)
     {
     	cout<<"\n  No Patient to out";
     }
     else
     {
     	patientdata*p=new patientdata();
     	p=head;
     	head=head->next;
 	    cout << "\n  Patient to out:"<<endl;
        output(p);
        int day, billperday=500;
        cout<<"\n\nEnter the number day patient admit:"; 
        cin>>day;
        cout<<"Please pay your bill :"<<endl;
        cout<<"Your bill is: "<<day*billperday<<endl;
 	 }   
}
void departmentmenu (Hospital * q)
{
    int choice = 0, success;
    patientdata p;
    while (choice != 6)
	{
    system("cls");
    cout<<"\n  *******************************************";
    cout<<"\n  ||   -- HOSPITAL MANAGEMENT SYSTEM --    ||";
    cout<<"\n  *******************************************";
	cout<<"\n\n   "<<q->departmentname;
	cout<<"\n [1] Add normal patient        \n";
	cout<<"   [2] Add critically ill patient\n";
	cout<<"   [3] Take patient to Doctor    \n";
	cout<<"   [4] Display list              \n";
    cout<<"   [5] take patient out          \n";
	cout<<"   [6] Change department or exit \n";
	cout<<"\n   Please enter your choice : ";
	choice=readnumber();
	cout<<"  ***************************************************";

    switch (choice)
	{
	  case 1:	q->insertatend();
				cout << "\n   Press any key";
	    		getch();
	 			break;

      case 2:	q->insertatbeg();
	    		cout << "\n   Press any key";
	    		getch();
				break;

      case 3:	q->getpatientoperate();
	 			cout<<"\n   Press any key";
     			getch();
	      		break;

      case 4:	q->listofpatients();
	 			cout<<"\n   Press any key";
	 			getch();
				break;
      case 5:	system("cls");
                q->getpatienttoout();
	 			cout<<"\n   Press any key";
     			getch();
	      		break;
	 }
    }
}
int main ()
{
    int i, choice = 0;
	Hospital departments[5];

	while(choice!=6)
	{
		strcpy(departments[0].departmentname,"CNACER PATIENT\n");
		strcpy(departments[1].departmentname,"ORTHOPAEDIC CLINIC\n");
		strcpy(departments[2].departmentname,"LUNG CLINIC\n");
		strcpy(departments[3].departmentname,"DENTIST CLINIC\n");
        strcpy(departments[4].departmentname,"HEART CLINIC\n");
		system("cls");
		cout<<"\n  **********************************************";
		cout<<"\n  ||  ---- HOSPITAL MANAGEMENT SYSTEM ----    ||";
		cout<<"\n  **********************************************\n\n";
		cout<<"   Main Menu\n\n";
		for (i = 0; i < 5; i++)
		{
			cout<<"   "<<(i+1)<<": "<<departments[i].departmentname;
		}
		cout<<"   6: Exit";
		cout<<"\n\n   Please enter your choice  : ";
		choice=readnumber();
		if(choice>=1 && choice<=5)
		{
			departmentmenu(&departments[choice-1]);
		}

	}
	if(choice==6)
	cout<<"\n\t\tThank you! \n";
	exit(0);
}