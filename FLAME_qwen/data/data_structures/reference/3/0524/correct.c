#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000]={0},n[1000]={0},d[1000]={0};
	scanf("%s",s);
	int t=-1,k=-1,m=0,a=0,b=0,i=0,c=0;
	a=strlen(s);
	for(i=0;s[i]!='.';i++)
	t=i;
	for(i=0;s[i]=='.'||s[i]=='0';i++)
	k=i;
	if(t<=k)
	{
		c=t-k;
		n[0]=s[k+1];
		for(i=k;i+2<a;i++)
		n[i-k+2]=s[i+2];
		if(i!=k)	n[1]='.';
	}
	else
	{
		c=t-k-1;
		for(i=0;i<a;i++)
	    {
		    if(i>=2&&i<=t+1)
		    n[i]=s[i-1];
		    else
		    n[i]=s[i];
	    }
	    n[1]='.';
	}
    printf("%s",n);
    printf("e%d",c);
	return 0;
}

