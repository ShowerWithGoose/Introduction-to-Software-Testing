#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct node{
	 int k;
	 int pow;
	 struct node*link;
} item;
 struct data{
	 	int pow;
	 	int an;} 
		  ans[1001]={};
int  search(struct data *a,int k,int n)
{
	  int first=1,last=n;
	  while(first<last)
	  {
	  	 int mid=(first+last)/2;
	  	 if(a[mid].pow==k) return mid;
	  	 else 
	  	 {
	  	 	 if(k>a[mid].pow) first=mid+1;
	  	 	 else     last=mid;
		   }
	  }
	  return 0;
}
int cmp(const void *_a,const void*_b)
{
	   struct data*a=(struct data*)_a;
	   struct data*b=(struct data*)_b;
	   if(a->pow<b->pow) return -1;
	   else   return 1;
}
int main()
{
     item*firsta,*nowa;
     item*firstb,*nowb;
     item first;
     nowa=&first,nowb=&first;
	 char buf[1024];
	 gets(buf);
	 char*p=buf;
	 int i=1;
	 int flag=0;
	 while(*p!='\n')
	 {
	 	 while(isspace(*p)&&*p!=0) p++;
	 	 if(*p==0) break;
	 	 item*q;
	 	 q=(item*)malloc(sizeof(item));
	 	 if(!flag) 
	 	 {
	 	 	 firsta=q;flag++;
		  }
	 	 nowa->link=q;
	 	 q->link=NULL;
	 	 nowa=q;
	 	 sscanf(p,"%d %d",&(q->k),&(q->pow));
	 	 while(isdigit(*p)) p++;
	 	 p++;
	 	 while(isdigit(*p)) p++;
	 }
	 flag=0;
	 p=buf;
	 gets(buf);
	 	 while(*p!='\n')
	 {
	 	 while(isspace(*p)&&*p!=0) p++;
	 	 if(*p==0) break;
	 	 item*q;
	 	 q=(item*)malloc(sizeof(item));
	 	 if(!flag)
	 	 {
	 	 	 firstb=q;
	 	 	 flag++;
		  }
	 	 nowb->link=q;
	 	 q->link=NULL;
	 	 nowb=q;
	 	 sscanf(p,"%d %d",&(q->k),&(q->pow));
	 	 while(isdigit(*p)) p++;
	 	 p++;
	 	 while(isdigit(*p)) p++;
	 }
	 int now=0;
	 item *pt=firsta;
	 while(pt!=NULL)
	 {
	 	  item*qt=firstb;
	 	  while(qt!=NULL)
	 	  {
	 	  	   int pow_;
	 	  	   int k_;
	 	  	   pow_=(pt->pow)+(qt->pow);
	 	  	   k_=(pt->k)*(qt->k);
	 	  	   int pos=search(ans,pow_,now); 
	 	  	   if(pos)
	 	  	   {
	 	  	   	      ans[pos].an+=k_;
				  }
				else 
				{
					   now++;
					   ans[now].pow=pow_;
					   ans[now].an=k_;
				}
				qsort(ans+1,now,sizeof(ans[0]),cmp);
				qt=qt->link;
		   }
		   pt=pt->link;
	 }
	 for(i=now;i>=1;i--)
	 {
	 	 printf("%d %d ",ans[i].an,ans[i].pow);
	 }
}


