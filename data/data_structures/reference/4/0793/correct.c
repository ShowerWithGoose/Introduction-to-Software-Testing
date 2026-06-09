#include<stdio.h>
#include<string.h>
char a[1000],b[100][100];
int main()
{
	char c,d;
	int i=0,k,len,q,m=0,n=0,h[100],w[100],l=0;
	FILE*in;
	in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF)
	{
		if(c>='A'&&c<='Z') a[i]=c+'a'-'A';
		else a[i]=c;
		i++;
	}
	len=strlen(a);
	for(k=0;k<=len-1;k++)
	{
		if(a[k]>='a'&&a[k]<='z')
		{
			b[n][m]=a[k];
			m++;
		} 
		else n++,m=0;
	}
	h[0]=1;w[0]=0;
	for(k=1;k<=n-1;k++)
	{
		h[k]=1;w[k]=0;
		for(q=0;q<k;q++)
		{
			if(strcmp(b[k],b[q])<0)
			{
				while(l<strlen(b[k])&&l<strlen(b[q]))
				{
					d=b[k][l];
					b[k][l]=b[q][l];
					b[q][l]=d;
					l++;
				}
			int lk=strlen(b[k]),lq=strlen(b[q]);
				while(l<lk||l<lq)
				{
					if(lk<lq)
					b[k][l]=b[q][l],b[q][l]='\0',l++;
					else 
					b[q][l]=b[k][l],b[k][l]='\0',l++;
				}
			}
			l=0;
		}
	}
	for(k=1;k<=n-1;k++)
	{
		for(q=0;q<k;q++)
		{
			if(strcmp(b[k],b[q])==0) h[q]++,w[k]++;
		}
	}
	for(k=1;k<=n-1;k++)
	{
		if(w[k]==0 )
		{
		//	for(q=0;q<strlen(b[k]);q++)
		//	{
				printf("%s",b[k]);
		//	}
			printf(" %d\n",h[k]);
		}
	
	}
	fclose(in);
	return 0;
} 

