#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int a[101],b[101],c[101],d[101],e[105]={};
int main()
{
    int n,i,j=0,h=0,k=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(c[j]==a[i]&&d[j]==b[i])
            {
                j=i; // @@ This modifies the outer loop variable j inside the inner loop, causing incorrect iteration and potential infinite loop.
                i=0; // @@ Resetting i to 0 inside the loop disrupts the normal loop progression and may cause an infinite loop.
                e[h]=e[h]+1;
            }
        }
        j=h; // @@ This overwrites j with h, which is the segment counter, breaking the outer loop's intended iteration over all segments.
        h=h+1;    
    }
    for(i=0;i<n;i++)
    {
        if(e[i]<=e[i+1])
        {
            k=i+1; 
        }
        else
        {
            e[i+1]=e[i]; // @@ This modifies the array e while iterating, which corrupts the comparison logic for finding the maximum.
        }
    }
    printf("%d %d %d",e[k]+1,a[k],b[k]);
    return 0;
}