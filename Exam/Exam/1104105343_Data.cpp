#include "1104105343_Data.h"
void ReadCompanyData(vector<Company *> *comp) {
	ifstream fin("company.txt");
	if (!fin) {
		cout << "公司讀檔失敗";
		return;
	}
	string Name;
	string Contact;
	string Phone;
	while (!fin.eof()) {
		fin >> Name >> Contact >> Phone;
		Add_Company(comp, Name, Contact, Phone);
	}
	fin.close();
}
void ReadGoodsData(vector<Goods *> *goo) {
	ifstream fin("goods.txt");
	if (!fin) {
		cout << "公司讀檔失敗";
		return;
	}
	string ID;
	string Name;
	int Price;
	string company_name;
	int Buy_Price;
	string date;
	int store;
	while (!fin.eof()) {
		fin >> ID >> Name >> Price >> company_name >> Buy_Price >> date >> store;
		string year;
		string month;
		string day;
		for (int i = 0; i < 4; i++) {
			year.push_back(date.at(i));
		}
		month.push_back(date.at(5));
		month.push_back(date.at(6));
		day.push_back(date.at(8));
		day.push_back(date.at(9));
		Date *date_temp = new Date(stoi(year), stoi(month), stoi(day));
		Add_Goods(goo, ID, Name, Price, company_name, Buy_Price, *date_temp, store);
	}
	fin.close();
}
bool WriteCompanyData(vector<Company *> *comp) {
	ofstream fout("company.txt");
	if (!fout) {
		cout << "無法寫檔";
		return false;
	}
	for (vector<Company *>::iterator it = comp->begin(); it != comp->end(); it++) {
		fout << (*it)->getname() << " " << (*it)->getContact_Person() << " " << (*it)->getPhone();
		if (it != (comp->end() - 1)) {
			 fout << endl;
		}
	}
	fout.close();
	return true;
}
bool WriteGoodsData(vector<Goods *> *goo) {
	ofstream fout("goods.txt");
	if (!fout) {
		cout << "無法寫檔";
		return false;
	}
	for (vector<Goods *>::iterator it = goo->begin(); it != goo->end(); it++) {
		fout << (*it)->getID_Number() << " " << (*it)->getName() << " " << (*it)->getPrice() << " " << (*it)->getcompany_name() << " " << (*it)->getBuy_Price() <<" " << setw(10) << setfill('0') << (*it)->getDate() << " " << (*it)->getstore();
		if (it != goo->end() - 1) {
			fout << endl;
		}
	}
	fout.close();
	return true;
}