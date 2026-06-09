#include<stdio.h>
#include<string.h>
char a[10000];
int ok(char a[],int i,int k)
{
	if(a[i]>='0'&&a[i]<='9'&&a[k]>='0'&&a[k]<='9'&&a[k]>a[i])return 1;
	else if(a[i]>='a'&&a[i]<='z'&&a[k]>='a'&&a[k]<='z'&&a[k]>a[i])return 2;
		else if(a[i]>='A'&&a[i]<='Z'&&a[k]>='A'&&a[k]<='Z'&&a[k]>a[i])return 3;
		else return 0;
}
int main()
{
int i,j,k;
scanf("%s",a);
for(i=0;i<strlen(a);i++)
{
	j=i+1;
	k=j+1;
	int s=ok(a,i,k);
	char d=a[i];
	if(a[j]=='-'&&s>0)
	{for(d=a[i];d<a[k];d++)printf("%c",d);i++;}
	else {
		
		printf("%c",a[i]);
		
	}

	
}
return 0;
}

