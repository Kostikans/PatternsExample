#include <string>
#include "Logger.h"

using namespace std;
int main()
{
	string fileName = "log.txt";
	string log = "message";
	Logger* p = new FileLogger(fileName);
	p->log(log);
	delete p;
	system("PAUSE");
	return 0;
}