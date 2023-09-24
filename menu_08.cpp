#include<iostream>
using namespace std;


int a[20],b[20],c[40];
int m,n,p,val,i,j,key,pos,temp;

/*Function Prototype*/
void display();
void insert();
void del();
int main()
{
int choice;
cout<<"\nEnter the size of the array to be created:\t";
cin>>n;
cout<<"\nEnter the elements for the array:\n";
for (i=0;i<n;i++)
{
cin>>a[i];
}
do {
cout<<"\nArray successfully created";
cout<<"\n\n--------Menu-----------\n";
cout<<"1.Insert\n";
cout<<"2.Delete\n";
cout<<"3.Exit\n";
cout<<"-----------------------";
cout<<"\nEnter your choice:\t";
cin>>choice;
switch (choice)
{
  case 1: insert();
  break;
  case 2: del();
  break;
  case 3:break;
  default :cout<<"\nInvalid choice:\n";
}
} while (choice!=3);
return 0;
}

void display()//displaying an array elements
{
    int i;
    cout<<"\nThe array elements are:\n";
    for(i=0;i<n;i++)
    {
      cout<<a[i]<<" ";
    }
}//end of display()
void insert()//inserting an element in to an array
{
    cout<<"\nEnter the position for the new element:\t";
    cin>>pos;
    cout<<"\nEnter the element to be inserted :\t";
    cin>>val;
for (i=n; i>=pos-1; i--)
{
  a[i+1]=a[i];
}
 a[pos-1]=val;
 n=n+1;
 display();
}//end of insert()
void del()//deleting an array element
{
  cout<<"\n Enter the position of the element to be deleted:\t";
  cin>> pos;
  val= a [pos];
  for (i= pos;i<n-1;i++)
  {
    a[i]=a[i+1];
  }
n=n-1;
cout<<"\nThe deleted element is = "<<val;
display();
}//end of delete()