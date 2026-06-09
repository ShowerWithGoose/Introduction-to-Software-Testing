#include<stdio.h>
#include<string.h>

int main()
{
	char a[500];
	int num[500];
	int i=0,n;
	int total=0,l;
	while(scanf("%d %c",&num[i],&a[i])!=EOF)
	{
		
		
		if(a[i]=='=')
		{
			break;
		}
		i++;
		
	 } 
	 n=i;
	 for(i=0;i<n;i++)
	 {
	 	if(a[i]=='*')
	 	{
	 		num[i+1]=num[i]*num[i+1];num[i]=0;
	 		
		 }
		if(a[i]=='/')
		{
			num[i+1]=num[i]/num[i+1];num[i]=0;
		}
	 }
	 for(i=0;i<n;i++)
	 {
	 	if(a[i]=='-'&&a[i+1]!='+')
	 	{
	 		num[i+1]=-num[i+1];
	 		a[i+1]='-';
	 		
		 }
		 else if(a[i]=='-'&&a[i+1]=='+')
		 {
		 	num[i+1]=-num[i+1];
		 }
	 }
	 for(i=0;i<=n;i++)
	 {
	 	total=total+num[i];
	 }
	 printf("%d\n",total);
	 
	 return 0;
}




