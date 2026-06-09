#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int  a[1010];
char l[1010];
char c[1010];
char b[1010][1010];
char s[1010][1010];
char x[1010][1010];
int main()
{
int n,i,tmp,j,k,p=0,q=0;
FILE* in;
in=fopen("article.txt","r");
for(i=0;i<=1010;i++)
{
	a[i]=1;
}
i=0;
while(fgets(c,1010,in)!=NULL)
{
	strcpy(s[n],c);
    n++;
}
for(i=0;i<n;i++)
{
	for(j=0;j<strlen(s[i]);j++)
	{
		if(s[i][j]>='A'&&s[i][j]<='Z')
	    {
		s[i][j]=s[i][j]+32;
	    }
	}
}
for(i=0;i<n;i++)
{
	q=0;
    for(j=0;j<strlen(s[i]);j++)
	{
		if(s[i][j]>='a'&&s[i][j]<='z')
		{
			x[p][q]=s[i][j];
			q++;
		}
		else
		{
			p++;
			q=0;
		}
	}	
}
for(i=0;i<p;i++)
{
	for(j=0;j<p-i-1;j++)
	{
		if(strcmp(x[j],x[j+1])>0)
		{
			strcpy(l,x[j]);
			strcpy(x[j],x[j+1]);
			strcpy(x[j+1],l);
		}
	}
}
for(i=0;i<p;i++)
{
	if(strcmp(x[i],x[i+1])!=0)
	{
		strcpy(b[tmp],x[i]);
		tmp++;
	}
	else
	{
		a[tmp]++;
	}
} 
for(i=1;i<tmp;i++)
{
	printf("%s %d\n",b[i],a[i]);
}
fclose(in);
return 0;
}




