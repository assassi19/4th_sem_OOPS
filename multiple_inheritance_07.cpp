// C++ program to illustrate Single Inheritance
#include <iostream>
using namespace std;
class A {
public:
	string employee = "employee1";
	float salary = 80000;
};
class B : public A {
public:
	float bonus = 8000;
	void ts()
	{
		cout << "Total salary.." << (salary + bonus)
			<< endl;
	}
};
int main()
{
	B worker;
	cout << "Salary:" << worker.salary << endl;
	cout << "Bonus:" << worker.bonus << endl;
	worker.ts();
	return 0;
}

/*Single inheritance is implemented as
Class DerivedClass_name : access_specifier Base_Class{};
Single inheritance constructs an inheritance tree
Single inheritance is a lot close to specialization..

Multiple inheritance is implemented as
Class DerivedClass_name : access_specifier Base_Class1, access_specifier Base_Class2, ….{};.
Multiple inheritance constructs Inheritance Directed Acyclic Graph (DAG)
multiple inheritance is a lot close to generalization...*/

