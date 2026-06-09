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
                j=i; // @@ Modifies outer loop variable j, disrupting the loop control and causing incorrect traversal.
                i=0; // @@ Resets inner loop variable i, leading to repeated searches and potential infinite loops.
                e[h]=e[h]+1; // @@ Increments count for chain starting at original j, but h does not correspond to the correct starting segment index.
            }
        }
        j=h; // @@ Overwrites j with the current chain index h, causing the outer loop to skip segments.
        h=h+1; // @@ Increments h without properly associating it with the starting segment of the chain.
    }
    for(i=0;i<n;i++)
    {
        if(e[i]<=e[i+1])
        {
            k=i+1; // @@ Inefficiently tracks index; does not correctly find the maximum length.
        }
        else
        {
            e[i+1]=e[i]; // @@ Modifies the array, corrupting chain length data.
        }
    }
    printf("%d %d %d",e[k]+1,a[k],b[k]);
    return 0;
}