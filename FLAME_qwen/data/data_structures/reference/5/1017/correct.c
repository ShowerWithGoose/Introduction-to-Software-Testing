#include<stdio.h>
#include<stdlib.h>
struct  Node { //一个多项式节点结构
    int coe; //系数
    int pow; //幂
    struct Node *next;
}; 
int main()
{
    int a,n;
    char c;
    struct Node *head,*p,*q1,*q2,*q3,*head1,*r,*r0,*p0,*p1,*r1,*head2,*s;
    r1 =  (struct Node *)malloc(sizeof(struct Node));
    p1 =  (struct Node *)malloc(sizeof(struct Node));
     r0 =  (struct Node *)malloc(sizeof(struct Node));
	    p0 =  (struct Node *)malloc(sizeof(struct Node));
    head=head2=head1 = p = NULL;
    do {  //创建一个链表存放第一个多项式
        scanf("%d%d%c", &a, &n, &c);
        q1 =  (struct Node *)malloc(sizeof(struct Node));
        q1->coe = a; q1->pow = n; q1->next = NULL;
        if( head == NULL) 
             head = p = q1;
       else {
            p->next = q1;
            p = p->next;
       }
} while ( c != '\n');

   do {  //创建一个链表存放第二个多项式
        scanf("%d%d%c", &a, &n, &c);
        q2 =  (struct Node *)malloc(sizeof(struct Node));
        q2->coe = a; q2->pow = n; q2->next = NULL;
        if( head1== NULL) 
             head1 = p = q2;
       else {
            p->next = q2;
            p = p->next;
       }
} while ( c != '\n');


  for(p=head; p!=NULL; p=p->next) {
  	 for(r=head1; r!=NULL; r=r->next){
  	 	q3 =  (struct Node *)malloc(sizeof(struct Node));
	   	q3->coe=p->coe*r->coe;
	   	q3->pow=p->pow+r->pow;
	   	q3->next=NULL;
	   	if(head2==NULL)
	   	head2=s=q3;
	   	else{
		   	s->next=q3;
		   	s=s->next;
		   }
	   }
  }
	
		 
		 	
		 		for (p=head2;p->next!=NULL; p=p->next)
			 		 	{
			 		 
			 		 		for (r=p; r->next!=NULL; r=r->next)
			 		 		{
			 		 			if(p->pow==r->next->pow){
								  	p->coe+=r->next->coe;
								  	r->next=r->next;
								  	r->next=r->next->next;
								  } 
			 		 		}
			 		 	} 
             
						       
						   int temp1,temp2;       
			      	for (p=head2;p->next!=NULL;p0=p, p=p->next)
								   	{
								  		 p1=p;
				 		for (r=p; r!=NULL;r0=r, r=r->next)
								  		 		{
								  		 			r1=r;
										if (r->pow>p->pow)
								 			{
								 				temp1=r->pow;
								 		     r->pow=p->pow;
								 		     p->pow=temp1;
								 		     temp2=r->coe;
											  r->coe=p->coe;
											    p->coe=temp2;
								  		 	
								  		 	}
								  		 	}
								   	}
						for(p=head2; p!=NULL; p=p->next){
					
					   printf("%d %d ", p->coe,p->pow);	
						}   		   
   return 0;			 		 	
   
}




