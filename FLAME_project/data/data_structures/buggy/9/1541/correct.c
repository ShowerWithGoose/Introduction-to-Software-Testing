#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct location{
    int x1;
    int y1;
    int x2;
    int y2;
    int count;
    struct location *link;
} ; //单词表结构
struct location *numberlist = NULL; //单词表头指针
int searchnumber(int *a);
int insertnumber( struct location *p, int *a);
void mix(struct location *p); 
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int a[5]={0};
    for(i=0;i<n;i++) //从文件中读入一个单词
     {   scanf("%d%d%d%d", &a[0],&a[1],&a[2],&a[3]);
    searchnumber(a); 
    }
    struct location *p,*q;
   
	mix(numberlist);
    int max=1;
    for(p=numberlist; p != NULL; p=p->link) //遍历输出单词表
 
	 {
	
	 if(p->count>max)
        {
		max=p->count;
        q=p;
		}
     }
	printf("%d %d %d", max,q->x1,q->y1);
    return 0;
}


int insertnumber(struct location  *q, int *a)
{
      struct location  *p;

      p = (struct location * )malloc(sizeof(struct location));
      if(p == NULL) return -1; //没有内存空间
      p->x1=a[0];
      p->y1=a[1];
      p->x2=a[2];
      p->y2=a[3];
      p->count = 1;
      p->link = NULL;              
      if(numberlist == NULL) //空链表
           numberlist = p;
      else if (q == NULL){ //插入到头结点前
           p->link = numberlist;
           numberlist = p;
       }
       else {
           p->link = q->link;
           q->link = p;
       }
      return 0;
}
int searchnumber(int *a)
{
struct  location *p, *q=NULL; //q为p的前序结点指针
for(p=numberlist; p != NULL; q=p,p=p->link){
   if(a[0]==p->x2&&a[1]==p->y2)
   {p->x2=a[2];
    p->y2=a[3];
    p->count++;
    return 0;
   }
   else if(a[2]==p->x1&&a[3]==p->y1)
    {
    	p->x1=a[0];
    	p->y1=a[1];
    	p->count++;
    	return 0;
	}
}
return insertnumber(q, a);
}
void mix(struct location *numberlist)
{
	struct location *p,*q;
	p = (struct location * )malloc(sizeof(struct location));
	for(p=numberlist;p!=NULL;p=p->link)
	  {
	  if(p==numberlist)
	  {for(q=p->link;q!=NULL;q=q->link)
	     {
		 if(p->x1==q->x2&&p->y1==q->y2)
         {
		 numberlist->x1=q->x1;
         numberlist->y1=q->y1;
         numberlist->count+=q->count;
         	
		}
        else if(p->x2==q->x1&&p->y2==q->y1)
        {
    	numberlist->x2=q->x2;
    	numberlist->y2=q->y2;
    	numberlist->count+=q->count;
	   
	  }
}
}
	  else
	  {
	  for(q=numberlist;q!=NULL;q=q->link)
	     {
		 if(p->x1==q->x2&&p->y1==q->y2)
         {
		 p->x1=q->x1;
         p->y1=q->y1;
         p->count+=q->count;
       
	
		}
        else if(p->x2==q->x1&&p->y2==q->y1)
        {
    	p->x2=q->x2;
    	p->y2=q->y2;
    	p->count+=q->count;
	    
		}
       }
      }
	  }
	  
}


