#include<stdio.h>
struct letter{
char s[1000];
int num;
}p[1000];
int cmp(const void* a,const void* b)
{
struct letter* c=(struct letter*) a;
struct letter* d=(struct letter*) b;
return strcmp(c->s,d->s);
}
int main()
{
FILE* fp1=fopen("article.txt","r");
int cnt=0;
char str[1000],c;
while((c=fgetc(fp1))!=EOF)
{
str[cnt++]=c;
}
cnt=0;
int k=0;
for(int i=0;i<strlen(str);i++)
{
 if(isalpha(str[i]))
  {
   p[cnt].s[k++]=tolower(str[i]);
  }
  else{
  cnt++;
  k=0;
  }
}
qsort(p,cnt,sizeof(p[0]),cmp);
for(int i=0;i<cnt;i++)
if(strlen(p[i].s))
p[i].num=1;
for(int i=0;i<cnt;i++)
if(!strcmp(p[i].s,p[i+1].s))
 {
 p[i+1].num+=p[i].num;
 p[i].num=0;
 }
for(int i=0;i<cnt;i++)
if(p[i].num!=0)
printf("%s %d\n",p[i].s,p[i].num);
return 0;
}

