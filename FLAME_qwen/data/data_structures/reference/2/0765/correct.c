#include<stdio.h>
#define M 200
typedef struct node
{
    int num;
    int flag;
}node;
int cmp(char get ,char tp);
int change(char *s ,node Prestack[],int *ptop);
int main()
{
    char s[M]={0};
    node Press[M];
    double stack[M]={0};
    int i,ptop=-1,top=-1;
    gets(s);
    change(s,Press,&ptop);
    /*for(i=0;i<=ptop;i++)
    {
        if(Press[i].flag==0)
        printf("%c",Press[i].num);
        else
        printf("%c",Press[i].num);
    }
    printf("\n");*///后缀表达式输出
    for(i=0;i<=ptop;i++)
    {
        if(Press[i].flag==0)//运算对象
        {
            top++;
            stack[top]=(double)Press[i].num;
        }
        else
        {
            double a=stack[top--];
            double b=stack[top--];
            double tmp=0;
            switch (Press[i].num)
            {
            case '+': tmp=b+a; break;
            case '-': tmp=b-a; break;
            case '*': tmp=b*a; break;
            case '/': tmp=b/a; break;
            }
            top++;
            stack[top]=tmp;
        }
    }
    printf("%d",(int)stack[top]);
    return 0;
}
int cmp(char get ,char tp)//0时，进栈
{
    if(get=='+'||get=='-')
    {
        switch (tp)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case ')':return 1;
        default:return 0;
        }
    }
    else if(get=='*'||get=='/')
    {
        switch (tp)
        {
        case '*':
        case '/':
        case ')': return 1;
        default: return 0;
        }
    }
    else if(get=='(')
    return 0;
    else if(get==')')
    return 1;
    else //'='
    return 1;
}
int change(char *s ,node Prestack[],int *ptop)
{
    int i=0,top=0;
    char stack[M];
    stack[0]='=';
    //stack里只有运算符号
    while(1)
    {
//        x=s[i];
        if(s[i]=='=')
        {
            while(top>0)
            {
                if(*ptop==M-1)
                return 0;
                else
                {
                    *ptop=*ptop+1;
                    Prestack[*ptop].flag=1;
                    Prestack[*ptop].num=stack[top];
                    top--;
                }
            }
            return 1;
        }
        else if(s[i]==')')
        {
            while(stack[top]!='(')
            {
                *ptop=*ptop+1;
                Prestack[*ptop].flag=1;
                Prestack[*ptop].num=stack[top];
                top--;
            }
            top--;
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='(')
        {
            while(cmp(s[i],stack[top])>0)
            {
                *ptop=*ptop+1;
                Prestack[*ptop].flag=1;
                Prestack[*ptop].num=stack[top];
                top--;
            }
            top++;
            stack[top]=s[i];
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            int mid=s[i]-48;
            while(s[i+1]>='0'&&s[i+1]<='9')
            {
                mid=mid*10+(s[i+1]-48);
                i++;
            }
            *ptop=*ptop+1;
            Prestack[*ptop].flag=0;
            Prestack[*ptop].num=mid;
        }
        i++;
    }
}
