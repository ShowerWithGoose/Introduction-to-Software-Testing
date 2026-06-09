#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-8
#define MAX 11

void leftswap(int a[],int left,int i)
{
    int tag,j;
    tag=a[i];
    for(j=i;j>left;j--)
        a[j]=a[j-1];
    a[left]=tag;
}

void rightswap(int a[],int left,int i)
{
    int tag,j;
    tag=a[left];
    for(j=left;j<i;j++)
        a[j]=a[j+1];
    a[i]=tag;
}

void Array(int a[],int left,int right)
{
    int i;
    if(left==right)
    {
        for(i=0;i<=right;i++)
            printf("%d",a[i]); // @@ [Missing space between numbers; should print "%d " to match expected output format]
        printf("\n");
    }
    else
    {
        for(i=left;i<=right;i++)
        {
            leftswap(a,left,i);
            Array(a,left+1,right);
            rightswap(a,left,i);
        }
    }
}



int main(){
    int n;
    int a[MAX];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    Array(a,0,n-1);
return 0;
}