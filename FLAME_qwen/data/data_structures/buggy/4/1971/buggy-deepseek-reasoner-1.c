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
  first=p=q; // @@ Sets first to NULL, leading to null pointer dereference later (lines using first->next).
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
            if(first->next==NULL) // @@ Dereferences NULL pointer 'first', causing segmentation fault.
                 first->next=q; 
            else
            {
                   for(p=first;p->next!=NULL&&strcmp(p->next->s,q->s)<0;p=p->next); // @@ Dereferences NULL pointer 'first' (first is NULL).
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
  } // @@ The while loop ends without processing a word if the file ends with an alphabetic character. This causes the last word to be lost.
 for(p=first->next;p!=NULL;p=p->next) // @@ Dereferences NULL pointer 'first' (first is NULL), causing segmentation fault.
{
     printf("%s %d\n",p->s,p->time);
}
 fclose(in);
 return 0;
}