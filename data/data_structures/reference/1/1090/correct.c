#include<stdio.h>
int n;
void rank(int p,int w);//p是当前数字所在位置，n是要生成全排列几，w是还剩几个数待生成排序
int mark[30];//记录该数字是否被使用
int ans[30];//将全排列的一组数据（10个）存在这里面，如果满了10个，就输出，返回下一次递归
int main()
{
  scanf("%d",&n);
  rank(0,n);
  return 0;
}

void rank(int p,int w)//或者去掉int n,将n开在全局变量里也可以
{
  int i;
  if(w==0)//还剩0个数待生成，说明这一组数都已经生成完了
  {
    for(i=0;i<n;i++)//为什么不是for(i=1;i<=n;i++)
    printf("%d ",ans[i]);

    printf("\n");
    return;
  }

  //还有w个没排好的数，那就接着排
    for(i=1;i<=n;i++)
    {
      if(mark[i]==0)
      {
        mark[i]=1;
        ans[p]=i;
        rank(p+1,w-1);//生成下一个数字
        mark[i]=0;
      }
    }
  
}
