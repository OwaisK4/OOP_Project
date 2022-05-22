#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define TOTAL_PASSWORDS 3
#define TOTAL_USERS 3

int validate_int(void);
long int validate_long_int(void);
void menu();
void display();
void add_employee();
void search_employee();
void changedetail();
void delete_employee();
void change_salary();
void batch_change_salary();
void decode_file(char *read, char *write);
void encode_file(char *read, char *write);
void encode_to_temp();

int authorization;
//char passwords[TOTAL_PASSWORDS][30] = {"owais", "ali", "khan"};
char passwords[TOTAL_PASSWORDS][30] = {"owais3298", "saad3267", "fahad4926"};
char users[TOTAL_USERS][50] = {"CEO", "Manager", "Worker"};
	
struct employees{
	int id, join_year, permanent;
	long int salary;
	long phone;
 	char name[20], designation[20], dob[20];
}d[100];

int main(){
	printf("\n\n\n");
	system("color 60");
	printf("\t\t*    *    *  *******    *         *********   ***********   *       *   *******\n");
	printf("\t\t*   * *   *  *          *         *           *         *   * *   * *   *\n");
	printf("\t\t*  *   *  *  *******    *         *           *         *   *   *   *   *******\n");
	printf("\t\t* *     * *  *          *         *           *         *   *       *   *\n");
	printf("\t\t*         *  *******    ********  *********   ***********   *       *   *******\n");
	printf("\nBuilt by\nK21-3298 Owais Ali Khan\nK21-3267 Mohammad Saad\nK21-4926 Fahad Ahmed\n");
	printf("\n\npress any key to continue...");
	getch();
    system("CLS");
    
	int i, pass_flag=0;
	authorization=0;
	int retry;
	FILE *fa;
	char pass[30];
	printf("Enter password: ");
	fflush(stdin);
	gets(pass);
//	char passwords[TOTAL_PASSWORDS][30] = {"owais", "ali", "khan"};
//	char users[TOTAL_USERS][50] = {"CEO", "Manager", "Worker"};
	for (i=0; i<TOTAL_PASSWORDS; i++){
		if (strcmp(pass, passwords[i]) == 0){
			pass_flag = 1;
			authorization = i;
		}
	}
	if (pass_flag == 1){
		decode_file("encoded.txt", "decoded.txt");
		system("color 20");
		printf("Login successful. Currently logged in as %s with authorization level %d.\n",users[authorization], authorization);
//		getch();
//		system("color 60");
		int h,g;
		printf("\t\t\t\tLOADING");
		for(h=0;h<=10;h++){
			printf(" . ");
			for(g=0;g<=100000000;g++){
			}
		}
		system("color 60");
		menu(authorization);
	}
	else{
		system("color 40");
		printf("\a\nGiven password not in authorization list.\nEnter any key to try again, or 0 to exit: ");
		int num;
		num = getch();
		if (num-48 == 0){
//			system("color 64");
			system("cls");
			encode_file("decoded.txt", "encoded.txt");
			remove("decoded.txt");
			exit(0);
		}
		else{
			system("cls");
			main();
		}
/*
		if (num == 0){
			system("cls");
			remove("decoded.txt");
			exit(0);
		}
*/
		
	}
	encode_file("decoded.txt", "encoded.txt");
	remove("decoded.txt");
}

void decode_file(char *read, char *write){
	char ch;
	FILE *fp, *fp2;
	fp = fopen(read, "r");
	if(fp == NULL)
        return;
    fp2 = fopen(write, "w");
    if(fp2 == NULL)
        return;
    ch = fgetc(fp);
    while(ch != EOF){
		if (ch != '\n')
			ch = ch - 10;
		fputc(ch, fp2);
		ch = fgetc(fp);
    }
	fflush(stdout);
	fclose(fp2);
	fclose(fp);
}

void encode_file(char *read, char *write){
	char ch;
	FILE *fp, *fp2;
	fp = fopen(read, "r");
	if(fp == NULL)
        return;
    fp2 = fopen(write, "w");
    if(fp2 == NULL)
        return;
    ch = fgetc(fp);
    while(ch != EOF){
		if (ch != '\n')
			ch = ch + 10;
		fputc(ch, fp2);
		ch = fgetc(fp);
    }
	fflush(stdout);
	fclose(fp2);
	fclose(fp);
}

void display(){
	FILE *fp;
	fp = fopen("decoded.txt", "r");
	int i=0, w;
	printf("\n");
//	fseek( fp, 0L, SEEK_SET );
	while (!feof(fp)){
//	for (i=0; i<19; i++){
		fscanf(fp,"%d%s%ld%d%d%lu%s%s",&d[i].id,&d[i].name,&d[i].salary,&d[i].join_year,&d[i].permanent,&d[i].phone,&d[i].dob,&d[i].designation);
		printf("%d %s %ld %d %d 0%lu %s %s\n",d[i].id,d[i].name,d[i].salary,d[i].join_year,d[i].permanent,d[i].phone,d[i].dob,d[i].designation);
		i++;
	}
	fclose(fp);
	getch();
	printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
	w = validate_int();
	while ((w != 1) && (w != 2)){
		printf("Invalid choice");
		printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
		w = validate_int();
	}
	if (w == 1)
		menu(authorization);
	else{
		printf("Thank you for using Office Management System.");
		printf("\nPress any key to exit.");
		encode_file("decoded.txt", "encoded.txt");
		remove("decoded.txt");
		getch;
		exit(0);
	}
}

void menu(){
	int i, choice;
	system("cls");
	printf("\n\n\t\t\tWELCOME TO OFFICE MANAGEMENT SYSTEM\n");
	printf("\nAuthorization level: %d, Postion: %s\n", authorization, users[authorization]);
	printf("Press:\n1 for displaying employee data\n");
	printf("2 for searching specific employee(ID required)\n");
	if (authorization <= 1){
		printf("3 for incrementing/decrementing salary of specific employee(ID required)\n");
		printf("4 for incrementing/decrementing salary of all employees\n");
		printf("5 for changing detail of specific employee(ID required)\n");
		if (authorization == 0){
			printf("6 for hiring new employee\n");
			printf("7 for firing current employee\n");
		}
	}
	printf("8 to exit Office Management System\n");
	printf("\nEnter choice: ");
	choice = validate_int();
//	scanf("%d", &choice);
	if (authorization == 2){
		if (choice == 8){
			encode_file("decoded.txt", "encoded.txt");
			remove("decoded.txt");
			printf("Thank you for using Office Management System.");
			printf("\nPress any key to exit.");
			getch();
			exit(0);
		}
		while ((choice < 0) || (choice > 2)){
			printf("Enter valid choice: ");
			choice = validate_int();
			if (choice == 8)
				break;
		}
	}
	else if (authorization == 1){
		if (choice == 8){
			encode_file("decoded.txt", "encoded.txt");
			remove("decoded.txt");
			printf("Thank you for using Office Management System.");
			printf("\nPress any key to exit.");
			getch();
			exit(0);
		}
		while ((choice < 0) || (choice > 5)){
			printf("Enter valid choice: ");
			choice = validate_int();
			if (choice == 8)
				break;
//			scanf("%d", &choice);
		}
	}
	else if (authorization == 0){
		while (!(choice >= 0) && !(choice <= 8)){
			printf("Enter valid choice: ");
			choice = validate_int();
		}
	}
	if (choice == 1)
		display();
	else if (choice == 2)
		search_employee();
	else if (choice == 3)
		change_salary();
	else if (choice == 4)
		batch_change_salary();
	else if (choice == 5)
		changedetail();
	else if (choice == 6)
		add_employee();
	else if (choice == 7)
		delete_employee();
	else if (choice == 8){
		encode_file("decoded.txt", "encoded.txt");
		remove("decoded.txt");
		printf("Thank you for using Office Management System.");
		printf("\nPress any key to exit.");
		exit(0);
	}
	else{
		menu();
	}
//	fclose(fa);
}

int validate_int(){
	int x,num=0;
	while(1){
		fflush(stdin);
		x=getch();
		if(x>=48&&x<=57){
			printf("%d",x-48);
			num=num*10+(x-48);
		}
		if(x==13){
			printf("\n");
			break;
		}
	}
	return(num);
}
long int validate_long_int(){
	long int x,num=0;
	while(1){
		fflush(stdin);
		x=getch();
		if(x>=48&&x<=57){
			printf("%ld",x-48);
			num=num*10+(x-48);
		}
		if(x==13){
			printf("\n");
			break;
		}
	}
	return(num);
}

void search_employee(){
	int flag=0, i_flag, choice, w;
	FILE *fp;
	fp = fopen("decoded.txt", "r");
	int id, i=0;
	system("cls");
	printf("\nEnter the ID of employee to search: ");
	id = validate_int();

//	while (fscanf(fp,"%d%s%d%d%d%lu%s%s",&d[i].id,&d[i].name,&d[i].salary,&d[i].join_year,&d[i].permanent,&d[i].phone,&d[i].dob,&d[i].designation)!=EOF){
	while (!feof(fp)){
		fscanf(fp,"%d%s%ld%d%d%lu%s%s",&d[i].id,&d[i].name,&d[i].salary,&d[i].join_year,&d[i].permanent,&d[i].phone,&d[i].dob,&d[i].designation);
		if (d[i].id == id){
			flag = 1;
			i_flag = i;
		}
		i++;
	}
		if (flag == 0){
			printf("Invalid ID. User not found.");
			printf("\nEnter 1 to try another ID, or 0 to exit to main menu: ");
			w = validate_int();
			while ((w != 0) && (w != 1)){
				printf("Invalid choice");
				printf("\nEnter 1 to return to Main menu, or 0 to exit: ");
				w = validate_int();
			}
			if (w == 1)
				search_employee();
			else{
//				printf("Thank you for using Office Management System.");
//				printf("\nPress any key to exit.");
//				encode_file("decoded.txt", "encoded.txt");
//				remove("decoded.txt");
//				getch;
//				exit(0);
				menu(authorization);
			}	
		}
		
		if (flag == 1){
			printf("\nEmployee ID: %d\n",d[i_flag].id);
			printf("Name: %s\n",d[i_flag].name); 
			printf("Salary: %ld\n",d[i_flag].salary);
			printf("Join year: %d\n",d[i_flag].join_year);
			printf("Type: %d\n",d[i_flag].permanent);
			printf("Phone number: %lu\n",d[i_flag].phone);
			printf("Date of Birth: %s\n",d[i_flag].dob);
			printf("Designation: %s\n",d[i_flag].designation);
			fflush(stdin);
		}

	fclose(fp);
	getch();
	printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
	w = validate_int();
	while ((w != 1) && (w != 2)){
		printf("Invalid choice");
		printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
		w = validate_int();
	}
	if (w == 1)
		menu(authorization);
	else{
		printf("Thank you for using Office Management System.");
		printf("\nPress any key to exit.");
		encode_file("decoded.txt", "encoded.txt");
		remove("decoded.txt");
		getch;
		exit(0);
	}
}

void add_employee(){
	system("cls");
	time_t current_time;
	current_time = time(NULL);
	char *ctime_no_newline = strtok(ctime(&current_time), "\n");
//    printf("%s - [following text]\n", ctime_no_newline);
	int i=0, n, w;
	char HR[50];
	FILE *fp, *fp2, *fp3;
	fp = fopen("decoded.txt", "r");
	fp2 = fopen("hired.txt", "w");
	fp3 = fopen("time.txt", "a");

	while (fscanf(fp,"%d%s%ld%d%d%lu%s%s",&d[i].id,&d[i].name,&d[i].salary,&d[i].join_year,&d[i].permanent,&d[i].phone,&d[i].dob,&d[i].designation)!=EOF){
		fprintf(fp2,"%d %s %ld %d %d %lu %s %s\n",d[i].id,d[i].name,d[i].salary,d[i].join_year,d[i].permanent,d[i].phone,d[i].dob,d[i].designation);
		fflush(stdout);
		i++;
	}
	printf("Enter number of employees you want to add ");
   	n = validate_int();
	for (i=0;i<n;i++) {
 		struct employees employee;
		printf("New Hire no. %d:\n\n", i+1);
		printf("Employee ID: ");
//		employee.id = validate_int();
		scanf("%d", &employee.id);
		fflush(stdin);
		printf("Name: ");
		scanf("%s", &employee.name);
		printf("Salary: ");
//		employee.salary = validate_long_int();
		scanf("%ld", &employee.salary);
		fflush(stdin);
		printf("Join Year: ");
//		employee.join_year = validate_int();
		scanf("%d", &employee.join_year);
		fflush(stdin);
		printf("Type: ");
//		employee.permanent = validate_int();
		scanf("%d", &employee.permanent);
		fflush(stdin);
		printf("Phone Number: ");
//		employee.phone = validate_long_int();
		scanf("%lu", &employee.phone);
		fflush(stdin);
		printf("Date of Birth: ");
		gets(employee.dob);
		printf("Designation: ");
		gets(employee.designation);
		fprintf(fp2, "%d %s %ld %d %d 0%lu %s %s\n",employee.id,employee.name,employee.salary,employee.join_year,employee.permanent,employee.phone,employee.dob,employee.designation);
		printf("Enter name of hiring manager(HR): ");
		gets(HR);
		fprintf(fp3, "%d %s  Hired by: %s\n", employee.id, ctime_no_newline, HR);
		printf("Employee hired successfully.\n");
		getch();
		system("cls");
}
	fclose(fp3);
	fclose(fp2);
	fclose(fp);
	remove("decoded.txt");
	rename("hired.txt","decoded.txt");
	getch();
	printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
	w = validate_int();
	while ((w != 1) && (w != 2)){
		printf("Invalid choice");
		printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
		w = validate_int();
	}
	if (w == 1)
		menu(authorization);
	else{
		printf("Thank you for using Office Management System.");
		printf("\nPress any key to exit.");
		encode_file("decoded.txt", "encoded.txt");
		remove("decoded.txt");
		getch;
		exit(0);
	}
}

void delete_employee(){
	system("cls");
	time_t current_time;
	current_time = time(NULL);
	char *ctime_no_newline = strtok(ctime(&current_time), "\n");
	int id, i=0, w;
	int flag=0, i_flag;
	char HR[50];
	FILE *fp,*fp2, *fp3;
	fp = fopen("decoded.txt", "r");
	fp2 = fopen("fired.txt", "w");
	fp3 = fopen("time.txt", "a");
	printf("\n\t\tENTER THE ID of employee to fire:");
	id = validate_int();
	while (!feof(fp)){
		fscanf(fp,"%d%s%ld%d%d%lu%s%s",&d[i].id,&d[i].name,&d[i].salary,&d[i].join_year,&d[i].permanent,&d[i].phone,&d[i].dob,&d[i].designation);
		if (d[i].id == id){
			flag = 1;
			i_flag = i;
		}
		i++;
//		fclose(fp);
	}
	if (flag = 1){
		printf("Enter name of hiring manager(HR): ");
		gets(HR);
		while (!feof(fp)){
			fscanf(fp,"%d%s%ld%d%d%lu%s%s",&d[i].id,&d[i].name,&d[i].salary,&d[i].join_year,&d[i].permanent,&d[i].phone,&d[i].dob,&d[i].designation);
			if (i != i_flag)
				fprintf(fp2,"%d %s %ld %d %d %lu %s %s\n",d[i].id,d[i].name,d[i].salary,d[i].join_year,d[i].permanent,d[i].phone,d[i].dob,d[i].designation);
		}
		fprintf(fp3, "%d %s  Fired by: %s\n", id, ctime_no_newline, HR);
		printf("Employee fired successfully.\n");
	}
	else if (flag = 0){
		printf("Invalid ID!");
		printf("\nEnter 1 to try another ID, or 0 to return to Main menu: ");
		w = validate_int();
		while ((w != 0) && (w != 1)){
			printf("Invalid choice");
			printf("\nEnter 1 to try another ID, or 0 to return to Main menu: ");
			w = validate_int();
		}
		if (w == 1)
			changedetail();
		else{
			menu(authorization);
		}		
	}
	
	getch();
	fclose(fp3);
	fclose(fp2);
	fclose(fp);
	remove("decoded.txt");
	rename("fired.txt","decoded.txt");
	getch();
	printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
	w = validate_int();
	while ((w != 1) && (w != 2)){
		printf("Invalid choice");
		printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
		w = validate_int();
	}
	if (w == 1)
		menu(authorization);
	else{
		printf("Thank you for using Office Management System.");
		printf("\nPress any key to exit.");
		encode_file("decoded.txt", "encoded.txt");
		remove("decoded.txt");
		getch;
		exit(0);
	}
}

void change_salary(){
	system("cls");
	int id, type, i=0, w;
	long int temp, dep;
	int inc_dec;
	int id_flag=0;
	FILE *fp,*fp2;
	fp = fopen("decoded.txt", "r");
	fp2 = fopen("salary_changed.txt", "w");
	printf("Enter ID of employee to change salary of: ");
	id = validate_int();
//	scanf("%d", id);
	fflush(stdin);
	printf("Do you want to increment/decrement(1) or change salary(2)?");
	type = validate_int();
//	scanf("%d", type);
	fflush(stdin);
	while ((type != 1)&&(type != 2)){
		printf("\nInvalid type. Try again.\n");
		printf("\nDo you want to increment/decrement(1) or change salary(2)?");
		type = validate_int();
	}
	while (!feof(fp)){
		fscanf(fp,"%d%s%ld%d%d%lu%s%s",&d[i].id,&d[i].name,&d[i].salary,&d[i].join_year,&d[i].permanent,&d[i].phone,&d[i].dob,&d[i].designation);
		if (d[i].id == id){
			temp=d[i].salary;
			d[i].salary=0;
			if (type == 1){
				printf("\nDo you want to increment(1) or decrement(2) salary?");
//				inc_dec = validate_int();
				scanf("%d", &inc_dec);
				fflush(stdin);
				while ((inc_dec != 1)&&(inc_dec != 2)){
					printf("\nInvalid type. Try again.\n");
					printf("\nDo you want to increment(1) or decrement(2) salary?");
					inc_dec = validate_int();
				}
				printf("\nEnter the amount you want to change salary:");
				dep = validate_long_int();
				d[i].salary = dep;
				d[i].salary += temp;
			}
			else if (type == 2){
				printf("\nEnter the amount you want to change salary:");
//				dep = validate_long_int();
				scanf("%ld", &dep);
				fflush(stdin);
				d[i].salary = dep;
			}
		}
			fprintf(fp2,"%d %s %ld %d %d %lu %s %s\n",d[i].id,d[i].name,d[i].salary,d[i].join_year,d[i].permanent,d[i].phone,d[i].dob,d[i].designation);
			fflush(stdin);
			i++;
	}
	fclose(fp2);
	fclose(fp);
	remove("decoded.txt");
	rename("salary_changed.txt","decoded.txt");
	getch();
	printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
	w = validate_int();
	while ((w != 1) && (w != 2)){
		printf("Invalid choice");
		printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
		w = validate_int();
	}
	if (w == 1)
		menu(authorization);
	else{
		printf("Thank you for using Office Management System.");
		printf("\nPress any key to exit.");
		encode_file("decoded.txt", "encoded.txt");
		remove("decoded.txt");
		getch;
		exit(0);
	}
}

void batch_change_salary(){
	system("cls");
	int i=0, w;
	long int temp, dep;
	int inc_dec;
	FILE *fp,*fp2;
	fp = fopen("decoded.txt", "r");
	fp2 = fopen("salary_changed.txt", "w");
	
	printf("\nDo you want to increment(1) or decrement(2) salary?");
		inc_dec = validate_int();
		while ((inc_dec != 1)&&(inc_dec != 2)){
			printf("\nInvalid choice. Try again.\n");
			printf("\nDo you want to increment(1) or decrement(2) salary?");
			inc_dec = validate_int();
		}
		printf("\nEnter the amount you want to change salary:");
		dep = validate_long_int();
	while (!feof(fp)){
		fscanf(fp,"%d%s%ld%d%d%lu%s%s",&d[i].id,&d[i].name,&d[i].salary,&d[i].join_year,&d[i].permanent,&d[i].phone,&d[i].dob,&d[i].designation);
		temp=d[i].salary;
		d[i].salary=0;
		d[i].salary = dep;
		d[i].salary += temp;
		fprintf(fp2,"%d %s %ld %d %d %lu %s %s\n",d[i].id,d[i].name,d[i].salary,d[i].join_year,d[i].permanent,d[i].phone,d[i].dob,d[i].designation);
		fflush(stdout);
		i++;
	}
	fclose(fp2);
	fclose(fp);
	remove("decoded.txt");
	rename("salary_changed.txt","decoded.txt");
	getch();
	printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
	w = validate_int();
	while ((w != 1) && (w != 2)){
		printf("Invalid choice");
		printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
		w = validate_int();
	}
	if (w == 1)
		menu(authorization);
	else{
		printf("Thank you for using Office Management System.");
		printf("\nPress any key to exit.");
		encode_file("decoded.txt", "encoded.txt");
		remove("decoded.txt");
		getch;
		exit(0);
	}
}

void changedetail(){
	system("cls");
	int Employeefound=0, employeeID, flag=0, choice;
	char other;
	struct employees employee;
	int temp, i=0, w;
	FILE *fp,*fp2;
	fp = fopen("decoded.txt", "r");
	fp2 = fopen("detail_changed.txt", "w");
	printf("Change detail of the employee: \n\n");
	printf("Enter employee ID that has to be changed: ");
	employeeID = validate_int();
	printf("Enter:\n1 for name\n2 for salary\n3 for joining year\n4 for type\n5 for phone number\n6 for date of birth\n7 for desgination\n8 for all\n\nChoice: ");
	scanf("%d", &choice);
	fflush(stdin);
	
//	while (fscanf(fp,"%d%s%d%d%d%lu%s%s",&d[i].id,&d[i].name,&d[i].salary,&d[i].join_year,&d[i].permanent,&d[i].phone,&d[i].dob,&d[i].designation)!=EOF){
	while (!feof(fp)){
		fscanf(fp,"%d%s%ld%d%d%lu%s%s",&d[i].id,&d[i].name,&d[i].salary,&d[i].join_year,&d[i].permanent,&d[i].phone,&d[i].dob,&d[i].designation);
		Employeefound = 0;
		if(d[i].id==employeeID){
			Employeefound=1;			
		}
		if(Employeefound==1){
			printf("Old data is: \n");
			//old data
			printf("Employee ID: %d\n",d[i].id);
			printf("Name: %s\n",d[i].name); 
			printf("Salary: %ld\n",d[i].salary);
			printf("Join year: %d\n",d[i].join_year);
			printf("Type: %d\n",d[i].permanent);
			printf("Phone number: 0%lu\n",d[i].phone);
			printf("Date of Birth: %s\n",d[i].dob);
			printf("Designation: %s\n",d[i].designation);
			//new data
			if (choice == 1){
				printf("Name: ");
				scanf("%s", &employee.name);
				fflush(stdin);
				fprintf(fp2,"%d %s %ld %d %d %lu %s %s\n",d[i].id,employee.name,d[i].salary,d[i].join_year,d[i].permanent,d[i].phone,d[i].dob,d[i].designation);
				fflush(stdout);
				flag = 1;
				printf("\n\nDetails have been changed.");
			}
			if (choice == 2){
				printf("\nNew data is: \n");
				printf("Salary: ");
				scanf("%ld", &employee.salary);
				fflush(stdin);
				fprintf(fp2,"%d %s %ld %d %d %lu %s %s\n",d[i].id,d[i].name,employee.salary,d[i].join_year,d[i].permanent,d[i].phone,d[i].dob,d[i].designation);
				fflush(stdout);
				flag = 1;
				printf("\n\nDetails have been changed.");
			}
			if (choice == 3){
				printf("\nNew data is: \n");
				printf("Join Year: ");
				scanf("%d", &employee.join_year);
				fflush(stdin);
				fprintf(fp2,"%d %s %ld %d %d %lu %s %s\n",d[i].id,d[i].name,d[i].salary,employee.join_year,d[i].permanent,d[i].phone,d[i].dob,d[i].designation);
				fflush(stdout);
				flag = 1;
				printf("\n\nDetails have been changed.");
			}
			if (choice == 4){
				printf("\nNew data is: \n");
				printf("Type: ");
				scanf("%d", &employee.permanent);
				fflush(stdin);
				fprintf(fp2,"%d %s %ld %d %d %lu %s %s\n",d[i].id,d[i].name,d[i].salary,d[i].join_year,employee.permanent,d[i].phone,d[i].dob,d[i].designation);
				fflush(stdout);
				flag = 1;
				printf("\n\nDetails have been changed.");
			}
			if (choice == 5){
				printf("\nNew data is: \n");
				printf("Phone Number: ");
				scanf("%lu", &employee.phone);
				fflush(stdin);
				fprintf(fp2,"%d %s %ld %d %d %lu %s %s\n",d[i].id,d[i].name,d[i].salary,d[i].join_year,d[i].permanent,employee.phone,d[i].dob,d[i].designation);
				fflush(stdout);
				flag = 1;
				printf("\n\nDetails have been changed.");
			}
			if (choice == 6){
				printf("\nNew data is: \n");
				printf("Phone Number: ");
				scanf("%lu", &employee.phone);
				fflush(stdin);
				fprintf(fp2,"%d %s %ld %d %d %lu %s %s\n",d[i].id,d[i].name,d[i].salary,d[i].join_year,d[i].permanent,d[i].phone,employee.dob,d[i].designation);
				fflush(stdout);
				flag = 1;
				printf("\n\nDetails have been changed.");
			}
			
			if (choice == 7){
				printf("\nNew data is: \n");
				printf("Designation: ");
				gets(employee.designation);
				fflush(stdin);
				fprintf(fp2,"%d %s %ld %d %d %lu %s %s\n",d[i].id,d[i].name,d[i].salary,d[i].join_year,d[i].permanent,d[i].phone,d[i].dob,employee.designation);
				fflush(stdout);
				flag = 1;
				printf("\n\nDetails have been changed.");
			}
			
			if (choice == 8){
				fflush(stdin);
				printf("\nNew data is: \n");
				printf("Employee ID: ");
				scanf("%d", &employee.id);
				fflush(stdin);
//			employee.id = validate_int();
				printf("Name: ");
				scanf("%s", &employee.name);
				fflush(stdin);
				printf("Salary: ");
				scanf("%ld", &employee.salary);
				fflush(stdin);
//			employee.salary = validate_long_int();
				printf("Join Year: ");
				scanf("%d", &employee.join_year);
				fflush(stdin);
//			employee.join_year = validate_int();
				printf("Type: ");
				scanf("%d", &employee.permanent);
				fflush(stdin);
//			employee.permanent = validate_int();
				printf("Phone Number: ");
				scanf("%lu", &employee.phone);
				fflush(stdin);
//			employee.phone = validate_long_int();
				printf("Date of Birth: ");
				gets(employee.dob);
				printf("Designation: ");
				gets(employee.designation);
				fprintf(fp2,"%d %s %ld %d %d %lu %s %s\n",employee.id,employee.name,employee.salary,employee.join_year,employee.permanent,employee.phone,employee.dob,employee.designation);
				fflush(stdout);
				flag = 1;
				printf("\n\nDetails have been changed.");
			}
		}
		else{
			fprintf(fp2,"%d %s %ld %d %d %lu %s %s\n",d[i].id,d[i].name,d[i].salary,d[i].join_year,d[i].permanent,d[i].phone,d[i].dob,d[i].designation);
			fflush(stdout);
		}
		i++;
	}
	fclose(fp2);
	fclose(fp);	
	remove("decoded.txt");
	rename("detail_changed.txt","decoded.txt");
	if (Employeefound == 0 && flag == 0){
		printf("No employee with this id found in file.\n");
		printf("Do you want to change another employee details? (yY/nN): ");
		scanf("%c",&other);
		while((other != 'y')&&(other != 'Y')&&(other != 'n')&&(other != 'N'))
			scanf("%c",&other);
		if ((other == 'y')||(other == 'Y'))
			changedetail();
		else{
//			getch();
			printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
			w = validate_int();
			while ((w != 1) && (w != 2)){
				printf("Invalid choice");
				printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
				w = validate_int();
			}
			if (w == 1)
				menu(authorization);
			else{
				printf("Thank you for using Office Management System.");
				printf("\nPress any key to exit.");
				encode_file("decoded.txt", "encoded.txt");
				remove("decoded.txt");
				getch;
				exit(0);
			}
		}
	}
	printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
	w = validate_int();
	while ((w != 1) && (w != 2)){
		printf("Invalid choice");
		printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
		w = validate_int();
	}
	if (w == 1)
		menu(authorization);
	else{
		printf("Thank you for using Office Management System.");
		printf("\nPress any key to exit.");
		encode_file("decoded.txt", "encoded.txt");
		remove("decoded.txt");
		getch;
		exit(0);
	}
}
