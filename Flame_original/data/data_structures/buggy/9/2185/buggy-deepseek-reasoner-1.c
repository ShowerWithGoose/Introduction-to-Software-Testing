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
                j=i; // @@ [Modifying the outer loop variable j inside the inner loop disrupts the intended iteration, causing the algorithm to skip segments or loop incorrectly.]
                i=0; // @@ [Resetting i to 0 inside the inner loop leads to repeated checks and potential infinite loop; also interferes with the outer loop's control.]
                e[h]=e[h]+1;
            }
        }
        j=h; // @@ [Assigning j = h after the inner loop corrupts the outer loop's progress; h is incremented later, so the next iteration starts from an unintended index.]
        h=h+1;    
    }
    for(i=0;i<n;i++)
    {
        if(e[i]<=e[i+1]) // @@ [Using e[i+1] when i = n-1 accesses out-of-bounds (e[105] might be within allocated size but logically incorrect; also comparison logic is flawed for finding the maximum.]
        {
            k=i+1; 
        }
        else
        {
            e[i+1]=e[i]; // @@ [Overwriting e[i+1] with e[i] corrupts the original counts and does not correctly propagate the maximum.]
        }
    }
    printf("%d %d %d",e[k]+1,a[k],b[k]); // @@ [k may be uninitialized or out of range; a[k] and b[k] do not necessarily correspond to the start point of the longest continuous segment.]
    return 0;
}