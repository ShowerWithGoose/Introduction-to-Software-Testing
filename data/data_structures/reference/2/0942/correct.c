#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
struct s{
    int num;
    char op;
    int flag;//1--num,0--op
}save[500];
int prior(char c){
    // -1,0,0,1,1,2,2
    // EPT,ADD,MIN,MUL,DIV,LEFT,RIGHT
    if(c=='=') return -1;
    else if(c=='+') return 0;
    else if(c=='-') return 0;
    else if(c=='*') return 1;
    else if(c=='/') return 1;
    else if(c=='(') return 2;
    else if(c==')') return 2;
}

struct Node{
    struct s data;
    struct Node *lchild,*rchild;
};
typedef struct Node node;
typedef struct Node* nodeptr;


int main()
{
    //part 1 转换为后缀表达式
    char stack[500];
    int s_top=0;
    int top=0;
    char c;
    while((c=getchar())!='='){
        int n;
        if(c>='0'&&c<='9'){
            for(n=0;c>='0'&&c<='9';c=getchar()){
                n=n*10+c-'0';
            }
            ungetc(c,stdin);
            save[top].num=n;
            save[top].flag=1;
            top++;
        }else if(c!=' '){
            if(c!=')'){
                while(s_top!=0&&prior(stack[s_top-1])>=prior(c)&&stack[s_top-1]!='('){
                    save[top].op=stack[--s_top];
                    save[top].flag=0;
                    top++;
                }
                stack[s_top++]=c;
            }else {
                char t;
                while((t=stack[--s_top])!='('){
                    save[top].op=t;
                    save[top].flag=0;
                    top++;
                }
            }
        }
    }
    while(s_top>0){
        save[top].op=stack[--s_top];
        save[top].flag=0;
        top++;
    }
    // for(int i=0;i<top;i++){
    //     if(save[i].flag==0)printf("%c",save[i].op);
    // }
    // return 0;
    int ans=0;
    int compute[500];
    int c_top=0;
    int a=0;
    node * treestack[500];
    int t_top=0;
    for(int i=0;i<top;i++){
        int tmp;
        if(save[i].flag){
            compute[c_top++]=save[i].num;
            nodeptr p = (nodeptr)malloc(sizeof(node));
            p->data.num=save[i].num;
            p->data.flag=1;
            p->lchild=p->rchild=NULL;
            // printf("now %d num is %d\n",t_top,p->data.num);
            treestack[t_top++]= p;
            }
        else {
            nodeptr t1 =(nodeptr)malloc(sizeof(node));
            nodeptr t2 =(nodeptr)malloc(sizeof(node));
            memcpy(t1,treestack[t_top-1],sizeof(node));
            treestack[t_top-1]=NULL;
            t_top--;
            memcpy(t2,treestack[t_top-1],sizeof(node));
            treestack[t_top-1]=NULL;
            t_top--;
            nodeptr q =(nodeptr)malloc(sizeof(node));
            q->data.flag=0;
            q->data.op=save[i].op;
            q->rchild=t1;
            q->lchild=t2;
            // printf("now %d op is %c\n",t_top,q->data.op);
            // printf("now is %c\n",q->data.op);
            // printf("now is %c\n",q->data.op);
            treestack[t_top++]=q;
            if(save[i].op=='+'){
                tmp=compute[--c_top];
                a=compute[--c_top]+tmp;
                compute[c_top++]=a;
            }else if(save[i].op=='-'){
                tmp=compute[--c_top];
                a=compute[--c_top]-tmp;
                compute[c_top++]=a;
            }else if(save[i].op=='*'){
                tmp=compute[--c_top];
                a=compute[--c_top]*tmp;
                compute[c_top++]=a;
            }else if(save[i].op=='/'){
                tmp=compute[--c_top];
                a=compute[--c_top]/tmp;
                compute[c_top++]=a;
            }
        }
    }
    ans=compute[0];
    nodeptr p=treestack[0];
    // printf("here %d",p->data.flag);
    // if(p!=NULL){
    //     if(p->data.flag==1) printf("%d",p->data.num);
    //     else printf("%c",p->data.op);
    //     putchar(' ');
    // }if(p->lchild!=NULL){
    //     if(p->lchild->data.flag==1) printf("%d",p->lchild->data.num);
    //     else printf("%c",p->lchild->data.op);
    //     putchar(' ');
    // }if(p->rchild!=NULL){
    //     if(p->rchild->data.flag==1) printf("%d",p->rchild->data.num);
    //     else printf("%c",p->rchild->data.op);
    //     putchar('\n');
    // }
    printf("%d",compute[0]);
    return 0;
}
