#include"ForwardList.h"

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
		for (Iterator Temp = other.Head; Temp != nullptr; Temp++)push_back(*Temp);
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