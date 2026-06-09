#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int a[101],b[101],c[101],d[101],e[105]={}; // @@ Empty initializer {} is invalid in standard C; should be {0}
int main()
{
    int n,i,j=0,h=0,k=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    for(j=0;j<n;j++) // @@ Modifying loop variable j inside the loop leads to incorrect iteration and undefined behavior
    {
        for(i=0;i<n;i++)
        {
            if(c[j]==a[i]&&d[j]==b[i])
            {
                j=i; // @@ Modifying outer loop variable j breaks the traversal logic and causes incorrect chain tracking
                i=0; // @@ Resetting i causes redundant checks and potential infinite loops
                e[h]=e[h]+1;
            }
        }
        j=h; // @@ Incorrectly resetting j to h disrupts the outer loop iteration
        h=h+1;    
    }
    for(i=0;i<n;i++)
    {
        if(e[i]<=e[i+1]) // @@ Array index out of bounds when i equals n-1
        {
            k=i+1; 
        }
        else
        {
            e[i+1]=e[i]; // @@ Array index out of bounds and incorrect logic for finding maximum value
        }
    }
    printf("%d %d %d",e[k]+1,a[k],b[k]); // @@ k may be uninitialized or out of bounds, and e[k] does not correctly store the maximum chain length
    return 0;
}