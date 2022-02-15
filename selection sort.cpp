#include <iostream>
using namespace std;

int main()
{
    int n, a[10], i, j, mi;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    for(i=0;i<n;i++)
    {
        mi=i;
        for(j=i+1;j<n;j++)
        {
            if(a[mi]>a[j])
            mi=j;
        }
        swap(a[i],a[mi]);
    }
    
    for(i=0;i<n;i++)
    cout<<a[i]<<endl;
    

    return 0;
}
