//Yael Metzger 212373963
//Course in c++
//Homework 4 Question 1
//This file contains the implementation of the actionsand functions in the class of Account.

#include "Account.h"
#include <cstring>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

float Account::sumWithdraw = 0;              //initialize the static feild
float Account::sumDeposit = 0;              //initialize the static feild

Account::Account()                    //the empty constructor function
{
	accountNumber = 0;
	code = 0;
	balance = 0;
	mail = "";
}

Account::Account(int myAccountNumber, int myCode, float myBalance, string myMail)          //the constructor function
{
	accountNumber = myAccountNumber;
	code = myCode;
	balance = myBalance;
	mail = myMail;
}

int Account::getAccountNumber()                      //a function that returns the value that in the feild
{
	return accountNumber;
}

int Account::getCode()                      //a function that returns the value that in the feild
{
	return code;
}

float Account::getBalance()                      //a function that returns the value that in the feild
{
	return balance;
}

void Account::withdraw(int nis)                     // a function that gets a sum of money and performs a withdraw
{
	if ((balance - nis) <= -6000)                                      //in case the is Frame deviation credit- less than 6000
		throw "ERROR: cannot have less than - 6000 NIS!";
	else if (nis > 2500)                                                 //in case the wanted withdraw is bigger than 2500
		throw "ERROR: cannot withdraw more than 2500 NIS!";
	else                                                                //everything is good
	{
		balance -= nis;
		sumWithdraw += nis;
	}
}

void Account::deposit(int amount)                  // a function that gets a sum of money and performs a deposit
{
	if (amount <= 10000)                         //in case the sum is alright
	{
		balance += amount;
		sumDeposit += amount;
	}
	else                                                      //in case the wanted deposit is bigger than 10000
		throw "ERROR: cannot deposit more than 10000 NIS!";
}

float Account::getSumWithdraw()             //a function that returns the static feild of the object- sum of withdraws
{
	return sumWithdraw;
}

float Account::getSumDeposit()           //a function that returns the static feild of the object- sum of deposits
{
	return sumDeposit;
}