#include<stdio.h>
#include<string.h>
int main()
{
	char a[200],b[500];
	int k=0;
	for(k=0;k<=199;k++)
	{
		b[k]='*';
	}
	scanf("%s",a);
	int j,n,l=strlen(a); 
	if(a[0]=='0')//首位为0，即0.几 
	{
		int i;
		for(i=2;i<=l-1;i++)
		{
			j=i;
			if(a[i]=='0')continue;
			if(a[i]!='0')break;
		}
		int t;
		for(t=0;t<=l-1-j;t++)
		{
			b[t]=a[t+j];
		}
		n=j-1;
		printf("%c",b[0]);
		if(b[1]!='*'){
			printf(".");
			for(i=1;i<=l-j-1;i++){
				printf("%c",b[i]);
			}
			printf("e");
			printf("-%d",n);
		}
		else if(b[1]=='*')
		{
			printf("e");
			printf("-%d",n);
		}	
	}
	else if(a[0]!='0')
	{
		int p,q,r;
	 printf("%c",a[0]);
	 printf(".");
	 for(p=1;p<=l-1;p++){
	 	if(a[p]=='.'){
	 		break;
		 }
		 if(a[p]!='.')
		 {
		 	continue;
		 }
	 }
	 if(p==l){
	 	for(q=1;q<=l-1;q++){
	 		printf("%c",a[q]);
		 }
		 printf("e");
		 printf("%d",l-1);
	 }
else if(p!=l){
	for(q=1;q<p;q++)printf("%c",a[q]);
	for(q=p+1;q<=l-1;q++)printf("%c",a[q]);
	printf("e");
	printf("%d",p-1);
}
	}
	return 0;
 } 




