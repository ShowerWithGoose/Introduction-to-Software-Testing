#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
struct node
{
    long long num;
    long long index;
    struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;

Nodeptr insert(Nodeptr lisk,long long num,long long index)
{
    Nodeptr p=lisk,q=NULL,r=NULL;
    r=(Nodeptr)malloc(sizeof(Node));
    r->num=num;
    r->index=index;
    r->link=NULL;
    if(lisk==NULL)return r;
    for(p=lisk;p!=NULL&&p->index>index;q=p,p=p->link)
        ;
    if(p!=NULL&&p->index==index)p->num+=num;
    else if(p==lisk){
        r->link=p;
        return r;
    }
    else{
        q->link=r;
        r->link=p;
    }
    return lisk;
}
int print(Nodeptr lisk)
{
 if (lisk==NULL)
  return 0;
 Nodeptr p;
 for (p=lisk; p!=NULL;p=p->link)
 {
  if (p->num!= 0)
  {
   printf("%lld ", p->num);
   printf("%lld ", p->index);
  }
 }
 return 1;
}
int main()
{

    Nodeptr line=NULL,ans=NULL;
    long long num,index,tmp=20000000000;
    while(scanf("%lld%lld",&num,&index)!=EOF){

        if(tmp<=index){
        Nodeptr p=NULL;
        for(p=line;p!=NULL;p=p->link)ans=insert(ans,(p->num)*num,(p->index)+index);
        break;
        }

        line=insert(line,num,index);
        tmp=index;
    }
    while(scanf("%lld%lld",&num,&index)!=EOF){
        Nodeptr q=NULL;
        for(q=line;q!=NULL;q=q->link)ans=insert(ans,(q->num)*num,(q->index)+index);

    }

    print(ans);
    return 0;
}

