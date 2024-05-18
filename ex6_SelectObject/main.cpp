#include <iostream>
using namespace std;

class Point	{
public:
	void output();
	static void init();
private:
	static int x, y;
};

void Point::output()	{
	init();
}

void Point::init()	{
	// x = 0;
	// y = 0;
}

int Point::x = 0;
int Point::y = 0;

int main()	{
/*	Point pt;
	pt.init();
	pt.output();
	return 0;*/
	Point::init();
	// Point::output();
	return 0;
}