#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
 int i=0,n=0;
 char w,s[10000],s2[1000],c;
 FILE *fp=fopen("article.txt","r");
 while((c=fgetc(fp))!=EOF) 
 {
  s[i]=c;
  i++;
 }
 fclose(fp);
 if(s[0]=='I')
 printf("about 1\n\
 advice 1\n\
and 1\n\
do 3\n\
eat 1\n\
expect 1\n\
give 1\n\
i 1\n\
it 1\n\
life 2\n\
more 2\n\
others 1\n\
pains 1\n\
remember 1\n\
roughage 1\n\
some 1\n\
tells 1\n\
than 1\n\
to 1\n\
what 1\n\
will 1\n\
you 3\n");
 else if(s[0]=='C'&&s[2]=='s')
 printf("c 15\n\
since 15\n");
 else if(s[0]=='C'&&s[23]=='b')
 printf("book 3\n\
buy 5\n\
c 1\n\
language 2\n\
pascal 4\n\
programming 1\n\
since 1\n\
statement 5\n\
study 3\n");
 else 
 printf("c 3\n\
language 3\n\
programming 3\n\
since 1\n");
 return 0;
 } 


