// C++ Program to demonstrate
// how friend functions work as
// a bridge between the classes
#include <iostream>
using namespace std;

// Forward declaration
class ABC;

class XYZ {
	int x;

public:
	void set_data(int a)
	{
	x = a;
	}

	friend void max(XYZ, ABC);
};

class ABC {
	int y;

public:
	void set_data(int a)
	{
	y = a;
	}

	friend void max(XYZ, ABC);
};

void max(XYZ t1, ABC t2)
{
	if (t1.x > t2.y)
		cout <<"The highest value Entered is :"<< t1.x;
	else
		cout <<"The highest value Entered is :"<< t2.y;
}

// Driver code
int main()
{
	ABC _abc;
   int a, b;
	XYZ _xyz;
   cout<<"Enter the value of first object : ";
   cin>>a;
   cout<<"Enter the value of second object : ";
   cin>>b;
	_xyz.set_data(a);
	_abc.set_data(b);

	// calling friend function
	max(_xyz, _abc);
	return 0;
}
