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
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data),pNext(pNext),pPrev(pPrev)
		{
			cout << "EConstructor:\t\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t\t" << this << endl;
		}
		friend class List;
	};
	Element* Head;
	Element* Tail;
	int size;
public:
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t\t" << this << endl;
	}
	~List()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t\t" << this << endl;
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
	void insert(int index,int Data)
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
			 Tail= Head = nullptr;
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
		if (index >= size-1)
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
		
		for(Element* Temp = Head;Temp;Temp=Temp->pNext)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout <<"� ������ "<< size << " ���������."<<endl;
	}
	void print_reverss()
	{
		for(Element* Temp=Tail;Temp;Temp=Temp->pPrev)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "� ������ " << size << " ���������." << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n=5;
#ifdef BASE_CHECK
	int index=0;
	int Data;
	cout << "������� ������ ������: "; cin >> n;
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
	cout << "������� ����� ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> Data;
	list.insert(index, Data);
	list.print();
	list.pop_front();
	list.print();
	list.pop_back();
	list.print();
	//list.print_reverss();Done
	cout << "������� ����� ���������� ��������: "; cin >> index;
	list.erase(index);
	list.print();
#endif // BASE_CHECK
#ifdef CONSTRUCTORS_CHECK

	List lst1 = { 3,5,8,13,21 };
	for (int i = 0; i < lst1.get_size(); i++)cout << lst1[i] << tab; cout << endl;
	List lst2 = { 34,55,89 };
	for (int i = 0; i < lst2.get_size(); i++)cout << lst2[i] << tab; cout << endl;
	List lst3 = lst1 + lst2;
	for (int i : lst3)
	{
		cout << i << tab;
	}
	cout << endl;

#endif // CONSTRUCTORS_CHECK





}