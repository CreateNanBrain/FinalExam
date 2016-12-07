#include "1104105343_checkout.h"
bool is_goods_exist = false;
bool is_first_in = true;
vector<Goods *> *shopping_cart;
vector<int> *amount;
void choose(vector<Goods *> *goo) {
	if (is_first_in) {
		shopping_cart = new vector<Goods *>;
		amount = new vector<int>;
		is_first_in = false;
	}
	show_choose_goods(goo);
	string input;
	if (is_goods_exist) {
		is_goods_exist = false;
		cout << "���~�w�g�b�ʪ����A�p�ݥ[�ʽЦ��ʪ����ק�q��" << endl;
	}
	cout << "�п�J���Q�ʶR������(0.�i�J�ʪ���):";
	cin >> input;
	if (input == "0") {
		if (show_shopping_cart(shopping_cart, amount))
			return;
	}
	if (IS_NUMBER(input)) {
		if (stoi(input) > 0 && stoi(input) <= goo->size()) {
			is_goods_exist = false;
			for (vector<Goods *>::iterator it = shopping_cart->begin(); it != shopping_cart->end(); it++) {
				if ((*it) == goo->at(stoi(input) - 1))
					is_goods_exist = true;
			}
			while (!is_goods_exist) {
				cout << "�п�J���Q�ʶR�ƶq(0.����):";
				string number;
				cin >> number;
				if (number == "0")
					break;
				if (IS_NUMBER(number)) {
					if (stoi(number) <= goo->at(stoi(input) - 1)->getstore()) {
						shopping_cart->push_back(goo->at(stoi(input) - 1));
						amount->push_back(stoi(number));
						break;
					}
				}
			}	
		}
	}
	choose(goo);
	
}
void show_choose_goods(vector<Goods *> *goo) {
	system("cls");
	cout << setfill(' ') << "����" << setw(20) << "�ӫ~�W��" << setw(8) << "����" << setw(10) << "�s�f" << endl;
	int i = 1;
	for (vector<Goods *>::iterator it = goo->begin(); it != goo->end(); it++) {
		cout << setfill('0') << setw(3) << i << ":" << setfill(' ') << setw(20) << (*it)->getName() << setw(8) << (*it)->getPrice() << setw(10) << (*it)->getstore() << endl;
		i++;
	}
}
void show_shopping_goods(vector<Goods *> *goo, vector<int> *amount) {
	system("cls");
	cout << "����" << setw(20) << "�ӫ~�W��" << setw(8) << "����" << setw(10) << "�ʶR�ƶq" << endl;
	int i = 1;
	for (vector<Goods *>::iterator it = goo->begin(); it != goo->end(); it++) {
		cout << setw(3) << i << ":" << setw(20) << (*it)->getName() << setw(8) << (*it)->getPrice() << setw(10) << amount->at(i-1) << endl;
		i++;
	}
}
bool show_shopping_cart(vector<Goods *> *goo, vector<int> *amount) {
	show_shopping_goods(goo, amount);
	cout << "0.�����ʶR  1.�~���ʪ�  2.�ק��ʶR�ƥ�  3.�����ӫ~�ʶR  Y.���b";
	string input;
	cin >> input;
	if (input == "y" || input == "Y") {
		int total=0;
		for (int i = 0; i < goo->size(); i++) {
			total += goo->at(i)->getPrice()*amount->at(i);
			goo->at(i)->setstore(goo->at(i)->getstore() - amount->at(i));
		}
		cout << "�`�@" << total << "��" << endl;
		system("pause");
		is_first_in = true;
		return true;
	}
	if (IS_NUMBER(input)) {
		switch (stoi(input)) {
		case 0:return true;
		case 1:return false;
		case 2: {
			while (1) {
				show_shopping_goods(goo, amount);
				cout << "�п�J���ק�ƶq������(0.�����ק�):";
				string sel;
				cin >> sel;
				if (sel == "0")
					break;
				string number;
				if (IS_NUMBER(sel)) {
					if (stoi(sel) > 0 && stoi(sel) <= goo->size()) {
						while (1) {
							system("cls");
							cout << "�п�J�ƶq(0.�����ק�):";
							cin >> number;
							if (number == "0")
								break;
							if (IS_NUMBER(number)) {
								if (stoi(number) <= goo->at(stoi(sel) - 1)->getstore()) {
									amount->at(stoi(sel)-1) = stoi(number);
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
			while (1) {
				show_shopping_goods(goo, amount);
				cout << "�п�J���Q�����ʶR�ӫ~������(0.�h�X):";
				string sel;
				cin >> sel;
				if (sel == "0")
					break;
				if (IS_NUMBER(sel)) {
					if (stoi(sel) > 0 && stoi(sel) <= goo->size()) {
						cout << "�O�_�����ʶR�ӫ~" << goo->at(stoi(sel) - 1)->getName() << "?(��Jy�T�w):";
						string yesorno;
						cin >> yesorno;
						if (yesorno == "y" || yesorno == "Y") {
							cout << "�w�����ӫ~" << goo->at(stoi(sel) - 1)->getName();
							goo->erase(goo->begin() + stoi(sel) - 1);
							amount->erase(amount->begin() + stoi(sel) - 1);
						}
					}
				}
			}
			break;
		}
		}
	}
	return show_shopping_cart(goo, amount);
}