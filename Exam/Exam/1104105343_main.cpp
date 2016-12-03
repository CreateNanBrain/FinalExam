#define _CRT_SECURE_NO_WARNINGS
#define use_outside_file true
#include <iostream>
#include <vector>
#include <time.h>
#include "1104105343_Date.h"
#include "1104105343_company.h"
#include "1104105343_goods.h"
#include "1104105343_purchase.h"
#include "1104105343_Data.h"
#include "1104105343_judge.h"
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
	case 2:break;//暫時還沒做
	case 3:break;//還沒做
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
#endif
	MainMenu(&company, &goods);
#if use_outside_file
	while (!WriteCompanyData(&company));
	while (!WriteGoodsData(&goods));
#endif 
}