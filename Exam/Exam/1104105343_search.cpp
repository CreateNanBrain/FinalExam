#include "1104105343_search.h"
void Goods_search_By_ID(vector<Goods *> *goo, string ID) {
	vector<Goods *> goo_temp;
	for (vector<Goods *>::iterator it = goo->begin(); it != goo->end(); it++) {
		if (IS_STRING_INCLUDE((*it)->getID_Number(), ID))
			goo_temp.push_back((*it));
	}
	if (goo_temp.size() == 0) {
		cout << "�d�L�ŦX������" << endl;
	}
	else {
		ShowGoods(&goo_temp);
	}
	system("pause");
}
void Goods_search_By_Name(vector<Goods *> *goo, string Name) {
	vector<Goods *> goo_temp;
	for (vector<Goods *>::iterator it = goo->begin(); it != goo->end(); it++) {
		if (IS_STRING_INCLUDE((*it)->getName(), Name))
			goo_temp.push_back((*it));
	}
	if (goo_temp.size() == 0) {
		cout << "�d�L�ŦX������" << endl;
	}
	else {
		ShowGoods(&goo_temp);
	}
}
void Goods_search_By_Company(vector<Goods *> *goo, string company) {
	vector<Goods *> goo_temp;
	for (vector<Goods *>::iterator it = goo->begin(); it != goo->end(); it++) {
		if (IS_STRING_INCLUDE((*it)->getcompany_name(), company))
			goo_temp.push_back((*it));
	}
	if (goo_temp.size() == 0) {
		cout << "�d�L�ŦX������" << endl;
	}
	else {
		ShowGoods(&goo_temp);
	}
	system("pause");
}
void Show_Goods_Date(vector<Goods *> *goo,Date date) {
	/*cout << setfill(' ') << "�Τ@�s��" << setw(20) << "�ӫ~�W��" << setw(15) << "�̫�i�f���" << endl;
	for (vector<Goods *>::iterator it = goo->begin(); it != goo->end(); it++) {
		cout << setfill(' ') << setw(8) << (*it)->getID_Number() << setw(20) << (*it)->getName() << setw(15) << (*it)->getDate() << endl;
	}*/
	vector<Goods *> goo_temp;
	string d;
	d += to_string(date.getyear()) + "/";
	if (date.getmonth() < 10)
		d += "0";
	d += to_string(date.getmonth()) + "/";
	if (date.getday() < 10)
		d += "0";
	d += to_string(date.getday());
	for (vector<Goods *>::iterator it = goo->begin(); it != goo->end(); it++) {
		if ((*it)->getDate()==d)
			goo_temp.push_back((*it));
	}
	if (goo_temp.size() == 0) {
		cout << "�d�L�ŦX������" << endl;
	}
	else {
		ShowGoods(&goo_temp);
	}
	system("pause");
}
void Search_Menu(vector<Goods *> *goo) {
	string input;
	while (1) {
		system("cls");
		cout << "0.�h�X  1.�̲Τ@�s��  2.�̰ӫ~�W��  3.�̤W�夽�q  4.��ܰӫ~�i�f�̫���:";
		cin >> input;
		if (input == "0")
			break;
		if (IS_NUMBER(input))
			break;
	}
	system("cls");
	switch (stoi(input)) {
	case 0:return;
	case 1: {
		string check_is_words = "0123456789abcdefghijklmnopqrstuvwxyz";
		string ID;
		while (1) {
			cout << "�п�J���d�߲Τ@�s��(!.����)";
			cin >> ID;
			if (ID == "!")
				break;
			bool is_right=true;
			for (int i = 0; i < ID.size(); i++) {
				if (!IS_STRING_INCLUDE(check_is_words, ID.at(i))) {
					is_right = false;
					break;
				}
			}
			if (is_right) {
				break;
			}
		}
		if (ID == "!")
			break;
		Goods_search_By_ID(goo, ID);
		break;
	}
	case 2: {
		string Name;
		cout << "�п�J���d�߰ӫ~�W��(0.����)";
		cin >> Name;
		if (Name == "0")
			break;
		Goods_search_By_Name(goo, Name);
		break;
	}
	case 3: {
		string company;
		cout << "�п�J�W�夽�q�W��(0.����):";
		cin >> company;
		if (company == "0")
			break;
		Goods_search_By_Company(goo, company);
		break;
	}
	case 4: {
		string year;
		string month;
		string day;
		string temp;
		while (1) {
			year = "";
			month = "";
			day = "";
			temp = "";
			cout << "�п�J����榡��yyyy/mm/dd(0.����):";
			cin >> temp;
			if (temp == "0")
				break;
			if (temp.size() == 10) {
				year.push_back(temp.at(0));
				year.push_back(temp.at(1));
				year.push_back(temp.at(2));
				year.push_back(temp.at(3));
				month.push_back(temp.at(5));
				month.push_back(temp.at(6));
				day.push_back(temp.at(8));
				day.push_back(temp.at(9));
				if (IS_NUMBER(year) && IS_NUMBER(month) && IS_NUMBER(day)) {
					if ((stoi(month)>=1)&&(stoi(month)<=12)) {
						int in_day = stoi(day);
						if ((stoi(year) == getnowYear()) && (stoi(month) == getnowMonth())) {
							if (stoi(day) <= getnowDay()) {
								break;
							}
						}
						else {
							if ((in_day <= 29) && (stoi(month) == 2) && (stoi(year) % 4 == 0) && ((stoi(year) % 100 != 0) || (stoi(year) % 400 == 0))) {
								break;
							}
							else {
								int true_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
								if (in_day >= 1 && in_day <= true_day[stoi(month) - 1]) {
									break;
								}
							}
						}
					}
				}	
			}
		}
		if (temp == "0")
			break;
		Date *date = new Date(stoi(year), stoi(month), stoi(day));
		Show_Goods_Date(goo,*date); 
		break; 
	}
	}
	Search_Menu(goo);
}