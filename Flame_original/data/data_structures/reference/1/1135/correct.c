#include<stdio.h>
int a[10],ans[10];
int i,j,N,key,k,temp,low,high;
void output();
void change();
int main()
{
  int n;
  scanf("%d",&N);
  a[0]=1;
  for(i=1; i<10; i++)
    {
      a[i]=(i+1)*a[i-1];
    }//算出阶乘
  for(i=0; i<N; i++)
    ans[i]=i+1;
  output();
  for(n=0;n<a[N-1]-1;n++)
  {
  	change();
  	output();
  }
  return 0;
}

void output()
{
  for(i=0; i<N-1; i++)
    printf("%d ",ans[i]);
  printf("%d\n",ans[i]);
}

void change()
{
  for(i=N-1; i>0; i--)
    {
      if(ans[i]>ans[i-1])
        {
          key=i-1;
          break;
        }
    }
  for(j=N-1; j>=i; j--)
    {
      if(ans[j]>ans[key])
        {
          k=j;
          break;
        }
    }
/*数列从右往左递增，因此只需要从右往左找到大于ans【key】的数
就是最小的大于ans【key】的数*/
  temp=ans[k];
  ans[k]=ans[key];
  ans[key]=temp;
  //交换ans【key】和ans【k】
  for( low=key+1,high=N-1;low<high;low++,high--)
  {
  	temp=ans[low];
  	ans[low]=ans[high];
  	ans[high]=temp;
  }//逆序
}



