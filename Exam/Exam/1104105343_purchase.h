#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "1104105343_company.h"
#include "1104105343_goods.h"
using namespace std;
//menu
void ShowMaintainMenu(vector<Company *> *comp, vector<Goods *> *goo);
void ShowCompanyMaintain(vector<Company *> *comp, vector<Goods *> *goo);
void ShowGoodsMaintain(vector<Goods *> *goo,vector<Company *> *comp);
//廠商維護
void Add_Company(vector<Company *> *comp, string in_name, string in_contact, string in_Phone);
void Update_Company_Phone(vector<Company *> *comp, int position, string in_Phone);
void Update_Company_Name(vector<Company *> *comp, int position, string in_Name);
void Update_Company_Contact_Person(vector<Company *> *comp, int position, string in_Contact);
void Delete_Company(vector<Company *> *comp, int position);
bool IS_COMPANY_EXIST(vector<Company *> *comp, string in_name);
void ShowCompany(vector<Company *> *comp);
//	商品維護
void Add_Goods(vector<Goods *> *goo, string in_ID_Number, string in_Name, int in_Price, string in_company_name, int in_Buy_Price, Date in_Date, int in_store);
void Update_Goods_Name(vector<Goods *> *goo, int position, string in_Name);
void Update_Goods_Price(vector<Goods *> *goo, int position, int in_Price);
void Update_Goods_Company_Name(vector<Goods *> *goo, int position, string in_company_name);
void Update_Goods_Buy_Price(vector<Goods *> *goo, int position, int in_Buy_Price);
void Update_Goods_Last_Date(vector<Goods *> *goo, int position, Date in_Date);
void Update_Goods_Store(vector<Goods *> *goo, int position, int in_store);
void Delete_Goods(vector<Goods *> *goo, int position);
bool IS_Goods_ID_EXIST(vector<Goods *> *goo, string id);
void ShowGoods(vector<Goods *> *goo);
