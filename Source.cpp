//Yael Metzger 212373963
//Course in c++
//Homework 4 Question 1
//A program that receives details for 10 bank accounts. The plan allows for the execution of various 
//transactions in these bank accounts such as depositing checks or withdrawing cash. 
//The program issues outputs according to the various possible anomalies.

#include <iostream>
#include "Clock.h"
#include "Account.h"
using namespace std;

ostream& operator<<(ostream& os, const Clock& c)           //a function that prints the object
{
	(c.hour < 10)? os << 0 << c.hour <<':' : os << c.hour<<':'; 
    (c.minute < 10)? os << 0 << c.minute << ':' : os << c.minute << ':';
	(c.second < 10) ? os << 0 << c.second : os << c.second;
	return os;
}

istream& operator>>(istream& is, Clock& c)            //a function that gets the values to the object
{
	char ch;
	is >> c.hour >> ch >> c.minute >> ch >> c.second;
	if (c.second > 59)
		throw "Invalid time - more than 60 seconds.";
	if (c.minute > 59) 
		throw "Invalid time - more than 60 minutes.";
	if (c.hour > 23) 
		throw "Invalid time - more than 24 hours.";
	if (c.second < 0) 
		throw "Invalid time - negative number of seconds.";
	if (c.minute < 0) 
		throw "Invalid time - negative number of minutes.";
	if (c.hour < 0) 
		throw "Invalid time - negative number of hours.";
	return is;
}

istream& operator>>(istream& is, Account& ac)                       // a function that gets the values to the account
{
	is >> ac.accountNumber >> ac.code >> ac.mail;
	int counter=0, temp = ac.code;
	while (temp > 0)                       //to check the number of digits in the code
	{
		temp = temp / 10;
		counter++;
	}
	if (counter != 4)
		throw "ERROR: code must be of 4 digits!";
	int found=(ac.mail).find_first_of('@');                   //to check if there is a @ in the mail
	if (found == -1)
		throw "ERROR: email must contain @!";
	int len = (ac.mail).length();                           //the length of the mail
	if (((ac.mail).compare(len - 4, len, ".com") != 0)&& ((ac.mail).compare(len - 6, len, ".co.il") != 0))    //there isnt a proper endding
		throw "ERROR: email must end at .com or .co.il!\n";
	ac.balance = 0;
	return is;
}

enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop\n" << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size)
{
	int number, code;
	cout << "please enter account number:\n";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
	if (i == size)
		throw "ERROR: no such account number!\n";
	cout << "please enter the code:\n";
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
	throw "ERROR: wrong code!\n";
}
void printTransaction(Account a, action ac, Clock& c)
{
	cout << c << "\t";
	;
	switch (ac)
	{
	case balance: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], balance, c);
}
void cashDeposit(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the check:\n ";
	cin >> amount;
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], deposit, c);
}
void cashWithdraw(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw:\n";
	cin >> amount;
	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], withdraw, c);
}

int main()
{
	Clock c(8);
	Account bank[10];
	cout << "enter account number, code and email for 10 accounts:\n"<<endl;
	for (int i = 0; i < 10; i++)                                                   //gets the details of the bank accounts
	{
		try
		{
			cin >> bank[i];
			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
					throw "ERROR: account number must be unique!\n";
		}
		catch (const char* msg)
		{
			cout << c << '\t' << msg;
			i--;
		}
	}
	action ac = menu();
	while (ac)                             //to perform actions
	{
		try
		{
			switch (ac)
			{
			case balance: getBalance(bank, 10, c);
				break;
			case withdraw:cashWithdraw(bank, 10, c);
				break;
			case deposit:cashDeposit(bank, 10, c);
				break;
			case sumDeposit:c += 60;
				printTransaction(bank[0], sumDeposit, c);
				break;
			case sumWithdraw:c += 60;
				printTransaction(bank[0], sumWithdraw, c);

			}
		}
		catch (const char* msg)
		{
			cout << c << '\t' << msg<<endl;
		}
		ac = menu();
	}
	return 0;
}