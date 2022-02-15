// This program creates a BST by inserting values, traversal inorder, search an element, find minimum and maximum
// find successor of a node->key, delete an element

#include <bits/stdc++.h>
using namespace std;

struct node {
	int key;
	struct node *left, *right, *parent;
};

struct node* root = NULL; // declaring the root node pointer and initializing as NULL

//function to create a new BST node
struct node* newNode(int item)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	                                        //dynamically allocating the memory for every new node
	temp->key = item;
	temp->left = temp->right = temp->parent = NULL;
	return temp;
}

// function to do inorder traversal of BST
// This also gives a sorted(ascending order) list of elements
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}

// function to insert a new node with given key in  BST
struct node* insert(struct node* node, int key)
{
    struct node* temp;

	// Here we make new node for inserted elements
	if (node == NULL)
		return newNode(key);

	if (key <= node->key) // in left the value must be equal or less from the parent value
    {
        temp = insert(node->left, key); // Here in node left the new node's address will be stored
        node->left = temp;
        temp->parent = node; // storing parent address
    }

	else if (key > node->key) // in right the value must be greater than the parent value
    {
        temp = insert(node->right, key); // Here in node right the new node's address will be stored
        node->right = temp;
        temp->parent = node; // storing parent address
    }

	// If the above doesn't work, return the (unchanged) node pointer
	return node;
}

// function to search a value in BST
struct node* search(struct node* root, int key)
{
    // First Case: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;
    // Second Case: key is greater than root's key
    if (root->key < key)
       return search(root->right, key);

    // Third Case: key is smaller than root's key
    return search(root->left, key);
}

// function to find minimum value in BST
int minimumValue(struct node* node)
{
    struct node* current = node;
    while(current->left!=NULL)
        current = current->left;

    return current->key;
}

// function to find maximum value in BST
int maximumValue(struct node* node)
{
    struct node* current = node;
    while(current->right!=NULL)
        current = current->right;

    return current->key;
}

// function for finding successor
int successor(int value)
{
    struct node* n = search(root,value);  // finding the given values node
    // Case 1: if the node has right subtree
    if(n->right != NULL)
        return minimumValue(n->right);
    // Case 2: if the node doesn't have a right subtree
    struct node* p = n->parent;
    while (p != NULL && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p->key;
}

// function for delete an element in BST
struct node* deleteElement(struct node* node, int value)
{
    if (node == NULL)
		return node;

    if (value < node->key)
		node->left = deleteElement(node->left, value);
    else if (value > node->key)
		node->right = deleteElement(node->right, value);
    // now we get the out value's node and will delete it
    else
    {
        // node with only one child or no child
        if (node->left == NULL)
        {
            struct node* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct node* temp = node->left;
            free(node);
            return temp;
        }

        // node with both left and right child
        struct node* temp = node->right;

        while(temp->left!=NULL) // finding the successor of value
            temp = temp->left;  // the successor is the leftmost value(min value) of it's right subtree

        node->key = temp->key;  // Copy the inorder successor to this node

        node->right = deleteElement(node->right, temp->key); // Delete the inorder successor's node
    }


    return node;
};

int main()
{
	/* Let us create following BST
          50
		/	 \
       30	 70
       / \   / \
      20 40 60 80 */

	root = insert(root, 50);   // inserting the root key and storing it's address
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	// print inorder traversal of the BST
	cout<<"Inorder Traversal of BST(gives a sorted list): ";
	inorder(root);

    // searching an element from BST
    struct node* temp;
    int f = 40;
	temp=search(root,f);
	if(temp!=NULL)
        cout<<"\n"<<f<<" found successfully!";
    else
        cout<<"\n"<<f<<" not found";

	// finding minimum value in BST
	cout<<"\nMinimum value in BST is: "<<minimumValue(root);

	// finding maximum value in BST
	cout<<"\nMaximum value in BST is: "<<maximumValue(root);

	// finding successor of a node value
	int s=40;
	cout<<"\nSuccessor of "<<s<<" is: "<<successor(s);

	// deleting an element from BST
	int d=30;
	struct node* temporary;
	temporary=deleteElement(root,d);
	if(temporary!=NULL)
        cout<<"\n"<<d<<" delete successfully!";
    else
        cout<<"\n"<<d<<" delete failed";
    // printing inorder traversal of the BST after deleting an element
	cout<<"\nInorder Traversal of BST after deleting an element: ";
	inorder(root);


	return 0;
}
