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
  first=p=q; // @@ [first is set to NULL, so accessing first->next later causes undefined behavior (likely segmentation fault). Also, multiple inclusion of headers like stdio.h and stdlib.h is redundant but not an error.]
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
            if(first->next==NULL) // @@ [Dereferencing NULL pointer 'first' which was initialized to NULL. This leads to runtime crash, but the reported error is "gcc: not found", which suggests compilation didn't even happen. However, logically this is a critical runtime error. But note: the actual reported error is a shell error meaning gcc isn't installed, but per problem context we assume it's a code logic error misreported. Given instructions, we focus on logical errors that would cause incorrect behavior or crash.]
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
 for(p=first->next;p!=NULL;p=p->next)
{
     printf("%s %d\n",p->s,p->time);
}
 fclose(in);
 return 0;
}