//Yael Metzger 212373963
//Course in c++
//Homework 4 Question 1
//This file contains the implementation of the actionsand functions in the class of Clock.

#include "Clock.h"

Clock::Clock()        //empty constructor function
{
	hour=0;
	minute=0;
	second=0;
}
Clock::Clock(int myHour, int myMinute, int mySecond)        // constructor function
{
	if (myHour > 23 || myHour < 0 || myMinute>59 || myMinute < 0 || mySecond>59 || mySecond < 0)     //in case one of the inputs is wrong
	{
		hour = 0;
		minute = 0;
		second = 0;
	}
	else                    //in case all the inputs are good
	{
		hour = myHour;
		minute = myMinute;
		second = mySecond;
	}
}
Clock::Clock(const Clock& myClock)          //copy constructor function
{
	hour = myClock.hour;
	minute = myClock.minute;
	second = myClock.second;
}

void Clock::setHour(int myHour)       //a function that gets a value to set in the feild
{
	hour = myHour;
}

void Clock::setMinute(int myMinute)       //a function that gets a value to set in the feild
{
	minute = myMinute;
}

void Clock::setSecond(int mySecond)       //a function that gets a value to set in the feild
{
	second = mySecond;
}

int Clock::getHour()                      //a function that returns the value that in the feild
{
	return hour;
}

int Clock::getMinute()                      //a function that returns the value that in the feild
{
	return minute;
}

int Clock::getSecond()                      //a function that returns the value that in the feild
{
	return second;
}

void Clock::operator+=(int seconds)            //a function that gets a numbers of seconds and adding it to the time
{
	if (seconds >= 3600)        //in case the seconds are bigger than 3600
	{
		hour += seconds / 3600;
		minute += seconds % 3600 / 60;
		second += seconds % 3600 % 60;
	}
	else if (seconds >= 60)    //in case the seconds are bigger than 60 but smaller than 3600
	{
		minute += seconds / 60;
		second += seconds % 60;
	}
	else                       //in case the seconds are smaller than 60 and smaller than 3600
		second += seconds;
	if (second > 59)              //to update the minutes
	{
		minute += second / 60;
		second = second % 60;
	}
	if (minute > 59)                 //to update the hour
	{
		hour += minute / 60;
		minute = minute % 60;
	}
	if (hour > 23)                 //to reset the hour
		hour /= 24;
}