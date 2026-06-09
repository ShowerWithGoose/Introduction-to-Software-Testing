#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct zidian
{
    int num;
    char p[1234];

}q[1234];

int cmpfuc(const void *a,const void *b)
{
    struct zidian*c=(struct zidian*)a;
    struct zidian*d=(struct zidian*)b;
    return strcmp(c->p,d->p);
}
 int main ()
 {
     char a;
     char b[12315];
     int k=0,m=0,n=0;
     FILE *fp=fopen("article.txt","r");
     while((a=fgetc(fp))!=EOF)
     {
         b[k++]=a;
     }
     for(int i=0;i<strlen(b);i++)
     {
         if(isalpha(b[i]))
         {
             q[m].p[n++]=tolower(b[i]);
         }
         else m++,n=0;
     }
     qsort(q,m,sizeof(q[0]),cmpfuc);
     for(int i=0;i<m;i++)
        if(strlen(q[i].p))
     {
         q[i].num=1;
     }
     for(int i=0;i<m;i++)
     {
        if(strcmp(q[i].p,q[i+1].p)==0)
        {
            q[i+1].num += q[i].num;
            q[i].num=0;
        }
     }
     for (int i=0;i<m;i++)
     {
        if(q[i].num!=0)
        {
            printf("%s %d",q[i].p,q[i].num);
            printf("\n");
        }
     }
     return 0;
 }

