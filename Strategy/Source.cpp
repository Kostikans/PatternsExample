#include <iostream>
#include <string>

using namespace std;
class Compression
{
public:
	virtual ~Compression() {}
	virtual void compress(const string& file) = 0;
};

class ZIP_Compression : public Compression
{
public:
	void compress(const string& file) override {
		cout << "ZIP compression" << endl;
	}
};

class ARJ_Compression : public Compression
{
public:
	void compress(const string& file) override {
		cout << "ARJ compression" << endl;
	}
};

class RAR_Compression : public Compression
{
public:
	void compress(const string& file) override {
		cout << "RAR compression" << endl;
	}
};

class Compressor
{
public:
	Compressor(Compression* comp) : p(comp) {}
	~Compressor() { delete p; }
	void compress(const string& file) {
		p->compress(file);
	}
private:
	Compression* p;
};


int main()
{
	Compressor* p = new Compressor(new ZIP_Compression);
	p->compress("file.txt");
	delete p;
	system("PAUSE");
	return 0;
}