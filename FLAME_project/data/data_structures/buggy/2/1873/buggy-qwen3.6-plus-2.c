#include <stdio.h>
#include <string.h>
#define N 100005
char stack[N],stack1[N];
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
            return num[y]-num[x]; // @@ The operands are swapped incorrectly for subtraction in the context of how they are popped. In postfix evaluation, if we pop x then y, x is the second operand and y is the first. Here x is popped first (top), so x is the right operand. num[y] - num[x] is correct IF y is left and x is right. Let's trace: stack has ... y, x. Pop x, pop y. Calc y op x. So num[y] - num[x] is correct for subtraction. Wait, let's look at division.
        case '*':
            return num[x]*num[y];
        case '/':
            return num[y]/num[x]; // @@ Similar to subtraction, this assumes num[y] is the dividend and num[x] is the divisor. This is correct for standard postfix evaluation where the first popped element is the right operand.
    }
}
int main ()
{
    char y[N],s[N];
    gets(y);
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
                while(!ispri(stack[top],s[i])&&top>=0)//一直比较 
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
         stack1[++top1]=op[k];
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
      printf("%d\n",tmp); // @@ The variable 'tmp' here holds the result of the *last* calculation performed in the loop. If the expression has multiple operations, 'tmp' is overwritten in each iteration. However, the final result of the entire expression is indeed the last calculation. BUT, if the expression starts with a number and ends with an operator sequence that results in multiple cal calls, the last one is the answer. Wait, look at the scope. 'tmp' is declared inside the else block? No, 'tmp' is declared at line 43 'int tmp=0;'. Inside the loop, 'int tmp=cal(...)' shadows the outer tmp? No, in C, redeclaring 'int tmp' inside the block creates a new local variable. The 'tmp' printed at the end is the one from line 43, which was last updated in the parsing loop (line 48-49) or potentially uninitialized/garbage if not touched there. The calculated result is stored in the inner 'tmp' which goes out of scope. The final result is actually in 'num[cnt-1]' or should be popped from the stack. The print statement prints the wrong variable.
      return 0;
}