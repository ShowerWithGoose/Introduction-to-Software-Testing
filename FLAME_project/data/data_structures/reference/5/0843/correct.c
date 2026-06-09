#include<stdio.h>
#include<malloc.h>
struct link{
    int k;
    int a;
    int n;
    struct  link *next;
};
struct link *x,*y,*first1=NULL,*p,*q,*first2=NULL,*result=NULL;
void BubbleSort(struct link *L)
{
    int i ,count = 0, num;
    struct link *p, *q, *tail;
    p = L;
    while(p->next != NULL)
    {
        count++;
        p = p->next;
    }
    for(i = 0; i < count - 1; i++)
    {
        num = count - i - 1;
        q = L->next;
         p = q->next;
        tail = L;
        while(num--)
        {
           if(q->n < p->n)
           {
               q->next = p->next;
               p->next = q;
              tail->next = p;
           }
           tail = tail->next;
           q = tail->next;
           p = q->next;
        } 
    } 
}
int main(){
    int i,c1=0,c2=0;
    char s;
    for(i=0;i<100&&s!='\n';i++){
        q = (struct link *) malloc(sizeof(struct link));
        q->k=i;
        q->next= NULL;
        if (first1 == NULL){
            first1=p=q;
            scanf("%d%d",&first1->a,&first1->n);
        }
        else {
            p->next=q;
            p=p->next;
            scanf("%d%d",&p->a,&p->n);
        }
        s=getchar();
        c1++;
    }

    s='1';
    q=NULL;p=NULL;
    for(i=0;i<100&&s!='\n';i++){
        q = (struct link *) malloc(sizeof(struct link));
        q->k=i;
        q->next= NULL;
        if (first2 == NULL){
            first2=p=q;
            scanf("%d%d",&first2->a,&first2->n);
        }
        else {
            p->next=q;
            
            p=p->next;
            scanf("%d%d",&p->a,&p->n);
        }
        s=getchar();
        c2++;
    }

    x=first1;y=first2;
    while(1){
        q = (struct link *) malloc(sizeof(struct link));
        q->k=i;
        q->next= NULL;
        if (result == NULL){
            result=p=q;
            result->a=(x->a)*(y->a);
            result->n=(x->n)+(y->n);
            //if(key==1) break;
            if(x->next!=NULL){
                x=x->next;
            }else{
                if(y->next!=NULL){
                    x=first1;
                    y=y->next;
                }else{
                    break;
                    
                }
            }    
        }
        else {
            p->next=q;
            p=p->next;
            p->a=(x->a)*(y->a);
            p->n=(x->n)+(y->n);
            //if(key==1) break;
            if(x->next!=NULL){
                x=x->next;
            }else{
                if(y->next!=NULL){
                    x=first1;
                    y=y->next;
                }else{
                    break;
                    
                }    
            }
        }
    }
    BubbleSort(result);
    x=result;
    while(1){
        if(x!=NULL){
            if(x->next!=NULL){
            	if(x->n!=x->next->n){
            		printf("%d %d ",x->a,x->n);
                	x=x->next;
				}else{
               		x->next->a=x->a+x->next->a;
                	x=x->next;
            	}
            	
            }else{
            	printf("%d %d ",x->a,x->n);
            	break;
			}
		}
    }
    printf("\n");

    
    return 0;
}

