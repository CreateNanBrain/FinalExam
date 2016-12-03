#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include "1104105343_goods.h"
#include "1104105343_company.h"
#include "1104105343_purchase.h"
using namespace std;
void ReadCompanyData(vector<Company *> *comp); 
void ReadGoodsData(vector<Goods *> *goo);
bool WriteCompanyData(vector<Company *> *comp);
bool WriteGoodsData(vector<Goods *> *goo);