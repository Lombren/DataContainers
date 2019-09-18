#include<iostream>

using namespace std;

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
		{
			this->Data = Data;
			this->pLeft = pLeft;
			this->pRight = pRight;
			cout << "EConstructor:\t\t" << this << endl;

		}
		~Element()
		{
			cout << "EDestructor:\t\t" << this << endl;
		}
		bool is_leaf()
		{
			return pLeft == pRight;
		}
		friend class Tree;
	}*Root;
public:
	Element* getRoot()
	{
		return this->Root;
	}
	Tree()
	{
		Root = nullptr;
		cout << "TConstructor:\t\t" << this << endl;
	}
	Tree(initializer_list<int>il):Tree()
	{
		for (int const* it = il.begin(); it != il.end(); it++) insert(*it);
	}
	~Tree()
	{
		clear(this->Root);
		cout << "TDestructor:\t\t" << this << endl;
	}
	int getMinValue()
	{
		return getMinValue(this->Root);
	}
	int getMinValue(Element* Root)
	{
		if (Root->pLeft == nullptr)return Root->Data;
		return getMinValue(Root->pLeft);

	}
	int getMaxValue()
	{
		return getMaxValue(this->Root);
	}
	int getMaxValue(Element* Root)
	{
		if (Root->pRight == nullptr)return Root->Data;
		return getMaxValue(Root->pRight);
	}
	int count()
	{
		return count(this->Root);

	}
	int count(Element* Root)
	{
		if (Root == nullptr)return 0;
		return count(Root->pLeft) + count(Root->pRight) + 1;
	}
	void insert(int Data)
	{
		insert(Data, this->Root);
	}
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)
			{
				Root->pLeft = new Element(Data);
			}
			else
			{
				insert(Data, Root->pLeft);
			}
		}
		else //if(Data>Root->Data)
		{
			if (Root->pRight == nullptr)
			{
				Root->pRight = new Element(Data);
			}
			else
			{
				insert(Data, Root->pRight);
			}
		}
	}
	void erase(int Data)
	{
		erase(Data, this->Root);
	}
	void erase(int Data, Element*& Root)
	{
		if (Root == nullptr)return;
		if (Data == Root->Data)
		{
			if (Root->is_leaf())
			{
				delete Root;
				Root = nullptr;
				return;
			}
			else
			{
				if (Root->pLeft)
				{
					Root->Data = getMaxValue(Root->pLeft);
					erase(getMaxValue(Root->pLeft),Root->pLeft);
				}
				else
				{
					Root->Data = getMinValue(Root->pRight);
					erase(getMinValue(Root->pRight), Root->pRight);
				}
				
			}
		}

		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
	}
	void clear()
	{
		clear(this->Root);
		this->Root = nullptr;
	}
	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}
	int Sum()
	{
		return Sum(this->Root);
	}
	int Sum(Element* Root)
	{
		if (Root == nullptr)return 0;
		return Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}
	double Avg()
	{
		return (double)Sum() / count();

	}
	void print()
	{
		print(this->Root);
		cout << endl;
	}
	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);

	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	int Data;
	cout << "������� ������ ������: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();
	cout << "����������� �������� � ������: " << tree.getMinValue() << endl;
	cout << "������������ �������� � ������: " << tree.getMaxValue() << endl;
	//tree.clear();
	//tree.print();
	cout << "���������� ��������� � ������: " << tree.count() << endl;
	cout << "����� ��������� ������: " << tree.Sum() << endl;
	cout << "������� ��������� ������: " << tree.Avg() << endl;
	cout << "������� ��������� ��������: "; cin >> Data;
	tree.erase(Data);
	tree.print();
	Tree tr2 = { 3,5,8,13,21 };
	tr2.print();

}