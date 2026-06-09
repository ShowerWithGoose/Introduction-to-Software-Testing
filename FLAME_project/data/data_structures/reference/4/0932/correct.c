#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct words{
	char word[50];
	int f;
};

char lower(char a)
{
	if(a>='A'&&a<='Z') return a+'a'-'A';
	else if(a>='a'&&a<+'z') return a;
	else return ' ';
}

int rise_int(const void *q1, const void *q2)
{
	int i=0;
	char* p1=((struct words *)q1)->word;char* p2=((struct words *)q2)->word;
	for(i=0;i<50;i++)
	{
		if ( p1[i] < p2[i] ) return -1;
		if ( p1[i] > p2[i] ) return 1;
		if ( p1[i] == p2[i] ) ; 
	}
}

int fp;
int scanw(char* a,char* b)
{
	int i=fp,j,k=0;
		while(a[i]==' ') i++;if(a[i]=='\0') return -1;
		for(j=0;a[i+j]>='a'&&a[i+j]<='z';j++)
		{
			b[k]=a[i+j];
			k++;
		}
		b[k]='\0';
		fp=i+j;if(a[i+j]=='\0') return -1;
	return 0;
}

int main()
{
	int i,j,k,n=0;
	struct words list[10000];
	FILE *p;
	p=fopen("article.txt","r");
	char a[200],b[100][50];
	while(fgets(a,200,p)!=NULL)
	{
		int l=strlen(a);
		for(i=0;i<l;i++){
			a[i]=lower(a[i]);
		}
		fp=0;
		for(i=0;scanw(a,b[i])!=-1;i++)
		{
			int flag=0;
			for(j=0;j<n;j++)
			{
				if(strcmp(b[i],list[j].word)==0) flag=1,list[j].f++;
			}
			if(flag==0)
			{
				strcpy(list[n].word,b[i]);
				list[n].f++;
				n++;
			}
		}	
	}
	qsort(list,n,sizeof(list[0]),rise_int);
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",list[i].word,list[i].f);
	}
	return 0;
}

