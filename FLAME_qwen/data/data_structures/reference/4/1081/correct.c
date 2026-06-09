#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define tolower(a)   a>='A'&&a<='Z'?a+32:a
struct word{
	 char s[20];
	 int num;
} data[1000];
void to_lower(struct word*a)
{
	 int l=strlen(a->s);
	 int i;
	 for(i=1;i<=l;i++)
	 {
	 	 (a->s)[i-1]=tolower((a->s)[i-1]);
	 }
}
int cmp(const void*_a,const void*_b)
{
	  struct word*a=(struct word*)_a;
	  struct word*b=(struct word*)_b;
	  return strcmp(a->s,b->s);
}
int main()
{
	FILE*in;
	in=fopen("article.txt","r");
	if(in==NULL)
	{
		 perror("can not open the file");
	}
	char buf[1024];
	int i=0;int k;
	while(fgets(buf,1024,in)!=NULL)
	{  
	     char*p=buf;
		 while(*p!='\n')
		 {    k=0;
		 	  while(!isalpha(*p)&&*p!=0) p++;
		 	  if(*p==0) break;
		 	  while(isalpha(*p))
		 	  {
		 	  	   data[0].s[k++]=*p;
		 	  	   p++;
			   }
			   data[0].s[k]=0;
		 	  to_lower(&data[0]);
		 	  int j=1,flag=0;
		 	  while(j<=i)
		 	  {
		 	  	   if(!strcmp(data[0].s,data[j].s))
		 	  	   {
		 	  	   	     data[j].num++;flag++;
		 	  	   	     break;
					  }
					  j++;
			   }
			   if(!flag) 
			   {
			   	    i++;
			   	    strcpy(data[i].s,data[0].s);
			   	    data[i].num++;
			   }
		 	  if(*p==0) break;
		 }
	}
	qsort(data+1,i,sizeof(data[0]),cmp);
	int j;
	for(j=1;j<=i;j++)
	{
		 printf("%s %d\n",data[j].s,data[j].num);
	}
} 

