#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum class Warrior_ID { Infantryman_ID, Archer_ID, Horseman_ID };

class Warrior;  
typedef map<Warrior_ID, Warrior*> Registry;

Registry& getRegistry()
{
	static Registry _instance;
	return _instance;
}

class Dummy { };

class Warrior
{
public:
	virtual Warrior* clone() = 0;
	virtual void info() = 0;
	virtual ~Warrior() {}
	static Warrior* createWarrior(Warrior_ID id) {
		Registry& r = getRegistry();
		if (r.find(id) != r.end())
			return r[id]->clone();
		return 0;
	}
protected:

	static void addPrototype(Warrior_ID id, Warrior* prototype) {
		Registry& r = getRegistry();
		r[id] = prototype;
	}

	static void removePrototype(Warrior_ID id) {
		Registry& r = getRegistry();
		r.erase(r.find(id));
	}
};

class Infantryman : public Warrior
{
public:
	Warrior* clone() {
		return new Infantryman(*this);
	}
	void info() {
		cout << "Infantryman" << endl;
	}
private:
	Infantryman(Dummy) {
		Warrior::addPrototype(Warrior_ID::Infantryman_ID, this);
	}
	Infantryman() {}
	static Infantryman prototype;
};

class Archer : public Warrior
{
public:
	Warrior* clone() {
		return new Archer(*this);
	}
	void info() {
		cout << "Archer" << endl;
	}
private:
	Archer(Dummy) {
		addPrototype(Warrior_ID::Archer_ID, this);
	}
	Archer() {}
	static Archer prototype;
};

class Horseman : public Warrior
{
public:
	Warrior* clone() {
		return new Horseman(*this);
	}
	void info() {
		cout << "Horseman" << endl;
	}
private:
	Horseman(Dummy) {
		addPrototype(Warrior_ID::Horseman_ID, this);
	}
	Horseman() {}
	static Horseman prototype;
};


Infantryman Infantryman::prototype = Infantryman(Dummy());
Archer Archer::prototype = Archer(Dummy());
Horseman Horseman::prototype = Horseman(Dummy());


int main()
{
	vector<Warrior*> v;
	v.push_back(Warrior::createWarrior(Warrior_ID::Infantryman_ID));
	v.push_back(Warrior::createWarrior(Warrior_ID::Archer_ID));
	v.push_back(Warrior::createWarrior(Warrior_ID::Horseman_ID));

	for (int i = 0; i < v.size(); i++)
		v[i]->info();
	system("PAUSE");
	return 0;
}