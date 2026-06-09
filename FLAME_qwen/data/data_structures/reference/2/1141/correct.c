//用树实现表达式计算；
//栈；树的后序遍历；
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char sig[100];//符号栈
int stop = -1,ztop=-1;//符号栈顶,指针栈顶
struct node{//逆波兰表达式栈
    int num;
    char fuhao;
    struct node *link;
};
struct tree{//表达式二叉树
    int shuzi;
    char signal;
    struct tree *left, *right;
};
typedef struct tree *ptr;
typedef struct node *nodeptr;
typedef struct node *node;
ptr zhizhen[50];//树指针栈
nodeptr top, first = NULL;
int isempty()//判断表达式栈是否为空
{
    return top == NULL;
}
void numpush(int n)//数字入表达式栈
{
    nodeptr q;
    q=(nodeptr)malloc(sizeof(node));
    q->num = n;
    q->fuhao = 'n'; // nothing;
    q->link = NULL;
    if(first==NULL)
        first = top = q;
    else
    {
        top->link = q;
        top = top->link;
    }
}
void fuhaopush(char s)//符号入表达式栈
{
    nodeptr q;
    q=(nodeptr)malloc(sizeof(node));
    q->num = 20030129;
    q->fuhao = s; 
    q->link = NULL;
    if(first==NULL)
        first = top = q;
    else
    {
        top->link = q;
        top = top->link;
    }
}
int sisempty()//判断符号栈是否为空
{
    return stop == -1;
}
void spush(char s[],char i)//进入符号栈
{
        s[++stop] = i;
}
char spop(char s[])//弹出符号栈
{
        return s[stop--];
}
void ptrpush(ptr s[],ptr p)//进入指针栈
{
        s[++ztop] = p;
}
ptr ptrpop(ptr s[])//弹出指针栈
{
        return s[ztop--];
}
ptr creatree(ptr a,ptr b)
{
    ptr p;
    p = (struct tree *)malloc(sizeof(struct tree));
    p->shuzi = first->num;
    p->signal = first->fuhao;
    p->left = a;
    p->right = b;
    return p;
}
int cal(int x,int y,char c)
{
    switch(c)
    {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
    }
}
void serch(ptr p)
{
    if(p!=NULL)
    {
        serch(p->left);
        serch(p->right);
        if(p->shuzi==20030129)
        {
            p->shuzi = cal(p->left->shuzi, p->right->shuzi, p->signal);
        }
    }
}
int main()
{
    char c[200] = {};
    gets(c);
    for (int i = 0; i < strlen(c);i++)//转为后缀表达式
    {
        char ai[20]={};
        if(c[i]==' ')
            continue;
        else if(c[i]>='0'&&c[i]<='9')
        {
            int j = 0,number;
            for (;;i++)//将c中数字字符转成整型
            {
                ai[j] = c[i];
                if(c[i+1]>'9'||c[i+1]<'0')
                    break;
                else
                    j++;
            }
            number = atoi(ai);
            numpush(number);
        }
        else
        {
            int k = stop;
            if(c[i]=='(')
                spush(sig,c[i]);
            else if(c[i]=='+'||c[i]=='-')
            {
                for (; k >= 0;k--)
                {
                    if(sig[k]!='(')
                    {
                        fuhaopush(spop(sig));
                    }
                    else
                        break;
                }
                spush(sig, c[i]);
            }
            else if(c[i]=='*'||c[i]=='/')
            {
                for (; k >= 0;k--)
                {
                    if(sig[k]!='('&&sig[k]!='+'&&sig[k]!='-')
                    {
                        fuhaopush(spop(sig));
                    }
                    else
                        break;
                }
                spush(sig, c[i]);
            }
            else if(c[i]==')')
            {
                 for (; k >= 0;k--)
                {
                    if(sig[k]!='(')
                    {
                        fuhaopush(spop(sig));
                    }
                    else
                        break;
                }
                spop(sig);//弹出左括号；
            }
            else if(c[i]=='=')
            {
                while(stop!=-1)
                    fuhaopush(spop(sig));
                fuhaopush(c[i]);
                break;
            }
        }
    }
    ptr root=NULL;
        while (first->link != NULL)
        {
            ptr a=NULL, b=NULL;
            if(first->num!=20030129)
            {
                root = creatree(b, a);
                ptrpush(zhizhen,root);
            }
            else
            {
                a = ptrpop(zhizhen);
                b = ptrpop(zhizhen);
                root = creatree(b, a);
                ptrpush(zhizhen, root);
            }
            first = first->link;
        }
        
        serch(root);
        printf("%d", root->shuzi);
        return 0;
}
