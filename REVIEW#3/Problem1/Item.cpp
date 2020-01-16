#include "Item.h"

Item::Item() : code(""), name(""), price(0) {}
Item::Item(string _code, string _name, int _price) : code(_code), name(_name), price(_price) {}

void Item::setCode(string _code) { code = _code; }
void Item::setName(string _name) { name = _name; }
void Item::setPrice(int _price) { price = _price; }

string Item::getCode() { return code; }
string Item::getName() { return name; }
int Item::getPrice() { return price; }