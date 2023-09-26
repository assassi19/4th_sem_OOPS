#include <iostream>
#include <string>
//code contributed by UZAIR HASSAN and MANOJ O M
using namespace std;

class Student {
public:
    string name;
    int USN;
    string branch;
    int sem_no;
    unsigned long long int phone_num; // Consider using a string for phone_num if necessary

    Student(string n, int usn, string b, int sem, unsigned long long int phone)
        : name(n), USN(usn), branch(b), sem_no(sem), phone_num(phone) {}
};

class Node {
public:
    Student data;
    Node* next;

    Node(Student student) : data(student), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtHead(Student data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(Student data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void del(int pos) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << std::endl;
        return;
    }

    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr; // Set temp to nullptr after deletion
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;
    int index = 0;

    while (temp != nullptr && index != pos) {
        prev = temp;
        temp = temp->next;
        index++;
    }

    if (temp == nullptr) {
        cout << "Position not found." << std::endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    temp = nullptr; // Set temp to nullptr after deletion
}

void view() {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
    } else {
        Node* temp = head;
        cout << "*********************************************************************************************" << endl;
        cout << "Name       Branch\tUSN NO\tSem No\tPhone No.\n";
        while (temp != nullptr) {
            cout << temp->data.name << "\t   " << temp->data.branch << "\t\t" << temp->data.USN << "\t" << temp->data.sem_no << "\t" << temp->data.phone_num;
            cout << endl;
            temp = temp->next;
        }
        cout << "*********************************************************************************************" << endl;
        cout << endl;
    }
}
};

int main() {
    LinkedList studentList;

    int choice;
    do {
        cout << "\n\n--------Menu-----------\n";
        cout << "1.Insert\n";
        cout << "2.Delete\n";
        cout << "3.View\n";
        cout << "4.Exit\n";
        cout << "-----------------------";
        cout << "\nEnter your choice:\t";
        cin >> choice;

        switch (choice) {
            case 1:
                int n;
                cout << "Enter the number of Students:\t";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    std::string name, branch;
                    int USN, sem_no;
                    unsigned long long int phone_num;
                    
                    cout << "Student " << i + 1 << " name: ";
                    cin >> name;
                    cout << "Student " << i + 1 << " Branch: ";
                    cin >> branch;
                    cout << "Student " << i + 1 << " USN: ";
                    cin >> USN;
                    cout << "Student " << i + 1 << " sem No.: ";
                    cin >> sem_no;
                    cout << "Student " << i + 1 << " phone No.: ";
                    cin >> phone_num;
                    
                    Student student(name, USN, branch, sem_no, phone_num);
                    studentList.insertAtHead(student);
                    cout << endl;
                }
                break;

            case 2:
                int pos;
                cout << "Enter the position where you want to delete: ";
                cin >> pos;
                pos++;
                studentList.del(pos);
                break;

            case 3:
                studentList.view();
                break;

            case 4:
                break;

            default:
                cout << "\nInvalid choice:\n";
        }
    } while (choice != 4);

    return 0;
}