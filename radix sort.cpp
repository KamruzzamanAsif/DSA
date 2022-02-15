#include <iostream> 
using namespace std; 

int getMax(int arr[], int n) 
{ 
	int mx = arr[0]; 
	for (int i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i]; 
	return mx; 
} 

// A function to do counting sort of arr[] according to 
// the digit represented by place. 
void countSort(int arr[], int n, int place) 
{ 
	int output[n]; // output array 
	int i, count[10] = { 0 }; 

	// Store count of occurrences in count[] 
	for (i = 0; i < n; i++) 
		count[(arr[i] / place) % 10]++; 

	// Change count[i] so that count[i] now contains actual 
	// position of this digit in output[] 
	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	// Build the output array 
	for (i = n - 1; i >= 0; i--) { 
		output[count[(arr[i] / place) % 10] - 1] = arr[i]; 
		count[(arr[i] / place) % 10]--; 
	} 

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 

void radixsort(int arr[], int n) 
{ 
	// Find the maximum number to know number of digits 
	int m = getMax(arr, n); 

	for (int place = 1; m / place > 0; place *= 10) 
		countSort(arr, n, place); 
} 

void print(int arr[], int n) 
{ 
    cout<<"Sorted array: ";
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

int main() 
{ 
	int arr[100], n; 
	cout<<"Enter array size:";
	cin>>n;
	cout<<endl;
	cout<<"Enter array: ";
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	radixsort(arr, n); 
	print(arr, n); 
	return 0; 
}
