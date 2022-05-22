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
		char name[60], phone_number[30], email[50], DOB[30];
		int age;
	public:
		void set_name(string x){
			strncpy(name, x.c_str(), 60);
		}
		void set_phone_number(string x){
			strncpy(phone_number, x.c_str(), 30);
		}
		void set_email(string x){
			strncpy(email, x.c_str(), 40);
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
		char* get_email(){
			return email;
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
		virtual void fire() = 0;
		virtual void hire() = 0;
};

class Doctor : public Personnel{
	protected:
		char specialization[50];
	public:
		static int doctor_count;
//		friend void validate_int(string message, int &var);
		void hire(){
//		char name[60], phone_number[30], email[50], DOB[30];
//		int age;
			system("cls");
			string temp;
//			flush();
			cout << "Enter details of doctor you wish to hire.\n";
			cout << "Name: ";
			cin.getline(name, 60);
			cout << "Phone number: ";
			cin.getline(phone_number, 30);
			cout << "Specialization: ";
			cin.getline(specialization, 50);
			cout << "Date of Birth: ";
			cin.getline(DOB, 30);
			validate_int("Age: ", age);
			validate_long("Salary: ", salary);
			cout << "Email: ";
			cin.getline(email, 50);
			
			fstream fout("Doctors.dat", ios::app | ios::binary);
			fout.write((char *) this, sizeof(*this));
			fout.close();
		}
		void fire(){
		}
		void display(){
			cout << "The details of all current doctors are as follows.\n";
			fstream fin("Doctors.dat", ios::in | ios::binary);
			while (fin.read((char *) this, sizeof(*this))){
				cout << "\nName: " << name;
				cout << "\nPhone number: " << phone_number;
				cout << "\nSpecialization: " << specialization;
				cout << "\nDate of Birth: " << DOB;
				cout << "\nAge: " << age;
				cout << "\nSalary: " << salary;
				cout << "\nEmail: " << email << "\n";
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
