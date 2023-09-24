// C++ program to demonstrate private
// access modifier

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Circle
{
	// private data member
	private:
		double radius=0;	//incase is not given 1.5 is used as a default
	
	// public member function
	public:
		void compute_area(double r)
		{ // member function can access private
		  // data member radius
				radius = r;

			
			double area = 3.14*radius*radius;
			
			cout << "Radius is: " << radius << endl;
			cout << "Area is: " << area;
			cout << "\ncircumference is : "<<2*3.14*radius;
		}
	
};

// main function
int main()
{
	// creating object of the class
	Circle obj;
	float rad;
	// trying to access private data member
	cout<<"Enter the radius of the Circle : ";
	cin>>rad;
	// directly outside the class
	obj.compute_area(rad);
	
	
	return 0;
}
