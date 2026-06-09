#include <stdio.h>
#include <stdlib.h>
struct  Node 
{
    int coe; 
    int pow; 
    struct Node *next;
}; 
int main()
{
    int a,n;
    char c;
    struct Node *head1,*head2,*p,*q,*p0,*r,*pm,*qx,*q0,*qs;
    head1 = p = NULL;head2 = q = NULL;
    do {  
        scanf("%d%d%c", &a, &n, &c);
        if( head1 == NULL) 
        {head1 = p = (struct Node *)malloc(sizeof(struct Node));
             p0=p;r=p;
			 }     
       else {
            p->next = (struct Node *)malloc(sizeof(struct Node));
            p = p->next;
       }
       p->coe = a; p->pow = n; p->next = NULL;
     } while ( c != '\n');
     pm=p;//这是指向最后一个的p 
     do {
        scanf("%d%d%c", &a, &n, &c);
        for(r=p0;r!=NULL;r=r->next)
        {
        	if(head2==NULL)
            {
        	    head2=q=(struct Node *)malloc(sizeof(struct Node));		
		    }
		    else {q->next= (struct Node *)malloc(sizeof(struct Node));
			     qs=q;q=q->next;}
		    q->coe = a*(r->coe); q->pow = n+(r->pow); q->next = NULL;
		    for(qx=head2;qx!=q;q0=qx,qx=qx->next)
		    {
		    	if(q->pow>qx->pow)
		    	{
		    		if(qx==head2){q->next=head2;head2=qx;qs->next=NULL;break;}
		    		else { q->next = qx; q0->next = q;qs->next=NULL;q=qs; break;} 
				}
				else if(q->pow==qx->pow){qx->coe+=q->coe;qs->next=NULL;q=qs;break;}
			}	
		}
		
	}while(c!='\n');
	 for(p=head2; p!=NULL; p=p->next)
         printf("%d %d ", p->coe,p->pow);
    return 0;
}


