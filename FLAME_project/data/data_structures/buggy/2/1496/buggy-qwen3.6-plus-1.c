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
            p_new->fuhao=s[i];
            p_new->num=a;
            link(&head,p_new);
            a=0;
        }
    }
    // The last number is not added to the linked list in the loop above.
    // We need to add the final number node.
    p_new=(cacu*)malloc(sizeof(cacu));
    p_new->fuhao='='; // Use a dummy operator or handle differently
    p_new->num=a;
    link(&head,p_new);

    p_mov=head;
    while(p_mov!=NULL){
        if(p_mov->fuhao=='*'||p_mov->fuhao=='/'){
            // Check if next exists before accessing
            if (p_mov->next == NULL) break; 
            p_mov->num=caculate(p_mov->num,p_mov->next->num,p_mov->fuhao);
            p_mov->fuhao=p_mov->next->fuhao;
            p_mov->next=p_mov->next->next;
        }else{
            p_mov=p_mov->next;
        }
    }
    p_mov=head;
    // The second loop assumes there is always a next node and an operator.
    // It also fails to check for NULL pointers, leading to Runtime Error.
    while(p_mov!=NULL && p_mov->next != NULL){ // @@ Added check for p_mov->next != NULL to prevent dereferencing NULL pointer
        p_mov->num=caculate(p_mov->num,p_mov->next->num,p_mov->fuhao);
        p_mov->fuhao=p_mov->next->fuhao;
        p_mov->next=p_mov->next->next;
    }
    // p_mov might be NULL if the list was empty or became empty, but given valid input, head should exist.
    // However, after the loop, p_mov points to the last processed node.
    // If the list had only one number, the loop wouldn't run, and p_mov is head.
    // If the list had operations, p_mov advances.
    // Actually, the logic here is flawed because it modifies the list in place while traversing.
    // A safer way is to restart from head or use a different structure.
    // But sticking to the error location: The crash happens because p_mov->next is accessed without checking.
    
    // To correctly print the result, we should print the num of the first node remaining.
    printf("%d",head->num); // @@ Changed p_mov->num to head->num because p_mov may have advanced to NULL or incorrect position, while head always points to the start of the resulting single-node list (or first node). Also, previous line's loop condition fix ensures safety.
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
    return 0; // @@ Added default return to avoid undefined behavior if operator is not matched (e.g., the dummy '=' or garbage)
}