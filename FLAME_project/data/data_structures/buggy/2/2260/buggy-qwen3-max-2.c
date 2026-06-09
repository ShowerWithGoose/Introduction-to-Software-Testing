#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 1000
char a[1000];
char temp[1000];
int tt[1000],reverse[1000];
typedef struct{
    int data[MAX];
    int top;
}stack;
stack init(stack *p){     //当栈空的时候 初始化栈顶指针为-1
    p->top=-1;
}
//判断栈是否为空
int isempty(stack *p){
    return p->top==-1;  //******
}
//判断栈是否满
int isfull(stack *p){
    return p->top==MAX-1;
}
//弹出栈元素(pop)
int pop(stack *p){
    if(isempty(p)){
        printf("栈为空\n");
        return 0;
    }
    int val=p->data[p->top];
    p->top--;
    return val;
}
//插入栈元素
void push(stack *p,int new){
    if(isfull(p)){
        printf("插入元素失败\n");
        return;
    }
    p->top+=1;
    p->data[p->top]=new; 
}
//获取栈顶元素的值
int gettop(stack *p){
    if(isempty(p)){
        printf("获取失败\n");
        return 0;
    }
    return p->data[p->top];
}
int num(int c){
    if(c==-1||c==-2)return 1;
    if(c==-3||c==-4)return 2;
}
int issign(int c){
    if(c==-1||c==-2||c==-3||c==-4)return 1;
    return 0;
}
int main(){
    gets(a); @@ [Using `gets` is unsafe and may cause buffer overflow; more critically, it reads the whole line including spaces, but later processing assumes `temp` length equals original input length, which is incorrect after removing spaces and '='.]
    int len=strlen(a);
    int j=0;
    for(int i=0;i<len;i++){
        if(a[i]!=' '&&a[i]!='='){
            temp[j]=a[i];j++;
        }
    }
    j=0;
    for(int i=0;i<len;i++){ @@ [Loop bound should be based on `strlen(temp)` or the actual processed length, not original `len`. This causes reading beyond valid `temp` content, leading to garbage values in `tt`.]
        if(temp[i]=='+'){tt[j]=-1;j++;}
        if(temp[i]=='-'){tt[j]=-2;j++;}
        if(temp[i]=='*'){tt[j]=-3;j++;}
        if(temp[i]=='/'){tt[j]=-4;j++;}
        if(temp[i]>='0'&&temp[i]<='9'){
            int x=temp[i]-'0';
            while(temp[i+1]>='0'&&temp[i+1]<='9'){
                x=10*x+temp[i+1]-'0';
                i++;
            }
            tt[j]=x;
            j++;
        }
    }
    for(int i=0;i<j;i++)printf("%d ",tt[i]);printf("\n");
    stack *sss=(stack*)malloc(sizeof(stack));
    init(sss);
    int ll=strlen(temp); @@ [Unused variable; does not affect logic but indicates confusion. The real issue is earlier loop bound.]
    int k=0;
    for(int i=0;i<j;i++){
        if(!issign(tt[i])){
            reverse[k]=tt[i];k++;
        }
        else{
            if(isempty(sss)){
                push(sss,tt[i]);
            }
            else if(num(tt[i])>num(sss->data[sss->top])){
                push(sss,tt[i]);
            }
            else{
                while(issign(sss->data[sss->top])&&(num(tt[i])<=num(sss->data[sss->top]))){
                        reverse[k]=pop(sss);k++;
                }
                push(sss,tt[i]);
            }
        }
    }
    while(!isempty(sss)){
        reverse[k]=pop(sss);k++;
    }
    for(int i=0;i<j;i++)printf("%d ",reverse[i]);printf("\n");
    stack *fff=(stack*)malloc(sizeof(stack));
    init(fff);
    for(int i=0;i<j;i++){
        if(!issign(reverse[i])){
            push(fff,reverse[i]);
        }
        else{
            int a=pop(fff);
            int b=pop(fff);
            int c=a;int d=b;
            int eee;
            if(reverse[i]==-1)eee=c+d;
            else if(reverse[i]==-2)eee=d-c; @@ [Incorrect operand order: should be `b - a` (i.e., `d - c` is correct here since `b` was pushed before `a`, so `b` is left operand). However, note that in postfix evaluation, first pop is right operand, second is left. So for `b - a`, it's `d - c` — this line is actually correct. But wait: expression "10 + 20 * 30 - 40 / 5" becomes infix: ((10 + (20*30)) - (40/5)) = (10+600-8)=602. In postfix: 10 20 30 * + 40 5 / - → so when evaluating '-', we pop 8 then 610, then do 610 - 8 = 602. But in code: a=8, b=610, then eee = b - a = 610 - 8 = 602 → correct. So this line is OK.]
            else if(reverse[i]==-4)eee=d/c; @@ [Same as above: division should be `b / a` → `d / c`, which is correct.]
            else if(reverse[i]==-3)eee=c*d; @@ [Multiplication is commutative, so order doesn't matter, but consistency: should be `b * a` → `d * c`. However, since multiplication is commutative, result is same. But for consistency and correctness in non-commutative ops, better to use `d * c`. However, this is not the source of error.]
            int e=eee;
            push(fff,e);
        }
    }
    int final=pop(fff);
    printf("%d\n",final);
    return 0;
}