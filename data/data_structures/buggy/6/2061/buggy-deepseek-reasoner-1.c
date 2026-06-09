#include <stdio.h>
int s[100];
int top=-1;
int main()
{
    int n,a;
    while(~(scanf("%d",&n))){  // @@ 无法正确识别结束标志-1：当输入-1时，scanf返回1，~1 = -2（非0），循环继续，且-1未被break，会被当作pop操作处理，导致逻辑错误。
        if(n==1){
            scanf("%d",&a);
            if(top==99){
                printf("error ");
            }else{
                s[++top]=a;
            }
        }else{  // @@ 此处未区分n==0（pop操作）和n==-1（结束标志），导致输入-1时错误地执行pop操作，输出不应出现的元素。应增加n==-1的判断并break。
            if(top==-1){
                printf("error ");
            }else{
                printf("%d ",s[top]);
                top--;
            }
        }
    }
    return 0;
}