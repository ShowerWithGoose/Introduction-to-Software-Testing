#include <stdio.h>

int used[1000]={0},path[1000]={0};
int n,length;
void perum(int n,int length);

int main()
{
  scanf("%d",&n);
  perum(n,0);
	return 0;
}
void perum(int n,int length){
  int i;
  for(i=1;i<=n;i++){
    if(used[i]!=1){
      path[length]=i;//在该层放入数字 
      used[i]=1;//标记已用 
      perum(n,length+1);//进入下一层 
      //撤销前一层的选择，继续递归
      //此时， used[1]=used[2]=used[3]=used[4]=1,
      used[i]=0;
    }
  }
  //i==n,每一层都放了东西，输出
  if(length==n){
    for(i=0;i<n;i++){
      printf("%d ",path[i]);
      if(i==n-1){
        printf("\n");
      } 
    }
  }
  return ;
}

