#include <stdio.h>
#include <stdlib.h>
int b[100]={0};
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
            permutate(b,begin+1,length); // @@ 该递归调用未保证子数组的有序性，导致输出排列的顺序不是字典序。应在递归前对剩余部分排序（如使用 qsort）以符合要求。
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