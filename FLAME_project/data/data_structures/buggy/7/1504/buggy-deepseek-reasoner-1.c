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
    scanf("%d",&tmp); // @@ [Error: The first integer read is supposed to be the count 'n', but the program treats it as the first data value. For input '1\n5678', root becomes 1 instead of 5678. The height of root is 1, but the actual root should be 5678. The program then reads the next integer as a second node, resulting in an extra node and incorrect height for the leaf.]
    front->num=tmp; // @@ [Error: This sets the root's value to 'n' (the count), which is wrong. The count should not be stored in the tree; it should only be used to control the loop.]
    front->high=1;
    front->small=NULL;
    front->big=NULL;
    while(scanf("%d",&tmp)!=EOF){ // @@ [Error: This loop reads all remaining integers until EOF. For n=1, it reads one extra integer (5678) and builds a second node. Correct behavior is to read exactly 'n' integers, e.g., use 'for(int i=1;i<front->num;i++)' but note front->num is incorrect. Should handle count separately.]
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
        free(s); // @@ [Potential error: After freeing s, the code accesses s->big in the next line. This is undefined behavior. The free should be after both recursive calls or restructured.]
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