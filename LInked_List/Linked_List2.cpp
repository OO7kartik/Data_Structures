#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};
struct node *head; //a global variable

void Insert(int val)
{
	//now we need to create a new node.
	node *temp = new node();
	temp->data = val; //store the val in this new node
	temp->next = NULL; //now this will point to NULL
	//now we have to make head to point to this node
	//this is when our list is empty
	if(head != NULL)
		temp->next  = head;
	head = temp;
}

void Printy()
{
	node *temp = head;
	cout<<"the elements of the list are: ";
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	head = NULL; //our variable points to NULl this is our first element that will store the location of the second element
	cout<< "enter the number of elementd\n";
	int n,val;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cout<<"enter the element\n";
		cin>>val;
		Insert(val); //this will insert val at the starting of this list
		Printy();
	}

}