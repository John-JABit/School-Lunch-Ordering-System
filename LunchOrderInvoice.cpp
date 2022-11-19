//John and Naomi's School Lunch ordering System
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include<vector>
#include <iomanip>  

using namespace std;

//Enum created to store lunch items

enum lunchItems {
	meatWrap = 1,
	veganWrap,
	chickenSandwich,
	vegSandwich,
	fruitSlices,
	upandGo,
	fruitandNutBar,
	weeklySpecialOrder,
	monthlySpecialOrder
};

static const char* enum_str[] = {
	"-",
	"meatWrap",
	"veganWrap",
	"chickenSandwich",
	"vegSandwich",
	"fruitSlices",
	"upandGo",
	"fruitandNutBar",
	"weeklySpecialOrder",
	"monthlySpecialOrder"
};

const vector <double> itemPrice = { 0,10.5,12,14.3,16,8.5,4,5.3,50,200 };

void menu() {

	cout << "+++++++++++++Lunch Menu+++++++++++++++++++\n";
	cout << "1:Meat Wrap $" << itemPrice[1] << endl;
	cout << "2:Vegan Wrap $" << itemPrice[2] << endl;
	cout << "3:Chicken Sandwich $" << itemPrice[3] << endl;
	cout << "4:Veg Sandwich $" << itemPrice[4] << endl;
	cout << "5:Fruit Slices $" << itemPrice[5] << endl;
	cout << "6:Up and Go $" << itemPrice[6] << endl;
	cout << "7:Fruit and Nut Bar $" << itemPrice[7]<<endl;
	cout << "8:Weekly Lunch Special(weekdays) $" << itemPrice[8] << endl;
	cout << "9:Monthly Lunch Special(weekdays) $" << itemPrice[9] << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++\n";
}

int main() {

	int accountID = 123456789;
	string childName = "kiwi";

	//utc_clock::time_point t = clock_cast<utc_clock>(file_clock::now());// compile using: /std:c++latest
	int lunchItemsCord;
	int quantity;//User to enter quantity wanted
	double totalItemPrice, totalAmount = 0.0,discount,discountTotal,taxTotal;
	char answer;

	//fstream to write a file for lunch menu
	fstream lunchFile;

	lunchFile.open("lunch.csv", ios::out);//write title
	if (lunchFile.is_open()) {
		lunchFile << "Item Name" << ","
			<< "Unit Price" << ","
			<< "Quantity" << ","
			<< "Total Price" << endl;

		lunchFile.close();
	}
	menu();

	fstream invoice;

	invoice.open("lunchInvoice.txt", ios::out);//write for invoice
	if (invoice.is_open()) {
		invoice << "***********************************************************************************************\n"
			<< "*************************     Naomi and John's School Lunch invoice      **********************\n\n"
			<< "***********************************************************************************************\n\n\n"
			//<< "\tDate : " << t << endl
			<< "\tCustomer ID : " << accountID << "\t"
			<< "\tCustomer's Name : " << childName << endl
			<< "___________________________________________________________________________________________________\n"
			<< "| Item name\t\t\t" << "|" << " Unit Price\t" << "|" << " Quantity\t" << "|" << " Total Price\t|" << endl
			<< "---------------------------------------------------------------------------------------------------\n";


	}
	do {
		cout << "Please enter your selection : ";
		cin >> lunchItemsCord;

		cout << "You have entered: ";
		switch (lunchItemsCord) { //Switch case for displaying selected lunch itemsmeatWrap,

		case meatWrap: cout << "Meat Wrap\n";

			break;
		case veganWrap: cout << "Vegan Wrap\n";

			break;
		case chickenSandwich: cout << "Chicken Sandwich\n";

			break;
		case vegSandwich: cout << "Veg Sandwich\n";

			break;
		case fruitSlices: cout << "Fruit Slices\n";

			break;
		case upandGo: cout << "Up And Go\n";

			break;
		case fruitandNutBar: cout << "Fruit And Nut Bar\n";

			break;
		case weeklySpecialOrder: cout << "Weekly Special lunch(weekdays)\n";

			break;
		case monthlySpecialOrder: cout << "Monthly Special lunch(weekddays)\n";

			break;
		}

		cout << "Please enter your Quantity: ";
		cin >> quantity;

		totalItemPrice = itemPrice[lunchItemsCord] * quantity;

		totalAmount = totalAmount + totalItemPrice;

		cout << "You have selected: "
			<< enum_str[lunchItemsCord] << " $" << itemPrice[lunchItemsCord] << " x " << quantity << "	Totalprice $" << totalItemPrice << endl;
		invoice << left << setw(32) << enum_str[lunchItemsCord]
				<< right << setw(12) << "$" << itemPrice[lunchItemsCord]
				
			<< setw(15) << quantity
				<< right << setw(13) << "$" << totalItemPrice << endl;

		lunchFile.open("lunch.csv", ios::app);//fstream to append file for lunch menu
		if (lunchFile.is_open()) {
			lunchFile << enum_str[lunchItemsCord] << ","
				<< itemPrice[lunchItemsCord] << ","
				<< quantity << ","
				<< totalItemPrice << endl;

			lunchFile.close();
		}
		cout << "Would you like to choose anything else?(y/n) :";
		cin >> answer;
	} while (answer == 'y');

	invoice << "***********************************************************************************\n" 
		<<"Total : $" << totalAmount << endl;
	if (totalAmount >= 200) {
		discount = totalAmount * 0.1;
		invoice << "10% discount : $" << discount <<"\t";
	}
	else if (totalAmount >= 50) {
		discount = totalAmount * 0.05;
		invoice << "5% discount : $" << discount << "\t";

	}
	discountTotal = totalAmount - discount;

	invoice << "Total Amount : $" << fixed << setprecision(2) << discountTotal <<endl;
	taxTotal = discountTotal* 1.15;
	invoice << "Total Amount with GST : $" << fixed << setprecision(2) <<taxTotal;
	invoice.close();

	system("pause>0");
}
