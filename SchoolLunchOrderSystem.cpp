#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include"slos.h"


using namespace std;


int main() {

	int paymentType = 0, monthOfExpire, yearOfExpire, cvvNumber = 0;
	char saveNo;
	string cardNo, paypalNo, username;

	cout << "*****Payment Type*****" << endl;
	cout << "  1 : credit card" << endl;
	cout << "  2 : Paypal" << endl;
	cin >> paymentType;

	if (paymentType == 1) {
		cout << "Please enter your credit card number : ";

		cin >> cardNo;

		if (checkLuhn(cardNo)) {

			cout << "Please enter the expiry date" << endl;
			cout << "Month : ";
			cin >> monthOfExpire;
			cout << "Year (20XX): ";
			cin >> yearOfExpire;

			if (yearOfExpire < 22) {
				invalidnumber();
				exit;
			} else {
			cout << "please enter CVV number : ";
			cin >> cvvNumber;
			
			cout << "Would you like to save the card number? (y/n) : ";
			cin >> saveNo;

				if (saveNo == 'y') {

				ofstream ofs;
				ofs.open ("customer.csv",ios_base::app);
				ofs << username << "," << cardNo << "," << monthOfExpire << "," << yearOfExpire << endl;

					if (!ofs) {
					cerr << "Erorr" << endl;
					ofs.close();
					}
				}
			}
		} else {
			invalidnumber();
		}

	}
	else if (paymentType == 2) {
		cout << "Please enter your paypal number : ";
		cin >> paypalNo;

		/*
		// Send string to PayPal server
		WinHttpClient WinClient1(ExpChkoutStr.GetBuffer());
		WinClient1.SetRequireValidSslCertificates(false);

		// Now we get PayPal's response:
		WinClient1.SendHttpRequest(L"GET");
		httpResponseContent1 = WinClient1.GetResponseContent();
		CString strTransactionRet = UrlDecode(httpResponseContent1.c_str());
	}*/

	}

	system("pause>0");
}
