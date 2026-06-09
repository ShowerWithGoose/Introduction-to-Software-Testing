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
    gets(s); // @@ [Using `gets()` is unsafe and may cause buffer overflow; more critically, it reads the entire line including the '=', but the parsing logic does not account for the '=' as a terminator properly. The loop processes every non-digit as an operator, so '=' will be treated as an operator, leading to invalid memory access later.]
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
            p_mov->num=caculate(p_mov->num,p_mov->next->num,p_mov->fuhao); // @@ [If `p_mov->next` is NULL (e.g., last node), this dereferences a null pointer, causing runtime error. The input ends with '=', which becomes the last node's fuhao, and there's no number after it, so the last node has no next node.]
            p_mov->fuhao=p_mov->next->fuhao;
            p_mov->next=p_mov->next->next;
        }else{
            p_mov=p_mov->next;
        }
    }
    p_mov=head;
    while(p_mov!=NULL){
        p_mov->num=caculate(p_mov->num,p_mov->next->num,p_mov->fuhao); // @@ [Same issue: when processing the last operator (which is '='), `p_mov->next` is NULL, leading to dereferencing NULL and runtime crash. Also, '=' is not a valid operator for `caculate()`.]
        p_mov->fuhao=p_mov->next->fuhao;
        p_mov->next=p_mov->next->next;
    }
    printf("%d",p_mov->num); // @@ [At this point, `p_mov` is NULL because the loop exits when `p_mov` becomes NULL, so accessing `p_mov->num` is invalid and causes runtime error.]
    return 0;
}
void link(cacu **p_head,cacu *p_new){//why use double pointer: because to change some value you must pass its pointer to function
    cacu *p_mov=*p_head;//this step is to traverse without changing head in else
    if(*p_head==NULL){
        *p_head=p_new;
    }else{
        while(p_mov->next!=NULL){//(first check if head has next node) this is to traverse from head to tail, since head doesn't change
            p_mov=p_mov->next;
        }
        p_mov->next=p_new;
    }
    p_new->next=NULL;//assigning head can only link one list unit
}
void squeeze(char s[],char c){
    //c is char variable
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