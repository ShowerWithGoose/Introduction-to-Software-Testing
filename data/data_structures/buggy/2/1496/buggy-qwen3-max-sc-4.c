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
    gets(s); // @@ [Using `gets` is unsafe and may cause compilation errors or warnings in modern compilers; it was removed in C11. Use `fgets` instead.]
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
            p_mov->num=caculate(p_mov->num,p_mov->next->num,p_mov->fuhao);
            p_mov->fuhao=p_mov->next->fuhao;
            p_mov->next=p_mov->next->next;
        }else{
            p_mov=p_mov->next;
        }
    }
    p_mov=head;
    while(p_mov!=NULL){
        p_mov->num=caculate(p_mov->num,p_mov->next->num,p_mov->fuhao); // @@ [Dereferencing `p_mov->next` without checking if it's NULL leads to undefined behavior when reaching the last node.]
        p_mov->fuhao=p_mov->next->fuhao; // @@ [Same issue: accessing `p_mov->next->fuhao` when `p_mov->next` might be NULL.]
        p_mov->next=p_mov->next->next; // @@ [Same issue: accessing `p_mov->next->next` when `p_mov->next` might be NULL.]
    }
    printf("%d",p_mov->num); // @@ [`p_mov` is NULL here because the loop condition exits when `p_mov` becomes NULL, so dereferencing it causes undefined behavior.]
    return 0;
}
void link(cacu **p_head,cacu *p_new){//why use double pointer: because to change a value you must pass its pointer to the function
    cacu *p_mov=*p_head;//this step is to traverse to the end without changing head in else clause
    if(*p_head==NULL){
        *p_head=p_new;
    }else{
        while(p_mov->next!=NULL){//(first check if head has next node) this step traverses from head to tail since head doesn't change
            p_mov=p_mov->next;
        }
        p_mov->next=p_new;
    }
    p_new->next=NULL;//a head can only link one list unit
}
void squeeze(char s[],char c){
    //c is a char variable
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