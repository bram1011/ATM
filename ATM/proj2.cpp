/*
---------------------------------------------------
			CS 215 -- Spring 2018
				 Project 2
---------------------------------------------------
Author: Bram Hampton
Section: 003
Description: Software for an ATM which can read accounts from a text file called accounts.txt
Assistance:
*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;



void writeLogo() {
	cout << "+----------------------------------------------------------------------------+\n";
	cout << "|                         BANKING BONANZA ATM                                |\n";
	cout << "|                           by Bram Hampton                                  |\n";
	cout << "+----------------------------------------------------------------------------+\n";
	cout << "\nATM starting up.....";
}

void shutdown() {

}

int readAccounts(string acctno[], int pin[], double balance[]) {
	ifstream acctFile;
	acctFile.open("accounts.txt");
	if (acctFile.fail()) {
		return -1;
	}
	int numAccts;
	acctFile >> numAccts;
	for (int i = 0; i < numAccts; i++) {
		acctFile >> acctno[i] >> pin[i] >> balance[i];
	}
	return numAccts;
}

void printAccounts(string acctno[], int numAccts, int pin[], double balance[]) {
	cout << endl << "Number of accounts: " << numAccts;
	cout << setw(20) << left << "\nAccount" << setw(10) << left << "Pin" << setw(10) << left << "Balance";
	cout << endl << "---------------    ------    ----------\n";
	for (int i = 0; i < numAccts; i++) {
		cout << setw(20) << left << acctno[i];
		cout << setw(10) << left << pin[i];
		cout << setw(10) << left << balance[i];
		cout << endl;
	}
}

int custLogin(string acctno[], int pin[], int numAccts) {
	string userno;
	int userPin;
	cout << "\nPlease enter your account number: ";
	cin >> userno;
	cout << "\nPlease enter pin:                 ";
	cin >> userPin;
	if (userno == "10000" && userPin == 1000)
		return -2;

	for (int i = 0; i < numAccts; i++) {
		if (userno == acctno[i] && userPin == pin[i]) {
			return i;
		}
	}
	return -1;
}

char askAction() {
	string userTransCode;
	char transCode;
	cout << endl << "W  -  Withdraw";
	cout << endl << "D  -  Deposit";
	cout << endl << "B  -  Get current balance";
	cout << endl << "Enter transaction code: ";
	cin >> userTransCode;
	transCode = toupper(userTransCode[0]);
	while (transCode != 'W' && transCode != 'D' && transCode != 'B') {
		cout << "ERROR, must be W, D, or B: ";
		cin >> userTransCode;
		transCode = toupper(userTransCode[0]);
	}
	return transCode;
}

int main() {
	const int MAX_ACCOUNTS = 100;
	const int MAX_TRANSACTIONS = 5;
	string acctno[MAX_ACCOUNTS]; int pin[MAX_ACCOUNTS]; double balance[MAX_ACCOUNTS];
	int numAccts = readAccounts(acctno, pin, balance);
	

	system("pause");
	return 0;
}