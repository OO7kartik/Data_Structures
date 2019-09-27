#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
}*head;
void Insert(int data) //to insert data at the starting
{
	node *temp1 = new node();
	temp1->data = data;
	temp1->next = head;
	head = temp1;
}
void Printy()
{
	node *temp = head;
	cout<<"the list now is: ";
	while(temp != NULL)
	{
		cout<< temp->data << " ";
		temp = temp->next;
	}
	cout<<endl;
}
void ReverseList(node *p)
{
	//for the last node we set head to point to it.
	//Then we go to the previous recurcive call when p is the second last node
	//and follow the routine after the recursive call.
	if(p->next == NULL)
	{
		head = p;
		return;
	}
	ReverseList(p->next);
	//for the first time this is executed....
	node *q = p->next; //p is the second last node, so we set q to the last node
	q->next = p; //make the last node ie. q to point to the previous node ie. p
	p->next = NULL;
}
int main(int argc, char const *argv[])
{

	return 0;
}