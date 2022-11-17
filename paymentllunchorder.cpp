#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;


struct Creditcard {

	string cardNumber;
	int monthOfExpire;
	int yearOfExpire;
	int cvvNumber = 0;
};

struct UserData {

	string username;
	string userId;
	string emailAddress;
};

bool checkLuhn(const string& cardNo) { //Luhn algorithm for creditcard

	int nDigits = cardNo.length();

	int nSum = 0, isSecond = false;

	for (int i = nDigits - 1; i >= 0; i--) {

		int d = cardNo[i] - '0';

		if (isSecond == true) {

			d = d * 2;

			nSum += d / 10;
			nSum += d % 10;

			isSecond = ~isSecond;
		}
	}
	return (nSum % 10 == 0);
}

void invalidnumber() {
	cout << "This is invalid number, please try again" << endl;
}


int main() {

	int paymentType = 0;
	char saveNo;
	
	Creditcard credit;
	UserData userInfo;
	
	cout << "*****Payment Type*****" << endl;
	cout << "  1 : Credit card" << endl;
	cout << "  2 : Bank Account" << endl;
	cin >> paymentType;
	

	if (paymentType == 1) {
		cout << "Please enter your credit card number : ";

		cin >> credit.cardNumber;

		int n = credit.cardNumber.length();

		if (checkLuhn(credit.cardNumber) && n >=14) {

			cout << "Please enter the expiry date" << endl;
			cout << "Month : ";
			cin >> credit.monthOfExpire;
			cout << "Year (20XX): ";
			cin >> credit.yearOfExpire;

			if (credit.yearOfExpire < 22) {
				invalidnumber();
				exit;
			}
			else {
				cout << "please enter CVV number : ";
				cin >> credit.cvvNumber;

				cout << "Thank you for purchesing our lunch service. We are prosessing now...\n";

				cout << "Would you like to save the card number? (y/n) : ";
				cin >> saveNo;

				if (saveNo == 'y') {
					//save cardnumber s into customer.csv 
					ofstream ofs;
					ofs.open("customer.csv", ios_base::app);
					ofs << userInfo.username << "," << credit.cardNumber << "," << credit.monthOfExpire << "," << credit.yearOfExpire << endl;

					if (!ofs) {
						cerr << "Error" << endl;  // Error message if couldn"t open ofs
						ofs.close();
					}
				}
			}
		}
		else {
			invalidnumber();
		}

		} else if (paymentType == 2) {
			cout << "Please enter your Email address: ";
			cin >> userInfo.emailAddress;
			cout << "Thank you for ordering our lunch service. we are going to send invoice soon." << endl;
		}

	system("pause>0");
}
