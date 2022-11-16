// Billing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//John and Naomi's School Lunch ordering System
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<chrono>

using namespace std;



int main() {

	int accountID = 123456789; 
	string childName = "kiwi";
	
	//utc_clock::time_point t = clock_cast<utc_clock>(file_clock::now());// compile using: /std:c++latest

	//fstream to write a file for lunch menu
	fstream invoice;
	fstream lunchFile;

	lunchFile.open("..//LunchOrder//lunch.csv", ios::in);//read lunch file
	if (lunchFile.is_open()) {
		string line;
		while (getline(lunchFile, line)) {
			cout << line << endl;
		}
		
		lunchFile.close();
	}

	invoice.open("lunchInvoice.txt", ios::out);//write for invoice
	if (invoice.is_open()) {
		invoice << "***********************************************************************************************\n"
				<< "*************************     Naomi and John's School Lunch invoice      **********************\n\n"
				<< "***********************************************************************************************\n\n\n"
			//<< "\tDate : " << t << endl
			<< "\tCustomer ID : " << accountID << "\t"
			<< "\tCustomer's Name : " << childName <<endl
			<< "___________________________________________________________________________________________________\n"
			<< "| Item name\t\t" <<"|" << " Unit Price\t" <<"|" << " Quantity\t" <<"|" << " Total Price\t|" << endl
			<< "---------------------------------------------------------------------------------------------------\n";

		invoice.close();
	}

		
		

	system("pause>0");
}