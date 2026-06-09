#include<stdio.h>
int n,x,num[11],flag[11];
void search(int x)//搜索第x个位置
{
    int i;//局部变量！！
    if(x==n+1)//递归终止，输出一个结果
    {
        for(i=1;i<n;i++)
            printf("%d ",num[i]);
        printf("%d\n",num[i]);
        return;//回溯
    }
    for(i=1;i<=n;i++)
        if(flag[i]==0)//i不在结果中
        {
            num[x]=i;
            flag[i]=1;//标记i已被使用
            search(x+1);//寻找下一个位置中能被存储的数
            flag[i]=0;//复位
        }
}
int main()
{
    scanf("%d",&n);
    search(1);//从第一个位置开始搜索
    return 0;
}


