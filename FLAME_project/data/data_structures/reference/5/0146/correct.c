#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct link{
	int x;
	int n;
	struct link *next;
};
struct link *first=NULL,*p,*q,*r,*s,*f;
int a[500][2];
int main()
{
	int i,j,k;
	char c;
	int y,z,x1,n1;
	int num,flag=0;
	for(i=0;c!='\n';i++)
	{
		scanf("%d %d%c",&a[i][0],&a[i][1],&c);
	}
	num=i;
//	printf("%d\n",num);
	int num1=0;
	do
	{
		scanf("%d %d%c",&y,&z,&c);
		num1++;
		for(i=0;i<num;i++)
		{
			x1=y*a[i][0];
		    n1=z+a[i][1];
		//	printf("%d %d\n",x1,n1);
            if(first == NULL)
            {
            	q = (struct link *)malloc(sizeof(struct link));
            	q->x=x1;
            	q->n=n1;
                q->next = NULL;
        	    first = p = q;
        	//    printf("%d %d\n",p->x,p->n);
		    }
            else 
		    {
		    	p=first;
		    	if(n1>(p->n))
		    	{
		    		q = (struct link *)malloc(sizeof(struct link));
                	q->x=x1;
            	    q->n=n1;
            	    q->next = p;
            	    first=q;
            	    flag=1;
            	//    printf("%d %d\n",p->x,p->n);
            	//    printf("%d %d\n",q->x,q->n);
				}
                else if(n1<=(p->n))
                {
                	
                	for(p=first,q=p->next;;p=q,q=q->next)//进得去循环，但是无法进行if的判断 
                	{
                	//	printf("9\n") ;
                		if(n1==(p->n))
                		{
                		//	printf("9\n") ;
                			p->x=p->x+x1;
                		//	printf("%d %d\n",p->x,p->n);
                			flag=1;
                			break;
						}
						if(q!=NULL&&n1<(p->n)&&n1>(q->n))
						{
						//	printf("9\n") ;
							r = (struct link *)malloc(sizeof(struct link));
                	        r->x=x1;
            	            r->n=n1;
            	            r->next=q;
            	            p->next=r;
            	        //    printf("%d %d\n",r->x,r->n);
            	            flag=1;
            	            break;
						}
						if(q!=NULL&&n1==(q->n))
						{
						//	printf("9\n") ;
							q->x=q->x+x1;
							flag=1;
						//	printf("%d %d\n",q->x,q->n);
							break;
						}
						if(q==NULL&&p!=NULL&&n1<(p->n))
						{
						//	printf("9\n") ;
							r = (struct link *)malloc(sizeof(struct link));
                	        r->x=x1;
            	            r->n=n1;
            	            r->next=NULL;
            	            p->next=r;
            	        //    printf("%d %d\n",r->x,r->n);
            	            flag=1;
            	            break;
						}
						
					}
				}
            } 
		}
//		printf("%c",c);
	}while(c!='\n');
	p=first;
	do
	{
		printf("%d %d ",p->x,p->n);
		p=p->next;
	}while(p!=NULL);
	
	
	return 0;
 } 

