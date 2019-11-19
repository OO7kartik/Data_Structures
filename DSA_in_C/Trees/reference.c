// C++ program to delete a node from AVL Tree 
#include<bits/stdc++.h> 
using namespace std; 

// An AVL tree node 
class Node 
{ 
	public: 
	int key; 
	Node *left; 
	Node *right; 
	int height; 
}; 

// A utility function to get maximum 
// of two integers 
int max(int a, int b); 

// A utility function to get height 
// of the tree 
int height(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

// A utility function to get maximum 
// of two integers 
int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

/* Helper function that allocates a 
new node with the given key and 
NULL left and right pointers. */
Node* newNode(int key) 
{ 
	Node* node = new Node(); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; // new node is initially 
					// added at leaf 
	return(node); 
} 

// A utility function to right 
// rotate subtree rooted with y 
// See the diagram given above. 
Node *rightRotate(Node *y) 
{ 
	Node *x = y->left; 
	Node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 
	x->height = max(height(x->left), 
					height(x->right)) + 1; 

	// Return new root 
	return x; 
} 

// A utility function to left 
// rotate subtree rooted with x 
// See the diagram given above. 
Node *leftRotate(Node *x) 
{ 
	Node *y = x->right; 
	Node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left), 
					height(x->right)) + 1; 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 

	// Return new root 
	return y; 
} 

// Get Balance factor of node N 
int getBalance(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - 
		height(N->right); 
} 

Node* insert(Node* node, int key) 
{ 
	/* 1. Perform the normal BST rotation */
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else // Equal keys not allowed 
		return node; 

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	/* 3. Get the balance factor of this 
		ancestor node to check whether 
		this node became unbalanced */
	int balance = getBalance(node); 

	// If this node becomes unbalanced, 
	// then there are 4 cases 

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 
 node pointer */
	return node; 
} 

Node * minValueNode(Node* node) 
{ 
	Node* current = node; 

	while (current->left != NULL) 
		current = current->left; 

	return current; 
} 

Node* deleteNode(Node* root, int key) 
{ 
	if (root == NULL) 
		return root; 

	if ( key < root->key ) 
		root->left = deleteNode(root->left, key); 

	else if( key > root->key ) 
		root->right = deleteNode(root->right, key); 

	else
	{ 
		if( (root->left == NULL) || 
			(root->right == NULL) ) 
		{ 
			Node *temp = root->left ? 
						root->left : 
						root->right; 

			if (temp == NULL) 
			{ 
				temp = root; 
				root = NULL; 
			} 
			else 
			*root = *temp; 
			free(temp); 
		} 
		else
		{ 
			Node* temp = minValueNode(root->right); 

			root->key = temp->key; 

			root->right = deleteNode(root->right, 
									temp->key); 
		} 
	} 

	if (root == NULL) 
	return root; 

	root->height = 1 + max(height(root->left), 
						height(root->right)); 

	int balance = getBalance(root); 

	if (balance > 1 && 
		getBalance(root->left) >= 0) 
		return rightRotate(root); 

	if (balance > 1 && 
		getBalance(root->left) < 0) 
	{ 
		root->left = leftRotate(root->left); 
		return rightRotate(root); 
	} 

	if (balance < -1 && 
		getBalance(root->right) <= 0) 
		return leftRotate(root); 

	if (balance < -1 && 
		getBalance(root->right) > 0) 
	{ 
		root->right = rightRotate(root->right); 
		return leftRotate(root); 
	} 

	return root; 
} 

// A utility function to print preorder 
// traversal of the tree. 
// The function also prints height 
// of every node 
void preOrder(Node *root) 
{ 
	if(root != NULL) 
	{ 
		cout << root->key << " "; 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 

// Driver Code 
int main() 
{ 
Node *root = NULL; 

	/* Constructing tree given in 
	the above figure */
	root = insert(root, 9); 
	root = insert(root, 5); 
	root = insert(root, 10); 
	root = insert(root, 0); 
	root = insert(root, 6); 
	root = insert(root, 11); 
	root = insert(root, -1); 
	root = insert(root, 1); 
	root = insert(root, 2); 

	/* The constructed AVL Tree would be 
			9 
		/ \ 
		1 10 
		/ \ \ 
	0 5 11 
	/ / \ 
	-1 2 6 
	*/

	cout << "Preorder traversal of the "
			"constructed AVL tree is \n"; 
	preOrder(root); 

	root = deleteNode(root, 10); 

	/* The AVL Tree after deletion of 10 
			1 
		/ \ 
		0 9 
		/ / \ 
	-1 5	 11 
		/ \ 
		2 6 
	*/

	cout << "\nPreorder traversal after"
		<< " deletion of 10 \n"; 
	preOrder(root); 

	return 0; 
} 

// This code is contributed by rathbhupendra 
