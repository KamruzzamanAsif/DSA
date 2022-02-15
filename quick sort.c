#include <stdio.h>
int a[100];

int partition(int left, int right)
{

    int p = a[left], l = left , r = right;
    while (l < r)
    {
        while (l < right && a[l] <= p) l++;
        while (r>left && a[r] > p) r--;
        if (l < r)
        {
            int temp = a[l]; a[l] = a[r]; a[r] = temp;
        }
    }
    a[left] = a[r];
    a[r] = p;
    return r;
}

void quicksort(int left, int right)
{
    if (left < right)
    {
        int p = partition(left, right);
        quicksort(left, p - 1);
        quicksort(p + 1, right);
    }
}

int main()
{
    int n, i;
    printf("Enter number of array elements:");
    scanf("%d",&n);
    printf("\nEnter an array:");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    quicksort(0,n-1);
    
    printf("Sorted array: ");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);

    return 0;
}