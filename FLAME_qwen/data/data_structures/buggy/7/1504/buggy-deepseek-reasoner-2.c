#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct node{
        int num;
        int high;
        struct node* small,*big;
    };
   
int main(){
    struct node*front,*p,*q,*q2;
    int hight,tmp;
    front=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&tmp); // @@ [Error: The first integer read is n (number of nodes), not a node value. This incorrectly treats n as root node value.]
    front->num=tmp;
    front->high=1;
    front->small=NULL;
    front->big=NULL;
    while(scanf("%d",&tmp)!=EOF){ // @@ [Error: The loop should read exactly n nodes after reading n, not read until EOF. This causes the tree to be built from wrong data.]
        hight=1;
        p=(struct node*)malloc(sizeof(struct node));
        p->num=tmp;
        p->small=NULL;
        p->big=NULL;
        q=front;
        q2=front;
        while(q!=NULL){
            if(p->num<q->num){
                q2=q;
                q=q->small;
                hight++;
            }
            else{
                q2=q;
                q=q->big;
                hight++;
            }
        }
        p->high=hight;
        if(p->num<q2->num)
        q2->small=p;
        else
        q2->big=p;
    }
    popnums(front); // @@ [Error: Function 'popnums' is not declared before its use; implicit declaration causes compilation error in C99+.]
    deletree(front); // @@ [Error: Function 'deletree' is not declared before its use; implicit declaration causes compilation error.]
    return 0;
}
void deletree(struct node*s)
{
    if(s!=NULL)
    {   if(s->small!=NULL)
        deletree(s->small);
        free(s); // @@ [Error: Use after free – accessing s->big on the next line after freeing s. Should free children before freeing the node.]
        if(s->big!=NULL)
        deletree(s->big);
    }
}
 void popnums(struct node* s)
{
    if(s!=NULL)
    {
        if(s->small==NULL&&s->big==NULL)
            printf("%d %d\n",s->num,s->high);
        if(s->small!=NULL)
        popnums(s->small);
        if(s->big!=NULL)
        popnums(s->big);
    }
}