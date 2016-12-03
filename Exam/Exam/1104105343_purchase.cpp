#include "1104105343_purchase.h"
#include "1104105343_judge.h"
//menu
void ShowMaintainMenu(vector<Company *> *comp, vector<Goods *> *goo) {
	system("cls");
	cout  << "0.�h�X" << "  " << "1.�t�Ӻ��@" << "  " << "2.�ӫ~���@�G";
	string input;
	while (1) {
		cin >> input;
		if (IS_NUMBER(input)) {
			if(stoi(input)>=0 && stoi(input)<=2)
				break;
		}
		system("cls");
		cout << "ĵ�i!�п�J���T�ﶵ" << endl;
		cout << "0.�h�X" << "  " << "1.�t�Ӻ��@" << "  " << "2.�ӫ~���@�G";
	}
	switch (stoi(input)) {
	case 1:ShowCompanyMaintain(comp);	break;
	case 2:ShowGoodsMaintain(goo,comp);		break;
	default:return;
	}
	ShowMaintainMenu(comp, goo);
}
//�t�Ӻ��@
void Add_Company(vector<Company *> *comp, string in_name, string in_contact, string in_Phone) {
	Company *temp = new Company(in_name, in_contact, in_Phone);
	comp->push_back(temp);
}
void Update_Company_Phone(vector<Company *> *comp, int position, string in_Phone) {
	comp->at(position)->setPhone(in_Phone);
}
void Update_Company_Name(vector<Company *> *comp, int position, string in_Name) {
	comp->at(position)->setname(in_Name);
}
void Update_Company_Contact_Person(vector<Company *> *comp, int position, string in_Contact) {
	comp->at(position)->setpContact_Person(in_Contact);
}
void Delete_Company(vector<Company *> *comp,int position) {
	comp->erase(comp->begin() + position);
}
bool IS_COMPANY_EXIST(vector<Company *> *comp, string in_name) {
	bool exist=false;
	for (vector<Company *>::iterator it = comp->begin(); it != comp->end(); it++) {
		if ((*it)->getname() == in_name) {
			exist = true;
			break;
		}
	}
	return exist;
}
void ShowCompany(vector<Company *> *comp) {
	int i=1;
	system("cls");
	for (vector<Company *>::iterator it = comp->begin(); it != comp->end(); it++) {
		cout << setw(3) << setfill('0') << i << ":" << (*it)->getname() << endl;
		i++;
	}
}
void ShowCompanyMaintain(vector<Company *> *comp) {
	string input;
	system("cls");
	cout << "0.�h�X" << "  " << "1.�s�W�t��" << "  " << "2.�ק�t��" << "  " << "3.�R���t��" << "  " << "4.�q�X�@�t�ӡG";
	while (1) {
		cin >> input;
		if (IS_NUMBER(input)) {
			if (stoi(input) >= 0 && stoi(input) <= 4)
				break;
		}
		system("cls");
		cout << "ĵ�i!�п�J���T�ﶵ" << endl;
		cout << "0.�h�X" << "  " << "1.�s�W�t��" << "  " << "2.�ק�t��" << "  " << "3.�R���t��" << "  " << "4.�q�X�@�t�ӡG";
	}
	system("cls");
	string Name = "";
	string Contact = "";
	string phone = "";
	string sel;
	switch (stoi(input)) {
	case 1:{
		while (1) {
			cout << "�п�J�t�ӦW��(0.�h�X)�G";
			cin >> Name;
			if (Name == "0")
				break;
			if (!IS_COMPANY_EXIST(comp, Name)) {
				break;
			}
			else {
				cout << "�t�ӦW�٤w�s�b�A";
			}
		}
		if (Name == "0")
			break;
		cout << "�п�J�p���H(0.�h�X)�G";
		cin >> Contact;
		if (Contact == "0")
			break;
		while (1) {
			cout << "�п�J�p���q��(���Ʀr,0.�h�X)�G";
			cin >> phone;
			if (phone == "0")
				break;
			if (IS_NUMBER(phone)) {
				break;
			}
		}
		if (phone == "0")
			break;
		Add_Company(comp, Name, Contact, phone);
		cout << "�s�W����" << endl;
		system("pause");
		break;
	}
	case 2: {
		while (1) {
			ShowCompany(comp);
			cout << "�п�J���ק�t�ӧǸ�(0.�h�X)";
			cin >> sel;
			if (sel == "0")
				break;
			if (IS_NUMBER(sel)) {
				int seltemp = stoi(sel);
				if ((seltemp >= 1) && (seltemp <= comp->size())) {
					while (1) {
						system("pause");
						cout << "�п�J���קﶵ��(0.�h�X,1.�t�ӦW��,2.�p���H,3.�q��)�G";
						string updatesel;
						cin >> updatesel;
						if (updatesel == "0")
							break;
						if (IS_NUMBER(updatesel)) {
							int updatesel_temp = stoi(updatesel);
							switch (updatesel_temp) {
							case 1:
								while (1) {
									cout << "�п�J�t�ӦW��(0.�h�X)�G";
									cin >> Name;
									if (Name == "0")
										break;
									if (!IS_COMPANY_EXIST(comp, Name)) {
										break;
									}
									else {
										cout << "�t�ӦW�٤w�s�b�A";
									}
								}
								Update_Company_Name(comp, seltemp - 1, Name);
								break;
							case 2:
								cout << "�п�J�p���H(0.�h�X)�G";
								cin >> Contact;
								if (Contact == "0")
									break;
								Update_Company_Contact_Person(comp, seltemp - 1, Contact);
								break;
							case 3:
								while (1) {
									cout << "�п�J�p���q��(���Ʀr,0.�h�X)�G";
									cin >> phone;
									if (phone == "0")
										break;
									if (IS_NUMBER(phone)) {
										break;
									}
								}
								Update_Company_Phone(comp, seltemp - 1, phone);
								break;
							}

						}
					}
				}
			}
		}
		break;
	}
	case 3: {
		ShowCompany(comp);
		while (1) {
			string sel;
			cout << "�п�J���R���t�ӧǸ�(0.�h�X)�G";
			cin >> sel;
			if (sel == "0")
				break;
			if (IS_NUMBER(sel)) {
				int sel_temp = stoi(sel);
				cout << "�t�ӡG" << comp->at(sel_temp - 1)->getname() << "�A��JY�T�{�R��";
				string yesorno;
				cin >> yesorno;
				if (yesorno == "Y" || yesorno == "y") {
					cout << "�w�R���t��" << comp->at(sel_temp)->getname() <<endl;
					Delete_Company(comp, sel_temp - 1);
					system("pause");
				}
			}
		}
		break;
	}
	case 4: {
		ShowCompany(comp);
		system("pause");
		break;
	}
	default:return;
	}
	ShowCompanyMaintain(comp);
}
//�ӫ~���@
void Add_Goods(vector<Goods *> *goo, string in_ID_Number, string in_Name, int in_Price, string in_company_name, int in_Buy_Price, Date in_Date, int in_store) {
	Goods *temp = new Goods(in_ID_Number, in_Name, in_Price, in_company_name, in_Buy_Price, in_Date,in_store);
	goo->push_back(temp);
}
void Update_Goods_Name(vector<Goods *> *goo, int position, string in_Name) {
	goo->at(position)->setName(in_Name);
}
void Update_Goods_Price(vector<Goods *> *goo, int position, int in_Price) {
	goo->at(position)->setPrice(in_Price);
}
void Update_Goods_Company_Name(vector<Goods *> *goo, int position, string in_company_name) {
	goo->at(position)->setcompany_name(in_company_name);
}
void Update_Goods_Buy_Price(vector<Goods *> *goo, int position, int in_Buy_Price) {
	goo->at(position)->setBuy_Price(in_Buy_Price);
}
void Update_Goods_Last_Date(vector<Goods *> *goo, int position, Date in_Date) {
	goo->at(position)->setdate(in_Date);
}
void Delete_Goods(vector<Goods *> *goo,int position) {
	goo->erase(goo->begin() + position);
}
bool IS_Goods_ID_EXIST(vector<Goods *> *goo, string id) {
	bool exist=false;
	for (vector<Goods *>::iterator it = goo->begin(); it != goo->end(); it++) {
		if ((*it)->getID_Number() == id) {
			exist = true;
		}
	}
	return exist;
}
void ShowGoods(vector<Goods *> *goo) {
	cout << setfill(' ') << "�Τ@�s��" << setw(20) << "�ӫ~�W��" << setw(8) << "�w�s" << endl;
	for (vector<Goods *>::iterator it = goo->begin(); it != goo->end(); it++) {
		cout << setw(8) <<(*it)->getID_Number() << setw(20) << (*it)->getName() << setw(8) << (*it)->getstore() << endl;
	}
}
void ShowGoodsMaintain(vector<Goods *> *goo, vector<Company *> *comp) {
	system("cls");
	string input;
	while (1) {
		cout << "0.�h�X" << "  " << "1.�s�W�ӫ~" << "  " << "2.�ק�ӫ~" << "  " << "3.�R���ӫ~" << "  " << "4.�q�w�s:";
		cin >> input;
		if (IS_NUMBER(input))
			if((stoi(input)>=0) && (stoi(input)<=4))
				break;
	}
	switch (stoi(input)) {
	case 1: {
		system("cls");
		string rand_compare = "0123456789abcdefghijklmnopqrstuvwxyz";
		char rand_temp_char[5];
		string Name;
		string Price;
		string comp_name;
		string Buy_Price;
		string ID;
		string store;
		while (1) {
			cout << "�п�J�ӫ~�W��(0.����):";
			cin >> Name;
			if (Name == "0")
				break;
			while (1) {
				cout << "�п�J���(0.����):";
				cin >> Price;
				if (IS_NUMBER(Price))
					break;
			}
			if (Price == "0")
				break;
			while (1) {
				cout << "�п�J�W�夽�q�W��(0.����):";
				cin >> comp_name;
				if (comp_name == "0")
					break;
				if (IS_COMPANY_EXIST(comp, comp_name))
					break;
			}
			if (comp_name == "0")
				break;
			while (1) {
				cout << "�п�J�ʶR����(0.����):";
				cin >> Buy_Price;
				if (IS_NUMBER(Buy_Price))
					break;
			}
			if (Buy_Price == "0")
				break;
			while (1) {
				cout << "�п�J�ʶR�ƶq(0.����)";
				cin >> store;
				if (IS_NUMBER(store))
					break;
			}
			if (store == "0")
				break;
			while (1) {
				ID = "";
				for (int i = 0; i < 5; i++) {
					ID.push_back(rand_compare.at(rand() % rand_compare.length()));
				}
				if (!IS_Goods_ID_EXIST(goo, ID))
					break;
			}
			Date *date=new Date();
			Add_Goods(goo, ID, Name, stoi(Price), comp_name, stoi(Buy_Price), *date, stoi(store));
			cout << "�s�W����" << endl;
			system("pause");
			break;
		}
		break;
	}
	case 4: ShowGoods(goo); system("pause"); break;
	default:return;
	}
	ShowGoodsMaintain(goo,comp);
}