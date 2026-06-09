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
    gets(s); // @@ [Using `gets` is unsafe and deprecated; however, the immediate error is not here. The real issue is that the last number before '=' is never added to the linked list because the loop only adds a number when encountering a non-digit (i.e., an operator or '='), but after adding, it resets `a=0`. However, the '=' triggers adding the last number, but then the code tries to process operators including '=', which is invalid. Also, the final result access is wrong.]
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
        p_mov->num=caculate(p_mov->num,p_mov->next->num,p_mov->fuhao);
        p_mov->fuhao=p_mov->next->fuhao;
        p_mov->next=p_mov->next->next;
    }
    printf("%d",p_mov->num); // @@ [At this point, `p_mov` is NULL because the previous while loop runs until `p_mov` becomes NULL. So dereferencing `p_mov->num` causes undefined behavior (likely segmentation fault). Also, the last number (after the final operator) is stored in the last node's `num`, but the loop structure assumes every node has a next node, which fails for the last node. Additionally, the '=' character is treated as an operator, leading to incorrect parsing.]
    return 0;
}
void link(cacu **p_head,cacu *p_new){//why use double pointer: because to change some value you must pass its pointer to the function
    cacu *p_mov=*p_head;//this step is to traverse to the end without changing head in else
    if(*p_head==NULL){
        *p_head=p_new;
    }else{
        while(p_mov->next!=NULL){//(first check if head has next nodes) this step traverses to the tail
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