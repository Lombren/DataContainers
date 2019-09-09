#pragma once
#include<iostream>;
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
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();

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
		Iterator(Element* Temp = nullptr);
		~Iterator();

		Iterator& operator++();

		int& operator* ();
		const int& operator* () const;

		bool operator==(const Iterator& other);
		bool operator!=(const Iterator& other);

	};
	int get_size();
	Iterator begin();
	const Iterator begin() const;
	const Iterator end() const;
	Iterator end();

	List();
	List(initializer_list<int> il);
	~List();
	//Operators
	int& operator[](int index);
	const int& operator[](int index) const;

	//Methods

	void push_front(int Data);
	void push_back(int Data);
	void insert(int index, int Data);
	void pop_front();
	void pop_back();
	void erase(int index);
	void print();
	void print_reverss();
};