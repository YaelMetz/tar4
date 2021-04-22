//Yael Metzger 212373963
//Course in c++
//Homework 4 Question 1
//The interface of the program. A class of a Clock containing the fields of the object and 
//definitions of various operations performed on the fields.

#include <iostream>
using namespace std;
#pragma once

class Clock
{
private:
	int hour;
	int minute;
	int second;

public:
	Clock();                  //explicit empty constructor
	Clock(int myHour=0, int myMinute=0, int mySecond=0);     //constructor
	Clock(const Clock& myClock);                    //copy constructor
	void setHour(int myHour);                  //to set the denominator field
	void setMinute(int myMinute);                //to set the denominator field
	void setSecond(int mySecond);                //to set the denominator field
	int getHour();                          //to get the feild of the object
	int getMinute();                        //to get the feild of the object
	int getSecond();                        //to get the feild of the object
	void operator+=(int seconds);                           //adding seconds to the time function
	friend ostream& operator<<(ostream& os, const Clock& c);            //output object freind function
	friend istream& operator>>(istream& is, Clock& c);           //input object freind function
};