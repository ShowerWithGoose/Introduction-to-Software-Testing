#include<stdio.h>
#include<string.h>
char s[1024];
int p[1000]={0};
int main()
{
	int i,c,flag=0,j=0,k,t,h;
	scanf("%s",s);
	c=strlen(s);
	p[0]=-1;
	for(i=0;i<=c-1;i++)
	{
		if(s[i]=='-'&&((s[i-1]>='0'&&s[i+1]<='9')+(s[i-1]>='a'&&s[i+1]<='z')+(s[i-1]>='A'&&s[i+1]<='Z')==1))
		 {
		 	j++;
		 	p[j]=i;
		 	flag=1;
		 }
	}
	if(flag==0)
	printf("%s",s);
	else
	{
		for(k=1;k<=j;k++)
		{
			for(t=p[k-1]+1;t<p[k];t++)
			printf("%c",s[t]);
			for(h=s[p[k]-1]+1;h<s[p[k]+1];h++)
			printf("%c",h);
		}
		for(h=p[j]+1;h<=c-1;h++)
		printf("%c",s[h]);
	}
	return 0;
}

