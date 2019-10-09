#include<iostream>
#include<string>
#include<map>
#include<forward_list>
#include"Crime.h"
#include<conio.h>
#include<windows.h>
using namespace std;
#define tab "\t"

void print(const std::map<std::string, std::forward_list<Crime>>& database);
void print(const std::map<std::string, std::forward_list<Crime>>& database, const std::string& id);
void print(const std::map<std::string, std::forward_list<Crime>>& database, const std::string& start_id, const std::string& end_id);
void input_line(std::string& str)
{
	SetConsoleCP(1251);
	std::getline(std::cin, str);
	SetConsoleCP(866);
}
void main()
{
	setlocale(LC_ALL, "");
	std::map<std::string, std::forward_list<Crime>> database =
	{
		std::pair<std::string,std::forward_list<Crime>>("BI 6666 BC",std::forward_list<Crime>{Crime("АТБ на Ляли","Принес в жертву черного барана, в результате чего облил светофор кровью барана, и заляпал зебру")}),
		std::pair<std::string,std::forward_list<Crime>>("BI 6667 CB",std::forward_list<Crime>{Crime("Макдональдс","Плюнул в пост ГАИ")}),
		std::pair<std::string,std::forward_list<Crime>>("BI 1488 CI",std::forward_list<Crime>{Crime("Корпусный парк","Сбил забор возле клумбы")})
	};

	//std::cout << database.size() << std::endl;

	do
	{
		system("CLS");
		char key;
		cout << "1. Вывод всей базы;" << endl;
		cout << "2. Вывод информации по номеру;" << endl;
		cout << "3. Вывод информации по диапазону номеров;" << endl;
		cout << "4. Добавление записи;" << endl;
		cout << "Выберите действие: "; std::cin >> key;
		switch (key)
		{
		case '1':
		{
			system("CLS");
			print(database);
			break;
		}
		case '2':
		{
			system("CLS");
			std::string id;
			cout << "Введите номер автомобиля: ";
			//std::cin >> id;
			std::cin.clear();
			std::cin.ignore();
			std::getline(std::cin, id);
			print(database, id);
			break;
		}
		case'3':
		{
			system("CLS");
			std::string start_id, end_id;
			cout << "Введите начальный номер автомобиля: ";
			std::cin.clear();
			std::cin.ignore();
			std::getline(std::cin, start_id);
			cout << "Введите конечный номер автомобиля: ";
			std::cin.clear();
			std::cin.ignore();
			std::getline(std::cin, end_id);
			print(database, start_id, end_id);
			break;
		}
		case '4':
		{
			system("CLS");
			std::cout << "Добавление квитанции: " << endl;
			std::string id, place, crime;
			std::cin.sync();
			std::cin.get();
			std::cout << "Номер авто: "; /*std::getline(std::cin*/input_line(id);
			std::cout << "Место происшествия: "; /*std::getline(std::cin,place)*/input_line(place);
			std::cout << "Правонарушение: "; /*std::getline(std::cin,crime)*/input_line(crime);
			database[id].push_front(Crime(place, crime));
			break;
		}
		}
		cout << "Press Esc to exit..." << endl;
	} while (getch() != 27);


}

void print(const std::map<std::string, std::forward_list<Crime>>& database)
{
	for (std::pair<std::string, std::forward_list<Crime>> i : database)
	{
		std::cout << i.first << ":\n";
		for (Crime j : i.second)
		{
			std::cout << "Место происшествия: " << j.get_place() << tab << "Нарушение: " << j.get_crime() << ";\n";
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
void print(const std::map<std::string, std::forward_list<Crime>>& database, const std::string& start_id, const std::string& end_id)
{
	//std::cout<<database[id]
	bool present_in_base = false;
	for (std::pair<std::string, std::forward_list<Crime>>i : database)
	{
		if (i.first>=start_id && i.first<=end_id)
		{
			std::cout << i.first << ":\n";
			present_in_base = true;
			for (Crime j : i.second)
			{
				std::cout <<"Место происшествия: " << j.get_place() << tab << "Нарушение: " << j.get_crime() << ";\n";
			}
			//break;
		}
	}
	if (!present_in_base)std::cout << "В базе нет такого номера; " << std::endl;
}