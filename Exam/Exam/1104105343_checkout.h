#pragma once
#include "1104105343_goods.h"
#include "1104105343_Date.h"
#include "1104105343_Data.h"
#include "1104105343_judge.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
void choose(vector<Goods *> *goo);
void show_choose_goods(vector<Goods *> *goo);
bool show_shopping_cart(vector<Goods *> *goo, vector<int> *amount);
void show_shopping_goods(vector<Goods *> *goo, vector<int> *amount);