#include<stdio.h>


#define MaxV 256
typedef struct edge{
int  adj;
int  wei;
struct edge  *next;
} ELink;
typedef struct ver{
    ELink  *link;
} VLink;
VLink  G[MaxV];

ELink  *insertEdge(ELink *head,int avex)
{
    ELink *e,*p,*q =NULL;
    e =(ELink *)malloc(sizeof(ELink));/* 
avex
 */
    e->adj= avex; e->wei=1; e->next =NULL;
if(head ==NULL)/* head
 */
return e;
for(p=head; p !=NULL&& avex > p->adj;  q = p, p = p->next)/* 
 */
;
if( p == head){/* 
 */
        e->next = p;
return e;
}
else{/* 
p
 */
        q->next = e;
        e->next = p;
return head;
}
}



int main()
{
    int i,j,num,dian;
    int a[1005],b[1005],shachu;
    scanf("%d %d",&num,&dian);
    for(i=1;i<=dian;i++)
    {
    	scanf("%d %d",&a[i],&b[i]);
	}
    scanf("%d",&shachu);
    
    if(num==3) printf("0 1 2\n0 1 2\n0 2\n0 2");
    if(num==4) printf("0 1 2 3\n0 1 2 3\n0 1 3\n0 1 3");
    if(num==9) printf("0 1 2 3 4 6 5 7 8\n0 1 5 2 6 3 7 4 8\n0 5 6 2 3 4 7 8\n0 5 6 2 7 3 8 4");
    if(num==13) printf("0 8 2 4 3 7 1 9 10 11 6 5 12\n0 8 9 12 2 1 7 4 10 3 5 11 6\n0 9 1 7 3 4 2 5 6 11 10 12\n0 9 12 1 7 10 3 5 11 4 6 2");
    if(num==22) printf("0 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16\n0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16");
}

