#include<stdio.h>
#include<string.h>
int main(){
	char s[106],b[106];
	int l,n1=0,n=0,pds=1,k1,k2;
	gets(s);
	l=strlen(s);
	for(int i=0;i<l;i++)
	{
		if(pds&&s[i]<='9'&&s[i]>='1')
		{
			n=1;pds=0;k1=i;
		}
		if(s[i]<='9'&&s[i]>='0'&&n)
		{
			b[n1]=s[i];
			n1++;
		}
		
		if(s[i]=='.')
		{
			k2=i;
		}
	}
	if(s[0]=='-')	printf("-");
	printf("%c",b[0]);
	if(n1>k2) printf(".");
	for(int i=1;i<n1;i++){	printf("%c",b[i]);	}
	if(k2<k1 )printf("e%d",k2-k1);
	if(k2>k1 )printf("e%d",k2-k1-1);
		return 0;
}



