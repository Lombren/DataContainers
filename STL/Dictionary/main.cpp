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
		pair<string,vector<string>>("pain\t",vector<string>{"����","���������"}),
		pair<string,vector<string>>("love\t",vector<string>{"������","�������"}),
		pair<string,vector<string>>("space\t",vector<string>{"������","������������","������"}),
		pair<string,vector<string>>("void\t",vector<string>{"�������","������"}),
		pair<string,vector<string>>("solitude",vector<string>{"�����������","���������"}),
		pair<string,vector<string>>("winter\t",vector<string>{"����"})
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