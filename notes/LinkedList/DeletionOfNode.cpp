// A complete working C++ program to
// demonstrate deletion in singly
// linked list with class
#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node{
public:
	int data;
	Node* next;
};

// Given a reference (pointer to pointer)
// to the head of a list and an int,
// inserts a new node on the front of the
// list.
void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

// Given a reference (pointer to pointer)
// to the head of a list and a key, deletes
// the first occurrence of key in linked list
void deleteNode(Node** head_ref, int key)
{

	// Store head node
	Node* temp = *head_ref;
	Node* prev = NULL;

	// If head node itself holds
	// the key to be deleted
	if (temp != NULL && temp->data == key)
	{
		*head_ref = temp->next; // Changed head
		delete temp;		 // free old head
		return;
	}

	// Else Search for the key to be deleted,
	// keep track of the previous node as we
	// need to change 'prev->next' */
	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}

	// If key was not present in linked list
	if (temp == NULL)
		return;

	// Unlink the node from linked list
	prev->next = temp->next;

	// Free memory
	delete temp;
}

// This function prints contents of
// linked list starting from the
// given node
void printList(Node* node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

/* Function to remove the first node
   of the linked list */
Node* removeFirstNode(struct Node* head)
{
    if (head == NULL)
        return NULL;

    // Move the head pointer to the next node
    Node* temp = head;
    head = head->next;

    delete temp;

    return head;
}
// Driver code
/* Function to remove the last node
   of the linked list */
Node* removeLastNode(struct Node* head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    // Find the second last node
    Node* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    // Delete last node
    delete (second_last->next);

    // Change next of second last
    second_last->next = NULL;

    return head;
}
int main()
{

	// Start with the empty list
	Node* head = NULL;

	// Add elements in linked list
	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);

	puts("Created Linked List: ");
	printList(head);

	deleteNode(&head, 1);
	puts("\nLinked List after Deletion of 1: ");

	printList(head);
    cout<<endl;
	head=removeFirstNode(head);
	printList(head);


	cout<<endl;
	head=removeLastNode(head);
	printList(head);

	return 0;
}

// This code is contributed by ac121102
