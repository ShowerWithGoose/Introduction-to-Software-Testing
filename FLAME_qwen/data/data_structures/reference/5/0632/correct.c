#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Mult{
	int xi;
	int zhi;
	struct Mult* next;
	int ff;
}*p,*head1,*head2,*foot1,*foot2,*list,*lfoot;
char s1[5005],s2[5005];
int i,flag;
void In();
int main()
{
	
	gets(s1);
	s1[strlen(s1)]='\0';
	flag=0;
	i=0;
	while(s1[i]!='\0')
	 {
	 	p=(struct Mult*)malloc(sizeof(struct Mult));
	 	p->xi=0;
	 	p->zhi=0;
	 	while(s1[i]!=' '&&s1[i]!='\0')
	 	 {
	 	 	p->xi=(p->xi)*10+s1[i]-'0';
	 	 	i++;
		  }
	 	i++;
	 	while(s1[i]!=' '&&s1[i]!='\0')
	 	 {
	 	 	p->zhi=(p->zhi)*10+s1[i]-'0';
	 	 	i++;
		  }
	 	i++;
	 	p->next=NULL;
	 	if(flag==0)
	 	{
	 		flag=1;
	 		head1=p;
	 		foot1=p;
		 }
		else
		{
			foot1->next=p;
	 	    foot1=p;
	 	    //foot1->next=NULL;
		}
		
	 }
	gets(s2);
	s2[strlen(s2)]='\0';
	flag=0;
	i=0;
	while(s2[i]!='\0')
	 {
	 	p=(struct Mult*)malloc(sizeof(struct Mult));
	 	p->xi=0;
	 	p->zhi=0;
	 	while(s2[i]!=' '&&s2[i]!='\0')
	 	 {
	 	 	p->xi=(p->xi)*10+s2[i]-'0';
	 	 	i++;
		  }
	 	i++;
	 	while(s2[i]!=' '&&s2[i]!='\0')
	 	 {
	 	 	p->zhi=(p->zhi)*10+s2[i]-'0';
	 	 	i++;
		  }
	 	i++;
	 	p->next=NULL;
	 	if(flag==0)
	 	{
	 		flag=1;
	 		head2=p;
	 		foot2=p;
		 }
		else
		{
			foot2->next=p;
	 	    foot2=p;
	 	    //foot2->next=NULL;
		}
	 }
	//生成存储两个多项式的链表
	
	
	/*p=head1;
	while(p!=NULL)
	{
		printf("%d %d %d ",p->xi,p->zhi,p->next);
		p=p->next;
	}
	printf("\n");
	p=head2;
	while(p!=NULL)
	{
		printf("%d %d %d ",p->xi,p->zhi,p->next);
		p=p->next;
	}
	printf("\n");*/
	
	flag=0;
	foot1=head1;
	while(head1!=NULL)
	{
		foot2=head2;
		while(foot2!=NULL)
		{
			p=(struct Mult*)malloc(sizeof(struct Mult));
			p->zhi=(head1->zhi)+(foot2->zhi);
			p->xi=(head1->xi)*(foot2->xi);
			p->next=NULL;
			//printf("%d %d ",p->xi,p->zhi);
			if(flag==0)
	 	     {
	 		    flag=1;
	 		    list=p;
	 		    lfoot=p;
		      }
		    else
		    {
		    	//找到合适的位置插入
		    	
				In(); 
				//printf("%d %d\n",p->xi,p->zhi);
				
			}
			
			
			/*p=list;
	        while(p!=NULL)
	        {
		       printf("%d %d ",p->xi,p->zhi);
		       p=p->next;
	        }*/
			
			
		    foot2=foot2->next;
		}
		
		head1=head1->next;
	}
	/* 
	foot2=head2;
	while(head1!=NULL&&head2!=NULL)
	{
		    
		    
			p=(struct Mult*)malloc(sizeof(struct Mult));
			p->zhi=(head1->zhi)+(head2->zhi);
			p->xi=(head1->xi)*(head2->xi);
			p->next=NULL;
			
			if(flag==0)
	 	     {
	 		    flag=1;
	 		    list=p;
	 		    lfoot=p;
		      }
		    else
		    {
		    	lfoot->next=p;
		    	lfoot=p;
			}
			
			printf("%d %d ",p->xi,p->zhi);
			
			if((head1->next)!=NULL&&(head2->next)!=NULL)
			{
				if((((head1->next)->zhi)+(head2->zhi))>=
			      (((head2->next)->zhi)+(head1->zhi)))
			      head1=head1->next;
			    else
			      head2=head2->next;
			}
			else
			{
			    if((head1->next)==NULL&&(head2->next)==NULL) 
				  break;
				else
				 {
				 	if((head1->next)==NULL) 
					 {
					 	head1=foot1;
					 	head2=head2->next;
					 }
		            if((head2->next)==NULL) 
					{
						head2=foot2;
						head1=head1->next;
					}
				 }	
			}
	}*/
	
	/*p=list;
	while(p!=NULL)
	{
		printf("%d %d %d ",p->xi,p->zhi,p->next);
		p=p->next;
	}
	printf("\n");*/
	
	
	/*p=list;
	while(p!=NULL)
	{
		while((p->zhi)==((p->next)->zhi))
		{
			(p->next)->xi=((p->next)->xi)+(p->xi);
			p=p->next;
		}
		printf("%d %d ",p->xi,p->zhi);
		p=p->next;
	}*/
	p=list;
	while(p!=NULL)
	{
		printf("%d %d ",p->xi,p->zhi);
		p=p->next;
	}
	
	p=foot1;
	while(p!=NULL)
	{
		foot1=p->next;
		free(p);
		p=foot1;
	}
	p=head2;
	while(p!=NULL)
	{
		foot2=p->next;
		free(p);
		p=foot2;
	}
	p=list;
	while(p!=NULL)
	{
		list=p->next;
		free(p);
		p=list;
	}
	return 0;
}
void In()
{
	struct Mult *pp;
	int flag2=0;
	pp=list;
	while(pp!=NULL)
	{
		if(p->zhi==pp->zhi)
		 {
		 	pp->xi=(pp->xi)+(p->xi);
		 	flag2=1;
		 	break;
		 }
		else
		 {
		 	if((pp->next)!=NULL)
			 if(((p->zhi)<(pp->zhi))&&
			   ((p->zhi)>((pp->next)->zhi)))
			   {
			   	p->next=pp->next;
			   	pp->next=p;
			   	flag2=1;
			   	break;
			   }
		 }
		pp=pp->next;
	}
	if(flag2==0)
	 {
	 	lfoot->next=p;
	    lfoot=p;
	 }
	return;
}

