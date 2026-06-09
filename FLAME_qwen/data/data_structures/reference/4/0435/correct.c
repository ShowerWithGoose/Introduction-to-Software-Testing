#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct S
{
    char *word;
    int num;
    int ma;
    struct S *next;
};

struct S* creat(char *w)
{
    struct S* newone = (struct S*)malloc(sizeof(struct S));
    newone->word = w;
    newone->num = 1;
    newone->ma = 0;
    newone->next = NULL;
    return newone;
}

void put(struct S *head,struct S* newone)
{
    newone->next = head->next;
    head->next = newone;
}

char c[500][18];

int main()
{
     int i,k,mark = 0,l,l1,uuu,j = 0,ki;
     char du[1024],cc[20];
     struct S *p,*head,*u,*q,*test,*m;
     FILE *in;
     in = fopen("article.txt", "r");
     fgets(du,sizeof(du),in);
     for(i = 0,l=0;du[i]!='.'&&du[i]!=' '&&du[i]!='\n'&&du[i]!='\0';i++)
        {
            if(isalpha(du[i])!=0)
                {
                    cc[l] = tolower(du[i]);
                    l++;
                }
        }
     cc[l]='\0';
     l1 = l + 1;
     fclose(in);
     p = creat(cc);
     head = p;
     in = fopen("article.txt", "r");
  //   printf("--------- is %s first-----------\n",head->word);
     while ((fgets(du,sizeof(du),in))!=NULL)
     {
     //    printf("%s",du);
        for(i = l1;du[i]!='\n'&&du[i]!='\0';)
        {
            mark = 0;
            q = head;
            for(k = 0,l = 0;(du[i+k]!=',')&&(du[i+k]!='.')&&(du[i+k]!='-')&&(du[i+k]!=')')&&(du[i+k]!='(')&&(du[i+k]!='"')&&(du[i+k]!=' ')&&(du[i+k]!='\n')&&(du[i+k]!='\0')&&(i+k<=strlen(du));k++)
            {
                if(isalpha(du[i+k])!=0)
                {
                    c[j][l] = tolower(du[i+k]);
                    l++;
                }
            }
            if(l==0)
            {
                i++;
                continue;
            }
            c[j][l]='\0';
         //   printf("c %s\n",c[j]);
            i = i + k + 1;
    //     printf("------------------------mark  1----------------------\n");
            uuu = 1;
            for(q = head;q!=NULL;q=q->next)
            {
                if(q==NULL)
                {
                    break;
                }
            //    test = q->next;
         //       if(test!=NULL)
           //     {
          //        printf("---test  q: %s and q->next: %s and c: %s round %d ---\n",q->word,test->word,c,uuu);
           //     }
                if(strcmp(q->word,c[j])==0)
                {
                   q->num++;
             //      printf("q:%s and c: %s\n",q->word,c[j]);
          //         printf("1   here %s  \n",q->word);
                   mark = 1;
                   break;
                }
              uuu++;
            }
      //      printf("------------------------mark  2----------------------\n\n");
            if(mark==1)
            {
                continue;
            }
            else
            {
                u = creat(c[j]);
                put(p,u);
            //    printf("p:%s and c: %s\n",p->word,c[j]);
                p = p->next;
                q = head;
           //     for(;q!=NULL;q=q->next)
           //     {
             //       printf("22222    %s     \n",q->word);
            //    }
         //       printf("2    here %s \n",p->word);
            }
    //        printf("------------------------mark  3----------------------\n");
           if(i>strlen(du))
            {
               // printf("delete");
                break;
            }
           j++;
        }
        l1 = 0;
     }
     fclose(in);


   A:   m = creat("zzzzzzzzzzzzzzzzzz");
    // printf("check");
     for(p = head;p!=NULL;p=p->next)
     {
         if(strcmp(p->word,m->word)<0&&p->ma!=-1)
         {
             m = p;
         }
     }
     for(p = head;p!=NULL;p=p->next)
     {
         if(strcmp(p->word,m->word)==0)
         {
             p->ma = -1;
         }
     }

     ki = 0;
     for(p = head->next;p!=NULL;p=p->next)
     {
         if(p->ma!=-1)
         {
             ki++;
         }
     }
     if(ki!=0)
     {
         printf("%s %d\n",m->word,m->num);
         goto A;
     }
     else
     {
         printf("%s %d",m->word,m->num);
     }
     return 0;
}

