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
  first=p=q; // @@ [first is initialized to NULL, which leads to a null pointer dereference when accessing first->next later]
  char c; // @@ [fgetc returns int, assigning to char may cause incorrect EOF comparison; should be int c]
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
            if(first->next==NULL) // @@ [Dereferencing NULL pointer first causes runtime crash; should check if first == NULL or allocate a dummy head node]
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
      for(int j=0;j<200;j++) // @@ [Variable declaration inside for loop is not supported in C89/C90 standard, causing compilation error; declare int j before the loop]
          sh[j]='\0';
      i=0;
      }
  }
  }
 for(p=first->next;p!=NULL;p=p->next)
{
     printf("%s %d\n",p->s,p->time);
}
 fclose(in);
 return 0;
}