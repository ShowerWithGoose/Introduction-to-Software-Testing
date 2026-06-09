#include <stdio.h>
#include <ctype.h>
#include <string.h>
int num[256];
int num1=-1;
int op[256];
int bbac1=-1;

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

int cal(int tmp1, int tmp2, int opp){
    int val;
    switch (opp)
    {
    case '+':
        val=tmp1+tmp2;
        break;
    case '-':
        val=tmp1-tmp2;
        break;
    case '*':
        val=tmp1*tmp2;
        break;
    case '/':
        val=tmp1/tmp2;
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
    int ch,abac,tmp1,tmp2,opp,result;
    while ((ch=getchar())==' ');
    push(op,&bbac1,'=');
    while (ch!='='||gettop(op,bbac1)!='=')
    {
        if (isdigit(ch))
        {
            abac=ch-'0';
            while (isdigit((ch=getchar())))
            {
                abac=abac*10+ch-'0';
            }
            push(num,&num1,abac);
        }else if(ch==' '){
            ch=getchar();
            continue;
        }else{
            switch (cmp(ch,gettop(op,bbac1)))
            {
            case 1:
                push(op,&bbac1,ch);
                ch=getchar();
                break;
            case 0:
                pop(op,&bbac1,&opp);
                pop(num,&num1,&tmp2);
                pop(num,&num1,&tmp1);
                result=cal(tmp1,tmp2,opp);
                push(num,&num1,result);
                break;
            }
        }
    }
    printf("%d",gettop(num,num1));
    return 0;
}


