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
        p->high=hight;
        if(p->num<q2->num)
        q2->small=p;
        else
        q2->big=p;
    }
    popnums(front); // @@ [Implicit declaration of function 'popnums' - no prototype before use; in C99 and later this is a compilation error. Should declare before main or move definition before main.]
    deletree(front); // @@ [Implicit declaration of function 'deletree' - same issue as above. Also, function 'deletree' is defined after main without prototype.]
    return 0;
}
void deletree(struct node*s)
{
    if(s!=NULL)
    {   if(s->small!=NULL)
        deletree(s->small);
        free(s); // @@ [Use-after-free: after freeing 's', the code still accesses 's->big' on the next line. This is undefined behavior, though not a compilation error. However, ordering error: should delete right subtree before freeing current node.]
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