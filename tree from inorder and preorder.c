#include<stdio.h>

void subTree(int start, int end, int tree_index);
//global
int tree_output[1000], inorder_input[100], preorder_input[1000], preorder_index=0;
int arraySize;
int x=-1;

int max(int a, int b){
    return (a>b)?a:b;
}

int main(){
    for(int i=1; i<1000; i++) tree_output[i]=-1;

    printf("Array size:");
    scanf("%d",&arraySize);

    printf("Inorder input: ");
    for(int i=0; i<arraySize; i++){
        scanf("%d",&inorder_input[i]);
    }

    printf("preOrder input: ");
    for(int i=0; i<arraySize; i++){
        scanf("%d",&preorder_input[i]);
    }

    subTree(0, arraySize-1, 1);

    for(int i=1; i<=x; i++) printf("%d ",tree_output[i]);
return 0;
}

void subTree(int start, int end, int tree_index){
    if(start>end) return;
    if(preorder_index>=arraySize) return;

    int root = preorder_input[preorder_index];
    preorder_index++;
    tree_output[tree_index]=root;
    x=max(x,tree_index);
    if(start==end) return;

    int i;
    for(i=start; i<=end; i++){
        if(inorder_input[i]==root) break;
    }

 //confusion
    subTree(start, i-1, 2*tree_index);
    subTree(i+1, end, 2*tree_index+1);


}
