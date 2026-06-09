#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int s[100];
    int i=0;
    int a,b;
    while(scanf("%d",&a)==1){
        if(a==0&&i==0){
            printf("error ");
        }else if(a==1){
            scanf("%d",&b);
            s[i++]=b; // @@ 缺少栈满检查，当i==100时应输出"error"而不压入栈
        }else{ // @@ 此分支错误地处理了输入中的-1（结束标志），且未检查栈空导致访问越界
            printf("%d ",s[i-1]); // @@ 当i==0时访问越界，应检查栈非空
            i--;
        }
    }
    return 0;
 }