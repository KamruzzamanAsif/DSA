// This program dynamically takes input from user until EOF is pressed and outputs a minheap
// Note: array indexing starts from 0
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int heap_size=0;
int a[100];

void minHeap(int data)
{
    heap_size++;
    int i = heap_size-1;
    a[i]=data;
    while (i != 0 && a[(i-1)/2] > a[i])  // (i-1)/2 is the parent of i
    {                                    //  while indexing from 0
       swap(a[i], a[(i-1)/2]);
       i = (i-1)/2;
    }
}

int main()
{
    int d;
    cout<<"Enter elements: ";
    while(cin>>d)
    {
        minHeap(d);
    }
    /*minHeap(8);
    minHeap(2);
    minHeap(10);
    minHeap(5);
    minHeap(6);
    minHeap(7);
    minHeap(12);
    minHeap(11);
    MinHeap array representation: 2 5 7 8 6 10 12 11 */
    cout<<"\nMinHeap array representation: ";
    for(int i=0;i<heap_size;i++)
        cout<<a[i]<<" ";
}
