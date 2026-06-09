#include <stdio.h>
#include <string.h>
#define N 100005
char stack[N],stack1[N]; // @@ stack1 should be int to hold negative indices without truncation
int num[N],op[N];
int top=-1,top1=-1;
int check(char a)
{
    return a>='0'&&a<='9';
}
int ispri(char a,char b)//若b符号比a高级,则输出1 
{
    return ((a=='-'&&(b=='*'||b=='/'))||(a=='+'&&(b=='*'||b=='/')));
}
int cal(int x,int y,char z)
{
    switch (z){
        case '+':
            return num[x]+num[y];
        case'-':
            return num[y]-num[x];
        case '*':
            return num[x]*num[y];
        case '/':
            return num[y]/num[x];
    }
}
int main ()
{
    char y[N],s[N];
    gets(y); // @@ gets() is unsafe and deprecated; may cause buffer overflow
    int l=0;
    for(int i=0;y[i]!='=';i++)
    if(y[i]!=' ')
    s[l++]=y[i];
    s[l]='\0';
    
    //用堆栈的形式把中缀表达式转成后缀表达式op
    int i,j;
    int cnt=1;//记录数字数组的下标 
    int tmp=0; 
    for( i=0,j=0;s[i];i++)
    {
        tmp=0;
        while(check(s[i]))
        tmp=tmp*10+s[i++]-'0';
        num[cnt]=tmp;
        
        op[j++]=-cnt;
        cnt++;
        if(!s[i]){
            break;
        }
        //加入符号 
        //判断栈是否为空
            if(top==-1) 
            stack[++top]=s[i];
            else if(ispri(stack[top],s[i]))//s[i]比stack[top]大，s[i]压栈 
            {
                //判断优先级并决定是否入栈
                 stack[++top]=s[i];
            }
            else//优先级<=a，里面的先出栈，再把后面的入栈
            {
                while(!ispri(stack[top],s[i])&&top>=0)//一直比较  // @@ order of conditions: top>=0 should be first to avoid accessing stack[-1]
                {
                op[j++]=stack[top--];      //printf("&");
                } 
                 stack[++top]=s[i];
             } //printf("%c ",stack[top]);
     } 
     while(top>=0)//把最后栈内的符号输出 
     {
         op[j++]=stack[top--];
      } 
     op[j]='\0';
     
     //for(int i=0;op[i];i++)
     //printf("%c",op[i]);
     //开始计算
     //int ans=0;
     
     stack1[++top1]=op[0];
     for(int k=1;op[k];k++)
     {
         if(op[k]<0)
         stack1[++top1]=op[k]; // @@ op[k] is int, but stack1 is char; truncation may occur
         else
         {
            int x=-stack1[top1--];
             int y=-stack1[top1--];
             int tmp=cal(x,y,op[k]);
             num[cnt]=tmp;
             stack1[++top1]=-cnt;
             cnt++;
             }
             //printf("%d\n",tmp);
         //printf("%c ",stack1[top1]);
         //printf("%d \n",num[stack1[top1]-'0']);
      } 
      printf("%d\n",tmp);
      return 0;
}