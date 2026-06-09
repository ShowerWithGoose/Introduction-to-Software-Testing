#include <stdio.h>
#include <stdlib.h>
int b[100]={0}; // @@ Using a global array for recursive permutation generation causes state interference across recursive calls, leading to incorrect or duplicate outputs. It should be declared locally within the function.
void swap(int* str, int front, int back)
{
    int flag=str[back];
    int i;
    for(i=back-1;i>=front;i--)
    {
        str[i+1]=str[i];
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
                b[j]=str[j];
            }//拷贝数组到b
            swap(b,begin,i);
            permutate(b,begin+1,length);
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