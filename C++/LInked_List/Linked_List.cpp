#include <iostream>
using namespace std;

Struct node
{
	int data;
	node *link;
};

Node *A;
A = NULL; //make the starting node point to null in the starting

Node *temp = new Node(); //dynamically create memory for new node

temp -> data = 2; //this mean (*temp).data = 2;
temp -> link = NULL;

A = temp; //linking the first element to the newly created one

//now we created our second node

//to create a third node
temp = new node(); //this time we only need to allocate memory since we delcared its datatype
temp -> data = 4;
temp -> link = NULL;
//we only know the address to which our first element points to but we need to store the third nodes adress in the second nodes link
//so in this case we have to transverse the whole list
node *temp1 = new node();
temp1 = A;
while ( temp1 -> link != NULL )
	temp1 = temp1 -> link;
//so now temp1 has reached the second node and it points to NULL we will change this so that it points to the third node
temp1 -> link = temp;


int main()
{

}