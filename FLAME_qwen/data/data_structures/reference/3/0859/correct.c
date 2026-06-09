#include<stdio.h>
#include<math.h>
int main()
{
	char s[105];
	char z[105];
	char r[105];
	scanf("%s",s);
	int i,n,m=0;
	int j=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!='.')
		{
			z[j]=s[i];
			j++;
		}
		else
		m=i;
	 }
	 z[j]='\0';
	 for(n=0;z[n]=='0';n++);
	 printf("%c",z[n]);
	 if(n==0&&m==0)
	 {
	 	for(i=1;z[i]=='0';i++);
	 	if(i>=j)
	 	printf("e%d",j-1);
	 	else
	 	{
	 		printf(".");
	 		for(i=1;z[i]!='\0';i++)
	 		printf("%c",z[i]);
	 		printf("e%d",j-1);
		 }
	 }
	 else if(n==0)
	 {
	 	printf(".");
	 	for(i=1;z[i]!='\0';i++)
	 	printf("%c",z[i]);
	 	printf("e%d",m-1);
	 }
	 else
	 {
	 	if(z[n+1]=='\0')
	 	printf("e%d",-n);
	 	else
	 	{
	 		printf(".");
	 		for(i=n+1;z[i]!='\0';i++)
	 		printf("%c",z[i]);
	 		printf("e%d",-n);
		 }
	 }
	 return 0;
}

