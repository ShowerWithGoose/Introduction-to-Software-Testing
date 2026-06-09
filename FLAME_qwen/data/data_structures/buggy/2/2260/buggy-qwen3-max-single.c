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
void push(stack *p,int new){ // @@ 'new' is a keyword in C++ and may cause issues with some compilers or strict C standards; better to use a different identifier like 'value'
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
    gets(a); // @@ 'gets' is unsafe and deprecated; it can cause buffer overflow. Use 'fgets' instead.
    int len=strlen(a);
    int j=0;
    for(int i=0;i<len;i++){
        if(a[i]!=' '&&a[i]!='='){
            temp[j]=a[i];j++;
        }
    }
    j=0;
    for(int i=0;i<len;i++){ // @@ This loop uses 'len' (original string length) but should iterate over 'strlen(temp)' or up to 'j' since 'temp' may be shorter
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
    stack *sss=(stack*)malloc(sizeof(stack)); // @@ Missing check for malloc failure (though not causing compilation error, it's unsafe)
    init(sss);
    int ll=strlen(temp); // @@ 'll' is unused
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
                while(issign(sss->data[sss->top])&&(num(tt[i])<=num(sss->data[sss->top]))){ // @@ If stack becomes empty during popping, accessing sss->data[sss->top] will be invalid
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
    stack *fff=(stack*)malloc(sizeof(stack)); // @@ Missing check for malloc failure
    init(fff);
    for(int i=0;i<j;i++){
        if(!issign(reverse[i])){
            push(fff,reverse[i]);
        }
        else{
            int a=pop(fff);
            int b=pop(fff); // @@ If expression starts with unary minus or has insufficient operands, this will pop from empty stack
            int c=a;int d=b;
            int eee;
            if(reverse[i]==-1)eee=c+d;
            else if(reverse[i]==-2)eee=d-c; // @@ Order of operands is swapped: should be b - a, but here it's d - c = b - a which is correct for postfix? Wait: in postfix, for "a b -", it's a - b, but we popped a then b, so b is first operand, a is second -> should be b - a? Actually standard is: pop right operand first, then left. So for "5 3 -", pop 3, then 5, compute 5 - 3. But here: a = pop() = 3, b = pop() = 5, then eee = d - c = 5 - 3 → correct. So this line is actually OK.
            else if(reverse[i]==-4)eee=d/c; // @@ Same as above: d / c = b / a → correct order
            else if(reverse[i]==-3)eee=c*d; // @@ Multiplication is commutative, so order doesn't matter
            int e=eee;
            push(fff,e);
        }
    }
    int final=pop(fff);
    printf("%d\n",final);
    return 0;
}