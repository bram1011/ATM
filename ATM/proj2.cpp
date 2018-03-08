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

const int MAX_ACCOUNTS = 100;
const int MAX_TRANSACTIONS = 5;

void writeLogo() {
	cout << "+----------------------------------------------------------------------------+\n";
	cout << "|                         BANKING BONANZA ATM                                |\n";
	cout << "|                           by Bram Hampton                                  |\n";
	cout << "+----------------------------------------------------------------------------+\n";
	cout << "\nATM starting up.....";
}

int readAccounts(string acctno[], int pin[], double balance[]) {
	ifstream acctFile;
	acctFile.open("accounts.txt");
	if (acctFile.fail()) {
		cout << "ATM shutting down.....";
		return 1;
	}
	else {
		int numAccts;
		acctFile >> numAccts;
		for (int i = 0; i < numAccts; i++) {
			acctFile >> acctno[i] >> pin[i] >> balance[i];
		}
		return numAccts;
	}
}

void printAccounts(string acctno[], int numAccts, int pin[], double balance[]) {
	cout << endl << "Number of accounts: " << numAccts;
	cout << setw(20) << left << "\nAccount";
	cout << "\n-------------------\n";

}

int main() {
	string acctno[MAX_ACCOUNTS]; int pin[MAX_ACCOUNTS]; double balance[MAX_ACCOUNTS];
	readAccounts(acctno, pin, balance);


	system("pause");
	return 0;
}