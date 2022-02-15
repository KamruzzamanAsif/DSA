// In this program we will start indexing from 1 in Binary Tree array
// This program can construct tree of char and int(2 or more than 2 digits of number)
#include<bits/stdc++.h>
using namespace std;
#define SIZE 10

string tree[SIZE]; // declaring global binary tree array

int root(string key)
{
	if(tree[1] != "#") // checking whether the tree already has a root or not
		cout << "Tree already has a root";
	else
		tree[1] = key;
	return 0;
}

int set_left_child(string key, int parent)
{
	if(tree[parent] == "#")
		cout << "\nCan't set child at"<< (parent * 2) << " , no parent found";
	else
		tree[parent * 2] = key; //as left child position is 2k
	return 0;
}

int set_right_child(string key, int parent)
{
	if(tree[parent] == "#")
		cout << "\nCan't set child at"<< (parent * 2) + 1 << " , no parent found";
	else
		tree[(parent * 2) + 1] = key;  //as right child position is 2k+1
	return 0;
}

int print_tree()   // printing the binary tree
{
	for(int i = 1; i < SIZE; i++)
	{
		if(tree[i] != "#")
			cout << tree[i]<<" ";
		else
			cout << "_"<<" ";
	}
	return 0;
}

int get_left_child(int index){

    int x = (2 * index); //left child location 2k
    if(tree[x] != "#" && x<SIZE){
        return (2*index);
    }
    else return -1;
}

int get_right_child(int index){

    int x = (2 * index) + 1; //right child location 2k+1
    if(tree[x] != "#" && x<SIZE){
        return (2*index)+1;
    }
    else return -1;
}

void PreOrder_Traverse(int index){

    if(tree[index] != "#" && index > 0 && index<SIZE){
        cout<<tree[index]<<" ";
        PreOrder_Traverse(get_left_child(index));
        PreOrder_Traverse(get_right_child(index));
    }
}

void InOrder_Traverse(int index){

    if(tree[index] != "#" && index > 0 && index<SIZE){
        InOrder_Traverse(get_left_child(index));
        cout<<tree[index]<<" ";
        InOrder_Traverse(get_right_child(index));
    }
}

void PostOrder_Traverse(int index){

    if(tree[index] != "#" && index > 0 && index<SIZE){
        PostOrder_Traverse(get_left_child(index));
        PostOrder_Traverse(get_right_child(index));
        cout<<tree[index]<<" ";
    }
}

int main()
{
    string c , d;
    int j;
    for(int i=1; i<SIZE; i++)
        tree[i]="#";          // setting all elements '#' for calculation purpose
    cout<<"Enter tree root: ";
    cin>>c;
	root(c);
	cout<<endl;
	while(1)     // continuously taking tree elements
    {
        cout<<"Enter 'l' to set left child or 'r' to set right child or 'e' to end: ";
        cin>>c;
        if(c=="l")
        {
            cout<<"Enter left child and parent: ";
            cin>>d>>j;
            set_left_child(d,j);
        }
        else if(c=="r")
        {
            cout<<"Enter right child and parent: ";
            cin>>d>>j;
            set_right_child(d,j);
        }
        else if(c=="e") break;
        else break;
    }

    cout<<endl<<"Binary Tree array: ";
	print_tree();
	cout<<endl<<"Preorder Traversal of Binary Tree: ";
	PreOrder_Traverse(1);
	cout<<endl<<"Inorder Traversal of Binary Tree: ";
	InOrder_Traverse(1);
	cout<<endl<<"Postorder Traversal of Binary Tree: ";
    PostOrder_Traverse(1);

	return 0;
}


