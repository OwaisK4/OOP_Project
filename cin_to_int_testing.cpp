#include <iostream>
using namespace std;

int main(){
	int age;
	cout << "Enter age: ";
	cin >> age;
	while (cin.fail()){
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Enter age: ";
		cin >> age;
	}
	return 0;
}
