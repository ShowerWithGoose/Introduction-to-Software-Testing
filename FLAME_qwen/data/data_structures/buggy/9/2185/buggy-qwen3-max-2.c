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
                j=i; // @@ [Modifying loop variable 'j' inside inner loop causes unpredictable iteration and skips segments]
                i=0; // @@ [Resetting 'i' to 0 inside the loop leads to infinite or incorrect looping behavior]
                e[h]=e[h]+1;
            }
        }
        j=h; // @@ [Overwriting loop variable 'j' with 'h' breaks the outer loop logic and causes incorrect traversal]
        h=h+1;    
    }
    for(i=0;i<n;i++)
    {
        if(e[i]<=e[i+1]) // @@ [Accessing e[i+1] when i = n-1 leads to out-of-bounds read (undefined behavior)]
        {
            k=i+1; 
        }
        else
        {
            e[i+1]=e[i]; // @@ [Same out-of-bounds write when i = n-1; also logic incorrectly propagates values]
        }
    }
    printf("%d %d %d",e[k]+1,a[k],b[k]); // @@ [If k is out of valid segment index range due to prior errors, this accesses invalid data]
    return 0;
}