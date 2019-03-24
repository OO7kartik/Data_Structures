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
	if(p->next == NULL)
	{
		head = p;
		return;
	}
	ReverseList(p->next);
	node *q = p->next; //p is second last node, q is last node now
	q->next = p;
	p->next = NULL;
}
int main(int argc, char const *argv[])
{
	int n,val;
	cout<< "enter the number of elements ";
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>val;
		Insert(val);
	}
	cout<<"the original list is"<<endl;
	Printy();
	cout<<"Revsering...."<<endl;
	ReverseList(head);
	Printy();
	return 0;
}