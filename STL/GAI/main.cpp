#include<iostream>
#include<string>
#include<map>
#include<forward_list>
#include"Crime.h"
using namespace std;
#define tab "\t"

void print(const std::map<std::string, std::forward_list<Crime>>& database);
void print(const std::map<std::string, std::forward_list<Crime>>& database, const std::string& id);

void main()
{
	setlocale(LC_ALL, "");
	std::map<std::string,std::forward_list<Crime>> database =
	{
		std::pair<std::string,std::forward_list<Crime>>("BI6666BC",std::forward_list<Crime>{Crime("АТБ на Ляли","Принес в жертву черного барана, в результате чего облил светофор кровью барана, и заляпал зебру")}),
		std::pair<std::string,std::forward_list<Crime>>("BI6667CB",std::forward_list<Crime>{Crime("Макдональдс","Плюнул в пост ГАИ")}),
		std::pair<std::string,std::forward_list<Crime>>("BI1488CI",std::forward_list<Crime>{Crime("Корпусный парк","Сбил забор возле клумбы")})
	};

	//std::cout << database.size() << std::endl;

	cout << "1. Вывод всей базы;" << endl;
	cout << "2. Вывод информации по номеру;" << endl;
	cout << "3. Вывод информации по диапазону номеров;" << endl;
	cout << "4. Добавление записи;" << endl;
	char key;
	cout << "Выберите действие: "; std::cin >> key;
	switch (key)
	{
	case '1':print(database); break;
	case '2': 
	{
		std::string id;
		cout << "Введите номер автомобиля: "; std::cin >> id;
		print(database, id);
	}; break;

	}
	


}

void print(const std::map<std::string, std::forward_list<Crime>>& database)
{
	for (std::pair<std::string, std::forward_list<Crime>> i : database)
	{
		std::cout << i.first << ":\n";
		for (Crime j : i.second)
		{
			std::cout <<"Место происшествия: "<< j.get_place() << tab <<"Нарушение: "<< j.get_crime() << ";\n";
		}
	}
}
void print(const std::map<std::string, std::forward_list<Crime>>& database, const std::string& id)
{
//std::cout<<database[id]
	bool present_in_base = false;
	for (std::pair<std::string, std::forward_list<Crime>>i : database)
	{
		if (id == i.first)
		{
			present_in_base = true;
			for (Crime j : i.second)
			{
				std::cout << "Место происшествия: " << j.get_place() << tab << "Нарушение: " << j.get_crime() << ";\n";
			}
			break;
		}
	}
	if (!present_in_base)std::cout << "В базе нет такого номера; " << std::endl;
}