#pragma once
#include "1104105343_goods.h"
#include "1104105343_company.h"
#include "1104105343_purchase.h"
#include "1104105343_judge.h"
#include "1104105343_Date.h"
#include <iostream>
#include <vector>;
using namespace std;
void Goods_search_By_ID(vector<Goods *> *goo, string ID);
void Goods_search_By_Name(vector<Goods *> *goo, string Name);
void Goods_search_By_Company(vector<Goods *> *goo, string company);
void Show_Goods_Date(vector<Goods *> *goo, Date date);
void Search_Menu(vector<Goods *> *goo);