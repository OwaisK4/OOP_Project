#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include<conio.h>
#include <string>
#include <cstdlib>
#include<stdlib.h>
#include <bits/stdc++.h>
#include<fstream>

using namespace std;

char slots[11][3][25]=
{
	{"1","04:00Pm - 4:30Pm","1"},
	{"2","04:30Pm - 5:00Pm","1"},
	{"3","05:30Pm - 06:00Pm","1"},
	{"4","06:00Pm - 6:30Pm","1"},
	{"5","06:30Pm - 7:00Pm","1"},
	{"6","07:00Pm - 7:30Pm","1"},
	{"7","07:30Pm - 8:00Pm","1"},
	{"8","08:00Pm - 8:30Pm","1"},
	{"9","08:30Pm - 9:00Pm","1"},
	{"10","09:00Pm - 9:30Pm","1"},
	{"11","09:30Pm - 10:00Pm","1"},
};
class Hospital
{
	protected:
		int c;
		string line;
		int id;
		string emergencycontact;
  		string name;
  		string illness;
  		int age;
  		string g;
  		string Department;
  		int salary;
  		char ch; 
   	 	int n;
   	 	int p;
   	 	int line_no;
   	 	string fname;
   	 	string lname;
   	 	int ans;
		int positivity;
   	 	char password[10];
};
class Appointment:public Hospital
{
	public:
		int setAppointment()
		{
			int timeslot,qty;
			char r,confirm;
			string name;
			string cellno;
			system("cls");
			int i,j;
			printf("Sr.No\t\tTime Slot\tAppointment Available\n\n");
			for(i=0;i<11;i++)
			{
				for(j=0;j<3;j++)
				{
					printf("%s\t\t",slots[i][j]);
				}
				printf("\n");
			}
			printf("Enter The Sr.No of the Appointment Slot you want to Book(Press 0 to Go Back)\n\t\t\t\t");
			scanf("%d",&timeslot);
			if(timeslot==0)
			{
				system("cls");
				return 1;
			}
			if(timeslot>11)
			{
				printf("\n\nInvalid input\n");
				Sleep(1000);
				system("cls");
				setAppointment();
			}
			if(atoi(slots[timeslot-1][2])==0)
			{
				printf("Appointmnet Slot is full!\n\t\t\t\t\tSorry For inconvenience\n");
				printf("Select Another Time\n");
				Sleep(2000);
				system("cls");
				setAppointment();
			}
			printf("Confirm Appointment\n\nPress Y - Confirm\nPress C - Cancel\nPress Any Key to Quit\n");
			scanf("%s",&confirm);
			if(confirm=='y' || confirm=='Y')
			{
				int qty=1;
				itoa((atoi(slots[timeslot-1][2])-qty),slots[timeslot-1][2],10);
				system("cls");
				cout<<"\nEnter Customer Full Name : ";
				cin>>name;
				cout<<"Enter your Mobile Number : ";
				cin>>cellno;
				system("cls");
				printf("Your Seat has Been reserved!!");
				Sleep(2000);
			}
			if(confirm=='c' || confirm=='C')
			{
				system("cls");
				setAppointment();
			}
			else{
				system("cls");
				return 1;
		}
	}

};
class admitPatient:public Hospital
{
	public:
		void add()
		{
			std::ofstream outfile;
  			outfile.open("Patients.txt", std::ios_base::app);
  			cout<<"Enter 6 Digit Patient ID : "<<endl;
  			cin>>id;
  			cout<<"Enter Patient's First Name : "<<endl;
  			cin>>fname;
  			fflush(stdin);
  			cout<<"Enter Patient's Last Name : "<<endl;
  			getline(cin,lname);
			fflush(stdin);
  			cout<<"Enter Patient Age : "<<endl;
  			cin>>age;
  			cout<<"Enter Patient's Gender : "<<endl;
  			cin>>g;
			fflush(stdin);
  			cout<<"Enter Patient's Illness : "<<endl;
  			cin>>illness;
  			fflush(stdin);
  			cout<<"Enter Patient's Emergency Contact Number : "<<endl;;
  			cin>>emergencycontact;
  			outfile <<"\n"<<id<<"\t"<<fname<<" "<<lname<<"\t"<<age<<"\t"<<g<<"\t"<<illness<<"\t       "<<emergencycontact;
		}
};
class Covid:public Hospital
{
	public:
		void Survey()
		{
			positivity=0;
			cout<<"Select 1 if you have one of the Following Conditions else Select 2\n\n"<<endl;
			cout<<"->Severe difficulty in Breathing(e.g. Struggle for each breath,Not being able to complete Sentences)"<<endl;
			cout<<"->Severe chest pain"<<endl;
			cout<<"->Struggling waking up"<<endl;
			cout<<"->feeling confused"<<endl;
			cout<<"->Lost consciousness"<<endl;
			cout<<" : ";cin>>ans;
			if (ans==1)
			{
				positivity++;
			}
			system("CLS");
			cout<<"Select 1 if you have one of the Following Conditions else Select 2\n\n"<<endl;
			cout<<"->Shortness of breath when resting\n"<<endl;
			cout<<"->Inability to lie down because of difficulty breathing"<<endl;
			cout<<"->Chronic health conditions that you are having difficulty managing because of your current respiratory illness"<<endl;
			cout<<" : ";cin>>ans;
			if (ans==1)
			{
				positivity++;
			}
			system("CLS");
			cout<<"Were you present in any social gathering or crowded place in the last 14 days\nIf YES select 1 otherwise select 2"<<endl;
			cout<<" : ";cin>>ans;
			if (ans==1)
			{
				positivity++;
			}
			system("CLS");
			cout<<"Did you traveled abroad recetly or returned from another country in the last 14 days\nIf yes select 1 otherwise select 2"<<endl;
			cout<<" : ";cin>>ans;
			if (ans==1)
			{
				positivity++;
			}
			system("CLS");
			cout<<"In the last 14 days If you have come across one of these following conditions, Select 1 otherwise select 2"<<endl;
			cout<<"1\tFever"<<endl;
			cout<<"2\tNew onset of cough or worsening of chronic cough"<<endl;
			cout<<"3\tNew or worsening shortness of breath"<<endl;
			cout<<"5\tSore throat"<<endl;
			cout<<"6\tRunny nose"<<endl;
			cout<<" : ";cin>>ans;
			if (ans==1)
			{
				positivity++;
			}
			system("CLS");
			cout<<"Select 1 if you have one of the Following Conditions else Select 2\n\n"<<endl;
			cout<<"1\tchills"<<endl;
			cout<<"2\tPainful swallowing"<<endl;
			cout<<"3\tStuffy nose"<<endl;
			cout<<"4\tHeadache"<<endl;
			cout<<"5\tMuscle or joint ache"<<endl;
			cout<<"6\tFeeling unwell, fatigue or severe exhaustion"<<endl;
			cout<<"7\tNausea, vomiting, diarrhea or unexplained loss of appetite"<<endl;
			cout<<"8\tLoss of sense of smell or taste"<<endl;
			cout<<"9\tConjunctivitis (Pink eye)"<<endl;
			cout<<" : ";cin>>ans;
			if (ans==1)
			{
				positivity++;
			}
			system("CLS");
			cout<<"Were you in Contact with any person who tested positive after your contact with him\nIf yes Select 1 otherwise select 2"<<endl;
			cout<<" : ";cin>>ans;
			if (ans==1)
			{
				positivity++;
			}
			system("CLS");
			cout<<"Is their any Covid 19 patient in your home, If yes select 1 otherwise select 2"<<endl;
			cout<<" : ";cin>>ans;
			if (ans==1)
			{
				positivity++;
			}
			system("CLS");
			cout<<"Has there been an outbreak of Covid 19 in your Office/Workplace/neihborhood/local mosque\nIf yes Select 1 otherwise Select 2 "<<endl;
			cout<<" : ";cin>>ans;
			if (ans==1)
			{
				positivity++;
			}
			system("CLS");
			cout<<"Are you above 60 years of age and already suffer from any medical condition/disease\nIf yes select 1 otherwise select 2"<<endl;
			cout<<" : ";cin>>ans;
			if (ans==1)
			{
				positivity++;
			}
			system("CLS");
			if(positivity>=7)
			{
				system("Color 04"); 
				cout<<"It is Recommended that you set an Appoinment with a Doctor to get Yourself Tested\n"<<endl;
				cout<<"You might have been Exposed to Covid 19 and need to take extreme precautions for your safety"<<endl;
			}
			else if(positivity>=5 && positivity<7){
			    system("Color 0A"); 
				cout<<"It is recommedned that you Quarantine yourseleves for 10-14 days and get yourself Tested\nif new Symptoms appear or Existing condition worsens"<<endl;
				cout<<"Take care of your health and Eat immunity boosting foods"<<endl;
				cout<<"Always wear a Facemask and keep a Check on your Health\nStay Home Stay Safe"<<endl;
			}
			else(positivity<3);
			{
				system("Color 0A"); 
				cout<<"It doesnt Seem like You have Serious Covid 19 Symptoms.\nYou should take a test for your Peace of Mind\nStay Home Stay Safe and avoid Social Gathering!"<<endl;
			}
		}
};
class Admin:public Hospital{
   	 	public:
   	 		int VerifyAdmin()
   	 		{
   	 			p=0;
				printf("Enter Password\n"); 
    			do{ 	
        			password[p]=getch(); 
        			if(password[p]!='\r' && password[p]!='\b')
					{ 
            			printf("*");
        			} 
        			p++; 
    				}while(password[p-1]!='\r' && password[p-1]!='\b');
    			password[p-1]='\0';
				while(strcmp(password,"2a2b")!=0)
				{
					system("cls");
					printf("Enter Password");
					fflush(stdin);
					printf("\n\nPress 0 to Exit\n\n");
					int p=0; 
    				do
					{ 
        				password[p]=getch(); 
	        			if(password[p]!='\r' && password[p]!='\b') 
						{ 
	            			printf("*"); 
	        			} 
	        			p++; 
					}
					while(password[p-1]!='\r' && password[p-1]!='\b'); 
	    			password[p-1]='\0'; 
					if(strcmp(password,"0")==0)
					{
						system("cls");
						return 1;
					}		
				}
			}
};
class Patient:virtual public Admin
{
	public:
		void displayPatient()
		{
			c=1;
			system("cls");
			string line;
			fstream pat; 
			pat.open("Patients.txt",ios::in);   
			if(!pat)
			{ 
				cout<<"File Does not Exist";
			}
			cout<<"Sr.No\tID\tPatient Name\tAge\tGender\tIllness\t      Emergency Contact"<<endl;
			while(!pat.eof()) 
			{
				cout<<c<<"\t"; 
				getline(pat, line);
				c++;
				cout << line<<endl; 
			}	 
			pat.close();
		}

		void discharge()
		{
			std::fstream is;
  			is.open("Patients.txt", std::ios_base::in);
    		ofstream ofs; 
    		ofs.open("temp.txt", ofstream::out); 
			cout<<"\nEnter the Patient you want to Discharge : "<<endl;
			cout<<" : ";cin>>ans;
    		line_no = 1; 
    		while (is.get(ch)) 
    		{ 
        		if (ch == '\n') 
        		{
        			line_no++; 
  				}
        		if (line_no != n) 
            	{	
						ofs << ch;
				}
			}  
    		ofs.close();  
    		is.close(); 
    		remove("Patients.txt"); 
    		rename("temp.txt", "Patients.txt");
    		system("cls");
    		cout<<"Patient Discharged!"<<endl;
    		Sleep(1000);
		}
};
class Doctors:public Admin{
	public:	
		void displayDoctor()
		{
			c=1;
			system("cls");
			fstream doc; 
			doc.open("Doctors.txt",ios::in);   
			if(!doc)
			{ 
				cout<<"File Does not Exist";
			}
			cout<<"Sr.No\tEmployeeID	Name		Age	Gender	Department	Salary\n";
			cout<<"-------------------------------------------------------------------------------\n";
			while(!doc.eof())
			{
				
				cout<<c<<"\t"; 
				getline(doc, line); 
				c++;
				cout << line<<endl; 
			}	 
			doc.close();
		}
		void addDoctor()
		{
			std::ofstream outfile;
  			outfile.open("Doctors.txt", std::ios_base::app);
  			cout<<"Enter Employee ID : "<<endl;
  			cin>>id;
  			cout<<"Enter Doctor full Name : "<<endl;
			fflush(stdin);
  			getline(cin,name);
			fflush(stdin);
  			cout<<"Enter Doctor Age : "<<endl;
  			cin>>age;
  			cout<<"Enter Doctor's Gender : "<<endl;
  			cin>>g;
  			cout<<"Enter Doctor's Department : "<<endl;
  			cin>>Department;
			fflush(stdin);
  			cout<<"Enter Doctor's Salary : "<<endl;;
  			cin>>salary;
  			outfile <<"\n"<<id<<"\t"<<name<<"\t"<<age<<"\t"<<g<<"\t"<<Department<<"\t"<<salary; 
		}
		void deleteDoctor()
		{
			std::fstream is;
  			is.open("Doctors.txt", std::ios_base::in);
    		ofstream ofs; 
    		ofs.open("temp.txt", ofstream::out); 
			displayDoctor();
			cout<<"\nEnter the Doctor you want to Delete : "<<endl;
			cin>>n;
    		line_no = 1; 
    		while (is.get(ch)) 
    		{ 
        	// if a newline character 
        		if (ch == '\n') 
        		{
        			line_no++; 
  				}
        		if (line_no != n) 
            	{	
						ofs << ch;
				}
			}  
    		ofs.close();  
    		is.close(); 
    		remove("Doctors.txt"); 
    		rename("temp.txt", "Doctors.txt");
    		system("cls");
    		cout<<"Record Deleted!"<<endl;
    		Sleep(1000);
		}
};
class Nurse:public Admin{
	public:
		void displayNurse()
		{
			c=1;
			system("cls");
			fstream nur; 
			nur.open("Nurse.txt",ios::in);   
			if(!nur)
			{ 
				cout<<"File Does not Exist";
			}
			cout<<"Sr.No\tEmployeeID	Name		Age	Gender	Department	Salary\n";
			cout<<"-------------------------------------------------------------------------------\n";
			while(!nur.eof()) 
			{
				
				cout<<c<<"\t"; 
				getline(nur, line); 
				c++;
				cout << line<<endl; 
			}	 
			nur.close();
		}
};
class addNurse:public Nurse
{
	public:
		void add()
		{
			std::ofstream outfile;
  			outfile.open("Nurse.txt", std::ios_base::app);
  			cout<<"Enter Employee ID : "<<endl;
  			cin>>id;
  			cout<<"Enter Nurse's First Name : "<<endl;
  			cin>>fname;
  			cout<<"Enter Nurse's Last Name : "<<endl;
  			cin>>lname;
  			cout<<"Enter Doctor Age : "<<endl;
  			cin>>age;
  			cout<<"Enter Doctor's Gender : "<<endl;
  			cin>>g;
  			cout<<"Enter Doctor's Department :"<<endl;
  			cin>>Department;
  			cout<<"Enter Doctor's Salary : "<<endl;;
  			cin>>salary;
  			outfile <<"\n"<<id<<"\t"<<fname<<" "<<lname<<"\t"<<age<<"\t"<<g<<"\t"<<Department<<"\t"<<salary;
		}
	
};
class delNurse:public Nurse{
	public:
		void deleteNurse()
		{
			std::fstream is;
  			is.open("Nurse.txt", std::ios_base::in);
    		ofstream ofs; 
    		ofs.open("temp.txt", ofstream::out); 
			Nurse::displayNurse();
			cout<<"\nEnter the Nurse you want to Delete : "<<endl;
			cin>>n;
    		line_no = 1; 
    		while (is.get(ch)) 
    		{ 
        		if (ch == '\n') 
        		{
        			line_no++; 
  				}
        		if (line_no != n) 
            	{	
						ofs << ch;
				}
			}  
    		ofs.close();  
    		is.close(); 
    		remove("Nurse.txt"); 
    		rename("temp.txt", "Nurse.txt");
    		system("cls");
    		cout<<"Record Deleted!"<<endl;
    		Sleep(1000);
		}
};
class Bill:virtual public Admin{
	protected:
		string cardnum;
		char cvv[3];
		double dues;
	public:
		int payment()
		{
			cout<<"Select Payment of Method\n\n1--->Cash\n\n2--->Credit/Debit : \n";
			cin>>c;
			system("cls");
			if(c==1)
			{
				cout<<"Thankyou for your Payment";
			}
			if(c==2)
			{
				cout<<"Enter 16 Digit Credit/Debit Card number\n";
				cin>>cardnum;
				while(cardnum.size()!=16)
				{
					system("cls");
					fflush(stdin);
					cout<<"Enter 16 Digit Credit/Debit Card number\n\nInvalid Number!! Enter Again\n";
					cout<<"Press 0 to Get Back to Menu\n";
					cout<<"--------------------\n";
					cin>>cardnum;
					if(cardnum[0]=='0')
					{
						return 0;
					}			
				}
				fflush(stdin);
				cout<<"\n----------------------\n";
				cout<<"Enter 3 Digit CARD CVV\n";
				cout<<"----------------------\n";
				cin>>cvv;
				cout<<"\n--------------------\n";
				while(strlen(cvv)!=3)
				{
					fflush(stdin);
					cout<<"Invalid CVV! Enter Again\n";
					cin>>cvv;
				}
				if(cardnum[0]=='4')
				{
					cout<<"\nThankyou for your Payment with VISA";
				}
				else if(cardnum[0]=='5')
				{
					cout<<"\nThankyou for your Payment with MASTERCARD";
				}
				else cout<<"\nThankyou for your Payment";
				
			}
		}
};
class PatientBill: public Bill,public Patient{
	public:
		void calculateBill()
		{
			Patient::displayPatient();
			Patient::discharge();
			cout<<"Enter Dues"<<endl;
			cin>>dues;
			Bill::payment();
			cout<<" of Rupeees "<<dues<<endl;
		}
		
};
int main()
{
	fflush(stdin);
	Admin a;
	Appointment app;
	Patient p;
	admitPatient ap;
	Doctors d;
	Nurse n;
	delNurse dl;
	addNurse an;
	Covid c19;
	Bill b;
	PatientBill pb;
	int c;
	int ver;
	int choice;
	char ch;
	cout<<"Select one of the Following Options\n\n1\tAdmit Patient\n2\tBook Appointment\n3\tCovid Survey\n4\tAdmin"<<endl<<"Enter your choice : ";
	cin>>choice;
	if(choice==1)
	{
		system("cls"); 
		ap.add();
		cout<<"\n\nPatient Record Updated!"<<endl;
		Sleep(2000);
		system("cls");
		main();	
	}

	if(choice==2)
	{
		system("cls");
		ver = app.setAppointment();
		system("cls");
		if(ver==1)
		{
			system("cls");
			main();
		}
	}
	if(choice==3)
	{
		system("cls");
		c19.Survey();
		cout<<"\nPress Any Key to Leave"<<endl;
		cin>>ch;
		if(ch)
		{
			system ( "color 07" );
			system("CLS");
			main();
		}
		
	}
	if(choice==4)
	{
		system("cls");
		ver = a.VerifyAdmin();
		system("cls");
		if(ver==1)
		{
			system("cls");
			main();
		}
		jump:
		cout<<"Select One of the Following Options\n1\tDisplay Patient Record\n2\tDisplay Doctors Record\n3\tAdd Doctors\n4\tDelete Doctor\n5\tDisplay Nurse Record"<<endl;
		cout<<"6\tAdd Nurse\n7\tDelete Nurse\n8\tBilling\n0\tExit"<<endl;
		cin>>c;
		if(c==0)
		{
			cout<<"\nAll changes have been saved......";
			Sleep(1000);
			system("CLS");
			main();
		}
		if(c==1)
		{
			p.displayPatient();
			cout<<"\nPress Any Key to Leave"<<endl;
			cin>>ch;
			if(ch)
			{
				system("CLS");
				goto jump;
			}
		}
		if(c==2)
		{
			d.displayDoctor();
			cout<<"Press Any Key to Leave"<<endl;
			cin>>ch;
			if(ch)
			{
				system("CLS");
				goto jump;
			}
		}
		if(c==3)
		{
			system("cls");
			ch='y';
			while(ch=='y' || ch== 'Y')
			{
			d.addDoctor();
			system("cls");
			cout<<"Record Updated!"<<endl;
			Sleep(1000);
			d.displayDoctor();
			cout<<"\nDo you want to add another record? PRESS Y"<<endl;
			cout<<"Press any Key to Leave"<<endl;
			cin>>ch;
			}
			system("cls");
			goto jump;
		}
		if(c==4)
		{
			d.deleteDoctor();
			d.displayDoctor();
			cout<<"Press Any Key to Leave"<<endl;
			cin>>ch;
			if(ch)
			{
				system("CLS");
				goto jump;
			}
		}
		if(c==5)
		{
			n.displayNurse();
			cout<<"\nPress Any Key to Leave"<<endl;
			cin>>ch;
			if(ch)
			{
				system("CLS");
				goto jump;
			}
		}
		if(c==6)
		{
			ch='y';
			while(ch=='y' || ch== 'Y')
			{
				system("cls");
				an.add();
				system("cls");
				cout<<"Record Updated!"<<endl;
				Sleep(1000);
				an.displayNurse();
				cout<<"\nDo you want to add another record? PRESS Y"<<endl;
				cout<<"Press any Key to Leave"<<endl;
				cin>>ch;
			}
			system("cls");
			goto jump;
		}
		if(c==7)
		{
			dl.deleteNurse();
			dl.displayNurse();
			cout<<"Press Any Key to Leave"<<endl;
			cin>>ch;
			if(ch)
			{
				system("CLS");
				goto jump;
			}
		}
		if(c==8)
		{
			system("cls");
			cout<<"Generate a Bill\n\nSelect one of the Following Option\n1\tAppointment Billing\n2\tPatient Billing\n"<<endl;
			cin>>c;
			if(c==1)
			{
				cout<<"Appointments are Free!!!"<<endl;
				Sleep(2000);
				system("cls");
				goto jump;
			}
			if(c==2)
			{
				pb.calculateBill();
				Sleep(3000);
				system("cls");
				goto jump;
			}
		}
	}
	if(choice>4)
	{
		cout<<"Incorrect Input! Enter Again!\n";
		Sleep(1000);
		system("cls");
		main();
	}
	
}