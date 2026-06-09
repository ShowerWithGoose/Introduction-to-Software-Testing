#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
// void swap(int*p,int*q)
// {
//     int t;
//     t=*p;
//     *p=*q;
//     *q=t;
// }
// void qpl(int put[],int begin,int end)
// {
//     int i;
//     if (begin>=end)
//     {
//         for ( i = 0; i < end; i++)
//         {
//             printf("%d",put[i]);
//             printf(" ");
//         }
//         printf("\n");
        
//     }
//     else
//     {
//         for ( i =begin; i < end; i++)
//         {
//            if (begin!=i)
//            {
//              swap(&put[begin],&put[i]);
//            }
//            qpl(put,begin+1,end);



//            if (begin!=i)
//            {
//              swap(&put[begin],&put[i]);
//            }


           
//         }
        
//     }
    
// }
// 前面的没有顺序
// 下面进行有顺序的
void qpl(int *a, int *b, int n , int depth) 
 { 
    int i;
    if(depth==n+1) 
    {
    for(i=1;i<=n;i++)
    { 
    printf("%d ",a[i]); 
    }
    printf("\n");

    return;
    }
     for(i=1;i<=n;i++) 
     { 
    if(b[i]==0) 
     {
        b[i]=1; 
       a[depth]=i;
       qpl(a,b,n,depth+1);
        b[i]=0;//b相当于是一个一直表示状态的数组
         } } }
 int main()
 {
  int n,i; int a[100]={0}; int b[100]={0}; 
  scanf("%d",&n);
   qpl(a,b,n,1); 
   return 0;

     return 0;
 }
