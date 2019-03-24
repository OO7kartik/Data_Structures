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
void Reverse()
{
	node *current,*prev,*next;
	current = head;
	prev = NULL;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}
int main()
{
	int n,val;
	cout<<"how many elements do you want to insert? ";
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>val;
		Insert(val);
		Printy();
	}
	cout<<"Revesring......\n ";
	Reverse();
	Printy();
	return 0;
}