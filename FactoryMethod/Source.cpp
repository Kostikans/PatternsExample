#include <iostream>
#include <vector>

using namespace std;

enum Warrior_ID { Infantryman_ID = 0, Archer_ID, Horseman_ID };

class Warrior
{
public:
	virtual void info() = 0;
	virtual ~Warrior() {};
	static Warrior* createWarrior(Warrior_ID id);
};

class Infantryman : public Warrior
{
public:
	void info() {
		cout << "Infantryman" << endl;
	}
};

class Archer : public Warrior
{
public:
	void info() {
		cout << "Archer" << endl;
	}
};

class Horseman : public Warrior
{
public:
	void info() {
		cout << "Horseman" << endl;
	}
};


Warrior* Warrior::createWarrior(Warrior_ID id)
{
	Warrior* p{ nullptr };
	switch (id)
	{
	case Infantryman_ID:
		p = new Infantryman();
		break;
	case Archer_ID:
		p = new Archer();
		break;
	case Horseman_ID:
		p = new Horseman();
		break;	
	}
	return p;
};

int main()
{
	vector<Warrior*> v;
	v.push_back(Warrior::createWarrior(Infantryman_ID));
	v.push_back(Warrior::createWarrior(Archer_ID));
	v.push_back(Warrior::createWarrior(Horseman_ID));

	for (int i = 0; i < v.size(); i++)
		v[i]->info();
	
	system("PAUSE");
	return 0;
}