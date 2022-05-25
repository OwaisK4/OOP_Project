#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#define TOTAL_PASSWORDS 3
using namespace std;

void validate_int(string message, int &var);
void validate_long(string message, unsigned long &var);
void validate_string(string message, char *text, int size);
void write_feedback();
void read_feedback();
void flush();

class Hospital{
	private:
		string Hospital_name;
		string passwords[TOTAL_PASSWORDS] = {"owais3298", "saad3267", "fahad4926"};
	public:
		static int authorization;
		void authenticate(){
			int i;
			string password;
			int try_again;
			flush();
			cout << "\nEnter password: ";
			cin >> password;
			for (i=0; i<TOTAL_PASSWORDS; i++){
				if (password == passwords[i]){
					authorization = i+1;
				}
			}
			while (authorization == 0){
				cout << "\aWrong password! Do you wish to try again?(1 for Yes, 0 to exit program).\n";
				cout << "Choice: ";
				cin >> try_again;
				if (try_again == 0){
					cout << "\nThank you for using Hospital Management System.";
					exit(0);
				}
				else{
					flush();
					cout << "\nEnter password: ";
					cin >> password;
					for (i=0; i<TOTAL_PASSWORDS; i++){
						if (password == passwords[i]){
							authorization = i+1;
						}
					}
				}
			}
		}
		
};

class Person{
	protected:
		char name[60], phone_number[30], DOB[30];
		int age;
	public:
		void set_name(string x){
			strncpy(name, x.c_str(), 60);
		}
		void set_phone_number(string x){
			strncpy(phone_number, x.c_str(), 30);
		}
		void set_DOB(string x){
			strncpy(DOB, x.c_str(), 30);
		}
		void set_age(int x){
			age = x;
		}
		char* get_name(){
			return name;
		}
		char* get_phone_number(){
			return phone_number;
		}

		char* get_DOB(){
			return DOB;
		}
		int get_age(){
			return age;
		}
		virtual void display() = 0;
};

class Personnel : public Person{
	protected:
		int ID, joining_year;
		unsigned long int salary;
	public:
		void set_ID(int x){
			ID = x;
		}
		void set_joining_year(int x){
			joining_year = x;
		}
		void set_salary(int x){
			salary = x;
		}
		int get_ID(){
			return ID;
		}
		int get_salary(){
			return salary;
		}
		int get_joining_year(){
			return joining_year;
		}
		virtual void fire() = 0;
		virtual void hire() = 0;
};

class Doctor : public Personnel{
	protected:
		char specialization[50];
	public:
		static int doctor_count;
		void set_specialization(string x){
			strncpy(specialization, x.c_str(), 50);
		}
		char *get_specialization(){
			return specialization;
		}
		
		Doctor(){
			fstream fin("Doctors.dat", ios::binary | ios::in);
			fin.seekg(0, ios::end);
			int file_size = fin.tellg();
//			cout << "\nTotal file size of Appointments.dat is: " << file_size;
//			cout << "\nNumber of appointments is: " << appointment_number;
			doctor_count = file_size / sizeof(*this);
			fin.close();
		}
		~Doctor(){}
		
		void hire(){
			system("cls");
			string temp;
			cout << "Enter details of doctor you wish to hire.\n";
			flush();
			validate_string("Name: ", name, 50);

			validate_int("ID: ", ID);
			flush();
			validate_string("Phone number: ", phone_number, 30);
			validate_string("Specialization: ", specialization, 50);
			validate_string("Date of Birth: ", DOB, 30);
			validate_int("Age: ", age);
			validate_long("Salary: ", salary);
			validate_int("Joining year: ", joining_year);
			flush();
			fstream fout("Doctors.dat", ios::app | ios::binary);
			fout.write((char *) this, sizeof(*this));
			fout.close();
			doctor_count++;
		}
		void fire(){
			system("cls");
			time_t curr_time;
			curr_time = time(NULL);
			char *tm = ctime(&curr_time);

			int choice;
			int check_ID;
			char check_name[60];
			bool fired = false;
			do{
				cout << "\nWhat do you wish to fire using?\n1 for Name\n2 for ID\n\n";
				do{
					validate_int("Choice: ", choice);
				} while(choice < 1 || choice > 2);
				fstream f("Doctors.dat", ios::binary | ios::in | ios::out);
				if (choice == 1){
					validate_string("Enter name of doctor to fire: ", check_name, 50);
					while (f.read((char *) this, sizeof(*this))){
						if (strcmp(name, check_name) == 0){
							cout << "\nSuccessfully fired Doctor " << name << " having ID: " << ID << "\n";
							ID = 0;
							salary = 0;
							age = 0;
							joining_year = 0;
							char name_of_fired[60] = "Fired doctor on ";
							strcat(name_of_fired, tm);
							strcpy(name, name_of_fired);
							strcpy(phone_number, "0");
							strcpy(specialization, "NULL");
							strcpy(DOB, "NULL");
							f.seekp(-sizeof(*this), ios::cur);
							f.write((char *) this, sizeof(*this));
							fired = true;
							doctor_count--;
							break;
						}
					}
				}
				else if (choice == 2){
					validate_int("Enter ID of doctor to fire: ", check_ID);
					while (f.read((char *) this, sizeof(*this))){
						if (ID == check_ID){
							cout << "\nSuccessfully fired Doctor " << name << " having ID: " << ID << "\n";
							ID = 0;
							salary = 0;
							age = 0;
							joining_year = 0;
//							strcpy(name, "Fired doctor");
							char name_of_fired[60] = "Fired doctor on ";
							strcat(name_of_fired, tm);
							strcpy(name, name_of_fired);
							strcpy(phone_number, "0");
							strcpy(specialization, "NULL");
							strcpy(DOB, "NULL");
							f.seekp(-sizeof(*this), ios::cur);
							f.write((char *) this, sizeof(*this));
							fired = true;
							doctor_count--;
							break;
						}
					}
				}
				if (!fired){
				cout << "Doctor having given details not found. Do you wish to try again?";
				cout << "\n1 to try again\n2 to exit\n\n";
					do{
						validate_int("Choice: ", choice);
					} while(choice < 1 || choice > 2);
				}
				f.close();
				if (choice == 2)
					break;
			} while (!fired);
		}

		void display(){
			system("cls");
			cout << "\nThe details of all current doctors are as follows.\n";
			fstream fin("Doctors.dat", ios::in | ios::binary);
			while (fin.read((char *) this, sizeof(*this))){
				if (ID == 0)
					continue;
				cout << "\nName: " << name;
				cout << "\nID: " << ID;
				cout << "\nPhone number: " << phone_number;
				cout << "\nSpecialization: " << specialization;
				cout << "\nDate of Birth: " << DOB;
				cout << "\nAge: " << age;
				cout << "\nSalary: " << salary;
				cout << "\nJoining year: " << joining_year << "\n";
			}
			fin.close();
		}
		
		void display_fired(){
			system("cls");
			cout << "\nThe details of all current doctors are as follows.\n";
			fstream fin("Doctors.dat", ios::in | ios::binary);
			while (fin.read((char *) this, sizeof(*this))){
				if (ID != 0)
					continue;
				cout << "\nName: " << name;
				cout << "\nID: " << ID;
				cout << "\nPhone number: " << phone_number;
				cout << "\nSpecialization: " << specialization;
				cout << "\nDate of Birth: " << DOB;
				cout << "\nAge: " << age;
				cout << "\nSalary: " << salary;
				cout << "\nJoining year: " << joining_year << "\n";
			}
			fin.close();
		}
		
		void display(Doctor &obj){
//			system("cls");
//			cout << "\nThe details of all current doctors are as follows.\n";
//			fstream fin("Doctors.dat", ios::in | ios::binary);
//			while (fin.read((char *) this, sizeof(*this))){
//				if (ID == 0)
//					continue;
			cout << "\nName: " << obj.get_name();
			cout << "\nID: " << obj.get_ID();
			cout << "\nPhone number: " << obj.get_phone_number();
			cout << "\nSpecialization: " << obj.get_specialization();
			cout << "\nDate of Birth: " << obj.get_DOB();
			cout << "\nAge: " << obj.get_age();
			cout << "\nSalary: " << obj.get_salary();
			cout << "\nJoining year: " << obj.get_joining_year() << "\n";
		}
		
};

//class Nurse : public Personnel{
//	protected:
//		int assigned_ward;
//	public:
//		static int nurse_count;
//};

class Bill{
	public:
		char diseases[5][50] = {"heart attack", "diabetes", "cataract", "cancer", "bone fractures"};
		int charges[5] = {750000, 250000, 30000, 200000, 60000};
		int charge = 10000;
		void calculate_bill(char *disease){
			for (int i=0; i<5; i++){
				if (strcmp(disease, operations[i]) == 0){
					charge = charges[i];
				}
			}
		}
};

class Patient : public Person{
	protected:
		Bill bill;
		int ward_number;
		char disease[50];
	public:
		void set_ward_number(int x){
			ward_number = x;
		}
		void set_disease(string x){
			strncpy(disease, x.c_str(), 49);
		}
		int get_ward_number(){
			return ward_number;
		}
		char *get_disease(){
			return disease;
		}
		static int patient_count;
		
		Patient(){
			fstream fin("Patients.dat", ios::binary | ios::in);
			fin.seekg(0, ios::end);
			int file_size = fin.tellg();
//			cout << "\nTotal file size of Appointments.dat is: " << file_size;
//			cout << "\nNumber of appointments is: " << appointment_number;
			patient_count = file_size / sizeof(*this);
			fin.close();
		}
		~Patient(){}
		
		void admit(){
			system("cls");
			cout << "Enter details of patient you wish to admit.\n";
			flush();
			validate_string("Name: ", name, 60);
			validate_int("Ward number: ", ward_number);
			flush();
			validate_string("Disease: ", disease, 50);
			bill.calculate_bill(disease);
			validate_string("Phone number: ", phone_number, 30);
			validate_string("Date of Birth: ", DOB, 30);
			validate_int("Age: ", age);
			fstream fout("Patients.dat", ios::app | ios::binary);
			fout.write((char *) this, sizeof(*this));
			fout.close();
			patient_count++;
		}
		
		Patient admit(string x){
			cout << "Enter details of patient you wish to admit.\n";
			flush();
			validate_string("Name: ", name, 60);
			validate_int("Ward number: ", ward_number);
			flush();
			validate_string("Disease: ", disease, 50);
			bill.calculate_bill(disease);
			validate_string("Phone number: ", phone_number, 30);
			validate_string("Date of Birth: ", DOB, 30);
			validate_int("Age: ", age);
			patient_count++;
			return *this;
		}
		
		void discharge(){
			system("cls");
			time_t curr_time;
			curr_time = time(NULL);
			char *tm = ctime(&curr_time);
//			cout << "Today is : " << tm;
			
			int choice;
			int check_ID;
			char check_name[60];
			bool discharged = false;
			do{
				cout << "\nWhat do you wish to fire using?\n1 for Name\n2 for Ward number\n\n";
				do{
					validate_int("Choice: ", choice);
				} while(choice < 1 || choice > 2);
				fstream f("Patients.dat", ios::binary | ios::in | ios::out);
				if (choice == 1){
					validate_string("Enter name of patient to discharge: ", check_name, 50);
					while (f.read((char *) this, sizeof(*this))){
						if (strcmp(name, check_name) == 0){
							cout << "\nSuccessfully discharged patient " << name << " from Ward: " << ward_number << "\n";
							ward_number = 0;
							age = 0;
							char name_of_discharged[60] = "Discharged patient on ";
							strcat(name_of_discharged, tm);
							strcpy(name, name_of_discharged);
							strcpy(phone_number, "0");
							strcpy(disease, "NULL");
							strcpy(DOB, "NULL");
							bill.charge = 0;
							f.seekp(-sizeof(*this), ios::cur);
							f.write((char *) this, sizeof(*this));
							discharged = true;
							patient_count--;
							break;
						}
					}
				}
				else if (choice == 2){
					validate_int("Enter name of patient to discharge: ", check_ID);
					while (f.read((char *) this, sizeof(*this))){
						if (ward_number == check_ID){
							cout << "\nSuccessfully discharged patient " << name << " from Ward: " << ward_number << "\n";
							ward_number = 0;
							age = 0;
							char name_of_discharged[60] = "Discharged patient on ";
							strcat(name_of_discharged, tm);
							strcpy(name, name_of_discharged);
							strcpy(phone_number, "0");
							strcpy(disease, "NULL");
							strcpy(DOB, "NULL");
							bill.charge = 0;
							f.seekp(-sizeof(*this), ios::cur);
							f.write((char *) this, sizeof(*this));
							discharged = true;
							patient_count--;
							break;
						}
					}
				}
				if (!discharged){
				cout << "Patient having given details not found. Do you wish to try again?";
				cout << "\n1 to try again\n2 to exit\n\n";
					do{
						validate_int("Choice: ", choice);
					} while(choice < 1 || choice > 2);
				}
				f.close();
				if (choice == 2)
					break;
			} while (!discharged);
		}
		
		void display(){
			system("cls");
			cout << "\nThe details of all admitted patients are as follows.\n";
			fstream fin("Patients.dat", ios::in | ios::binary);
			while (fin.read((char *) this, sizeof(*this))){
				if (ward_number == 0)
					continue;
				cout << "\nName: " << name;
				cout << "\nWard number: " << ward_number;
				cout << "\nDisease: " << disease;
				cout << "\nPhone number: " << phone_number;
				cout << "\nDate of Birth: " << DOB;
				cout << "\nAge: " << age;
				cout << "\nBill: " << bill.charge << "\n";
			}
			fin.close();
		}
		void display_discharged(){
			system("cls");
			cout << "\nThe details of all admitted patients are as follows.\n";
			fstream fin("Patients.dat", ios::in | ios::binary);
			while (fin.read((char *) this, sizeof(*this))){
				if (ward_number != 0)
					continue;
				cout << "\nName: " << name;
				cout << "\nWard number: " << ward_number;
				cout << "\nDisease: " << disease;
				cout << "\nPhone number: " << phone_number;
				cout << "\nDate of Birth: " << DOB;
				cout << "\nAge: " << age;
				cout << "\nBill: " << bill.charge << "\n";
			}
			fin.close();
		}
		
		void display(Patient obj){
//			system("cls");
			cout << "\nName: " << obj.get_name();
			cout << "\nWard number: " << obj.get_ward_number();
			cout << "\nDisease: " << obj.get_disease();
			cout << "\nPhone number: " << obj.get_phone_number();
			cout << "\nDate of Birth: " << obj.get_DOB();
			cout << "\nAge: " << obj.get_age() << "\n";
			cout << "\nBill: " << obj.bill.charge << "\n";
		}
		
		void survey(){
			int positivity = 0, ans = 0;
			cout<<"Select 1 if you have one of the Following Conditions else Select 2\n\n"<<endl;
			cout<<"->Severe difficulty in Breathing(e.g. Struggle for each breath,Not being able to complete Sentences)"<<endl;
			cout<<"->Severe chest pain"<<endl;
			cout<<"->Struggling waking up"<<endl;
			cout<<"->feeling confused"<<endl;
			cout<<"->Lost consciousness"<<endl;
			validate_int("Enter choice: ", ans);
			if (ans == 1){
				positivity++;
			}
			system("CLS");
			cout<<"Select 1 if you have one of the Following Conditions else Select 2\n\n"<<endl;
			cout<<"->Shortness of breath when resting\n"<<endl;
			cout<<"->Inability to lie down because of difficulty breathing"<<endl;
			cout<<"->Chronic health conditions that you are having difficulty managing because of your current respiratory illness"<<endl;
			validate_int("Enter choice: ", ans);
			if (ans == 1){
				positivity++;
			}
			system("CLS");
			cout<<"Were you present in any social gathering or crowded place in the last 14 days\nIf YES select 1 otherwise select 2"<<endl;
			validate_int("Enter choice: ", ans);
			if (ans == 1){
				positivity++;
			}
			system("CLS");
			cout<<"Did you traveled abroad recetly or returned from another country in the last 14 days\nIf yes select 1 otherwise select 2"<<endl;
			cout<<" : ";cin>>ans;
			validate_int("Enter choice: ", ans);
			if (ans == 1){
				positivity++;
			}
			system("CLS");
			cout<<"In the last 14 days If you have come across one of these following conditions, Select 1 otherwise select 2"<<endl;
			cout<<"1\tFever"<<endl;
			cout<<"2\tNew onset of cough or worsening of chronic cough"<<endl;
			cout<<"3\tNew or worsening shortness of breath"<<endl;
			cout<<"5\tSore throat"<<endl;
			cout<<"6\tRunny nose"<<endl;
			validate_int("Enter choice: ", ans);
			if (ans == 1){
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
			validate_int("Enter choice: ", ans);
			if (ans == 1){
				positivity++;
			}
			system("CLS");
			cout<<"Were you in Contact with any person who tested positive after your contact with him\nIf yes Select 1 otherwise select 2"<<endl;
			validate_int("Enter choice: ", ans);
			if (ans == 1){
				positivity++;
			}
			system("CLS");
			cout<<"Is their any Covid 19 patient in your home, If yes select 1 otherwise select 2"<<endl;
			validate_int("Enter choice: ", ans);
			if (ans == 1){
				positivity++;
			}
			system("CLS");
			cout<<"Has there been an outbreak of Covid 19 in your Office/Workplace/neihborhood/local mosque\nIf yes Select 1 otherwise Select 2 "<<endl;
			validate_int("Enter choice: ", ans);
			if (ans == 1){
				positivity++;
			}
			system("CLS");
			cout<<"Are you above 60 years of age and already suffer from any medical condition/disease\nIf yes select 1 otherwise select 2"<<endl;
			validate_int("Enter choice: ", ans);
			if (ans == 1){
				positivity++;
			}
			system("CLS");
			if(positivity>=7)
			{
//				system("Color 04");
				cout<<"It is Recommended that you set an Appoinment with a Doctor to get Yourself Tested\n"<<endl;
				cout<<"You might have been Exposed to Covid 19 and need to take extreme precautions for your safety"<<endl;
				
			}
			else if(positivity>=5 && positivity<7){
//			    system("Color 0A"); 
				cout<<"It is recommedned that you Quarantine yourseleves for 10-14 days and get yourself Tested\nif new Symptoms appear or Existing condition worsens"<<endl;
				cout<<"Take care of your health and Eat immunity boosting foods"<<endl;
				cout<<"Always wear a Facemask and keep a Check on your Health\nStay Home Stay Safe"<<endl;
			}
			else(positivity<3);
			{
//				system("Color 0A"); 
				cout<<"It doesnt Seem like You have Serious Covid 19 Symptoms.\nYou should take a test for your Peace of Mind\nStay Home Stay Safe and avoid Social Gathering!"<<endl;
			}
		}
};

class Appointment{
	protected:
		char newtime[50];
		Doctor doctor;
		Patient patient;
	public:
		static int appointment_number;
		Appointment(){
			fstream fin("Appointments.dat", ios::binary | ios::in);
			fin.seekg(0, ios::end);
			int file_size = fin.tellg();
//			cout << "\nTotal file size of Appointments.dat is: " << file_size;
//			cout << "\nNumber of appointments is: " << appointment_number;
			appointment_number = file_size / sizeof(*this);
			fin.close();
		}
		~Appointment(){}
		
		void schedule_appointment(){
			system("cls");
			int choice;
			int day;
			int check_ID;
			char check_name[60];
			bool found_doctor = false;
			bool found_patient = false;
			cout << "\nHow many days from now would you like to schedule appointment?\n";
			try{
				validate_int("Enter no. of days: ", day);
				if (day == 0)
					throw(day);
			}
			catch(int x){
				cout << "\nCannot schedule appointment for current day. Please try again later.\n";
				return;
			}
			
			//	Searching for doctor in Doctors.dat
			do{
				fstream f("Doctors.dat", ios::binary | ios::in | ios::out);
				cout << "Enter name or ID of doctor you wish to schedule appointment with:";
				cout << "\n1 for Name\n2 for ID\n\n";
				do{
					validate_int("Choice: ", choice);
				} while(choice < 1 || choice > 2);
				
				if (choice == 1){
					validate_string("Enter name of doctor to schedule appointment with: ", check_name, 50);
					
					while (f.read((char *) &doctor, sizeof(doctor))){
						if (strcmp(doctor.get_name(), check_name) == 0){
							found_doctor = true;
							break;
						}
					}
				}
				else if (choice == 2){
					validate_int("Enter ID of doctor to schedule appointment with: ", check_ID);
					while (f.read((char *) &doctor, sizeof(doctor))){
						if (doctor.get_ID() == check_ID){
							found_doctor = true;
							break;
						}
					}
				}
			if (!found_doctor){
				cout << "Doctor having given details not found. Do you wish to try again?";
				cout << "\n1 to try again\n2 to exit\n\n";
				do{
					validate_int("Choice: ", choice);
				} while(choice < 1 || choice > 2);
			}
			f.close();
			if (choice == 2)
				break;
			} while (!found_doctor);

			
			//	Searching for patient in Patients.dat
			do{
				cout << "\nDo you wish to schedule for already admitted patient or new patient?";
				cout << "\n1 for Admitted patient\n2 for New patient\n\n";
				do{
					validate_int("Choice: ", choice);
				} while(choice < 1 || choice > 2);
				if (choice == 1){
					fstream f("Patients.dat", ios::binary | ios::in | ios::out);
					cout << "\nEnter name or ward number of patient you wish to schedule appointment with:";
					cout << "\n1 for Name\n2 for ward number\n\n";
					do{
						validate_int("Choice: ", choice);
					} while(choice < 1 || choice > 2);
					
					if (choice == 1){
						validate_string("Enter name of patient to schedule appointment for: ", check_name, 50);
						
						while (f.read((char *) &patient, sizeof(patient))){
							if (strcmp(patient.get_name(), check_name) == 0){
								found_patient = true;
								break;
							}
						}
					}
					else if (choice == 2){
						validate_int("\nEnter ID of doctor to schedule appointment for: ", check_ID);
						while (f.read((char *) &patient, sizeof(patient))){
							if (patient.get_ward_number() == check_ID){
								found_patient = true;
								break;
							}
						}	
					}
					if (!found_patient){
						cout << "\nDoctor having given details not found. Do you wish to try again?";
						cout << "\n1 to try again\n2 to exit\n\n";
						do{
							validate_int("Choice: ", choice);
						} while(choice < 1 || choice > 2);
					}
					f.close();
					if (choice == 2)
						break;
				}
				else if (choice == 2){
					found_patient = true;
					patient = patient.admit("Using");
				}
			} while (!found_patient);
			
			time_t curr_time;
			curr_time = time(NULL);
			struct tm* tm = localtime(&curr_time);
		    tm->tm_mday += day;
    		time_t next = mktime(tm);
			strncpy(newtime, ctime(&next), 50);
			
	    	fstream fout("Appointments.dat", ios::binary | ios::out);
	    	fout.write((char *) this, sizeof(*this));
	    	fout.close();
	    	appointment_number++;
		}
		
		void display(){
			system("cls");
			cout << "\nThe appointments of all patients are as follows.\n";
			fstream fin("Appointments.dat", ios::in | ios::binary);
			while (fin.read((char *) this, sizeof(*this))){
				if (appointment_number == 0)
					continue;
				cout << "Appointment number: " << appointment_number;
				cout << "\nAppointment scheduled for " << newtime;
				cout << "\nDOCTOR: ";
				doctor.display(doctor);
				cout << "\nPATIENT: ";
				patient.display(patient);				
			}
			fin.close();
		}
		void display_cancelled(){
			system("cls");
			cout << "\nThe appointments of all patients are as follows.\n";
			fstream fin("Appointments.dat", ios::in | ios::binary);
			while (fin.read((char *) this, sizeof(*this))){
				if (appointment_number != 0)
					continue;
				cout << "Appointment number: " << appointment_number;
				cout << "\nAppointment scheduled for " << newtime;
				cout << "\nDOCTOR: ";
				doctor.display(doctor);
				cout << "\nPATIENT: ";
				patient.display(patient);				
			}
			fin.close();
		}
		
		void cancel(){
			system("cls");
			time_t curr_time;
			curr_time = time(NULL);
			char *tm = ctime(&curr_time);

			int choice;
			int check_ID;
			bool cancelled = false;
			do{
				fstream f("Appointments.dat", ios::binary | ios::in | ios::out);
					validate_int("Enter appointment number to cancel: ", check_ID);
					while (f.read((char *) this, sizeof(*this))){
						if (appointment_number == check_ID){
							cout << "\nSuccessfully cancelled appointment of patient " << patient.get_name() << " for doctor: " << doctor.get_name() << "\n";
							patient.set_ward_number(0);
							patient.set_age(0);
							char name_of_discharged[60] = "Discharged patient on ";
							strcat(name_of_discharged, tm);
							patient.set_name(name_of_discharged);
							patient.set_phone_number("0");
							patient.set_disease("NULL");
							patient.set_DOB("NULL");
							doctor.set_ID(0);
							doctor.set_salary(0);
							doctor.set_age(0);
							doctor.set_joining_year(0);
							char name_of_fired[60] = "Fired doctor on ";
							strcat(name_of_fired, tm);
							doctor.set_name(name_of_fired);
							doctor.set_phone_number("0");
							doctor.set_specialization("NULL");
							doctor.set_DOB("NULL");
							f.seekp(-sizeof(*this), ios::cur);
							f.write((char *) this, sizeof(*this));
							cancelled = true;
							appointment_number--;
							break;
						}
					}
				if (!cancelled){
				cout << "Appointment number: " << check_ID << "not found. Do you wish to try again?";
				cout << "\n1 to try again\n2 to exit\n\n";
					do{
						validate_int("Choice: ", choice);
					} while(choice < 1 || choice > 2);
				}
				f.close();
				if (choice == 2)
					break;
			} while (!cancelled);
		}
};

void write_feedback(){
	string line;
	cout << "Enter feedback: ";
	flush();
	getline(cin, line);
	fstream fd("feedback.txt", ios::app);
	fd << line << "\n";
	fd.close();
}
void read_feedback(){
	string line;
	cout << "Feedback:\n";
	fstream fd("feedback.txt", ios::in);
	while (getline(cin, line)){
		cout << line;
	}
	fd.close();
}

void validate_int(string message, int &var){
	cout << message;
	cin >> var;
	while (cin.fail()){
		cin.clear();
		cin.ignore(256, '\n');
		cout << message;
		cin >> var;
	}
}
void validate_long(string message, unsigned long &var){
	cout << message;
	cin >> var;
	while (cin.fail()){
		cin.clear();
		cin.ignore(256, '\n');
		cout << message;
		cin >> var;
	}
}

void validate_string(string message, char *text, int size){
	string temp;
	do{
		cout << message;
		getline(cin, temp);
	} while(temp.empty());
	strncpy(text, temp.c_str(), size);
}

void flush(){
	cin.clear();
	cin.ignore(256, '\n');
}

int Hospital::authorization = 0;
int Doctor::doctor_count = 0;
int Patient::patient_count = 0;
int Appointment::appointment_number = 0;
