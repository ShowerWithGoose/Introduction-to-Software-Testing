#include <stdio.h>
#include <ctype.h>
#include <string.h>
int num[256];
int numtop=-1;
int op[256];
int optop=-1;

int ops[5]={'+','-','*','/','='};
int table[5][5]={
    {0,0,0,0,1},
    {0,0,0,0,1},
    {1,1,0,0,1},
    {1,1,0,0,1}
};

void push(int stack[], int *top, int ch){
    (*top)+=1;
    stack[*top]=ch;
    return;
}
void pop(int stack[], int *top, int *ch){
    *ch=stack[*top];
    (*top)-=1;
    return;
}

int gettop(int stack[], int top){
    return stack[top];
}

int cal(int x, int y, int opp){
    int val;
    switch (opp)
    {
    case '+':
        val=x+y;
        break;
    case '-':
        val=x-y;
        break;
    case '*':
        val=x*y;
        break;
    case '/':
        val=x/y;
        break;
    }
    return val;
}

int cmp(int op1,int op2){
    int i,j;
    for ( int q = 0; q < 5; q++)
    {
        if (op1==ops[q])
        {
            i=q;
        }
        if (op2==ops[q])
        {
            j=q;
        }
    }
    return table[i][j];
}

int main(){
    int ch,a,x,y,opp,result;
    while ((ch=getchar())==' ');
    push(op,&optop,'=');
    while (ch!='='||gettop(op,optop)!='=')
    {
        if (isdigit(ch))
        {
            a=ch-'0';
            while (isdigit((ch=getchar())))
            {
                a=a*10+ch-'0';
            }
            push(num,&numtop,a);
        }else if(ch==' '){
            ch=getchar();
            continue;
        }else{
            switch (cmp(ch,gettop(op,optop)))
            {
            case 1:
                push(op,&optop,ch);
                ch=getchar();
                break;
            case 0:
                pop(op,&optop,&opp);
                pop(num,&numtop,&y);
                pop(num,&numtop,&x);
                result=cal(x,y,opp);
                push(num,&numtop,result);
                break;
            }
        }
    }
    printf("%d",gettop(num,numtop));
    return 0;
}


