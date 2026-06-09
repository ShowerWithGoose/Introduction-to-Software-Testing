#include<stdio.h>
#include<string.h>
int main(){
	char a[106],b[106];
	int n,j=0,pd=0,pds=1,k1,k2;
	gets(a);
	n=strlen(a);
	for(int i=0;i<n;i++)
	{
		if(pds&&a[i]<='9'&&a[i]>='1')
		{
			pd=1;pds=0;k1=i;
		}
		if(a[i]<='9'&&a[i]>='0'&&pd)
		{
			b[j]=a[i];
			j++;
		}
		
		if(a[i]=='.')
		{
			k2=i;
		}
	}
	if(a[0]=='-')	printf("-");
	printf("%c",b[0]);
	if(j>k2) printf(".");
	for(int i=1;i<j;i++){	printf("%c",b[i]);	}
	if(k2<k1 )printf("e%d",k2-k1);
	if(k2>k1 )printf("e%d",k2-k1-1);
		return 0;
}



