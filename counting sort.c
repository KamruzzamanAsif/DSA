#include <stdio.h>

int main()
{
    int a[100],c[100]={0},b[100], n, i, j;
    printf("Number of elements: ");
    scanf("%d",&n);
    printf("\nEnter array: ");
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    
    for(j=1;j<=n;j++)
    c[a[j]]+=1;          //temporary array, where elements number are counted accoring to index
    
    for(i=1;i<100;i++)
    c[i]=c[i]+c[i-1];    // making cumulative number array
    
    for(j=n;j>=1;j--)
    {
        b[c[a[j]]]=a[j];   
        c[a[j]]-=1;
    }
    
    printf("Sorted array: ");
    for(i=1;i<=n;i++)
    printf("%d ",b[i]);
    

    return 0;
}
