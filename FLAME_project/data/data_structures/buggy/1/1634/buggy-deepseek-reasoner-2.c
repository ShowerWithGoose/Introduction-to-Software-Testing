#include<stdio.h>
int a[15]={0};
void Full_Permutation(int a[],int n,int m);

int main()
{
    int n;
    scanf("%d",&n);
    Full_Permutation(a,n,0); 
    return 0;
}

void Full_Permutation(int a[],int n,int m)//m必须从0开始，才能保证填充能有效执行 
{
    int i=0,j=0,num=0;//num用于存储待排列的数字，具体大小是1~n
    if(m==n)//整个递归的出口，在本函数中执行n!次
    {
        for(i=0;i<n;i++)
        {
            printf("%d",a[i]); // @@ 缺少空格，应改为 printf("%d ",a[i]); 以符合输出格式中每个整数后跟一个空格
        }
        printf("\n");
        //return;
    }
    else//a数组还未填充完毕,第m位往后都是空的
    {
        for(num=1;num<=n;num++)//保证从小到大排列
        {
            for(j=0;j<m;j++)//用while容易越界
            {
                if(a[j]==num)
                break;
            }
            if(j==m)//num还没有被排列
            {
                a[m]=num;//把num排进a数组
                Full_Permutation(a,n,m+1);//递归，增加m
            }
        }
    }
}