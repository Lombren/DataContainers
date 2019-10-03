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
		std::pair<std::string,std::forward_list<Crime>>("BI6666BC",std::forward_list<Crime>{Crime("��� �� ����","������ � ������ ������� ������, � ���������� ���� ����� �������� ������ ������, � ������� �����")}),
		std::pair<std::string,std::forward_list<Crime>>("BI6667CB",std::forward_list<Crime>{Crime("�����������","������ � ���� ���")}),
		std::pair<std::string,std::forward_list<Crime>>("BI1488CI",std::forward_list<Crime>{Crime("��������� ����","���� ����� ����� ������")})
	};

	//std::cout << database.size() << std::endl;

	cout << "1. ����� ���� ����;" << endl;
	cout << "2. ����� ���������� �� ������;" << endl;
	cout << "3. ����� ���������� �� ��������� �������;" << endl;
	cout << "4. ���������� ������;" << endl;
	char key;
	cout << "�������� ��������: "; std::cin >> key;
	switch (key)
	{
	case '1':print(database); break;
	case '2': 
	{
		std::string id;
		cout << "������� ����� ����������: "; std::cin >> id;
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
			std::cout <<"����� ������������: "<< j.get_place() << tab <<"���������: "<< j.get_crime() << ";\n";
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
				std::cout << "����� ������������: " << j.get_place() << tab << "���������: " << j.get_crime() << ";\n";
			}
			break;
		}
	}
	if (!present_in_base)std::cout << "� ���� ��� ������ ������; " << std::endl;
}