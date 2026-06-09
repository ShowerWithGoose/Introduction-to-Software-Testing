#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
 

int main()
{
	char s0[500][500],s[500][500],p[500][500],p0[500];
	int a[500]={0},i0=1,i=1,j,m,b[500],k,l;
	FILE *in;
	in=fopen("article.txt","r");
	while(fscanf(in,"%s",s0[i0])!=EOF)
	{
		k=0;
		for(j=0;j<strlen(s0[i0]);j++)
		{
			if(s0[i0][j]>='A'&&s0[i0][j]<='Z')
			{
				
				s[i][k]=s0[i0][j]-'A'+'a';
				k++;
			}
			else if(s0[i0][j]>='a'&&s0[i0][j]<='z')
			{
				
				s[i][k]=s0[i0][j];
				k++;
			}
			else if((s0[i0][j]<'A'||(s0[i0][j]>'A'&&s0[i0][j]<'a')||s0[i0][j]>'z')&&k!=0&&((s0[i0][j+1]>'A'&&s0[i0][j+1]<'Z')||(s0[i0][j+1]>'a'&&s0[i0][j+1]<'z')))
			{
				s[i][k]='\0';
				i++;
				k=0;
			}
		}
		if(k!=0)
		{
			s[i][k]='\0';
			i++;
		}
		
		i0++;
	}
	m=i-1;
	for(i=1;i<=m;i++)
	{
		
		for(j=1;j<=i;j++)
		{
			if(strcmp(s[i],s[j])==0)
			{
				a[j]++;
				if(i!=j)
				{
					a[i]=0;
				}
				j=i+1;
			}
		}
	}
	j=1;
	for(i=1;i<=m;i++)
	{
		if(a[i]!=0)
		{
			strcpy(p[j],s[i]);
			b[j]=a[i];
			j++;
		}
	}
	for(i=1;i<j;i++)
	{
		for(k=i+1;k<j;k++)
		{
			if(strcmp(p[i],p[k])>0)
			{
				strcpy(p0,p[i]);
				strcpy(p[i],p[k]);
				strcpy(p[k],p0);
				l=b[i];
				b[i]=b[k];
				b[k]=l;
			}
		}
	}
	for(i=1;i<j;i++)
	{
		printf("%s %d\n",p[i],b[i]);
	}
	
	fclose(in);
	
	return 0;
}

