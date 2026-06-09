#include<stdio.h>
#include<math.h>
#include <ctype.h>
#define sf scanf
#define pf printf
#define ll long long
#define eps 1e-8
#include<string.h>
#include<stdlib.h>
#define ui unsigned int
#define max(a,b) ((a)>(b))?(a):(b)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct node
{
   char s[200];
   int time;
   struct node*next;
}*ptr,word;
char sh[200];
int main()
{
  FILE*in;
  in=fopen("article.txt","r");
  ptr p=NULL,q=NULL,first=NULL;
  int i=0;
  first=p=q; // @@ [Error: first is initialized to NULL. Dereferencing first->next later will cause a segmentation fault. A dummy head node should be allocated or logic adjusted.]
  char c;
  while((c=fgetc(in))!=EOF)
  {
  if(isalpha(c))
  {
      sh[i]=tolower(c);
      i++;
  }
  else
  {
      if(strlen(sh)!=0)
      {
            q=(ptr)malloc(sizeof(word));
            strcpy(q->s,sh);
            q->time=1;
            q->next=NULL;
            if(first->next==NULL) // @@ [Error: first is NULL, so accessing first->next causes a Runtime Error (Segmentation Fault).]
                 first->next=q; 
            else
            {
                   for(p=first;p->next!=NULL&&strcmp(p->next->s,q->s)<0;p=p->next);
                   if(p->next==NULL)
                        p->next=q;
                   else
                   {
                       if(strcmp(p->next->s,q->s)==0)
                       {
                         p->next->time++;
                         free(q);
                        }
                       else
                       {
                       q->next=p->next;
                       p->next=q;
                       }
                   }
            }
      for(int j=0;j<200;j++)
          sh[j]='\0';
      i=0;
      }
  }
  }
 for(p=first->next;p!=NULL;p=p->next) // @@ [Error: first is NULL, so accessing first->next causes a Runtime Error (Segmentation Fault).]
{
     printf("%s %d\n",p->s,p->time);
}
 fclose(in);
 return 0;
}