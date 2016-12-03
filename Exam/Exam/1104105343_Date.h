#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <ctime>
#include <Windows.h>
class Date
{
public:
	Date();
	Date(int in_year, int in_month, int in_day);
	void setyear(int in_year);
	void setmonth(int in_month);
	void setday(int in_day);
	int getyear();
	int getmonth();
	int getday();
private:
	int year;
	int month;
	int day;
};
int getnowYear();
int getnowMonth();
int getnowDay();