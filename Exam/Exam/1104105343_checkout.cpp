#ifndef use_outside_file
#define use_outside_file 1
#endif

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
		cout << "物品已經在購物車，如需加購請至購物車修改訂單" << endl;
	}
	cout << "請輸入欲想購買之索引(0.進入購物車):";
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
				cout << "請輸入欲想購買數量(0.取消):";
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
	cout << setfill(' ') << "索引" << setw(20) << "商品名稱" << setw(8) << "價錢" << setw(10) << "存貨" << endl;
	int i = 1;
	for (vector<Goods *>::iterator it = goo->begin(); it != goo->end(); it++) {
		cout << setfill('0') << setw(3) << i << ":" << setfill(' ') << setw(20) << (*it)->getName() << setw(8) << (*it)->getPrice() << setw(10) << (*it)->getstore() << endl;
		i++;
	}
}
void show_shopping_goods(vector<Goods *> *goo, vector<int> *amount) {
	system("cls");
	cout << "索引" << setw(20) << "商品名稱" << setw(8) << "價錢" << setw(10) << "購買數量" << endl;
	int i = 1;
	for (vector<Goods *>::iterator it = goo->begin(); it != goo->end(); it++) {
		cout << setw(3) << i << ":" << setw(20) << (*it)->getName() << setw(8) << (*it)->getPrice() << setw(10) << amount->at(i-1) << endl;
		i++;
	}
}
bool show_shopping_cart(vector<Goods *> *goo, vector<int> *amount) {
	show_shopping_goods(goo, amount);
	cout << "0.取消購買  1.繼續購物  2.修改購買數目  3.取消商品購買  Y.結帳";
	string input;
	cin >> input;
	if (input == "y" || input == "Y") {
		int total=0;
		for (int i = 0; i < goo->size(); i++) {
			total += goo->at(i)->getPrice()*amount->at(i);
			goo->at(i)->setstore(goo->at(i)->getstore() - amount->at(i));
		}
		cout << "總共" << total << "元" << endl;
		system("pause");
		is_first_in = true;
		#if use_outside_file
				while (!WriteGoodsData(goo));
		#endif
		return true;
	}
	if (IS_NUMBER(input)) {
		switch (stoi(input)) {
		case 0:return true;
		case 1:return false;
		case 2: {
			while (1) {
				show_shopping_goods(goo, amount);
				cout << "請輸入欲修改數量之索引(0.取消修改):";
				string sel;
				cin >> sel;
				if (sel == "0")
					break;
				string number;
				if (IS_NUMBER(sel)) {
					if (stoi(sel) > 0 && stoi(sel) <= goo->size()) {
						while (1) {
							system("cls");
							cout << "請輸入數量(0.取消修改):";
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
				cout << "請輸入欲想取消購買商品之索引(0.退出):";
				string sel;
				cin >> sel;
				if (sel == "0")
					break;
				if (IS_NUMBER(sel)) {
					if (stoi(sel) > 0 && stoi(sel) <= goo->size()) {
						cout << "是否取消購買商品" << goo->at(stoi(sel) - 1)->getName() << "?(輸入y確定):";
						string yesorno;
						cin >> yesorno;
						if (yesorno == "y" || yesorno == "Y") {
							cout << "已取消商品" << goo->at(stoi(sel) - 1)->getName();
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