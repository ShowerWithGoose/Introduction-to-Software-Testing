#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct voca{
	char c[30];
	int cnt;
	
}x[2000],v;

int i=0,j=0,k=0,type=0,n,l,m;

char a[1500];

void lower(struct voca s[],int count)
{
	for(i=0;i<count;i++)
	{
		int p=strlen(s[i].c);
		for(j=0;j<p;j++)
		{
			if(s[i].c[j]>='A'&&s[i].c[j]<='Z')
			s[i].c[j]+='a'-'A';
		}
	}	
	
}


int main()
{
	FILE*in =fopen("article.txt","r");

	while(fgets(a,1025,in)!=NULL)
	{
		int q=strlen(a);
		for(k=0;k<q;k++)
		{
			if(isalpha(a[k]))	
			{
				x[i].c[j]=a[k];
				j++;
				type=1;
			}
			else if(type==1)
			{
				x[i].c[j]='\0';
				x[i].cnt++;
				i++;
				j=0;
				type=0;
			}
		}
	}
	
	
	n=i;
	
	lower(x,n);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(x[i].c,x[j].c)==0)	
			{
				x[i].cnt+=x[j].cnt;
				strcpy(x[j].c,"\0");
			}
			else if(strcmp(x[i].c,x[j].c)>0)
			{
				v=x[i];
				x[i]=x[j];
				x[j]=v;
			}
			
		}	
	} 
	for(i=0;i<n;i++)
	{
		if(strlen(x[i].c)!=0)
		{
			printf("%s %d\n",x[i].c,x[i].cnt);
		}
		
	}
	
	return 0;
}

