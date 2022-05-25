#include <iostream>
#include "fstream_strtok.h"
#include "classes.h"
#include <conio.h>
using namespace std;

int main(){
	int i, choice;
	bool end_program = false;
	Hospital h;
	Doctor doctor;
	Patient patient;
	Appointment appoint;
	system("cls");
	printf("\n\n\t\t\tWELCOME TO HOSPITAL MANAGEMENT SYSTEM\n");
	h.authenticate();
	cout << "\nAuthorization level: " << h.authorization << "\n";
	do{
		cout << "\nPress:\n1 for Patient functions\n";
		if (h.authorization <= 2){
			cout << "2 for Doctor functions\n";
			
			if (h.authorization <= 1){
				cout << "3 for Appointment functions\n";
			}
		}
		cout << "0 to exit Hospital Management System\n";
		
		if (h.authorization == 1){
			do{
				validate_int("Enter choice: ", choice);
			} while(choice < 0 || choice > 3);
		}
		
		else if (h.authorization == 2){
			do{
				validate_int("Enter choice: ", choice);
			} while(choice < 0 || choice > 2);
		}
		
		else if (h.authorization == 3){
			do{
				validate_int("Enter choice: ", choice);
			} while(choice < 0 || choice > 1);
		}
	
		if (choice == 1){
			int function = 0;
			system("cls");
			cout << "\nPress:\n1 to admit patient\n";
			cout << "2 to discharge patient\n";
			cout << "3 to display current patients\n";
			cout << "4 to display discharged patient\n";
			cout << "5 to take Covid-19 survey\n";
			cout << "6 to get count of currently admitted patient\n";
			cout << "7 to write feedback\n";
			cout << "8 to read feedback\n";
			do{
				validate_int("Enter choice: ", function);
			} while(function < 1 || function > 8);
			if (function == 1)
				patient.admit();
			else if (function == 2)
				patient.discharge();
			else if (function == 3)
				patient.display();
			else if (function == 4)
				patient.display_discharged();
			else if (function == 5)
				patient.survey();
			else if (function == 6)
				cout << "\nTotal current patient count is: " << patient.patient_count << "\n";
			else if (function == 7)
				write_feedback();
			else if (function == 8)
				read_feedback();
			cout << "\nPress any key to continue...";
			getch();
		}
		else if (choice == 2){
			system("cls");
			int function = 0;
			cout << "\nPress:\n1 to hire doctor\n";
			cout << "2 to fire doctor\n";
			cout << "3 to display current doctors\n";
			cout << "4 to display fired doctors\n";
			cout << "5 to get count of currently hired doctors\n";
			do{
				validate_int("Enter choice: ", function);
			} while(function < 1 || function > 5);
			if (function == 1)
				doctor.hire();
			else if (function == 2)
				doctor.fire();
			else if (function == 3)
				doctor.display();
			else if (function == 4)
				doctor.display_fired();
			else if (function == 5)
				cout << "\nTotal hired doctor count is: " << doctor.doctor_count << "\n";
			cout << "\nPress any key to continue...";
			getch();			
		}
		else if (choice == 3){
			system("cls");
			int function = 0;
			cout << "\nPress:\n1 to schedule appointment\n";
			cout << "2 to cancel appointment\n";
			cout << "3 to display scheduled appointments\n";
			cout << "4 to display scheduled appointments\n";
			do{
				validate_int("Enter choice: ", function);
			} while(function < 1 || function > 4);
			if (function == 1)
				appoint.schedule_appointment();
			else if (function == 2)
				appoint.cancel();
			else if (function == 3)
				appoint.display();
			else if (function == 4)
				appoint.display_cancelled();
			cout << "\nPress any key to continue...";
			getch();			
		}
		else {
			end_program = true;
			break;
		}
		cout << "\nDo you wish to try again?";
		cout << "\n1 to try again\n2 to exit\n\n";
		do{
			validate_int("Choice: ", choice);
		} while(choice < 1 || choice > 2);
			if (choice == 2)
				break;
		} while (!end_program);
		
	cout << "\nThank you for using Hospital Management System.\n";
	cout << "Press any key to continue...";
	getch();
	
	return 0;
}

//int main(){	
//	Hospital h;
////	h.authenticate();
//	Hospital h;
//	Doctor doctor;
//	Patient patient;
//	Appointment appoint;
//	Doctor doctor;
//	Patient patient;
//	Appointment appoint;
////	doctor.hire();
////	doctor.display();
////	doctor.fire();
////	patient.admit();
//	patient.display();
////	appoint.schedule_appointment();
////	appoint.display();
////	appoint.cancel();
//	return 0;
//}
