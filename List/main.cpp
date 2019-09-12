#include"List.h"






void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
#ifdef BASE_CHECK
	int index = 0;
	int Data;
	cout << "¬ведите размер списка: "; cin >> n;
	List list;
	/*for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}*/
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	//list.push_front(123123);
	cout << "¬ведите номер добавл€емого елемента: "; cin >> index;
	cout << "¬ведите значение добавл€емого елемента: "; cin >> Data;
	list.insert(index, Data);
	list.print();
	list.pop_front();
	list.print();
	list.pop_back();
	list.print();
	//list.print_reverss();Done
	cout << "¬ведите номер удал€емого елемента: "; cin >> index;
	list.erase(index);
	list.print();
#endif // BASE_CHECK
#ifdef CONSTRUCTORS_CHECK

	List<int> lst1 = { 3,5,8,13,21 };
	/*lst1.print();*/
	//for (int i = 0; i < lst1.get_size(); i++)lst1[i] = rand() % 100;
	//for (int i = 0; i < lst1.get_size(); i++)cout << lst1[i] << tab; cout << endl;

	for (int i : lst1)
	{
		cout << i << tab;
	}
	/*List lst2 = { 34,55,89 };
	for (int i = 0; i < lst2.get_size(); i++)cout << lst2[i] << tab; cout << endl;
	List lst3 = lst1 + lst2;
	for (int i : lst3)
	{
		cout << i << tab;
	}
	cout << endl;*/

#endif // CONSTRUCTORS_CHECK





}