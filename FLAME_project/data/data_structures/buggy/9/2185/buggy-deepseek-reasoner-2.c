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
                j=i; @@ // [Modifying loop variable j inside inner loop causes incorrect iteration and skipping of segments]
                i=0; @@ // [Resetting inner loop counter may lead to infinite loop or missed connections]
                e[h]=e[h]+1;
            }
        }
        j=h; @@ // [Overwriting loop variable j with h disrupts the outer loop sequence]
        h=h+1; @@ // [Incrementing h after setting j to previous h leads to repeated processing of same index]
    }
    for(i=0;i<n;i++)
    {
        if(e[i]<=e[i+1]) @@ // [Accessing e[i+1] which may be uninitialized; logic fails to find maximum count correctly]
        {
            k=i+1; @@ // [Stores index incorrectly; does not guarantee maximum]
        }
        else
        {
            e[i+1]=e[i]; @@ // [Modifies e array, destroying original counts and causing incorrect final comparison]
        }
    }
    printf("%d %d %d",e[k]+1,a[k],b[k]);
    return 0;
}