#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
using std::string;
class Company {
public:
	Company(string , string, string );
	string getname();
	string getContact_Person();
	string getPhone();
	void setname(string in_name);
	void setpContact_Person(string in_Contact);
	void setPhone(string in_Phone);
private:
	string Name="";
	string Contact_Person = "";
	string Phone = "";
};