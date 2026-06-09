/*
 * @Course: Data Sturctures And Programming
 * @Teacher:
 * @Date: 2022-04-21 16:50:11
 * @LastEditors:
 * @LastEditTime: 2022-04-21 17:03:26
 * @FilePath: \Code\第四次\stack.c
 * @CopyRight:  ©2022 All Rights Reserved
 */
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main(){
   int sto[150]={0};
   int n=0,num=0,sum=0;
   scanf("%d",&n);
   while(n!=-1){
      
      if(n==1){
         scanf("%d",&num);
         if(sum<100){
            sto[sum]=num;
            sum++;
         }else{
            printf("%s ","error");
         }
      }
      if(n==0){
         if(sum>0){
            printf("%d ",sto[sum-1]);
            sum--;
         }else{
            printf("%s ","error");
         }
      }
      if(n==-1){
         break;
      }
      scanf("%d",&n);
   }
   
   return 0;
}
