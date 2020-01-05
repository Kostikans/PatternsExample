#include <iostream>
using namespace std;

class Base
{
	void a()
	{
		cout << "a  ";
	}
	void c()
	{
		cout << "c  ";
	}
	void e()
	{
		cout << "e  ";
	}
	
	virtual void ph1() = 0;
	virtual void ph2() = 0;
public:

	void execute()
	{
		a();
		ph1();
		c();
		ph2();
		e();
	}
};

class One : public Base
{
	void ph1() override
	{
		cout << "b  ";
	}
	void ph2() override
	{
		cout << "d  ";
	}
};

class Two : public Base
{
	void ph1() override
	{
		cout << "2  ";
	}
	void ph2() override
	{
		cout << "4  ";
	}
};

int main()
{
	One one;
	Two two;
	Base* array[] =
	{
	  &one,&two
	};
	for (int i = 0; i < 2; i++)
	{
		array[i]->execute();
		cout << '\n';
	}
	system("PAUSE");
	return 0;
}