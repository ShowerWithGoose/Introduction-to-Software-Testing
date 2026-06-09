#include<stdio.h>

#define Datatype int
#define Typedata int

typedef struct BTNodeptr{
	Typedata data;
	struct BTNodeptr* lchild;
	struct BTNodeptr* rchild;
	
}*BTNodeptr;
BTNodeptr  Root=NULL; //全局变量
int n,s;
Datatype k[500004];


void  sortTree(Datatype k[ ], int n) ;
void  insertBST( Typedata item);
void  preorder(BTNodeptr t);
void  VISIT(BTNodeptr t);

int main()
{
	scanf("%d",&n);
	sortTree(k,n) ;
	preorder(Root);
	
	return 0;
}

void  sortTree(Datatype k[ ], int n) 
{
       int i;
       for(i=0; i<n; i++)
             {
             	
             	scanf("%d",&k[i]);
			insertBST(k[i]);
		   }
       return  ;
 }


void  insertBST( Typedata item)
{
      BTNodeptr p, q;
      p=(BTNodeptr)malloc(sizeof(BTNodeptr));
      p->data=item;
      p->lchild=NULL;
      p->rchild=NULL; 
      if(Root==NULL)
	    Root=p;
      else{
      	    q=Root;
              while(1)
                  /* 比较值的大小 */
                  /* 小于向左，大于向右 */
                if(item<q->data)  
			 {
                   if(q->lchild==NULL)
			    {
                    q->lchild=p;
                    break;
                   }
                   else
                    q=q->lchild;
                 }
                 else 
			  {
                    if(q->rchild==NULL)
		          {
                     q->rchild=p;
                     break;     
                    }
                    else
                     q=q->rchild;
                 }
          }
}

void  preorder(BTNodeptr t)
{
      
	 if(t!=NULL){
	 	   s++; 
             VISIT(t);    
		     /* 访问t指的结点  */
             preorder(t->lchild);
             preorder(t->rchild);
             s--;
       }
}

void  VISIT(BTNodeptr t)
{
	if(t->lchild==NULL&&t->rchild==NULL)
	{
		printf("%d %d\n",t->data,s);
	}
	
	return;
}

