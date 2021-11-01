#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void zadatak2() {
	
	double number;
	int cnt = 0;
	int input;
	double min;
	double max;
	cout << "Enter range minimum: ";
	cin >> min;
	cout << "Enter range maximum: ";
	cin >> max;
	double range = max - min;
	while (range > 10) {
		cnt++;
		cout << "Range:" << min << " - " << max << endl;
		double value = min + range / 5;
		cout << "Is your number inside first 20% of this range (Less then " << value << ")" << endl;
		cout << "Enter 1 if true: ";
		cin >> input;
		if (input) {
			max = value;
		}
		else {
			min = value;
		}
		range = max - min;
	}

	cout << "New range: [" << min << " " << max << ")"<< endl;

	std::cout.precision(1);
	int precision = 1;
	int size = (max-min)*10;
	int a, b = 0;
	double* arr = new double[size];
	for (int i = 0; i < size; i++) {
		arr[i] = min + i * pow(10, -precision);
	}
	int mid = -5;
	while (true) {

		cnt++;		
		int newMid = size / 5;
		mid = newMid;
		cout << "Generated value " <<fixed << arr[mid] << endl;
		cout << "Enter 1 if this value is your key, 2 your key is lower or 3 if your key is larger: ";
		cin >> a;
		if (a == 1) {
			number = arr[mid];
			break;
		}
		else if (a == 2) {
			size = mid;
			double* arrCpy = new double[size];
			for (int i = 0; i < size; i++)
				arrCpy[i] = arr[i];
			arr = arrCpy;
		}
		else {
			size -= (mid+1);
			double* arrCpy = new double[size];
			for (int i = 0; i < size; i++)
				arrCpy[i] = arr[mid + 1 + i];
			arr = arrCpy;
		}
		if (!b) {
			cout << "Does this value have enough decimal spots (1 if true, 0 if false): ";
			cin >> b;
			if (b == 0) {
				precision++;
				std::cout.precision(precision);
				cout << "P = " << pow(10.0, -precision) << endl;
				int newSize = size * 10;
				double* arrCpy = new double[newSize];
				arrCpy[0] = arr[0];
				for (int i = 1; i < newSize; i++) {
					arrCpy[i] = arrCpy[i-1] + pow(10.0, -precision);
				}
				
				size = newSize;
				arr = arrCpy;				
			}
		}
	}
	cout << "Your number is " << fixed << setprecision(precision) << number << ", and it took " << cnt << " steps to guess." << endl;

	
}
