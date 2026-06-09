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
            return num[x]+num[y]; // @@ [Arguments x and y are indices into num[], but subtraction and division use reversed operand order: should be num[y] - num[x] and num[y] / num[x], but addition and multiplication are commutative so order doesn't matter. However, the bigger issue is that in postfix evaluation, the first popped operand is the right operand, and second is left. So for non-commutative ops like '-' and '/', it should be num[y] (left) op num[x] (right). But here, x is popped first (right), y second (left), so for '-', it should be num[y] - num[x], which is correct as written. However, note that in the call to cal(), arguments are passed as (x, y, op) where x is top (right operand), y is next (left operand). So this function is actually correct for '-', but incorrect for '+' and '*' because it uses num[x] + num[y] instead of num[y] + num[x]. But since + and * are commutative, it doesn't matter. So this line is not the main error.]
        case'-':
            return num[y]-num[x]; // @@ [This is correct: y is left operand, x is right operand.]
        case '*':
            return num[x]*num[y]; // @@ [Commutative, so order doesn't matter, but inconsistent with non-commutative ops. Not the main bug.]
        case '/':
            return num[y]/num[x]; // @@ [Correct: y is left, x is right.]
    }
}
int main ()
{
    char y[N],s[N];
    gets(y); // @@ [Using gets() is unsafe and may cause buffer overflow, but more importantly, the input includes '=' at the end, and the loop below stops at '=', which is correct. However, the main logic errors are elsewhere.]
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
        tmp=tmp*10+s[i++]-'0'; // @@ [After reading digits, i is incremented past the last digit. But the for-loop also increments i, so it skips the next character. This causes the operator after a multi-digit number to be skipped. For example, in "10+20", after reading '1','0', i points to '+', then i++ in for-loop makes it point to '2', skipping '+'. This is a critical error.]
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
             int tmp=cal(x,y,op[k]); // @@ [The variable 'tmp' here is local to the else block. The final printf uses the 'tmp' from the for-loop in the parsing phase, which is 0 after the loop ends (because the last number read leaves tmp as that number, but then the loop breaks and tmp is not updated for operators). So the final output is not the result of the expression but the leftover tmp from parsing, which for the test case "10 + 20 * 30 - 40 / 5 =" would be 5 (from the last number '5'). This is why the output is 5 instead of 602.]
             num[cnt]=tmp;
             stack1[++top1]=-cnt;
             cnt++;
             }
             //printf("%d\n",tmp);
         //printf("%c ",stack1[top1]);
         //printf("%d \n",num[stack1[top1]-'0']);
      } 
      printf("%d\n",tmp); // @@ [This prints the 'tmp' variable from the parsing loop, which is the last number parsed (5 in the test case), not the result of the expression evaluation. The result is stored in the stack1 and num arrays, but not printed. Should print the top of stack1 converted to actual value.]
      return 0;
}