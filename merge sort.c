#include <stdio.h>

int templist[1000];

void Merge(int a[], int lpos, int rpos, int rend)
{
    int lend=rpos-1;
    int tpos=lpos;
    int number=(rend-lpos)+1;
    
    while(lpos<=lend && rpos<=rend)
    {
        if(a[lpos]<=a[rpos])
        templist[tpos++]=a[lpos++];
        else 
        templist[tpos++]=a[rpos++];
    }
    while(lpos<=lend)
    {
        templist[tpos++]=a[lpos++];
    }
    while(rpos<=rend)
    {
        templist[tpos++]=a[rpos++];
    }
    for(int i=0; i<number; i++)
    {
        a[rend]=templist[rend];
        rend--;
    }
    
}

void Msort(int a[],int left,int right)
{
    int center;
    if(left<right)
    {
        center=(left+right)/2;
        Msort(a,left,center);
        Msort(a,center+1,right);
        Merge(a,left,center+1,right);
    }
}



int main()
{
    int a[10], i, n;
    printf("Enter array size:");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    Msort(a,0,n-1);
    
   
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    
    

    return 0;
}
