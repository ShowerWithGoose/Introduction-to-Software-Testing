#include<stdio.h>
#include<string.h>
int main()
{
	char a[200];
	int i,len,ws=0,b[200],j=0,zs=0,m=0,n=0; 
	scanf("%s",a);
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]=='.')
			n=1;
		if(n==1)
			ws=ws+1;
		if(a[i]!='0'&&a[i]!='-'&&a[i]!='.')
			m=1;
		if(m==1&&a[i]!='.')
			b[j++]=a[i]-'0';
	}
	ws=ws-1;
	if(a[0]=='-')
		printf("-");
	for(i=0;i<j;i++)
	{
		if(i==1)
			printf(".%d",b[i]);
		else
		printf("%d",b[i]);
	}
	zs=j-1-ws;
	printf("e%d",zs);
	return 0;
	
}



