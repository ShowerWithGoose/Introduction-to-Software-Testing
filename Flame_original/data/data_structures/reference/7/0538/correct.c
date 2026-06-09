#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct node
{
    int num;
    struct node *l,*r;
};
struct node *start=NULL;
struct node *now=NULL;

struct node *newNode(struct node *now,int num,int lr){
    if(now!=NULL){
        if(lr==0) now=now->l;
        else now=now->r;
    }
    now=(struct node *)malloc(sizeof(struct node*));
    now->num=num;now->l=now->r=NULL;
    return now;
}

void insert(int n){
    if(now==NULL) start=newNode(now,n,-1);
    else if(now->num<=n){
        if(now->r!=NULL) {now=now->r;insert(n);}
        else now->r=newNode(now,n,1);
    }
    else{
        if(now->l!=NULL){now=now->l;insert(n);}
        else now->l=newNode(now,n,0);
    }
    return;
}
void print(struct node *now,int depth){
    if(now->l!=NULL)
        print(now->l,depth+1);
    if(now->r!=NULL)
        print(now->r,depth+1);
    if(now->l==NULL && now->r==NULL)
        printf("%d %d\n",now->num,depth);
}
int main(){
    now=start;
    int n,tmp;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&tmp);
        now=start;
        insert(tmp);
    }
    print(start,1);
    return 0;
}
