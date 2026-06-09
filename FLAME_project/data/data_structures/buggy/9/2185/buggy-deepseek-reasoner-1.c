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
    for(j=0;j<n;j++) // @@ The outer loop variable j is modified inside the loop, causing incorrect iteration and failure to process all chain starting points.
    {
        for(i=0;i<n;i++)
        {
            if(c[j]==a[i]&&d[j]==b[i])
            {
                j=i; // @@ Modifying the outer loop variable j inside the inner loop disrupts the loop control, leading to skipped segments and incorrect chain detection.
                i=0; // @@ Resetting i to 0 is problematic; combined with modifying j, it may create an infinite loop or improper scanning.
                e[h]=e[h]+1;
            }
        }
        j=h; // @@ Setting j to h overwrites the current chain segment index, causing the outer loop to skip to the next chain index prematurely and losing the rest of the chain.
        h=h+1; // @@ The chain counter h is incremented without properly tracking which segments belong to each chain, and the first segment of a chain is never counted.
    }
    for(i=0;i<n;i++)
    {
        if(e[i]<=e[i+1]) // @@ The condition and logic for finding the maximum e[i] are incorrect; it modifies the array and does not accurately identify the index of the longest chain.
        {
            k=i+1; // @@ Setting k to i+1 when e[i]<=e[i+1] does not guarantee k holds the index of the maximum value.
        }
        else
        {
            e[i+1]=e[i]; // @@ Modifying e[i+1] during the loop corrupts subsequent comparisons, leading to incorrect maximum detection.
        }
    }
    printf("%d %d %d",e[k]+1,a[k],b[k]); // @@ Using a[k],b[k] as the starting point is wrong because k is not guaranteed to be the index of the starting segment of the longest chain; also the count e[k]+1 assumes the starting segment was not counted, which is not always true.
    return 0;
}