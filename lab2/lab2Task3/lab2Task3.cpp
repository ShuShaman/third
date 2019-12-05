
#include <iostream>
#include "Shop.h"

/*




Task_3(V2)

Написать собственный класс, в соответствии с вариантом. Продемонстрировать в коде
инкапсуляцию данных, применение конструкторов без параметров и с параметрами
для инициализации данных. Класс должен содержать метод serialize() для
сохранения данных класса в файл и метод deserialize() для чтения данных класса
из файла по умолчанию в текущей директории, а также перегруженные методы
serialize(const std::string& filename) и deserialize(const std::string&
filename) для работы с файлом с указанным в параметре именем.

Класс МАГАЗИН.
Данные: название, адрес, год основания, номер, суммарная прибыль.
Создать два объекта-магазина в куче и один в стеке. Данные первых двух заполнить с
помощью сеттеров, а третий проинициализировать с помощью конструктора с
параметрами. В главной функции проимитировать отдельно продажи за сентябрь,
октябрь и ноябрь. Вывести все магазины отдельно в двух рейтинговых списках (сначала
один, затем второй): 1) отсортировать в порядке убывания общей прибыли за 3 месяца;
2) отсортировать в порядке убывания среднего прироста прибыли за 3 месяца.
*/
int main()
{
	setlocale(LC_CTYPE, "rus");
	Shop* shop1 = new Shop();
	shop1->setNameOfShop("София");
	shop1->setAddress("пр. Театральный, дом 1");
	shop1->setOpeningYear(2013);
	shop1->setNumber(1);
	

	//shop1->PrintShop();
	Shop* shop2 = new Shop();
	shop2->setNameOfShop("Геркулес-MOLOKO");
	shop2->setAddress("пр. Мира, дом 13");
	shop2->setOpeningYear(2015);
	shop2->setNumber(2);

	Shop  shop3("Сундучок", "пр. Театральный, дом 1", 2005, 3, 0);

	const size_t len = 3;
	Shop arr[len] = { *shop1,*shop2, shop3 };

	string month[] = { "сентябрь", "октябрь", "ноябрь" };
	for (size_t i = 0; i < len; i++) {
		arr[i].AutumnSales(i, month[i], arr[i]);
	}
	shop1->PrintShop();
	cout << endl << "Сортировка по убыванию." << endl;
	shop1->DescendingSort(arr, len);
	cout << endl << "Сортировка по возрастанию." << endl;
	shop1->AscendingSort(arr, len);
	shop1->serialize();
	//shop2->serialize();
	//shop1->deserialize();

	cout << *shop1 << endl;
	delete	shop1;
	delete	shop2;
}
