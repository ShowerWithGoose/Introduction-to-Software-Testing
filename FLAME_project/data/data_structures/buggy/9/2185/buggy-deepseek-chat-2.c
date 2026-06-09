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
                j=i;
                i=0;
                e[h]=e[h]+1;
            }
        }
        j=h; // @@ [Error: This line incorrectly resets j to h, which is the current segment count index, not the original segment index. This breaks the outer loop logic and causes incorrect traversal of segments.]
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
            e[i+1]=e[i];
        }
    }
    printf("%d %d %d",e[k]+1,a[k],b[k]); // @@ [Error: The output uses e[k]+1, but the counting logic in the loop is flawed, so this does not correctly represent the maximum number of segments. Also, a[k] and b[k] may not correspond to the correct starting point of the longest chain.]
    return 0;
}