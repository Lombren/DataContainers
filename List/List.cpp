#include"List.h";

template<typename T>template<typename E>List<T>::Element<E>::Element(E Data, List<T>::Element<E>* pNext, List<T>::Element<E>* pPrev) :Data(Data), pNext(pNext), pPrev(pPrev)
{
	cout << "EConstructor:\t\t" << this << endl;
}
template<typename T>template<typename E>List<T>::Element<E>::~Element()
{
	cout << "EDestructor:\t\t" << this << endl;
}
template<typename T>
template<typename E>
List<T>::Element<E>::operator E&()
{
	return this->Data;
}


template<typename T>List<T>::Iterator::Iterator(Element<T>* Temp)
{
	this->Temp = Temp;
	cout << "ITConstructor:\t\t" << this << endl;
}
template<typename T>List<T>::Iterator::~Iterator()
{
	cout << "ITDestructor:\t\t" << this << endl;
}

template<typename T>List<T>::Iterator& List<T>::Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}

template<typename T>T& List<T>::Iterator::operator* ()
{
	return Temp->Data;
}
template<typename T>const T& List<T>::Iterator::operator* () const
{
	return Temp->Data;
}


template<typename T>bool List<T>::Iterator::operator==(const Iterator& other)
{
	return this->Temp == other.Temp;
}
template<typename T>bool List<T>::Iterator::operator!=(const Iterator& other)
{
	return this->Temp != other.Temp;
}

template<typename T>int List<T>::get_size()
{
	return this->size;
}
template<typename T>List<T>::Iterator List<T>::begin()
{
	return this->Head;
}
template<typename T>const List<T>::Iterator List<T>::begin() const
{
	return this->Head;
}
template<typename T>const List<T>::Iterator List<T>::end() const
{
	return nullptr;
}
template<typename T>List<T>::Iterator List<T>::end()
{
	return nullptr;
}

template<typename T>List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t\t" << this << endl;
}
template<typename T>List<T>::List(initializer_list<T> il) :List()
{
	for (const T* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
}
template<typename T>List<T>::~List()
{
	while (Head)pop_front();
	cout << "LDestructor:\t\t" << this << endl;
}
//Operators
template<typename T> T& List<T>::operator[](int index)
{
	Element<T>* Temp;
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
template<typename T>const T& List<T>::operator[](int index) const
{
	Element<T>* Temp;
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

template<typename T>void List<T>::push_front(T Data)
{
	size++;
	Element<T>* New = new Element(Data);
	if (Head == nullptr&&Tail == nullptr)
	{
		Head = Tail = New;
		return;
	}
	New->pNext = Head;
	Head->pPrev = New;
	Head = New;
}
template<typename T>void List<T>::push_back(T Data)
{
	size++;
	Element<T>* New = new Element(Data);
	if (Head == nullptr&&Tail == nullptr)
	{
		Head = Tail = New;
		return;
	}
	New->pPrev = Tail;
	Tail->pNext = New;
	Tail = New;
}
template<typename T>void List<T>::insert(int index, T Data)
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
	Element<T>* Temp;
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
template<typename T>void List<T>::pop_front()
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
template<typename T>void List<T>::pop_back()
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
template<typename T>void List<T>::erase(int index)
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
	Element<T>* Temp;
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
template<typename T>void List<T>::print()
{

	for (Element<T>* Temp = Head; Temp; Temp = Temp->pNext)
	{
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	}
	cout << "В списке " << size << " елементов." << endl;
}
template<typename T>void List<T>::print_reverss()
{
	for (Element<T>* Temp = Tail; Temp; Temp = Temp->pPrev)
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "В списке " << size << " елементов." << endl;
}