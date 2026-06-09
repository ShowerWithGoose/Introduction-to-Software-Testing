#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
typedef struct cacul{
    int num;
    char fuhao;
    struct cacul *next;
}cacu;//???
int caculate(int operand1,int operand2,char operator);
void link(cacu **p_head,cacu *p_new);
void squeeze(char s[],char c);
char s[10086];
int main(){
    int a=0,sum=0;
    cacu *head=NULL,*p_new=NULL,*p_mov;
    gets(s); // @@ [Using `gets` is unsafe and deprecated; however, the real issue is that the last number before '=' is never added to the linked list because the loop only adds a number when encountering a non-digit (i.e., an operator or '='), but after reading the last number, the loop ends without storing it.]
    squeeze(s,' ');
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='0'&&s[i]<='9'){
            a=a*10+s[i]-'0';
        }else{
            p_new=(cacu*)malloc(sizeof(cacu));
            p_new->fuhao=s[i];
            p_new->num=a;
            link(&head,p_new);
            a=0;
        }
    }
    p_mov=head;
    while(p_mov!=NULL){
        if(p_mov->fuhao=='*'||p_mov->fuhao=='/'){
            p_mov->num=caculate(p_mov->num,p_mov->next->num,p_mov->fuhao); // @@ [If `p_mov->next` is NULL (e.g., last element is '*' or '/'), this dereferences a null pointer, causing undefined behavior. Also, the last number is missing, so the list structure is incorrect.]
            p_mov->fuhao=p_mov->next->fuhao;
            p_mov->next=p_mov->next->next;
        }else{
            p_mov=p_mov->next;
        }
    }
    p_mov=head;
    while(p_mov!=NULL){
        p_mov->num=caculate(p_mov->num,p_mov->next->num,p_mov->fuhao); // @@ [Same issue: `p_mov->next` may be NULL, especially since the final '=' is stored as an operator, and there's no number after it. Also, the last operand is never added to the list, so the expression is incomplete.]
        p_mov->fuhao=p_mov->next->fuhao;
        p_mov->next=p_mov->next->next;
    }
    printf("%d",p_mov->num); // @@ [At this point, `p_mov` is NULL because the previous loop exits when `p_mov` becomes NULL, so dereferencing `p_mov->num` is invalid and leads to undefined behavior (likely segmentation fault).]
    return 0;
}
void link(cacu **p_head,cacu *p_new){//为什么用双重指针：因为要改变某个量必须传递某个量的指针到函数中
    cacu *p_mov=*p_head;//这一步是为了在else里不改变head的情况下历遍到尾
    if(*p_head==NULL){
        *p_head=p_new;
    }else{
        while(p_mov->next!=NULL){//（首先检查head是不是后面还有节点）这一步是为了从头历遍链表到尾部，因为头部不变
            p_mov=p_mov->next;
        }
        p_mov->next=p_new;
    }
    p_new->next=NULL;//给个表头只能链接一个链表单元
}
void squeeze(char s[],char c){
    //c为字符变量
    int i,j;
    for(i=j=0;s[i]!='\0';i++){
        if(s[i]!=c){
            s[j++]=s[i];
        }
    }
    s[j]='\0';
}
int caculate(int operand1,int operand2,char operator){
    switch(operator){
        case '+':
            return operand1+operand2;
        case '-':
            return operand1-operand2;
        case '*':
            return operand1*operand2;
        case '/':
            return operand1/operand2;
    }
}