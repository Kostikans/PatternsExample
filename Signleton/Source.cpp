#include<iostream>

using namespace std;

class Singleton
{
private:
	static Singleton* p_instance;
	Singleton() {}
	Singleton(const Singleton&);
	Singleton& operator=(Singleton&);
public:
	static Singleton* getInstance() {
		if (!p_instance)
			p_instance = new Singleton();
		return p_instance;
	}
	void getInfo() const noexcept
	{
		std::cout << "singleton instance" << std::endl;
	}
};
Singleton* Singleton::p_instance = nullptr;

int main()
{
	Singleton::getInstance()->getInfo();
	system("PAUSE");
	return 0;
}