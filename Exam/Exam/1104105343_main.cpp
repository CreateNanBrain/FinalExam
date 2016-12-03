#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <time.h>
#include "1104105343_Date.h"
#include "1104105343_company.h"
#include "1104105343_goods.h"
#include "1104105343_purchase.h"
#include "1104105343_Data.h"
using namespace std;


void main(void) {
	srand(time(NULL));
	vector<Company *> company;
	vector<Goods *> goods;
	ReadCompanyData(&company);
	ReadGoodsData(&goods);
	ShowMaintainMenu(&company, &goods);
	while (!WriteCompanyData(&company));
	while (!WriteGoodsData(&goods));
}