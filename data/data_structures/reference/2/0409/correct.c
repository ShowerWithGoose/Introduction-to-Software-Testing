#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100
double num_stack[MAXSIZE];    //数据栈
int Ntop = -1;
char op_stack[MAXSIZE];     //运算符栈
int Otop = -1;
void pushNum(int data)   //压入数据
{
    num_stack[++Ntop] = data;
}
int popNum()            //弹出数据
{
    return num_stack[Ntop--];
}
void pushOp(char data)    //压入数据
{
    op_stack[++Otop] = data;
}
char popOp()            //弹出运算符
{
    return op_stack[Otop--];
}
union sym
{
    int num;
    char op;
};
int pri(char op)
{
    if(op == '+'||op == '-')
        return 1;
    if(op == '*'||op == '/')
        return 2;
    if(op == '('||op == ')')
        return 3;
    return 0;
}
int getformular(union sym *item)
{
    char c;
    int n=0;
    while((c = getchar()) != '=')
    {
        if(c >= '0' &&c <= '9')
        {
            for(n = 0;c >= '0' && c <= '9';c = getchar())
                n = n * 10 + c -'0';
            ungetc(c,stdin);
            item -> num = n;
            return 1;
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
        {
            item -> op = c;
            return 2;
        }
    }
    return 0;
}
void doMath( char op )
{
    char t;
    if(op!=')')
    {
        //if( Otop == -1 )
            //pushOp(op);
        //else
        //{
            while( pri( op ) <= pri( op_stack[Otop] ) && op_stack[Otop] != '(' )
                calculate( popOp() );
                pushOp( op );
        //}
    }
    else
        while(( t = popOp() )!='(')
            calculate(t);




}
void calculate(char op)
{
    int tmp;
    switch(op)
    {
        case '+':
            pushNum( popNum() + popNum() ); break;
        case '-':
            tmp = popNum();
            pushNum( popNum() - tmp ); break;
        case '*':
            pushNum( popNum() * popNum() ); break;
        case '/':
            tmp = popNum();
            pushNum( popNum() / tmp ); break;
    }
}
union sym item;
int main()
{
    int flag;
    while((flag = getformular( &item )) != 0)
    {
        if(flag == 1)
            pushNum( item.num );
        else if(flag == 2)
            doMath( item.op );
    }
    //printf("%d",Otop);
    while(Otop >= 0)
        calculate( popOp() );
        //printf("%c",popOp());

    //if(Ntop == 0)
        printf("%d",popNum());
    return 0;
}


