#pragma once
#include<iostream>;
using namespace std;

#define tab "\t"
//#define BASE_CHECK
#define CONSTRUCTORS_CHECK


template<typename T>class List
{
	template<typename T=T>class Element
	{
		T Data;
		Element<T>* pNext;
		Element<T>* pPrev;
	public:
		Element(T Data, Element<T>* pNext = nullptr, Element<T>* pPrev = nullptr);
		~Element();
		operator T&();
		friend class List<T>;
	};
	Element<T>* Head;
	Element<T>* Tail;
	int size;
public:
	class Iterator
	{
		Element<T>* Temp;
	public:
		Iterator(Element<T>* Temp = nullptr);
		~Iterator();

		Iterator& operator++();

		T& operator* ();
		const T& operator* () const;

		bool operator==(const Iterator& other);
		bool operator!=(const Iterator& other);

	};
	int get_size();
	Iterator begin();
	const Iterator begin() const;
	const Iterator end() const;
	Iterator end();

	List();
	List(initializer_list<T> il);
	~List();
	//Operators
	T& operator[](int index);
	const T& operator[](int index) const;

	//Methods

	void push_front(T Data);
	void push_back(T Data);
	void insert(int index, T Data);
	void pop_front();
	void pop_back();
	void erase(int index);
	void print();
	void print_reverss();
};