#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<forward_list>

using namespace std;
using std::cout;

#define delimiter "\n---------------------------------------------------------------\n"
#define tab "\t"
//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
#define STL_FORWARD_LIST


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
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
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
	for (vector<int>::iterator it = vec.end() - 1; /*it !=vec.begin()*/; it--)
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
	int* vec_arr = vec.data();//гл€нуть в отладчике
	cout << delimiter << endl;
	int index;
	int Data;
	cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
	cout << "¬ведите значение добавл€емого элемента: "; cin >> Data;
	vec.insert(vec.begin() + index, Data);//арифметика указателей
	//cout << delimiter << endl;
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << delimiter << endl;

#endif // STL_VECTOR
#ifdef STL_DEQUE
	deque<int> dq = { 3,5,8,13,21 };
	for (int i = 0; i < dq.size(); i++)
	{
		cout << dq[i] << tab;
	}
	cout << delimiter;
	/*dq.push_back(34);
	dq.push_back(55);
	dq.push_back(89);
	dq.push_front(1);
	dq.push_front(0);*/
	/*std::deque<int>::iterator it = dq.begin();
	it = dq.insert(it, 1,2);
	it = dq.insert(it, 2,1);
	it = dq.insert(it, 1,0);*/
	/*for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
	{
		if (*it < 3)
		{
			it = dq.insert(it, 1, *it + *it - 1);
		}
		if (*it >= 21)
		{
			it = dq.insert(it, 1, *it + *it - 1);
		}
		if (*it >= 200)break;
	}*///не работает;
	/*auto il = { 10, 20, 30 };
	for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
	{
		dq.insert(il);
	}*///тоже не работает
	dq.insert(dq.begin(), { 0,1,1 });
	dq.insert(dq.end(), { 34,55,89 });
	
	
	for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
	{
		cout << *it << tab;
	};
	cout << delimiter;




#endif // STL_DEQUE
#ifdef STL_FORWARD_LIST
	forward_list<int> fl{ 3,5,8,13,21 };
	cout << fl.max_size() << endl;
	for (int i : fl)cout << i << tab; cout << endl;
#endif // STL_FORWARD_LIST






}