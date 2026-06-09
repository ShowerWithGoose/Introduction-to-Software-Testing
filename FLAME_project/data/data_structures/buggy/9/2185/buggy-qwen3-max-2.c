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
        j=h; // @@ [This line resets j to h, which breaks the outer loop's intended traversal. The logic for building chains is flawed because j is being overwritten, causing incorrect segment linking and chain counting.]
        h=h+1;    
    }
    for(i=0;i<n;i++)
    {
        if(e[i]<=e[i+1]) // @@ [This loop accesses e[i+1] when i can be n-1, leading to out-of-bounds access (undefined behavior). Also, the logic for finding the maximum chain length is incorrect—it doesn't properly track the index of the maximum value.]
        {
            k=i+1; 
        }
        else
        {
            e[i+1]=e[i]; // @@ [This modifies the e array during comparison, corrupting the original counts and leading to wrong results.]
        }
    }
    printf("%d %d %d",e[k]+1,a[k],b[k]); // @@ [The final output uses e[k]+1, but due to incorrect chain building and max-finding logic, both e[k] and k are likely wrong. Additionally, the starting point should correspond to the beginning of the longest chain, not necessarily a[k], b[k].]
    return 0;
}