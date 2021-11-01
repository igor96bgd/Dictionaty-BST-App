#include <iostream>

#include "zadatak1.h"
#include "zadatak2.h"

using namespace std;

int main() {
	int task;
	while (true) {
		cout << "Choose task" << endl;
		cout << "1 - Task 1" << endl;
		cout << "2 - Task 2" << endl;
		cout << "0 - Close" << endl;
		cout << "Your choice: ";
		cin >> task;
		if (task == 1) {
			zadatak1();
		}
		else if (task == 2) {
			zadatak2();
		}
		else if (task == 0) {
			break;
		}
		else {
			cout << "Invalid selection" << endl;
		}
	}
}