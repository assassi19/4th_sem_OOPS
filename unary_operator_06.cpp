/*1. Overloading Unary Operator
Let us consider overloading (-) unary operator. In the unary operator function, no arguments should be passed.
It works only with one class object. It is the overloading of an operator operating on a single operand.
Example: Assume that class Distance takes two member objects i.e. feet and inches,
and creates a function by which the Distance object should decrement the value of feet and inches by 1 (having a single operand of Distance Type). */

// C++ program to show unary
// operator overloading
#include <iostream>
using namespace std;

class Distance {
public:
	int feet, inch;

	// Constructor to initialize
	// the object's value
	Distance(int f, int i)
	{
		this->feet = f;
		this->inch = i;
      cout<<"\nbefore operation overloading by unary operator\n"<<f<<" feet "<<i<<" inches"<<endl;
	}

	// Overloading(-) operator to
	// perform decrement operation
	// of Distance object
	void operator-()
	{
		feet--;
		inch--;
		cout << "\nafter decrement by unary operation overloading :-\n" <<feet<<"'"<<inch<<endl;
				// feet << "'" << inch;
	}
};

// Driver Code
int main()
{
   int feet, inches;
   cout<<"Enter height in feet & inches";
   cin>>feet;
   cin>>inches;
	Distance d1(feet, inches);

	// Use (-) unary operator by
	// single operand
	-d1;
	return 0;
}
