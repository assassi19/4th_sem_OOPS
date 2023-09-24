#include <iostream>
using namespace std;
//same function adding different types of values
void add(int *a, int *b){
cout << "sum of values passed by referrance is : " << (*a + *b)<<endl;
}

void add(double a, double b){
	cout << endl << "sum of values passed by value is : " << (a + b);
}

// Driver code
int main(){
   int a, b; 
   double x, y;
	cout<<"Enter 1st value to pass by referrance : ";
   cin>>a;
	cout<<"Enter 2nd value to pass by referrance : ";
   cin>>b;
   add(&a,&b);
   cout<<"Now Enter decimal values to pass in function by value"<<endl;
	cout<<"Enter 1st value : ";
   cin>>x;
	cout<<"\nEnter 2nd value : ";
   cin>>y;

   add(x,y);

	return 0;
  }
