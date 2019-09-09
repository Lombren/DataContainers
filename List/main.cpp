#include<iostream>

using namespace std;
#define tab "\t"
//#define BASE_CHECK
#define CONSTRUCTORS_CHECK
class List
{
	class Element
	{
		int Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor:\t\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t\t" << this << endl;
		}

		/*int operator*()
		{
			return this->Data;
		}
		const int operator*() const
		{
			return this->Data;
		}*/
		operator int()
		{
			return this->Data;
		}

		friend class List;
	};
	Element* Head;
	Element* Tail;
	int size;
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr)
		{
			this->Temp = Temp;
			cout << "ITConstructor:\t\t" << this << endl;
		}
		~Iterator()
		{
			cout << "ITDestructor:\t\t" << this << endl;
		}

		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}

		int& operator* ()
		{
			return Temp->Data;
		}
		const int& operator* () const
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
	int get_size()
	{
		return this->size;
	}
	Iterator begin()
	{
		return this->Head;
	}
	const Iterator begin() const
	{
		return this->Head;
	}
	const Iterator end() const
	{
		return nullptr;
	}
	Iterator end()
	{
		return nullptr;
	}

	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t\t" << this << endl;
	}
	List(initializer_list<int> il) :List()
	{
		for (const int* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	~List()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t\t" << this << endl;
	}
	//Operators
	int& operator[](int index)
	{
		Element* Temp;
		if (index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = size-1; i > index; i--)Temp = Temp->pPrev;
		}
		return Temp->Data;

	}
	const int& operator[](int index) const
	{
		Element* Temp;
		if (index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = size - 1; i > index; i--)Temp = Temp->pPrev;
		}
		return Temp->Data;

	}

	//Methods

	void push_front(int Data)
	{
		size++;
		Element* New = new Element(Data);
		if (Head == nullptr&&Tail == nullptr)
		{
			Head = Tail = New;
			return;
		}
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;
	}
	void push_back(int Data)
	{
		size++;
		Element* New = new Element(Data);
		if (Head == nullptr&&Tail == nullptr)
		{
			Head = Tail = New;
			return;
		}
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;
	}
	void insert(int index, int Data)
	{
		if (index == 0)
		{
			push_front(Data); return;
		}
		if (index >= size)
		{
			push_back(Data); return;
		}
		if (Head == nullptr&&Tail == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp;
		if (index > size / 2)
		{
			Temp = Tail;
			for (int i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;


		}
		else
		{
			Temp = Head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;

		}
		/*Element* New = new Element(Data);
		New->pNext = Temp;
		New->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;*/
		Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
		size++;
	}
	void pop_front()
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (Head == Tail)
		{
			delete Tail;
			Tail = Head = nullptr;
			return;
		}
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;

	}
	void erase(int index)
	{
		if (index == 0)
		{
			pop_front(); return;
		}
		if (index >= size - 1)
		{
			pop_back(); return;
		}
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		if (Head == nullptr)return;
		Element* Temp;
		if (index > size / 2)
		{
			Temp = Tail;
			for (int i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
		}
		else
		{
			Temp = Head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;
		}
		Temp->pNext->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = Temp->pNext;
		delete Temp;
		size--;

	}
	void print()
	{

		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "В списке " << size << " елементов." << endl;
	}
	void print_reverss()
	{
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "В списке " << size << " елементов." << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
#ifdef BASE_CHECK
	int index = 0;
	int Data;
	cout << "Введите размер списка: "; cin >> n;
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
	cout << "Введите номер добавляемого елемента: "; cin >> index;
	cout << "Введите значение добавляемого елемента: "; cin >> Data;
	list.insert(index, Data);
	list.print();
	list.pop_front();
	list.print();
	list.pop_back();
	list.print();
	//list.print_reverss();Done
	cout << "Введите номер удаляемого елемента: "; cin >> index;
	list.erase(index);
	list.print();
#endif // BASE_CHECK
#ifdef CONSTRUCTORS_CHECK

	List lst1 = { 3,5,8,13,21 };
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