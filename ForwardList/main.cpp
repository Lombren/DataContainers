#include"ForwardList.h"
#include"ForwardList.cpp"


//#define BASE_CHECK
//#define DESTRUCTOR_CHECK
//#define INDEX_OPERATOR_CHECK
//#define CONSTRUCTORS_CHECK
//#define OPERATORS_CHECK
//#define RANGE_BASED_FOR
//#define ITERATORS_CHECK
//template<typename T>int ForwardList<T>::Element<T>::count = 0;



void main()
{
	setlocale(LC_ALL, "");
	int n;	//Количество элементов списка.
	cout << "Введите количество элементов: "; cin >> n;
#ifdef BASE_CHECK
	ForwardList fl;	//Создаем пустой список.
	for (int i = 0; i < n; i++)
	{
		fl.push_back(rand() % 100);
	}
	cout << delimiter;
	fl.push_back(123);
	fl.print();
	cout << delimiter;
	fl.pop_front();
	fl.print();
	cout << delimiter;
	fl.pop_back();
	fl.print();
	cout << delimiter;
	int Index;
	int Data;
	cout << "Введите индекс добавляемого элемента: "; cin >> Index;
	cout << "Введите значение добавляемого элемента: "; cin >> Data;
	fl.insert(Index, Data);
	fl.print();
	cout << "Введите индекс удаляемого элемента: "; cin >> Index;
	fl.erase(Index);
	fl.print();

#endif // BASE_CHECK

#ifdef DESTRUCTOR_CHECK
	ForwardList chain;
	for (int i = 0; i < n; i++)
	{
		chain.push_front(rand() % 100);
}
	//chain.print();
	cout << "List Full" << endl;
#endif // DESTRUCTOR_CHECK

#ifdef INDEX_OPERATOR_CHECK
	ForwardList fl(n);
	fl.print();
	for (int i = 0; i < fl.get_size(); i++)
	{
		fl[i] = rand() % 100;
	}
	for (int i = 0; i < fl.get_size(); i++)
	{
		cout << fl[i] << tab;
	}
	cout << endl;
#endif // INDEX_OPERATOR_CHECK

#ifdef CONSTRUCTORS_CHECK
	ForwardList fl1 = { 3,5,8,13,21 };
	for (int i = 0; i < fl1.get_size(); i++)
		cout << fl1[i] << tab;
	cout << endl;
	ForwardList fl2 = fl1;
	fl2.print();
#endif // CONSTRUCTORS_CHECK
#ifdef OPERATORS_CHECK
	ForwardList fl1 = { 3,5,8,13,21 };
	ForwardList fl2 = { 34,55,89 };
	for (int i = 0; i < fl1.get_size(); i++)
	{
		cout << fl1[i] << tab;
	}
	cout << endl;
	for (int i = 0; i < fl2.get_size(); i++)
	{
		cout << fl2[i] << tab;
	}
	cout << endl;

	ForwardList fl3;
	fl3 = fl1 + fl2;
	fl3.print();

#endif // OPERATORS_CHECK
#ifdef RANGE_BASED_FOR


	/*int Arr[] = { 3,5,8,13,21 };
	for (int i = 0; i < sizeof(Arr) / sizeof(int); i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;
	for (int i : Arr)cout << i << tab;cout << endl;*/

	ForwardList<int> fl = { 3,5,8,13,21 };
	for (int i : fl)cout << i << tab; cout << endl;
	/*for (ForwardList::Iterator it = fl.begin(); it != fl.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;*/

#endif // RANGE_BASED_FOR
#ifdef ITERATORS_CHECK
	ForwardList<double> lfd = { 2.7,3.14,5.5 };
	for (ForwardList<double>::Iterator it = lfd.begin(); it != lfd.end(); it++)cout << *it << endl;  
#endif // ITERATORS_CHECK
	ForwardList<double> lfd = { 2.7,3.14,5.5 };
	for (ForwardList<double>::Iterator it = lfd.begin(); it != lfd.end(); it++)cout << *it << endl;
	ForwardList<double> lsd = { 3, 5, 8 };
	for (ForwardList<double>::Iterator it = lsd.begin(); it != lsd.end(); it++)cout << *it << endl;
	
	ForwardList<double> meth = lfd + lsd;
	for (double i : meth)
		cout << i << "\t";
	cout << endl;
	

}