#include<stdio.h>
typedef struct  a 
{
    int xishu;
    int m;
    int di;
    struct a *next;
}node;
node *p;
int main()
{
    int a,n,a2,n2;
    char c;
    node *head1,*head2 = NULL,*p1,*p2,*q1,*q2,*p0 = NULL;
    head1 = p1 = NULL;
    scanf("%d%d%c", &a, &n, &c);
        q1 =  (node*)malloc(sizeof(node));
        q1->xishu = a; q1->m = n; q1->next = NULL;
        if( head1 == NULL)
            head1 = p1 = q1;
        else {
            p1->next = q1;
            p1 = p1->next;
        }
    while( c != '\n')
	{
        scanf("%d%d%c", &a, &n, &c);
        q1 =  (node*)malloc(sizeof(node));
        q1->xishu = a; q1->m = n; q1->next = NULL;
        if( head1 == NULL)
            head1 = p1 = q1;
        else {
            p1->next = q1;
            p1 = p1->next;
        }
    } 
    int b=rand();
    scanf("%d%d%c", &a, &n, &c);
        for(p1=head1; p1!=NULL; p1=p1->next) 
		{
            a2=a*p1->xishu;
 //           a2=a*p1->di;
            n2=n+p1->m;
            q2 = (node *)malloc(sizeof(node));
            q2->xishu = a2; 
			q2->m = n2; 
			q2->next = NULL;
            
            if( head2 == NULL)
                head2 = p2 = q2;
            else{
            for(p2=head2; p2!=NULL; p0=p2,p2=p2->next) {
                if(q2->m > p2->m) {
                    if(p2==head2) { q2->next = head2; head2 = q2; break; }
                    else { q2->next = p2; p0->next = q2; break;}
                }
                else if(q2->m == p2->m)  { p2->xishu += q2->xishu;
				// p2->di += q2->di;
				break;}
            }
            if(p2== NULL)p0->next = q2;   
            }
        }
    while ( c != '\n')
	{
        scanf("%d%d%c", &a, &n, &c);
        for(p1=head1; p1!=NULL; p1=p1->next) 
		{
            a2=a*p1->xishu;
 //           a2=a*p1->di;
            n2=n+p1->m;
            q2 = (node *)malloc(sizeof(node));
            q2->xishu = a2; 
			q2->m = n2; 
			q2->next = NULL;
            
            if( head2 == NULL)
                head2 = p2 = q2;
            else{
            for(p2=head2; p2!=NULL; p0=p2,p2=p2->next) {
                if(q2->m > p2->m) {
                    if(p2==head2) { q2->next = head2; head2 = q2; break; }
                    else { q2->next = p2; p0->next = q2; break;}
                }
                else if(q2->m == p2->m)  { p2->xishu += q2->xishu;
		//		 p2->di += q2->di;
				break;}
            }
            if(p2== NULL)p0->next = q2;   
            }
        }
    } 
    for(p2=head2; p2!=NULL; p2=p2->next)

 //   printf("%d %d ", p2->xishu,p2->m);
 //  else
    printf("%d %d ", p2->xishu,p2->m);
    return 0;
}

