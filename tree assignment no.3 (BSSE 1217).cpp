// This program constructs actual binary tree from given inorder and preorder/postorder traversal of that binary tree
// We start indexing from 1 in binary tree
// Here I used array representation
#include<bits/stdc++.h>
using namespace std;
#define SIZE 10
string tree[SIZE];

void Pre_In_Tree(string preOrder[], string inOrder[], int start, int end, int* preOrder_index, int tree_index)
{
    if(start>end || *preOrder_index>SIZE)
        return;

    string curret_element=preOrder[*preOrder_index];
    (*preOrder_index)++;

    if(start==end)
    {
        tree[tree_index]=curret_element;
        return;
    }

    int i;
    for(i=start; i<=end; i++)      // finding the index
    {
        if(curret_element==inOrder[i])
        break;
    }
                                                                // recursively calling the left and right subtree
    Pre_In_Tree(preOrder, inOrder, start, i-1, preOrder_index,2*tree_index);
    Pre_In_Tree(preOrder, inOrder, i+1, end, preOrder_index,2*tree_index+1);


    tree[tree_index]=curret_element;
    return;

}


void Post_In_Tree(string postOrder[], string inOrder[], int start, int end, int* postOrder_index, int tree_index)
{
    if(start>end || *postOrder_index<0)
        return;

    string curret_element=postOrder[*postOrder_index];
    (*postOrder_index)--;

    if(start==end)
    {
        tree[tree_index]=curret_element;
        return;
    }

    int i;
    for(i=start; i<=end; i++)    // finding the index
    {
        if(curret_element==inOrder[i])
        break;
    }
                                                                    // recursively calling the right and left subtree
    Post_In_Tree(postOrder, inOrder, i+1, end, postOrder_index,2*tree_index+1);
    Post_In_Tree(postOrder, inOrder, start, i-1, postOrder_index,2*tree_index);

    tree[tree_index]=curret_element;
    return;

}



int main()
{
    for(int i=0; i<SIZE; i++)
        tree[i]="-1";              // initializing all elements to -1

    // output tree[] ={1,2,3,4,5}
    //int  in[] = {4,2,5,1,3};
    //int  post[] = {4,5,2,3,1};
    // int pre[]= {1,2,4,5,3};

    cout<<"Enter size: ";
    int l,x,i;
    cin>>l;

    string in[l],post[l],pre[l];

    cout<<"\nEnter inorder traversal: ";
    for(i=0;i<l;i++)
        cin>>in[i];

    int len = sizeof(in) / sizeof(in[0]);  // taking the length

    cout<<"\nEnter choice(1 or 2):\n1.Preorder\t2.Postorder\n";
                                            // asking user's choice to construct tree form in and pre or in and post
    cin>>x;
    if(x==1)
    {
        cout<<"\nEnter preorder traversal: ";
        for(i=0;i<l;i++)
        cin>>pre[i];
        int pre_root_index = 0;
        Pre_In_Tree(pre, in, 0, len-1, &pre_root_index, 1);
    }
    else if(x==2)
    {
        cout<<"\nEnter postorder traversal: ";
        for(i=0;i<l;i++)
        cin>>post[i];
        int post_root_index = len-1;
        Post_In_Tree(post, in, 0, len-1, &post_root_index, 1);
    }
    else
        cout<<"\nWrong input";


    cout<<"\nTree array(Level-Order): ";
    for(int i=1; i<l+1; i++)
    {
        if(tree[i]=="-1") cout<<"_"<<" ";
        else cout<<tree[i]<<" ";
    }


    return 0;
}
