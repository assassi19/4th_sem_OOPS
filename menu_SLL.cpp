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

void insertAtTail(node* &head, S data){
   node* n = new node(data); //creating a new node & entering the input data init!
   // incase nothing is added in linked list so far then for that case
   if(head==NULL){
      head=n;
      return ;
      }
   node* temp = head;   //creating a temporary node which is given head's referrance
   //traversing the link list so that we can access the elements from head to last node whose pointer is null👇👇
   while(temp->next != NULL){
      temp = temp->next;      //keeps making the temps value to the next
   }
   temp->next = n;
   //once temp reaches last element it'll exit while loop & temp will be pointed towards node 'n' & since n already has NULL in it's next pointer
   // so no need to point towards anything further
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
std::cout<<"\n\n--------Menu-----------\n";
std::cout<<"1.Insert\n";
std::cout<<"2.Delete\n";
std::cout<<"3.View\n";
std::cout<<"4.Exit\n";
std::cout<<"-----------------------";
std::cout<<"\nEnter your choice:\t";
cin>>choice;
switch (choice)
      {
         case 1: insert();
         break;
         case 2: del();
         break;
         case 3: view();
         case 4:break;
         default :std::cout<<"\nInvalid choice:\n";
      }
} while (choice!=4);
return 0;
}

void insert(){
   int n,sub_choice; 
   std::cout<<"Enter the number of Students :\t";
   cin>>n;
   // struct Student s1[n];
   do{
   std::cout<<"Select insert position"<<endl;
   std::cout<<"1.Head\n";
   std::cout<<"2.Tail\n";
   cin>>sub_choice;

   switch (sub_choice)
         {
         case 1:
         for(int i=0; i<n; i++){
      // Student new_student;
         std::cout<<"Student "<<i+1<<" name : ";
      // cin>>new_student.name;
         cin>>s1[i].name;
         std::cout<<"Student "<<i+1<<" Branch : ";
         cin>>s1[i].branch;
         std::cout<<"Student "<<i+1<<" USN : ";
         cin>>s1[i].USN;
         std::cout<<"Student "<<i+1<<" sem No. : ";
         cin>>s1[i].sem_no;
         std::cout<<"Student "<<i+1<<" phone No. : ";
         cin>>s1[i].phone_num;
      // s1.push_back(new_student);
         insertAtHead(head,s1[i]);
         std::cout<<endl;
         }
         break;
         case 2 :
            for(int i=0; i<n; i++){
         // Student new_student;
         std::cout<<"Student "<<i+1<<" name : ";
         // cin>>new_student.name;
         cin>>s1[i].name;
         std::cout<<"Student "<<i+1<<" Branch : ";
         cin>>s1[i].branch;
         std::cout<<"Student "<<i+1<<" USN : ";
         cin>>s1[i].USN;
         std::cout<<"Student "<<i+1<<" sem No. : ";
         cin>>s1[i].sem_no;
         std::cout<<"Student "<<i+1<<" phone No. : ";
         cin>>s1[i].phone_num;
         // s1.push_back(new_student);
         insertAtTail(head,s1[i]);
         std::cout<<endl;
   }
         break;
         default:
            std::cout<<"invalid input";
}
}while(sub_choice != 1 && sub_choice != 2);

   std::cout<<"\nSuccessfully added "<<n<<" Students"<<endl;
}

void del(){
   int pos;
   std::cout<<"Enter the position where you want to delete : ";
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
std::cout<<"Successfully deleted the node"<<endl;
}        

void view(){
      node* temp = head;
         std::cout<<"*********************************************************************************************"<<endl;
         std::cout<<"Name       Branch\tUSN NO\tSem No\tPhone No.\n";
      while (temp!=NULL){
         std::cout<<temp->data.name<<"\t   "<<temp->data.branch<<"\t\t"<<temp->data.USN<<"\t"<<temp->data.sem_no<<"\t"<<temp->data.phone_num;
         std::cout<<endl;
            temp = temp->next;
      }
         std::cout<<"*********************************************************************************************"<<endl;
      std::cout<<endl;
}
