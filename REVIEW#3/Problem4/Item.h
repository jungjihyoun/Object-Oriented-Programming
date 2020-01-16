#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;

class Item
{
protected:
	string code;
	string name;
	string price;

public:
	Item();
	Item(string _code, string _name, string _price);

	void setCode(string _code);
	void setName(string _name);
	void setPrice(int _price);

	string getCode();
	string getName();
	string getPrice();

	void setItem(string _code, string _name, int _price);

	virtual void displayItem() const = 0;
	virtual int readItemFromFile(ifstream& _fin) = 0;
	virtual int writeItemToFile(ofstream& _fout) = 0;
};

