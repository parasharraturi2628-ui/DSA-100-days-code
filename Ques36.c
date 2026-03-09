//Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

#include <stdio.h>

int main()
{
    int n,m,i;
    scanf("%d",&n);
    
    int q[n];
    
    for(i=0;i<n;i++)
        scanf("%d",&q[i]);
        
    scanf("%d",&m);
    
    m = m % n;
    
    for(i=m;i<n;i++)
        printf("%d ",q[i]);
        
    for(i=0;i<m;i++)
        printf("%d ",q[i]);
        
    return 0;
}
