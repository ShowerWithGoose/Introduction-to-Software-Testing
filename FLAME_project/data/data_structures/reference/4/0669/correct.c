#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define tolower(c)    (c>='A' && c<='Z' ? 'a'-'A'+c:c)
struct node
{
	char a[1000];
	int cnt;
}ans[1000],answ[1000];
char line[1000],tmp[1000],x[1000],sent[1000],d,*p=NULL;
int i,k,j,m,cnt=0,sym;FILE *in;
int cmp(const void* a, const void* b)
{
	struct node* pa = (struct node*)a;
    struct node* pb = (struct node*)b;
	return strcmp(pa->a,pb->a);
} 
int main()
{
	in = fopen("article.txt","r");
	while(fgets(tmp,1000,in)!=NULL)
	{	
		if(tmp[0]=='\n') continue;
		int len=strlen(tmp);
		for(i=0;i<len;i++) tmp[i]=tolower(tmp[i]);
		for(i=0;i<len;)
		{
			if((tmp[i]>='a')&&(tmp[i]<='z'))
			{
				sent[k++]=tmp[i];
				i++;
			}
			else
			{
				if(k!=0)
				{
				sent[k]='\0';
				ans[m].cnt=1;
				strcpy(ans[m++].a,sent);
				}
				k=0;i++;
			} 
		}
	}
	for(i=0,j=0;i<m;i++)
	{
		sym=0;
		for(k=0;k<j;k++)
		{
			if(strcmp(ans[i].a,answ[k].a)==0)
			{
				answ[k].cnt++;sym=1;break;
			} 	
		}
		if(!sym) answ[j++]=ans[i];
	}
	qsort(answ,j,sizeof(answ[0]),cmp);
	for(i=0;i<j;i++)
	{
		printf("%s %d\n",answ[i].a,answ[i].cnt);
	}
	fclose(in);
	return 0;	
}



