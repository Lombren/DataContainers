#include<iostream>

using namespace std;

#define tab "\t"
#define delimiter "\n-----------------------------------------------\n"
//#define EXEPTIONS_INDEX
//#define DIVIZION_BY_ZERO_EXEPTIONS
#define FACTORIAL

long long int factorial(int n);

void main()
{
	setlocale(LC_ALL, "");
#ifdef EXEPTIONS_INDEX
	try
	{
		throw "Kakaya-to Fignia";
		cout << "That's OK in try block" << endl;

	}
	catch (const char* error)
	{
		cerr << "Error: " << error;
	}
	cout << delimiter;
	try
	{
		//throw 123;
	}
	catch (int error)
	{
		cout << "Error#" << error << endl;
	}
	catch (...)
	{
		cerr << "Something happend :-(" << endl;
	}
	cout << "Buy!" << endl;
#endif // EXEPTIONS_INDEX
#ifdef DIVIZION_BY_ZERO_EXEPTIONS
	int a = 20;
	int b = 0;
	try
	{
		cout << a / b << endl;
	}
	catch (std::exception& e)
	{
		cerr << e.what() << endl;
	}
	catch (...)//deprecated
	{
		cerr << "Error: integer division by zero." << endl;
	}
#endif // DIVIZION_BY_ZERO_EXEPTIONS
#ifdef FACTORIAL

	int n;

	cout << "Input number to find factorial: "; cin >> n;
	try
	{
		cout << n << " factorial: " << factorial(n) << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
#endif // FACTORIAL


}

long long int factorial(int n)
{
	if (n > 20)throw overflow_error("Too large number");//exception("Error: too large number, 20 maximum");
	long long int f = 1;//Factorial
	for (int i = 1; i <= n; i++)
	{
		/*cout << i << "! = ";*/
		f *= i;
		/*cout << f << endl;*/
	}
	return f;

}