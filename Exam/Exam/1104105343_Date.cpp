#include "1104105343_Date.h"
#include <iostream>
using namespace std;
Date::Date() {
	setyear(getnowYear());
	setmonth(getnowMonth());
	setday(getnowDay());
}
Date::Date(int in_year, int in_month, int in_day){
	if (in_year == 0) {
		setyear(getnowYear());
	}
	else {
		setyear(in_year);
	}
	if (in_month == 0) {
		setmonth(getnowMonth());
	}
	else {
		setmonth(in_month);
	}
	if (in_day == 0) {
		setday(getnowDay());
	}
	else {
		setday(in_day);
	}
}
void Date::setyear(int in_year) {
	int now_year = getnowYear();
	if (in_year > now_year) {
		year = now_year;
	}
	else {
		year = in_year;
	}
}
void Date::setmonth(int in_month) {
	if ((year == getnowYear()) && in_month > getnowMonth()) {
		month = getnowMonth();
	}
	else {
		if ((in_month >= 1) && (in_month) <= 12) {
			month = in_month;
		}
		else {
			month = 1;
		}
	}
}
void Date::setday(int in_day) {
	if((year==getnowYear()) && (month==getnowMonth()) && (day>getnowDay())){
		day = getnowDay();
	}
	else {
		if ((in_day <= 29) && (month == 2) && (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))) {
			day = in_day;
		}
		else {
			int true_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
			if (in_day >= 1 && in_day <= true_day[month - 1]) {
				day = in_day;
			}
			else {
				day = 1;
			}
		}
	}
}
int Date::getyear() {
	return year;
}
int Date::getmonth() {
	return month;
}
int Date::getday() {
	return day;
}
int getnowYear() {
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	return sys.wYear;
}
int getnowMonth() {
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	return sys.wMonth;
}
int getnowDay() {
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	return sys.wDay;
}
