#include <stdio.h>

int main()
{
    int n, a[7], i, tem, j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    for(i=1;i<n;i++)
    {
        tem=a[i];
        j=i-1;
        
        while(tem<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=tem;

    }
    
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    
    return 0;
}
