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
    scanf("%d",&tmp);
    front->num=tmp; // @@ The first integer read is the count of numbers (n), not the value of the root node. It should read the next integer for the root value.
    front->high=1;
    front->small=NULL;
    front->big=NULL;
    while(scanf("%d",&tmp)!=EOF){ // @@ The loop condition reads until EOF, but the problem specifies reading exactly n integers. Also, if n=1, this loop might not execute or execute incorrectly depending on input format, but the primary issue is the root initialization above. If n=1, there are no more numbers to read, so this loop body shouldn't run for data insertion. However, since the root was set to 'n' (1 in the test case), and no other nodes are inserted, the tree only has the root.
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
    popnums(front);
    deletree(front);
    return 0;
}
void deletree(struct node*s)
{
    if(s!=NULL)
    {   if(s->small!=NULL)
        deletree(s->small);
        free(s);
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