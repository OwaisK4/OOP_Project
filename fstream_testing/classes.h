#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#define TOTAL_PASSWORDS 3
using namespace std;

void validate_int(string message, int &var);
void validate_long(string message, unsigned long &var);
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
			cout << "\nEnter password: ";
			fflush(stdin);
			cin >> password;
			for (i=0; i<TOTAL_PASSWORDS; i++){
				if (password == passwords[i]){
					authorization = i+1;
				}
			}
			while (authorization == 0){
				cout << "Wrong password! Do you wish to try again?(1 for Yes, 0 to exit program).\n";
				cout << "Choice: ";
				cin >> try_again;
				if (try_again == 0){
					cout << "\nThank you for using Hospital Management System.";
					exit(0);
				}
				else{
					fflush(stdin);
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
//		char email[50];
		int age;
	public:
		void set_name(string x){
			strncpy(name, x.c_str(), 60);
		}
		void set_phone_number(string x){
			strncpy(phone_number, x.c_str(), 30);
		}
//		void set_email(string x){
//			strncpy(email, x.c_str(), 40);
//		}
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
//		char* get_email(){
//			return email;
//		}
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
		virtual void fire() = 0;
		virtual void hire() = 0;
};

class Doctor : public Personnel{
	protected:
		char specialization[50];
	public:
		static int doctor_count;
		void hire(){
			system("cls");
			string temp;
			cout << "Enter details of doctor you wish to hire.\n";
			flush();
			do{
				cout << "Name: ";
				getline(cin, temp);
			} while(temp.empty());
			strncpy(name, temp.c_str(), 50);
			validate_int("ID: ", ID);
			flush();
			do{
				cout << "Phone number: ";
				getline(cin, temp);
			} while(temp.empty());
			strncpy(phone_number, temp.c_str(), 30);
			do{
				cout << "Specialization: ";
				getline(cin, temp);
			} while(temp.empty());
			strncpy(specialization, temp.c_str(), 50);
			do{
				cout << "Date of Birth: ";
				getline(cin, temp);
			} while(temp.empty());
			strncpy(DOB, temp.c_str(), 30);
			validate_int("Age: ", age);
			validate_long("Salary: ", salary);
			validate_int("Joining year: ", joining_year);
			flush();
//			do{
//				cout << "Email: ";
//				getline(cin, temp);
//			} while(temp.empty());
//			strncpy(email, temp.c_str(), 50);

			fstream fout("Doctors.dat", ios::app | ios::binary);
			fout.write((char *) this, sizeof(*this));
			fout.close();
		}
		void fire(){
			int choice;
			int check_ID;
			char check_name[50];
			bool fired = false;
			memset(check_name, '\0',  sizeof(check_name));
			do{
			cout << "\nWhat do you wish to fire using?\n1 for Name\n2 for ID\n\n";
			do{
//				cout << "Choice: ";
//				cin >> choice;
				validate_int("Choice: ", choice);
			} while(choice < 1 || choice > 2);
			fstream f("Doctors.dat", ios::binary | ios::in | ios::out);
			if (choice == 1){
				cout << "Enter name of doctor to fire: ";
				do{
					cin.getline(check_name, 50);
				} while(check_name[0] == '\0');
				while (f.read((char *) this, sizeof(*this))){
					if (strcmp(name, check_name) == 0){
						cout << "\nSuccessfully fired Doctor " << name << " having ID: " << ID << "\n";
						ID = 0;
						salary = 0;
						age = 0;
						joining_year = 0;
						strcpy(name, "Fired doctor");
						strcpy(phone_number, "0");
						strcpy(specialization, "NULL");
						strcpy(DOB, "NULL");
//						cout << "\nName: " << name;
//						cout << "\nID: " << ID;
//						cout << "\nPhone number: " << phone_number;
//						cout << "\nSpecialization: " << specialization;
//						cout << "\nDate of Birth: " << DOB;
//						cout << "\nAge: " << age;
//						cout << "\nSalary: " << salary;
//						cout << "\nJoining year: " << joining_year << "\n";
						f.seekp(-sizeof(*this), ios::cur);
						f.write((char *) this, sizeof(*this));
						fired = true;
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
						strcpy(name, "Fired doctor");
						strcpy(phone_number, "0");
						strcpy(specialization, "NULL");
						strcpy(DOB, "NULL");
						f.seekp(-sizeof(*this), ios::cur);
						f.write((char *) this, sizeof(*this));
						fired = true;
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
			cout << "\nThe details of all current doctors are as follows.\n";
			fstream fin("Doctors.dat", ios::in | ios::binary);
			while (fin.read((char *) this, sizeof(*this))){
//				if (ID == 0)
//					continue;
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
};
class Nurse : public Personnel{
	protected:
		int assigned_ward;
	public:
		static int nurse_count;
};

class Patient : public Person{
	protected:
		char disease[50];
	public:
		static int patient_count;
};

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
void flush(){
	cin.clear();
	cin.ignore(256, '\n');
}

int Hospital::authorization = 0;
int Doctor::doctor_count = 0;
int Nurse::nurse_count = 0;
int Patient::patient_count = 0;
