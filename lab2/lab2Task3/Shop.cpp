#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "Shop.h"
using namespace std;

Shop::Shop() {
	nameOfShop_ = "No name";
	address_ = "Unknown";
	openingYear_ = 2000;
	number_ = 0;
	totalShopProfit_ = 0;

    // cout << "Магазин " << nameOfShop_ <<" записан." << endl;
}

Shop::Shop(const string& nameOfShop, const string& address, int openingYear, int number, int totalShopProfit) :
	nameOfShop_(nameOfShop), address_(address), openingYear_(openingYear), number_(number), totalShopProfit_(totalShopProfit)
{
	//cout << "Магазин " << nameOfShop_ << " записан." << endl << endl;
}


Shop::~Shop() {

	//cout << "Магазин " << nameOfShop_ << " удален." << endl  << endl;
}


void Shop::setNameOfShop(const string& nameOfShop) {
	nameOfShop_ = nameOfShop;
}
void Shop::setAddress(const string& address) {
	address_ = address;
}
void Shop::setOpeningYear(const int openingYear) {
	openingYear_ = openingYear;
}
void Shop::setNumber(const int number) {
	number_ = number;
}
void Shop::setTotalShopProfit(const short totalShopProfit) {
	totalShopProfit_ = totalShopProfit;
}

string Shop::getNameOfShop()const {
	return nameOfShop_;
}
string Shop::getAddress()const {
	return address_;
}
int Shop::getOpeningYear()const {
	return openingYear_;
}
int Shop::getNumber()const {
	return number_;
}
int Shop::getTotalShopProfit()const {
	return totalShopProfit_;
}


void Shop::serialize()const {

	
	string num = to_string(number_);
	const string path = num + ".txt";
	//std::string path = std::string("Shop") + num+ ".txt" ;
	ofstream fout(path);
	if (fout.is_open()) {
		fout << "Название:" << nameOfShop_ << endl;
		fout << "Адрес" << address_ << endl;
		fout << "Год открытия" << openingYear_ << endl;
		fout << "Номер" << number_ << endl;
		fout << "Суммарная прибыль" << totalShopProfit_ << endl;
	}
	fout.close();
}

void Shop::serialize(const string& filename)const {

	ofstream fout(filename, ios_base::app | ios::trunc);

	if (fout.is_open()) {

		fout << "Название:" << nameOfShop_ << endl;
		fout << "Адрес" << address_ << endl;
		fout << "Год открытия" << openingYear_ << endl;
		fout << "Номер" << number_ << endl;
		fout << "Суммарная прибыль" << totalShopProfit_ << endl;
	}
	fout.close();
}

void Shop::deserialize() {

	string num = to_string(number_);
	const string path = num + ".txt";
	//std::string path = number_ + ".txt";
	string line;
	ifstream fin(path);
	if (fin.is_open()) {

		while (getline(fin, line)) {
			cout << line << endl;
		}
	}
	fin.close();
}

void Shop::deserialize(const string& filename) {

	string line;
	ifstream fin(filename, ios_base::app | ios_base::trunc);
	if (fin.is_open()) {
		while (getline(fin, line)) {
			cout << line << endl;
		}
	}
	fin.close();
}

//вывод
void Shop::PrintShop() {
	cout << "Название:" << nameOfShop_ << endl;
	cout << "Адрес:" << address_ << endl;
	cout << "Год открытия:" << openingYear_ << endl;
	cout << "Номер:" << number_ << endl;
	cout << "Суммарная прибыль:" << totalShopProfit_ << endl;

}


void Shop::AutumnSales(size_t i, string month, Shop arr) {       
	//srand(time(NULL));
	for (size_t j = 0; j < 3; j++) {
		int profit = random(80000, 200000);//rand() % 70001 + 80000;//rand() % (b - a + 1) + a
		cout << "Прибыль за " << month << ": " << profit << endl;
		totalShopProfit_ += profit;	
	}
	cout << "Суммарная прибыль магазина №"<< i+1 << ": "<< totalShopProfit_ << endl << endl;
	arr.setTotalShopProfit(totalShopProfit_);
}

int Shop::random(int low, int high) {
	if (low > high) return high;
	return low + (std::rand() % (high - low + 1));
}

void Shop::DescendingSort(Shop* monthProfit, size_t len) {


	Shop tmp;
	for (size_t i = 0; i < len; i++) {
		int max = i;
		for (size_t j = i + 1; j < len; j++) {
			if (monthProfit[j].totalShopProfit_ > monthProfit[max].totalShopProfit_) {
				max = j;
			}
		}
		if (max != i) {
			tmp = monthProfit[i];
			monthProfit[i] = monthProfit[max];
			monthProfit[max] = tmp;
		}
	}

	for (size_t i = 0; i < 3; i++) {
		cout << "Магазин " << monthProfit[i].nameOfShop_ << "  Прибыль " << monthProfit[i].totalShopProfit_ << endl;
		if (i == 2)
			cout << endl << endl;
	}
}

void Shop::AscendingSort(Shop* arr, size_t len) {


	Shop tmp;
	for (size_t i = 0; i < len; i++) {
		int min = i;
		for (size_t j = i + 1; j < len; j++) {
			if (arr[j].totalShopProfit_ <  arr[min].totalShopProfit_) {
				min = j;
			}
		}
		if (min != i) {
			tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}

	for (size_t i = 0; i < 3; i++) {
		cout << "Магазин " << arr[i].nameOfShop_ << "  Прибыль " << arr[i].totalShopProfit_ << endl;
		if (i == 2)
			cout << endl << endl;
	}
}

std::ostream& operator<<(ostream& out,const Shop& shop)
{
	out << "Название:" << shop.nameOfShop_ << endl
	<< "Адрес:" << shop.address_.c_str() << endl
	<< "Год открытия:" << shop.openingYear_ << endl
	<< "Номер:" << shop.number_ << endl
	<< "Суммарная прибыль:" << shop.totalShopProfit_ << endl;
	return out;
}

