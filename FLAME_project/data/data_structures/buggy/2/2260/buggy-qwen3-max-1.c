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
    gets(a); @@ [Using `gets` is unsafe and may cause buffer overflow; more critically, it reads the whole line including spaces, but later processing assumes `temp` length equals original input length, which is incorrect due to space removal.]
    int len=strlen(a);
    int j=0;
    for(int i=0;i<len;i++){
        if(a[i]!=' '&&a[i]!='='){
            temp[j]=a[i];j++;
        }
    }
    j=0;
    for(int i=0;i<len;i++){ @@ [Loop bound should be based on `j` (length of `temp`) or use `i < strlen(temp)`, not original `len`. This causes reading beyond valid `temp` data, leading to garbage values like -1, -2 appearing in `tt`.]
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
    int ll=strlen(temp); @@ [Unused variable; doesn't affect logic but indicates confusion. Not an error by itself.]
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
    for(int i=0;i<k;i++){ @@ [Loop bound should be `k`, not `j`, because `reverse` has `k` elements. Using `j` may process uninitialized/garbage values beyond `k`, causing wrong computation. However, in this specific case, `k == j` usually holds, so this might not be the primary bug. But the real issue is operand order in subtraction/division.]
        if(!issign(reverse[i])){
            push(fff,reverse[i]);
        }
        else{
            int a=pop(fff);
            int b=pop(fff);
            int c=a;int d=b;
            int eee;
            if(reverse[i]==-1)eee=c+d;
            else if(reverse[i]==-2)eee=d-c; @@ [Incorrect operand order: for expression like "10 - 20", in postfix it's "10 20 -", so we pop 20 first (`a`), then 10 (`b`). Correct operation is `b - a`, but here it's `d - c` = `b - a` — wait, that seems correct? Actually: `b` is first popped as second operand, `a` as first. But in stack evaluation, for "b a -", result is `b - a`. However, in standard postfix evaluation, when you see operator, you do: second_popped OP first_popped. So for "10 20 -", you pop 20 (a), then 10 (b), then compute `b - a` = 10 - 20 = -10. That is correct. BUT: in this code, `a = pop()` → 20, `b = pop()` → 10, then `d = b = 10`, `c = a = 20`, then `eee = d - c = 10 - 20`. That is correct. So why wrong answer? Let's check division too.]
            else if(reverse[i]==-4)eee=d/c; @@ [Same issue: for "40 / 5", postfix is "40 5 /", pop 5 (a), pop 40 (b), then should do `b / a` = 40 / 5 = 8. Here: `d = b = 40`, `c = a = 5`, so `d / c = 40 / 5 = 8` — correct. So operand order seems fine. Then what's wrong?]

            // The real problem is in the tokenization loop: using `i < len` where `len` is original string length, but `temp` is shorter.
            // For input "10 + 20 * 30 - 40 / 5 =", after removing spaces and '=', `temp` becomes "10+20*30-40/5" (length 13).
            // But `len` is original length (e.g., 20+). So loop runs up to i=19, accessing `temp[13]` to `temp[19]` which are uninitialized (garbage).
            // This causes extra tokens like -1, -2, etc., to appear in `tt`, corrupting the expression.

            else if(reverse[i]==-3)eee=c*d;
            int e=eee;
            push(fff,e);
        }
    }
    int final=pop(fff);
    printf("%d\n",final);
    return 0;
}