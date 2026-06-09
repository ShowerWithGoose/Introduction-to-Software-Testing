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
    gets(s);
    squeeze(s,' ');
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='0'&&s[i]<='9'){
            a=a*10+s[i]-'0';
        }else{
            p_new=(cacu*)malloc(sizeof(cacu));
            p_new->fuhao=s[i]; // @@ 错误：没有区分'=', 该字符应为输入结束标志，不应存入节点
            p_new->num=a;
            link(&head,p_new);
            a=0;
        }
    }
    p_mov=head;
    while(p_mov!=NULL){
        if(p_mov->fuhao=='*'||p_mov->fuhao=='/'){
            p_mov->num=caculate(p_mov->num,p_mov->next->num,p_mov->fuhao);
            p_mov->fuhao=p_mov->next->fuhao;
            p_mov->next=p_mov->next->next;
        }else{
            p_mov=p_mov->next;
        }
    }
    p_mov=head;
    while(p_mov!=NULL){
        p_mov->num=caculate(p_mov->num,p_mov->next->num,p_mov->fuhao); // @@ 错误：未检查p_mov->next是否为NULL，当p_mov指向最后一个节点时访问空指针
        p_mov->fuhao=p_mov->next->fuhao; // @@ 错误：同上，p_mov->next可能为NULL
        p_mov->next=p_mov->next->next; // @@ 错误：同上
        p_mov=p_mov->next;
    }
    printf("%d",p_mov->num); // @@ 错误：循环结束后p_mov可能为NULL，导致空指针访问
    return 0;
}
void link(cacu **p_head,cacu *p_new){
    cacu *p_mov=*p_head;
    if(*p_head==NULL){
        *p_head=p_new;
    }else{
        while(p_mov->next!=NULL){
            p_mov=p_mov->next;
        }
        p_mov->next=p_new;
    }
    p_new->next=NULL;
}
void squeeze(char s[],char c){
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