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
    front->num=tmp;
    front->high=1;
    front->small=NULL;
    front->big=NULL;
    while(scanf("%d",&tmp)!=EOF){
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
        p->high=hight; // @@ [The height is computed as the depth during insertion, but the root's height should be 1. However, for a single-node tree, this loop doesn't run, so hight remains 1 — which is correct. But the real issue is that the input reading logic is flawed: it reads n, then tries to read more integers until EOF, but the problem says there are exactly n integers on the next line. So for input "1\n5678", it reads 1 into tmp (as n), then tries to read more numbers until EOF — but there's only one number total. Thus, the while loop never runs, and only the root is created. However, the root is printed with height 1, so why output is 2? Wait — actually, in this code, after reading n=1, it sets front->num = 1 (not 5678)! That's the bug.]
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