#include "1104105343_Data.h"
void ReadCompanyData(vector<Company *> *comp) {
	ifstream fin("company.txt");
	if (!fin) {
		cout << "公司讀檔失敗";
		return;
	}
	while (!fin.eof()) {
		string Name;
		string Name_temp;
		string Contact;
		string Contact_temp;
		string Phone;
		while (1) {
			fin >> Name_temp;
			if (Name_temp.at(0) == '"' && Name_temp.at(Name_temp.size() - 1) == '"') {
				Name_temp.erase(Name_temp.begin());
				Name_temp.erase(Name_temp.end() - 1);
				Name = Name_temp;
				break;
			}
			else if (Name_temp.at(0) == '"') {
				Name_temp.erase(Name_temp.begin());
				Name += Name_temp+" ";
			}
			else if (Name_temp.at(Name_temp.size() - 1) == '"') {
				Name_temp.erase(Name_temp.end() - 1);
				Name += Name_temp;
				break;
			}
			else {
				Name += Name_temp+" ";
			}
		}
		while (1) {
			fin >> Contact_temp;
			if (Contact_temp.at(0) == '"' && Contact_temp.at(Contact_temp.size() - 1) == '"') {
				Contact_temp.erase(Contact_temp.begin());
				Contact_temp.erase(Contact_temp.end() - 1);
				Contact = Contact_temp;
				break;
			}
			else if (Contact_temp.at(0) == '"') {
				Contact_temp.erase(Contact_temp.begin());
				Contact += Contact_temp + " ";
			}
			else if (Contact_temp.at(Contact_temp.size() - 1) == '"') {
				Contact_temp.erase(Contact_temp.end() - 1);
				Contact += Contact_temp;
				break;
			}
			else {
				Contact += Contact_temp + " ";
			}
		}
		fin >> Phone;
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
	string Name_temp;
	int Price;
	string company_name;
	string company_name_temp;
	int Buy_Price;
	string date;
	int store;
	while (!fin.eof()) {
		//fin >> ID >> Name >> Price >> company_name >> Buy_Price >> date >> store;
		fin >> ID;
		while (1) {
			fin >> Name_temp;
			if (Name_temp.at(0) == '"' && Name_temp.at(Name_temp.size() - 1) == '"') {
				Name_temp.erase(Name_temp.begin());
				Name_temp.erase(Name_temp.end() - 1);
				Name = Name_temp;
				break;
			}
			else if (Name_temp.at(0) == '"') {
				Name_temp.erase(Name_temp.begin());
				Name += Name_temp + " ";
			}
			else if (Name_temp.at(Name_temp.size() - 1) == '"') {
				Name_temp.erase(Name_temp.end() - 1);
				Name += Name_temp;
				break;
			}
			else {
				Name += Name_temp + " ";
			}
		}
		fin >> Price;
		while (1) {
			fin >> company_name_temp;
			if (company_name_temp.at(0) == '"' && company_name_temp.at(company_name_temp.size() - 1) == '"') {
				company_name_temp.erase(company_name_temp.begin());
				company_name_temp.erase(company_name_temp.end() - 1);
				company_name = company_name_temp;
				break;
			}
			else if (company_name_temp.at(0) == '"') {
				company_name_temp.erase(company_name_temp.begin());
				company_name += company_name_temp + " ";
			}
			else if (company_name_temp.at(company_name_temp.size() - 1) == '"') {
				company_name_temp.erase(company_name_temp.end() - 1);
				company_name += company_name_temp;
				break;
			}
			else {
				company_name += company_name_temp + " ";
			}
		}
		fin >> Buy_Price;
		fin >> date;
		fin >> store;
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
		fout << '"' << (*it)->getname() << '"' << " " << '"' << (*it)->getContact_Person() << '"' << " " << (*it)->getPhone();
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
		fout << (*it)->getID_Number() << " " << '"' << (*it)->getName() << '"' << " " << (*it)->getPrice() << " " << '"' << (*it)->getcompany_name() << '"' << " " << (*it)->getBuy_Price() <<" " << setw(10) << setfill('0') << (*it)->getDate() << " " << (*it)->getstore();
		if (it != goo->end() - 1) {
			fout << endl;
		}
	}
	fout.close();
	return true;
}