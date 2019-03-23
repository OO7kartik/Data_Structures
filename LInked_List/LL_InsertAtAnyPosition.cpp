#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};
struct node *head;
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
void Insert(int data, int n)
{
	//this our new node we need to insert at the nth position
	node *temp1 = new node();
	temp1->data = data;
	temp1->next = NULL;
	if(n==1) //for the first node, this covers the case where there is no previous first node and the case where we insert this inplace of this first node
	{
		temp1->next = head;
		head = temp1;
		return;
	}
	node *temp2 = head;
	for (int i = 0; i < n-2; ++i)//to tranverse to the n-1 node (n-2 since we need to reach n-1 and we already set the first node to head)
		temp2 = temp2->next;
	temp1->next = temp2->next;
	temp2->next = temp1;
}
int main(int argc, char const *argv[])
{
	head = NULL; //our head node which will point to our first node
	Insert(2,1);
	Insert(3,2);
	Insert(4,1);
	Insert(5,2);
	Printy();
	return 0;
}