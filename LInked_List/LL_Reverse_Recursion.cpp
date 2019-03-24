#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};
node *Insert(node *head, int data)
{
	node *temp = new node();
	temp->data = data;
	temp->next = NULL;
	if(head == NULL) head = temp;
	else
	{
		node *temp1 = head;
		while(temp1->next != NULL) temp1 = temp1->next; //do this till temp1 is the (n-1)th node
		temp1->next = temp;
	}
	return head; //we have to return head since its a local variable and its value won't change like pass by reference
}
void Printy(node *head)
{
	if(head == NULL) return;
	cout<<head->data<< " ";
	Printy(head->next);
}
void ReversePrinty(node *head)
{
	if(head == NULL) return;
	Printy(head->next);
	cout<<head->data<< " ";
}
int main(int argc, char const *argv[])
{
	node *head = NULL;
	head = Insert(head,2);
	head = Insert(head,4);
	head = Insert(head,6);
	head = Insert(head,5);
	Printy(head);
	cout<<endl;
	ReversePrinty(head);
	cout<<endl;
	return 0;
}