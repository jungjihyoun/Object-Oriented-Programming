#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Item
{
private:
	string code;
	string name;
	int price;

public:
	Item();
	Item(string _code, string _name, int _price);

	void setCode(string _code);
	void setName(string _name);
	void setPrice(int _price);

	string getCode();
	string getName();
	int getPrice();
};

