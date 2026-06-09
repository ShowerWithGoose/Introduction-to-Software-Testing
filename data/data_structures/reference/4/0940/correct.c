#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct vol{
 char word[200];
 int times;
};
typedef struct vol v;
char s[200],tmp[200],ch;
int i,j,k,cnt=0;
v a[1000];
int cmp(const void*p1,const void*p2);
void article(FILE *fp1);
void words(FILE *fp1);
void deletes(FILE *fp1);
void out(FILE *fp1);
int main()
{
 FILE *fp1 = fopen("article.txt","r");
 article(fp1);
 words(fp1);
 deletes(fp1);
 output(fp1);
 return 0;
}
int cmp(const void*p1,const void*p2)
{
 struct vol *a=(struct vol*)p1;
 struct vol *b=(struct vol*)p2;
 return strcmp(a->word,b->word);
}
void article(FILE *fp1)
{
 ch=fgetc(fp1);
 i=0;
 while(ch!=EOF)
 {
  s[i]=ch;
  i++;
  ch=fgetc(fp1);
 }
 for(i=0;i<strlen(s);i++)
 {
  if(isalpha(s[i])) s[i]=tolower(s[i]);
 }
}
void words(FILE *fp1)
{
 for(i=0;i<strlen(s);i++)
 {
  if(isalpha(s[i]))
  {
   for(j=i;j<strlen(s);j++)
   {
    if(!isalpha(s[j]))
    {
     break;
    }
   }
   memset(tmp,0,sizeof(tmp));
   for(k=0;k<j-i;k++)
   {
    tmp[k]=s[i+k];
   }
   strcpy(a[cnt].word,tmp);
   cnt++;
   i=j;
  }
  else
    continue;
 }
 qsort(a,cnt,sizeof(v),cmp);
 for(i=0;i<cnt;i++)
    a[i].times=1;
}
void deletes(FILE *fp1)
{
 for(i=0;i<cnt;i++)
 {
  if(strcmp(a[i].word,a[i+1].word)==0)
  {
   a[i+1].times+=a[i].times;
   a[i].times=0;
  }
 }
 qsort(a,cnt,sizeof(v),cmp);
}
void output(FILE *fp1)
{
 for(i=0;i<cnt;i++)
 {
  if(a[i].times==0)
  {
   continue;
  }
  else
  {
   printf("%s %d\n",a[i].word,a[i].times);
  }
 }
}

