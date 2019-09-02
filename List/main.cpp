#include<iostream>

using namespace std;
#define tab "\t"
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
		
		Element* New = new Element(Data);
		if (Head == nullptr&&Tail == nullptr)
		{
			Head = Tail = New;
			return;
		}
		Element* Temp;
		if (index > size / 2)
		{
			Temp = Tail;
			for (int i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
			//{
			//	/*if (i == index - 1)
			//	{
			//		Temp->pPrev = New;
			//		New->pPrev = Temp->pPrev->pPrev;
			//		New->pNext = Temp;
			//		
			//	}*/
			//}
			
		}
		else
		{
			Temp = Head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;
			//{
			//	/*if (i == index - 1)
			//	{
			//		Temp->pNext = New;
			//		New->pNext = Temp->pNext->pNext;
			//		New->pPrev = Temp;
			//		
			//	}*/
			//}
		}
		New->pNext = Temp;
		New->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;
		size++;
	}
	void print()
	{
		
		for(Element* Temp = Head;Temp;Temp=Temp->pNext)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout <<"В списке "<< size << " елементов."<<endl;
	}
	void print_reverss()
	{
		for(Element* Temp=Tail;Temp;Temp=Temp->pPrev)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "В списке " << size << " елементов." << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n=5;
	int index=0;
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
	list.insert(index,Data);
	list.print();
	list.print_reverss();


}