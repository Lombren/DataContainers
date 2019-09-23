#include<iostream>
#include<array>
#include<vector>


using namespace std;
using std::cout;

#define delimiter "\n---------------------------------------------------------------\n"
#define tab "\t"
//#define STL_ARRAY
#define STL_VECTOR


void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array -это контейнер который 
	int Arr[] = { 3,5,8,13,21 };
	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;

	for (int i : Arr)
	{
		cout << i << "\t";
	}
	cout << endl;

	/*int* d_arr = new int[5]{ 3,5,8,13,21 }
		for (int i : d_arr)
		{
			cout << i << "\t";

		}
	cout << endl;
	delete[] d_arr;*/
	for (int i : arr)cout << i << "\t"; cout << endl;
#endif // STL_ARRAY
#ifdef STL_VECTOR
	vector<int> vec = {0,1,1,2,3,5,8,13,21,34};
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	cout << "Size:\t\t" << vec.size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	cout << delimiter << endl;
	vec.push_back(55);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	cout << "Size:\t\t" << vec.size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	cout << delimiter << endl;
	vec.push_back(89);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	cout << "Size:\t\t" << vec.size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	cout << delimiter << endl;
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << delimiter << endl;
	cout << "unnormal Revers: " << endl;
	for (vector<int>::iterator it = vec.end()-1; /*it !=vec.begin()*/ ; it--)
	{
		cout << *it << tab;
		if (it == vec.begin())break;
	}
	cout << endl;
	cout << delimiter << endl;
	vec.resize(8);
;	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	vec.shrink_to_fit();
	vec.reserve(23);
	cout << "Size:\t\t" << vec.size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	cout << vec.empty() << endl;
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	cout << vec.data() << endl;
	int* vec_arr = vec.data();//глянуть в отладчике
	cout << delimiter << endl;
	int index;
	int Data;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> Data;
	vec.insert(vec.begin()+index,Data);//арифметика указателей
	//cout << delimiter << endl;
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << delimiter << endl;

#endif // STL_VECTOR






}