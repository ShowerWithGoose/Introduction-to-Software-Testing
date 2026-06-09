#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define maxN 200
char middle[maxN];
char op_stack[maxN];
int pos_op;
int num_stack[maxN];
int pos_num;

int is_empty();
int is_full();
void push(char x);
char pop();
char look();
void push_num(int x);
int pop_num();
int is_number(char x);
int cal(char op,int num1,int num2);
int get_pri(char x);

int main()
{
    pos_op=-1;
    pos_num=-1;
    int num1,num2;
    int cal_temp;
    char op;
    gets(middle);
    int len=strlen(middle);
    int i; 
    for(i=0;i<len;i++)
	{
        if(is_number(middle[i]))
		{
            int num=0;
            while(is_number(middle[i]))
			{
                num=num*10+middle[i]-'0';
                i++;
            }
            push_num(num);
        }
        if(middle[i]==' ') continue;
        if(middle[i]=='=') break;
        if(middle[i]==')'){
            while(1){
                op=pop();
                if(op=='(') break;
                num2=pop_num();
                num1=pop_num();
                cal_temp=cal(op,num1,num2);
                push_num(cal_temp);
            }
        }
        else{
            if(is_empty()){
                push(middle[i]);
                continue;
            }
            char stack_top=look();
            while(get_pri(stack_top)>=get_pri(middle[i])){
                if(stack_top=='(') break;
                op=pop();
                num2=pop_num();
                num1=pop_num();
                cal_temp=cal(op,num1,num2);
                push_num(cal_temp);
                if(is_empty()) break;
                stack_top=look();
            }
            push(middle[i]);
        }
    }
    while(!is_empty()){
        op=pop();
        num2=pop_num();
        num1=pop_num();
        cal_temp=cal(op,num1,num2);
        push_num(cal_temp);
    }
    int res=pop_num();
    
    printf("%d\n",res);
    return 0;
}

int is_empty()
{
    if(pos_op==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full()
{
    if(pos_op==maxN-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char x)
{
    op_stack[++pos_op]=x;
}

char pop()
{
    char res=op_stack[pos_op];
    op_stack[pos_op]='\0';
    pos_op--;
    return res;
}

char look()
{
    return op_stack[pos_op];
}

int is_number(char x)
{
    if(x>='0'&&x<='9') return 1;
    else return 0;
}

void push_num(int x)
{
    num_stack[++pos_num]=x;
}

int pop_num()
{
    int res=num_stack[pos_num];
    num_stack[pos_num]='\0';
    pos_num--;
    return res;
}

int cal(char op,int num1,int num2)
{
    switch(op){
        case '+':
            return num1+num2;
        case '-':
            return num1-num2;
        case '*':
            return num1*num2;
        case '/':
            return num1/num2;
        case '%':
            return num1%num2;
    }
}

int get_pri(char x)
{
    switch(x){
        case '+':
            return 0;
        case '-':
            return 0;
        case '*':
            return 1;
        case '/':
            return 1;
        case '%':
            return 1;
        case '(':
            return 2;
        case ')':
            return 2;
    }
}



