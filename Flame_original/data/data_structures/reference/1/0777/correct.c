#include<stdio.h>
int n;
int flag[11]={0}, output[11];
void work(int now){
 if(now == n+1){
  for(int i = 1; i <= n; i++ ){
   printf("%d ", output[i]);
  }
  printf("\n");
  return;
 }
 for(int i = 1; i <= n; i++ ){
  if(!flag[i]){
   flag[i] = 1;
   output[now] = i;
   work(now+1);
   flag[i] = 0;
  }
 }
}
int main(){
 scanf("%d",&n);
 work(1);
 return 0;
}

