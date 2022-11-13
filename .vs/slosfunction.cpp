#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include"slos.h"

bool checkLuhn(const string& cardNo) {

	int nDigits = cardNo.length();

	int nSum = 0, isSecond = false;


	for (int i = nDigits - 1; i >= 0; i--) {

		int d = cardNo[i] - '0';

		if (isSecond == true)

			d = d * 2;

		nSum += d / 10;
		nSum += d % 10;

		isSecond = ~isSecond;
	}
	return (nSum % 10 == 0);
}
void invalidnumber() {
	cout << "This is invalid number, please try again" << endl;
}

/*ProductName)
{
	m_sandbox = Sandbox;
	m_user = User;
	m_password = password;
	m_signature = signature;
	m_SuccessURL = successUrl;
	m_FailureURL = failedURL;
	m_ProductName = ProductName;
	CUR_CHAR = L"$";
	SYSTEMTIME st;
	GetSystemTime(&st);
	g_tPayStart = CTime(st);
	InitilizedPaypal = TRUE;
}*/

using namespace std;
