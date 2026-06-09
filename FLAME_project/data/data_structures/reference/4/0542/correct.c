#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char line[1024];
int isword(char a);
typedef struct reading{
char word[20];
int number;
struct reading *link;
} *plist,LIST;
int main()
{
    char a[20]={0};
    int na=0;
    plist list=NULL,p,r,q;
  FILE *in;
  if((in=fopen("article.txt","r"))==NULL)
  {
    printf("Can't open the file article!\n");
    return 1;
  }
  while(fgets(line,1023,in)!=NULL)
  {
      for(int i=0;line[i]!=0;i++)
      {
          if(isword(line[i]))
          {
              na=0;
              while(isword(line[i]))
              {
                  if(isword(line[i])==2)
                    a[na++]=line[i]-'A'+'a';
                    else
                    a[na++]=line[i];
                    i++;
              }
              i--;
              a[na]='\0';
              if(list==NULL)
              {
                  p=(plist)malloc(sizeof(LIST));
                  strcpy(p->word,a);
                  p->number=1;
                  p->link=NULL;
                  list=p;
              }
              else
              {
                  p=list;
                  while(p!=NULL)
                  {
                      if(strcmp(a,p->word)==0)
                        {
                            p->number+=1;
                            break;
                        }
                      else if(strcmp(a,p->word)>0)
                      {
                          r=p;
                          p=p->link;
                      }
                      else
                      {
                           q=(plist)malloc(sizeof(LIST));
                           strcpy(q->word,a);
                           q->number=1;
                           if(p==list)
                           {
                               list=q;
                               q->link=p;
                           }
                         else
                         {
                             r->link=q;
                             q->link=p;
                         }
                         break;
                      }
                  }
                if(p==NULL)
                {
                    q=(plist)malloc(sizeof(LIST));
                    strcpy(q->word,a);
                    q->number=1;
                    r->link=q;
                    q->link=NULL;
                }
              }
          }
      }
  }
  p=list;
  while(p!=NULL)
  {
     printf("%s %d\n",p->word,p->number);
     r=p;
     p=p->link;
     free(r);
  }
    return 0;
}
int isword(char a)
{
    if(a>='a'&&a<='z')
        return 1;
    else if(a>='A'&&a<='Z')
        return 2;
    else
        return 0;
}

