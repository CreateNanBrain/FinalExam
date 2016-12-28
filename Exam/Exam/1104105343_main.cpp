#define _CRT_SECURE_NO_WARNINGS
#define use_outside_file 1
#include <iostream>
#include <vector>
#include <time.h>
#include "1104105343_Date.h"
#include "1104105343_company.h"
#include "1104105343_goods.h"
#include "1104105343_purchase.h"
#include "1104105343_Data.h"
#include "1104105343_judge.h"
#include "1104105343_search.h"
#include "1104105343_checkout.h"
using namespace std;
void MainMenu(vector<Company *> *comp, vector<Goods *> *goo) {
	string sel;
	while (1) {
		system("cls");
		cout << "0.退出  1.進貨  2.查詢  3.結帳:";
		cin >> sel;
		if (sel == "0")
			break;
		if (IS_NUMBER(sel))
			break;
	}
	switch (stoi(sel)) {
	case 1:ShowMaintainMenu(comp, goo); break;
	case 2:Search_Menu(goo); break;
	case 3:choose(goo);break;
	case 0:return;
	}
	MainMenu(comp, goo);
}

void main(void) {
	srand(time(NULL));
	vector<Company *> company;
	vector<Goods *> goods;
#if use_outside_file
	ReadCompanyData(&company);
	ReadGoodsData(&goods);
	int i = 0;
	while (1) {
		if (i < goods.size()) {
			if (IS_COMPANY_EXIST(&company, goods.at(i)->getcompany_name())) {
				i++;
			}
			else {
				Delete_Goods(&goods, i);
			}
		}
		else {
			break;
		}
	}
	while (!WriteCompanyData(&company));
	while (!WriteGoodsData(&goods));
#endif
	MainMenu(&company, &goods);
#if use_outside_file
	while (!WriteCompanyData(&company));
	while (!WriteGoodsData(&goods));
#endif 
}