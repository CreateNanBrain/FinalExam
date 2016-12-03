#include "1104105343_goods.h"
Goods::Goods(string in_ID_Number, string in_Name, int in_Price, string in_company_name, int in_Buy_Price, Date in_date, int in_store){
	ID_Number = in_ID_Number;
	Name = in_Name;
	Price = in_Price;
	company_name = in_company_name;
	Buy_Price = in_Buy_Price;
	date = in_date;
	store = in_store;
}
string Goods::getName() {
	return Name;
}
string Goods::getID_Number() {
	return ID_Number;
}
int Goods::getPrice() {
	return Price;
}
string Goods::getcompany_name() {
	return company_name;
}
int Goods::getBuy_Price() {
	return Buy_Price;
}
string Goods::getDate() {
	string returnback;
	returnback += to_string(date.getyear())+"/";
	if (date.getmonth()/10==0) {
		returnback += "0";
	}
	returnback += to_string(date.getmonth()) + "/";
	if (date.getday() / 10 == 0) {
		returnback += "0";
	}
	returnback += to_string(date.getday());
	return returnback;
}
int Goods::getstore() {
	return store;
}
void Goods::setName(string in_Name) {
	Name = in_Name;
}
void Goods::setPrice(int in_Price) {
	Price = in_Price;
}
void Goods::setcompany_name(string in_company_name) {
	company_name = in_company_name;
}
void Goods::setBuy_Price(int in_Buy_Price) {
	Buy_Price = in_Buy_Price;
}
void Goods::setdate(Date in_Date) {
	date = in_Date;
}
void Goods::setstore(int in_store) {
	store = in_store;
}