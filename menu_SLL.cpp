#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct Student{
   string name;
   int USN;
   string branch;
   int sem_no;
   unsigned long long int phone_num;      //incase throws an Error than do change this to string
}s1[10];   typedef Student S;
// vector<Student> s1;
// struct {keyword} name_of_struct_type {student} name_of_struct_var s1;
class node
{
      public:
      S data;
      node *next;
      node(S student){
         data=student;
         next=NULL;
      }
};
node* head = NULL;

void insertAtHead(node* &head,S data){ //taking head by referrance & value to be inserted at head
      node* n = new node(data);//  new creates a node & value of the new node is set by this function
      n->next=head;     //makes the new node pointer to point towards the current head's address
      head=n;           //the new node is made head by doing head=n; 
      }

void insert();
void del();
void view();

/* step : 1
show the menu
step 2: (insertion) -> ask for no of students & make that many structures & use front insertion to add students in nodes
step 3: (deletion)  -> ask for place of the node & delete that node completely
step 4  (display)   -> ask for the display of the students and display will give us the details*/

int main(){
   int choice;
   do {
cout<<"\n\n--------Menu-----------\n";
cout<<"1.Insert\n";
cout<<"2.Delete\n";
cout<<"3.View\n";
cout<<"4.Exit\n";
cout<<"-----------------------";
cout<<"\nEnter your choice:\t";
cin>>choice;
switch (choice)
      {
         case 1: insert();
         break;
         case 2: del();
         break;
         case 3: view();
         case 4:break;
         default :cout<<"\nInvalid choice:\n";
      }
} while (choice!=4);
return 0;
}

void insert(){
   int n;
   cout<<"Enter the number of Students :\t";
   cin>>n;
   // struct Student s1[n];
   for(int i=0; i<n; i++){
      // Student new_student;
      cout<<"Student "<<i+1<<" name : ";
      // cin>>new_student.name;
      cin>>s1[i].name;
      cout<<"Student "<<i+1<<" Branch : ";
      cin>>s1[i].branch;
      cout<<"Student "<<i+1<<" USN : ";
      cin>>s1[i].USN;
      cout<<"Student "<<i+1<<" sem No. : ";
      cin>>s1[i].sem_no;
      cout<<"Student "<<i+1<<" phone No. : ";
      cin>>s1[i].phone_num;
      // s1.push_back(new_student);
      insertAtHead(head,s1[i]);
      cout<<endl;
   }
   cout<<"\nSuccessfully added "<<n<<" Students"<<endl;
}

void del(){
   int pos;
   cout<<"Enter the position where you want to delete : ";
   cin>>pos;
   node* temp = head;
   node* prev = head;
   for(int i = 0; i < pos; i++){
      if(i == 0 && pos == 1){
            head = head->next;
            free(temp);
      }
         else{
            if (i == pos - 1 && temp){
               prev->next = temp->next;
               free(temp);
            }
            else{
               prev = temp;
               if(prev == NULL) // position was greater than number of nodes in the list
                  break;
               temp = temp->next; 
            }
      }
   }
cout<<"Successfully deleted the node"<<endl;
}        

void view(){
      node* temp = head;
         cout<<"*********************************************************************************************"<<endl;
         cout<<"Name      Branch\tUSN NO\tSem No\tPhone No.\n";
      while (temp!=NULL){
         cout<<temp->data.name<<"\t "<<temp->data.branch<<"\t\t"<<temp->data.USN<<"\t"<<temp->data.sem_no<<"\t"<<temp->data.phone_num;
         cout<<endl;
         temp = temp->next;
      }
         cout<<"*********************************************************************************************"<<endl;
      cout<<endl;
}