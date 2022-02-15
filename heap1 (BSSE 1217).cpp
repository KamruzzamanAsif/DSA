// This program takes an unsorted int array from user and output a sorted array using heapsort
// Note: we started indexing from 1 in array
#include <bits/stdc++.h>
using namespace std;
#define SIZE 20

// function for making a max-heap
void MaxHeapify(int a[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i; // left = 2*i
	int r = 2 * i + 1; // right = 2*i + 1

	// If left child is larger than root
	if (l <=n && a[l] > a[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r <=n && a[r] > a[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(a[i], a[largest]);

		// Recursively MaxHeapify the sub-tree
		MaxHeapify(a, n, largest);
	}
}

// function to do heap sort
void heapSort(int a[], int n)
{
	// building max-heap
	for (int i = n / 2 ; i >= 1; i--)
		MaxHeapify(a, n, i);

	// extracting elements one by one from max-heap
	for (int i = n; i > 1; i--) {
		// moving current root to end
		swap(a[1], a[i]);
		//calling MaxHeapify reducing size (i-1)
		MaxHeapify(a, i-1, 1);
	}
}

// function to print sorted array
void printSortedarray(int a[], int n)
{
	for (int i = 1; i <=n; ++i)
		cout << a[i] << " ";
}

int main()
{
    int a[SIZE], n;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<endl;
    cout<<"Enter unsorted array: ";
    for(int i=1; i<=n; i++)
        cin>>a[i];
	//int a[] = { 0, 10, 13, 5, 6, 7 };
	//int n= sizeof(a)/sizeof(a[1])-1;

	heapSort(a, n);

	cout << "Sorted array is: ";
	printSortedarray(a, n);
}
