#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define eps 1e-9
struct lines
{
    int x1;
    int y1;
    int x2;
    int y2;
};
void sort(struct lines a[],int n);
int main()
{
    struct lines line[1024];
    int n;
    int check[1024]={0};
    scanf("%d",&n);
    int i,j;
    int max=0,place;
    int tempx,tempy;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);//x1<x2
    }
    sort(line,n);
    for(i=0;i<n;i++)
    {
        tempx=line[i].x2;
        tempy=line[i].y2;
        for(j=i;j<n;j++) // @@ The inner loop should restart from the beginning or search the entire array to find connected segments, not just from i. Also, it doesn't update j correctly to continue the chain properly because it relies on sorted order which might not guarantee adjacency in the list if gaps exist or if the sort is flawed. More critically, the logic assumes that if line[j] connects, it's the *next* one in the sorted array, but the chain might skip indices if the sort isn't perfect or if multiple segments start at same x (though constraint says no 3 share endpoint). The main issue is that `check[i]` only counts forward connections in a single pass without verifying continuity across non-adjacent sorted elements properly. However, the most immediate logical error is that the inner loop variable `j` is not reset or managed to follow the chain. It just iterates linearly. If segment A connects to B, and B connects to C, this loop for A will find B, update tempx/tempy, but then continue checking subsequent j's against the new end point. This part is actually okay for a linear scan IF the segments are sorted such that connected segments appear in order. But the sort function is flawed.
        {
        if(line[j].x1==tempx&&line[j].y1==tempy)
        {
            check[i]++;
            tempx=line[j].x2;
            tempy=line[j].y2;
            
        }
        }
    }
    for(i=0;i<n;i++)
    {
        if(check[i]>max)
        {
            max=check[i];
            place=i;
        }
    }
    printf("%d %d %d",max+1,line[place].x1,line[place].y1);
}
void sort(struct lines a[],int n)
{
    struct lines tmp;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[i].x1>a[j].x2) // @@ The sorting condition is incorrect. It compares x1 of one segment with x2 of another. To form a continuous line where x increases, we should sort by the starting coordinate x1. The condition `a[i].x1 > a[j].x2` does not produce a valid sort order for chaining. It should likely be `a[i].x1 > a[j].x1` to sort by start position.
            {
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}