#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
}*head;
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
void Delete(int n)
{
	node *temp1 = head; //make it the head first
	if(n==1)
	{
		head = temp1->next; //make head point to the second element
		delete temp1; //delete the first element
		return;
	}
	for (int i = 0; i < n-2; ++i) //shidt it to the (n-1)th node
		temp1 = temp1->next;
	node *temp2 = temp1->next; //make temp2 the nth node
	temp1->next = temp2->next; //make the (n-1)th node point to the  (n+1)th node
	delete temp2; //delete the nth node
}

int main(int argc, char const *argv[])
{
	head = 	NULL;
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);
	int n;
	Printy();
	cout<<"enter the position ";
	cin>>n;
	Delete(n);
	Printy();
	return 0;
}