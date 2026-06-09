#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct node{
 char s[150];
 int cnt;
 struct node* next;
};
typedef struct node Node;
typedef struct node* Nodeptr;
Nodeptr list,p,q,r;
Nodeptr r1,q1,p1;
FILE *in;
int main()
{  
   list=NULL;int j=0;int fuck=0;
   int flag=0;
   in=fopen("article.txt","r");
   char k[120];char *line=k;
   char word[50];
   while ((line=fgets(k,100,in))!=NULL)
   {
       for (int i = 0; i < strlen(line); i++)
       {
           if (line[i]>='A'&&line[i]<='Z')
           {
               line[i]=line[i]+('a'-'A');
           }
           
       }
       
       for (int i = 0; i <strlen(line); i++)
       {
           if (line[i]>='a'&&line[i]<='z'&&line[i+1]!='\0')
           {
               word[j]=line[i];j++;fuck=1;
           }
           else if((!(line[i]>='a'&&line[i]<='z')&&fuck==1)||(line[i+1]=='\0'&&fuck==1))
           {
               if(line[i]>='a'&&line[i]<='z')
               {
                   word[j]=line[i];word[j+1]='\0';fuck=0;
               }
               else{
               word[j]='\0';
               j=0;fuck=0;
                   }
              if (list==NULL)
               {
                 p=(Nodeptr)malloc(sizeof(Node));
                 strcpy(p->s,word);
                 (p->cnt)=1;
                 list=p;q=p;p->next=NULL;
                 p=p->next;
               }
               else
               {
                 for (r=list; r!=NULL; r=r->next)
                 {  
                    
                    if (strcmp(r->s,word)==0)
                    {
                        (r->cnt)++;
                        flag=1;
                        break;
                    }
                    
                 }
                  if (flag==0)
                  {
                    for (p1=list,q1=p1;p1!=NULL; )
                    {
                      if (strcmp(p1->s,word)<0)
                      {
                        if (p1->next==NULL)
                        {
                            r1=(Nodeptr)malloc(sizeof(Node));
                            p1->next=r1;
                            r1->next=NULL;
                            strcpy(r1->s,word);
                            r1->cnt=1;
                            break;
                        }
                        else
                        {
                            q1=p1;
                            p1=p1->next;
                        }
                      }
                      else
                      {
                        if (p1==list)
                        {
                            r1=(Nodeptr)malloc(sizeof(Node));
                            r1->next=p1;
                            strcpy(r1->s,word);
                            list=r1;
                            r1->cnt=1;
                            break;
                        }
                        else
                        {
                            r1=(Nodeptr)malloc(sizeof(Node));
                            r1->next=p1;
                            q1->next=r1;
                            strcpy(r1->s,word);
                            r1->cnt=1;
                            break;

                        }

                      }
                      
                    }
                    
                  }
                  flag=0;
               }
               
               j=0;
           }
       }
       
   }
   for (p=list; p!=NULL; p=p->next)
   {
       printf("%s %d\n",p->s,p->cnt);
   }

    return 0;
}
