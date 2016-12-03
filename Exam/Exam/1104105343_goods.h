#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include "1104105343_Date.h"
using namespace std;
class Goods {
public:
	Goods(string in_ID_Number, string in_Name, int in_Price, string in_company_name, int in_Buy_Price, Date in_date, int in_store);
	string getName();
	string getID_Number();
	int getPrice();
	string getcompany_name();
	int getBuy_Price();
	string getDate();
	int getstore();
	void setName(string in_Name);
	void setPrice(int in_Price);
	void setcompany_name(string in_company_name);
	void setBuy_Price(int in_Buy_Price);
	void setdate(Date in_Date);
	void setstore(int in_store);
private:
	string ID_Number;
	string Name;
	int Price;
	string company_name;
	int Buy_Price;
	Date date;
	int store;
};