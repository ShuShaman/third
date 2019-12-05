#pragma once
#include <iostream>
#include <string>

using namespace std;

class Shop
{
public:

	Shop(); 

	Shop(const string& nameOfShop, const string& address, int openingYear, int number, int totalShopProfit);//constructor с параметрами

	//gettes, setters
	void setNameOfShop(const string& nameOfShop);
	void setAddress(const string& address);
	void setOpeningYear(const int openingYear);
	void setNumber(const int number);
	void setTotalShopProfit(const short totalShopProfit);

	string getNameOfShop()const;
	string getAddress()const;
	int getOpeningYear()const;
	int getNumber()const;
	int getTotalShopProfit()const;

	void AutumnSales(size_t i, string month, Shop arr);
	int random(int low, int high);

	void DescendingSort(Shop* arr, size_t len);
	void AscendingSort(Shop* arr, size_t len);

	void serialize()const;
	void serialize(const string& filename)const;
	void deserialize();
	void deserialize(const string& filename);

	void PrintShop();
	friend std::ostream& operator<<(ostream& out,const Shop& shop);

	~Shop();

private:


	string nameOfShop_;
	string address_;
	int openingYear_;
	int number_;
	int totalShopProfit_;
};

