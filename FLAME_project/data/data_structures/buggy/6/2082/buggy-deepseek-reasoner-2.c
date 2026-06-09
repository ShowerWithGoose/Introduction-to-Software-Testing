#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int a[100],b[100],i=0,j=0,n,m,n1,flag=0;
   while(scanf("%d",&n)!=-1){ // @@ 循环条件错误：输入以-1结束，但scanf读取到-1时返回1，不会返回-1，导致循环无法在输入-1时停止，需要用户手动触发EOF或改为while(scanf("%d",&n)==1 && n!=-1)
       a[i]=n;
       i++;
       n1=i;
   }
   for(i=0;i<=n1;i++){ // @@ 循环次数多1次，应改为i<n1，否则会访问a[n1]（数组越界）
       if(a[i]==1){
           b[j]=a[i+1]; // @@ 1. 未检查i+1是否越界；2. 未跳过push的值，导致下一次循环会错误处理该值
           j++;
           flag++;
       }
    if(a[i]==0){
        flag--;
        if(flag<0){
            printf("error ");
        }
        else{
            printf("%d ",b[flag+1]); // @@ 栈索引错误：flag为当前元素个数，pop后flag--，此时应输出b[flag]（即栈顶元素），而非b[flag+1]
            j=flag+1; // @@ 无意义语句，j的值未正确维护
        }
    }
   }
    return 0;
}