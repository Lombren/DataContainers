#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------------------------------------------------------------------------\n"
//#define BASE_CHECK
//#define DESTRUCTOR_CHECK
//#define INDEX_OPERATOR_CHECK
//#define CONSTRUCTORS_CHECK
//#define OPERATORS_CHECK
//#define RANGE_BASED_FOR
//#define ITERATORS_CHECK



template<typename T>class ForwardList
{
public:
	template<typename T>class Element
	{
		T Data;
		Element<T>* pNext;
		//static int count;
	public:
		const T& getData() const
		{
			return this->Data;
		}
		Element(T Data, Element<T>* pNext = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
			//count++;
#ifdef DEBUG
			cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~Element()
		{
			//count--;
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

		}
		operator T&()
		{
			return this->Data;
		}
		friend class ForwardList;
		//friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);
	};
public:
	class Iterator 
	{
		Element<T>* Temp;
	public:
		Iterator(Element<T>* Temp) :Temp(Temp)
		{
#ifdef DEBUG
			cout << "itConstructor:\t\t" << this << endl;
#endif // DEBUG

		};
		~Iterator()
		{ 
#ifdef DEBUG
			cout << "itDestructor:\t\t" << this << endl;
#endif // DEBUG

		};
		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		Iterator operator++(int)
		{
			Element<T>* old = Temp;
			Temp = Temp->pNext;
			return old;
		}
		T& operator*()
		{
			return Temp->Data;
		}
		bool operator==(const Iterator& other)
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)
		{
			return this->Temp != other.Temp;
		}

	};
	Element<T>* Head;
private:
	int size;
public:
	const int get_size()
	{
		return this->size;
	}
	Iterator begin()
	{
		return Head;
	}
	Iterator begin() const
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	Iterator end()const
	{
		return nullptr;
	}
	ForwardList()
	{
		this->Head = nullptr;
		this->size = 0;
		//Изначально создаем пустой список.
		cout << "FLConstructor:\t\t" << this << endl;
	}
	ForwardList(const ForwardList<T>& other)
	{
		this->Head = nullptr;
		this->size = 0;
		//Element* Temp = other.Head;//Iterator для перемещения по другому списку
		//while (Temp)
		//{
		//	push_back(Temp->Data);
		//	Temp = Temp->pNext;
		//}
		for (Iterator Temp = other.Head; Temp!=nullptr; Temp++)push_back(*Temp);
		cout << "FLCopyConstructor:\t" << this << endl;
	}
	ForwardList(ForwardList<T>&& other)
	{
		this->Head = other.Head;
		this->size = other.size;
		other.Head = nullptr;
		cout << "FLMoveConstructor:\t" << this << endl;
	}
	ForwardList<T>& operator=(const ForwardList<T>& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element<T>* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
		cout << "FLCopyAssigment:\t" << this << endl;
		return *this;
	}
	ForwardList<T>& operator=(ForwardList<T>&& other)
	{
		this->Head = other.Head;
		this->size = other.size;
		other.Head = nullptr;
		cout << "FLMoveAssigment:\t" << this << endl;
		return *this;
	}
	
	ForwardList(int size) :ForwardList()
	{
		/*this->Head = nullptr;
		this->size = 0;*/
		while (size--)push_front(T());
	}
	ForwardList(initializer_list<T> il) :ForwardList()
	{
		//cout << typeid(il.begin()).name() << endl;
		for (T const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}

	}

	~ForwardList()
	{
		while (Head)pop_front();
		cout << "FLDestructor:\t\t" << this << endl;
	}

	//			Adding elements:
	void push_front(T Data)
	{
		////Добавляет значение в начало списка.
		////1)Создаем элемент, в который будет помещено добавляемое значение (Data).
		//Element* New = new Element(Data);
		////2)"Пристыковываем" новый элемент к началу списка:
		//New->pNext = Head;
		//Head = New;
		Head = new Element<T>(Data, Head);
		size++;
	}
	//удаляет элемент с начала списка:
	void pop_front()
	{
		Element<T>* Temp = Head;//запоминаем адресс удаляемого елемента
		Head = Head->pNext;//исключаем елемент из списка
		delete Temp;//Удаляем елемент из памяти
		size--;


	}
	//удаляет последний элемент списка:
	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)
		{
			pop_front();
			return;
		}
		Element<T>* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		size--;
		Temp->pNext = nullptr;
	}
	void insert(int Index, T Data)
	{
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element<T>* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			if (Temp->pNext == nullptr)break;
			Temp = Temp->pNext;
		}

		/*Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;*/
		Temp->pNext = new Element<T>(Data, Temp->pNext);
		size++;
	}
	void erase(int Index)
	{
		if (Index == 0)
		{
			pop_front();
			return;
		}
		if (Index >= Element<T>::count)
		{
			return;
		}
		Element<T>* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			if (Temp->pNext == nullptr)break;
			Temp = Temp->pNext;
		}
		Element<T>* toDel = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete toDel;
		size--;

	}
	void push_back(T Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element<T>* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element<T>(Data);
		size++;
	}

	T& operator[](int Index)
	{
		Element<T>* Temp = Head;
		for (int i = 0; i < Index; i++)Temp = Temp->pNext;
		return Temp->Data;
	}
	void print()
	{
		//Element* Temp = Head;	//Temp - это итератор.
		//Итератор - это УКАЗАТЕЛЬ, при помощи которого 
		//можно получить доступ к элементам структуры данных.
		/*while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переходим на следующий элемент.
		}*/
		for (Element<T>* Temp = Head; Temp; Temp = Temp->pNext)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "Кол-во элементов списка: " << size << endl;
	}
	//friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);
	friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right)
	{
		ForwardList<T> result = left;
		for (ForwardList<T>::Iterator Temp = right.begin(); Temp != right.end(); Temp++)result.push_back(*Temp);
		return result;
	}
};

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