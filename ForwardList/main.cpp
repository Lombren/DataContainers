#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------------------------------------------------------------------------\n"

class Element
{
	int Data;
	Element* pNext;
public:
	Element(int Data, Element* pNext = nullptr)
	{
		this->Data = Data;
		this->pNext = pNext;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head;
public:
	ForwardList()
	{
		this->Head = nullptr;
		//Изначально создаем пустой список.
		cout << "FLConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "FLDestructor:\t" << this << endl;
	}

	//			Adding elements:
	void push_front(int Data)
	{
		//Добавляет значение в начало списка.
		//1)Создаем элемент, в который будет помещено добавляемое значение (Data).
		Element* New = new Element(Data);
		//2)"Пристыковываем" новый элемент к началу списка:
		New->pNext = Head;
		Head = New;
	}
	//удаляет элемент с начала списка:
	void pop_front()
	{
		Element* Temp = Head->pNext;
		Head = Temp;

	}
	//удаляет последний элемент списка:
	void pop_back()
	{
		Element* Temp = Head;
		int i = 0;
		for (; Temp->pNext != nullptr; Temp = Temp->pNext)
		{
			i++;
		}
		Element* Temp1 = Head;
		for (int x = 0; x < i - 1; x++, Temp1 = Temp1->pNext);
		Temp1->pNext = nullptr;

	}
	void insert(int Index, int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}


	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);
	}

	void print()
	{
		Element* Temp = Head;	//Temp - это итератор.
		//Итератор - это УКАЗАТЕЛЬ, при помощи которого 
		//можно получить доступ к элементам структуры данных.
		while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переходим на следующий элемент.
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;	//Количество элементов списка.
	cout << "Введите количество элементов: "; cin >> n;
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

}