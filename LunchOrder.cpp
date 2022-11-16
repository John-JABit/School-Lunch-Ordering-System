//John and Naomi's School Lunch ordering System
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include<vector>

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

void menu(){

	cout << "+++++++++++++Lunch Menu+++++++++++++++++++\n";
	cout << "1:Meat Wrap $" << itemPrice[1] << endl;
	cout << "2:Vegan Wrap $" << itemPrice[2] << endl;
	cout << "3:Chicken Sandwich $" << itemPrice[3] << endl;
	cout << "4:Veg Sandwich $" << itemPrice[4] << endl;
	cout << "5:Fruit Slices $" << itemPrice[5] << endl;
	cout << "6:Up and Go $" << itemPrice[6] << endl;
	cout << "7:Fruit and Nut Bar $" << itemPrice[7];
	cout << "8:Weekly Lunch Special(weekdays) $" << itemPrice[8] << endl;
	cout << "9:Monthly Lunch Special(weekdays) $" << itemPrice[9] << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++\n";

}

int main() {

	int lunchItemsCord;
	int quantity;//User to enter quantity wanted
	double totalItemPrice;
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

		cout << "You have selected: "
			<< enum_str[lunchItemsCord] << " $" << itemPrice[lunchItemsCord] << " x "
			<< quantity << "	Totalprice $" << totalItemPrice << endl;


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

	system("pause>0");
}
		//fstream to read file
			/*fstream lunchFile;
			lunchFile.open("lunch.txt", ios::in);//read
			if (lunchFile.is_open()) {
				string line;
				while (getline(lunchFile, line)) {
					cout << line << endl;
				}
				lunchFile.close();
			}*/

			//system("pause>0");

