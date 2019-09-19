#include<iostream>
#include<array>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	//array -это контейнер который 
	int Arr[] = { 3,5,8,13,21 };
	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
	

}