#include<stdio.h>
#include<string.h>
int main()
{
	char a[100]={'\0'},b[100]={'\0'};
	int k=0;
	gets(a);
	for(int i=0;a[i]!='\0';i++)
	{int j=0;char t[100]={'\0'};
	b[k++]=a[i];
		if(a[i]=='-')
		{
			if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1])
			{
					for(j=0;j<(a[i+1]-a[i-1]-1);j++)
				t[j]=a[i-1]+1+j;
				k--;	b[k]='\0';k=k+a[i+1]-a[i-1]-1;	strcat(b,t);}
			if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])
			{
			for(j=0;j<(a[i+1]-a[i-1]-1);j++)
				t[j]=a[i-1]+1+j;
				k--;	b[k]='\0';k=k+a[i+1]-a[i-1]-1;	strcat(b,t);}
			if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1])
			{
			for(j=0;j<(a[i+1]-a[i-1]-1);j++)
				t[j]=a[i-1]+1+j;
			k--;	b[k]='\0';k=k+a[i+1]-a[i-1]-1;	strcat(b,t);}
		}
		
	}
	puts(b);
}



