#include <stdio.h>
#include <stdlib.h>
int b[100]={0}; // @@ Global array b is shared across recursive calls, causing state corruption and incorrect permutation generation.
void swap(int* str, int front, int back) // @@ Function implements a right shift instead of a true swap, breaking the permutation logic.
{
    int flag=str[back];
    int i;
    for(i=back-1;i>=front;i--)
    {
        str[i+1]=str[i]; // @@ Overwrites elements during shift instead of exchanging two values.
    }
    str[front]=flag;
}

void permutate(int* str, int begin, int length)
{

    int i;
    int j;
    if(begin==length)
    {
        for(i=0;i<length;i++)
        {
            printf("%d ",str[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        for(i=begin;i<length;i++)
        {
            for(j=0;j<length;j++)
            {
                b[j]=str[j]; // @@ Copies to global b, which gets corrupted by deeper recursive calls.
            }//拷贝数组到b
            swap(b,begin,i); // @@ Uses incorrect shift logic instead of swapping elements at begin and i.
            permutate(b,begin+1,length); // @@ Lacks backtracking to restore array state, causing incorrect permutations and violating lexicographical order.
        }
    }
}


int main()
{
    int n;
    scanf("%d",&n);//扫描数字
    int str[100]={0};
    int i;
    for(i=0;i<n;i++)
    {
        str[i]=i+1;
    }
    permutate(str,0,n);//排列
}