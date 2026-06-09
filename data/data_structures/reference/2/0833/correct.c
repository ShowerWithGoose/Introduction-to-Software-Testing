#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
char a[200];
void qudiao(char *);

int main() {
gets(a);
qudiao(a);
int n[200]={0},i,j,k=0,d,e,nu;
char f[200];


for(i=0,j=1;a[k]!='=';k++)
{
	if(a[k]>='0'&&a[k]<='9')
	{
		n[i]=10*n[i]+a[k]-'0';
	}
	else
	{
		f[j++]=a[k];
		i++;
	}	
}

d=j,j=1;
for(i=1;i<d;i++)
{
	if(f[i]=='-'||f[i]=='+')
	{
		f[j]=f[i];
		n[j]=n[i];
		j++;	
	}
	else if(f[i]=='*')
	n[j-1]=n[i]*n[j-1];
	else if(f[i]=='/')
	n[j-1]=n[j-1]/n[i];	
}

e=j;
nu=n[0];
for(i=1;i<e;i++)
{
	if(f[i]=='+')
	nu+=n[i];
	if(f[i]=='-')
    nu-=n[i];
}
printf("%d",nu);
return 0;
}



void qudiao(char *s)
{
	int i,j;
for(i=j=0;s[i]!='\0';i++)
if(s[i]!=' ')
s[j++]=s[i];
s[j]='\0';
}


