//Yael Metzger 212373963
//Course in c++
//Homework 4 Question 1
//The interface of the program. A class of a Account containing the fields of the object and 
//definitions of various operations performed on the fields.

#include <cstring>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

#pragma once

class Account
{
	private:
		int accountNumber;
		int code;
		float balance;
		string mail;

    public:
		static float sumWithdraw;                    //static feild
		static float sumDeposit;                    //static feild
		static float getSumWithdraw();                   //to get the static feild of the object
		static float getSumDeposit();                    //to get the static feild of the object

		Account();                      //the empty constructor
		Account(int myAccountNumber, int myCode, float myBalance, string myMail);      //the constructor

		int getAccountNumber();              //to get the feild of the object
		int getCode();                   //to get the feild of the object
		float getBalance();              //to get the feild of the object
	
		void withdraw(int nis);         //a function that perform a withdraw
		void deposit(int amount);       //a function that perform a deposit
		friend istream& operator>>(istream& is, Account& ac);           //input object freind function
};