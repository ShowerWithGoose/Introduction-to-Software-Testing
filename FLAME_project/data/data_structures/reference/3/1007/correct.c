#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char a[101],b[101];
int i,flag1,flag2,num=0,c=0,j=0,s=0;
int main()
{
	scanf("%s",a);
	for(i=0;i<strlen(a);i++){
		if(a[i]=='-')
		flag1=-1;
		if(a[i]=='.')
		flag2=1;
		if(flag2==1)
		num++;
		if(a[i]!='0'&&a[i]!='.'&&a[i]!='-')
		c=1;
		if(c==1&&a[i]!='.')
		b[j++]=a[i]-'0';
	}
	if(flag1==-1)
	printf("-");
	for(i=0;i<j;i++){
		if(i==1)
		printf(".");
		printf("%d",b[i]);
	}
	s=j-num;
	printf("e%d",s);
 	return 0;
}


