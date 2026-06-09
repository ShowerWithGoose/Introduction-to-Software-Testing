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
    // The last number is not added to the linked list because the loop only adds a node when an operator is encountered.
    // The input ends with '=', which is treated as an operator in the loop condition check implicitly by falling through, 
    // but actually the loop stops at '=' or processes it? 
    // Let's trace: "10+20*30-40/5="
    // After squeeze: "10+20*30-40/5="
    // i=0,1: '1','0' -> a=10
    // i=2: '+' -> create node(10, '+'), link. a=0.
    // i=3,4: '2','0' -> a=20
    // i=5: '*' -> create node(20, '*'), link. a=0.
    // ...
    // i=12: '5' -> a=5
    // i=13: '=' -> create node(5, '='), link. a=0.
    
    // So the linked list looks like:
    // Node1: num=10, fuhao='+', next -> Node2
    // Node2: num=20, fuhao='*', next -> Node3
    // Node3: num=30, fuhao='-', next -> Node4
    // Node4: num=40, fuhao='/', next -> Node5
    // Node5: num=5,  fuhao='=', next -> NULL
    
    // First pass: handle * and /
    // p_mov starts at head (Node1). fuhao is '+'. Skip. p_mov becomes Node2.
    // Node2: fuhao is '*'. 
    // Calculate Node2->num (20) op Node2->next->num (30). Result 600.
    // Node2->num becomes 600.
    // Node2->fuhao becomes Node2->next->fuhao ('-').
    // Node2->next becomes Node2->next->next (Node4).
    // List is now: Node1(10,+) -> Node2(600,-) -> Node4(40,/) -> Node5(5,=) -> NULL
    
    // p_mov is still Node2 (because we didn't advance p_mov in the if branch? No, we didn't change p_mov pointer itself, just the content).
    // Wait, the code says:
    // if(...){ ... } else { p_mov=p_mov->next; }
    // So after processing Node2, p_mov is still pointing to Node2.
    // Next iteration of while loop: p_mov is Node2. fuhao is '-'. Skip. p_mov becomes Node4.
    // Node4: fuhao is '/'.
    // Calculate Node4->num (40) op Node4->next->num (5). Result 8.
    // Node4->num becomes 8.
    // Node4->fuhao becomes Node4->next->fuhao ('=').
    // Node4->next becomes Node4->next->next (NULL).
    // List is now: Node1(10,+) -> Node2(600,-) -> Node4(8,=) -> NULL
    
    // p_mov is still Node4.
    // Next iteration: p_mov is Node4. fuhao is '='. Skip. p_mov becomes NULL.
    // Loop ends.
    
    // Second pass: handle + and -
    // p_mov = head (Node1).
    // Node1: fuhao is '+'.
    // Calculate Node1->num (10) op Node1->next->num (600). Result 610.
    // Node1->num becomes 610.
    // Node1->fuhao becomes Node1->next->fuhao ('-').
    // Node1->next becomes Node1->next->next (Node4).
    // List is now: Node1(610,-) -> Node4(8,=) -> NULL
    
    // p_mov is still Node1.
    // Next iteration: p_mov is Node1. fuhao is '-'.
    // Calculate Node1->num (610) op Node1->next->num (8). Result 602.
    // Node1->num becomes 602.
    // Node1->fuhao becomes Node1->next->fuhao ('=').
    // Node1->next becomes Node1->next->next (NULL).
    // List is now: Node1(602,=) -> NULL
    
    // p_mov is still Node1.
    // Next iteration: p_mov is Node1. fuhao is '='.
    // The condition `if(p_mov->fuhao=='*'||p_mov->fuhao=='/')` is false.
    // It goes to else? No, this is the second while loop.
    // The second while loop has NO if/else. It blindly executes:
    // p_mov->num=caculate(p_mov->num,p_mov->next->num,p_mov->fuhao);
    
    // Here lies the bug. In the second while loop, it does not check if p_mov->next is NULL.
    // When p_mov is Node1 (the last node remaining), p_mov->next is NULL.
    // Accessing p_mov->next->num causes a Segmentation Fault (Runtime Error).
    
    // Additionally, the logic assumes that the last node's operator is valid for calculation with a non-existent next node.
    // The loop should stop when there is only one node left (or when next is NULL).
    
    p_mov=head;
    while(p_mov!=NULL){
        p_mov->num=caculate(p_mov->num,p_mov->next->num,p_mov->fuhao); // @@ Runtime Error: Accesses p_mov->next->num when p_mov->next is NULL (at the last node). The loop should terminate when p_mov->next is NULL.
        p_mov->fuhao=p_mov->next->fuhao;
        p_mov->next=p_mov->next->next;
    }
    printf("%d",p_mov->num);
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