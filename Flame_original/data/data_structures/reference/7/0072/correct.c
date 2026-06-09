#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int num;
    char shendu;
    struct tree *llink,*rlink;
}*Nodeptr,node;
Nodeptr root=NULL;
Nodeptr p,q;
void xianxu(Nodeptr t); 
  int main(){
	int n,m;
	scanf("%d",&n);
    int i;
	for(i=0;i<n;i++){
	scanf("%d",&m);
   q=(Nodeptr)malloc(sizeof(node));
    q->num=m;
    q->llink=NULL;
    q->rlink=NULL;
    q->shendu=1;
    if(root==NULL)
        root=q;
    else{
        p=root;
    while(1)
        {
         if(m<p->num)
            {
        if(p->llink==NULL)
                {
                    q->shendu++;
                    p->llink=q;
                    break;
                }
        else{
                    q->shendu++;
                    p=p->llink;
                }
            }
     else if(m>=p->num)
          {
           if(p->rlink==NULL){
                    q->shendu++;
                    p->rlink=q;
                    break;
                }
            else{
                    q->shendu++;
                    p=p->rlink;
                }
            }
        }
    }
	}
	xianxu(root);
	return 0;	
}
void xianxu(Nodeptr t)
{
    if(t!=NULL)
    {
       if(t->llink!=NULL)
            xianxu(t->llink);
        if(t->rlink!=NULL)
            xianxu(t->rlink);
        if(t->llink==NULL&&t->rlink==NULL)
            printf("%d %d\n",t->num,t->shendu);
    }
}

