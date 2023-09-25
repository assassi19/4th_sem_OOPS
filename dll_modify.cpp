// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Structure of a Node
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

// Function to insert a node at the
// end of the given Linked List
void insertEnd(struct Node** start,
			int value)
{
	// If the list is empty, then
	// create a single node
	// circular and doubly list
	if (*start == NULL) {

		// Create a new Node
		struct Node* new_node = new Node();

		// Add values and links to
		// the next & the previous
		new_node->data = value;
		new_node->next = new_node;
		new_node->prev = new_node;

		// Update the start
		*start = new_node;
		return;
	}

	// If list is not empty, then
	// find last node
	Node* last = (*start)->prev;

	// Create Node dynamically
	struct Node* new_node = new Node;
	new_node->data = value;

	// Start is the next of new_node
	new_node->next = *start;

	// Make new node previous of start
	(*start)->prev = new_node;

	// Make last previous of new node
	new_node->prev = last;

	// Make new node next of old last
	last->next = new_node;
}

// Function to print the linked list
void display(struct Node* start)
{
	// Forward traversal
	struct Node* temp = start;

	cout << "Traversal in forward "
		"direction \n";
	while (temp->next != start) {
		cout << temp->data << " ";
		temp = temp->next;
	}
cout << temp->data << " " ;

	// Backward traversal
	cout << "\nTraversal in reverse"
		" direction \n";
	Node* last = start->prev;
	temp = last;

	// Traverse the Linked List
	while (temp->prev != last) {

		// Print the data
		cout << temp->data << " " ;
		temp = temp->prev;
	}

	// Print the data
	cout << temp->data << " ";
}

// Function to find the sum of all
// nodes in the given Linked List
int findSum(Node*& start)
{
	// Stores the sum of all the nodes
	int sum = 0;

	Node* temp = start;

	// Traverse the linked list and
	// update the sum
	while (temp->next != start) {

		// Update the sum
		sum += temp->data;

		// Update the temp
		temp = temp->next;
	}

	// Update the sum
	sum += temp->data;

	// Return the sum
	return sum;
}

// Function to update the data of
// every node with the sum of data
// of all nodes except itself
void updateNodeValue(Node*& start)
{
	// Stores the total sum
	// of all the nodes
	int sum = findSum(start);

	Node* temp = start;

	// Traverse the linked list
	// and update each node's data
	while (temp->next != start) {

		// Update the temp->data
		temp->data = sum - temp->data;

		// Update the temp
		temp = temp->next;
	}

	// Update the temp->data
	temp->data = sum - temp->data;
}

// Function to construct a
// circular doubly linked list
Node* formLinkedList(Node* start)
{
	// Given linked list as:
	// 4 <-> 5 <-> 6 <-> 7 <-> 8
	insertEnd(&start, 4);
	insertEnd(&start, 5);
	insertEnd(&start, 6);
	insertEnd(&start, 7);
	insertEnd(&start, 8);

	// Return the head of the
	// constructed Linked List
	return start;
}

// Driver Code
int main()
{
	// Linked list formation
	struct Node* start = NULL;
	start = formLinkedList(start);

	// Display the linked list
	display(start);

	// Function Call
	updateNodeValue(start);

	// Display the linked list
	// after updating nodes
	cout << "\nAfter updating "
		<< "the node values:\n";

	// Print the Linked List
	display(start);

	return 0;
}
