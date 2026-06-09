//  main.c
//  DS1-5
//
//  Created by  on 2022/3/9.
//
//  全排列递归
//

#include<stdio.h>
int N;
int a[15]={0};  //储存是否用过
int pr[15]={0}; //储存数字
void Print(int x);
int main()
{
 scanf("%d",&N);
 Print(1);
 return 0;
}
void Print(int x){    //x是层数
    int i=0;
    if(x==N+1){    //数组存完了
        for(i=1;i<=N;i++){
            printf("%d",pr[i]);
            if(i<N){
                printf(" ");  //空格
            }
        }
        printf("\n");  //换行
        return;

 }
 for(i=1;i<=N;i++)
     if(a[i]==0)
     {
         pr[x]=i;
         a[i]=1;
         Print(x+1);   //进入下一层
         a[i]=0;
     }
}



