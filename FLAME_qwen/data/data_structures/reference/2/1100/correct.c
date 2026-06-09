#include<stdio.h>
int main()
{
	char s[105];
	int n[105],flag[105];
	int i=0,j=0,k=0,a=1,b=0;
	while(s[j-1]!='=')
	{
		scanf("%d",&n[k]);
		k++;
		scanf(" %c",&s[j]);
		j++;
	}
	a=n[0];
	for(i=0;i<j;i++)
	{
	if(s[i]=='*')
		a=a*n[i+1];
	if(s[i]=='/')
		a=a/n[i+1];
	if(s[i]=='+'||s[i]=='-')
	   {
	   	k=1;
	   	b=n[i+1];
	    while(s[i+k]=='*'||s[i+k]=='/')
	    {
		if(s[i+k]=='*')
		b=b*n[i+k+1];
		if(s[i+k]=='/')
		b=b/n[i+k+1];
		k++; 
		}
		if(s[i]=='+')
		a=a+b;
		if(s[i]=='-')
		a=a-b;
		b=0;
		i=i+k-1;
	   }		
    }
    printf("%d",a);
    return 0;
} 



