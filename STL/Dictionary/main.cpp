#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
#define tab "\t"
#define delimiter "\n------------------------------------------------------------------------------\n"
void main()
{
	setlocale(LC_ALL, "");
	map<string, vector<string>>dictionary=
	{
		pair<string,vector<string>>("pain\t",vector<string>{"боль","огорчение"}),
		pair<string,vector<string>>("love\t",vector<string>{"любовь","страсть"}),
		pair<string,vector<string>>("space\t",vector<string>{"космос","пространство","пробел"}),
		pair<string,vector<string>>("void\t",vector<string>{"пустота","вакуум"}),
		pair<string,vector<string>>("solitude",vector<string>{"одиночество","уеденение"}),
		pair<string,vector<string>>("winter\t",vector<string>{"зима"})
	};
	//Standart output
	for (map<string, vector<string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		cout << it->first << tab;
		for (vector<string>::iterator jt = it->second.begin(); jt != it->second.end(); jt++)
		{
			cout << *jt << ",";
		}
		cout << "\b;\n";
	}
	cout << delimiter;
	//short output
	for (pair<string, vector<string>>i : dictionary)
	{
		cout << i.first << tab;
		for (string j :i.second)
		{
			cout << j << ",";
		}
		cout << "\b;\n";
	}

	
}