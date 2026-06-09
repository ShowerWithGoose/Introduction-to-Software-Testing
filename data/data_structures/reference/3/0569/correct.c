#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
char s[500],num[100];

int main()
{
	gets(s);
	int i,j,n1,n2=-1;
	for(i=j=0;s[i]!='\0';i++){
		if(s[i]=='.')
			n1=i;
		if(n2==-1&&s[i]<='9'&&s[i]>'0')
			n2=i;
		if(n2!=-1&&isdigit(s[i]))
			num[j++]=s[i];			
	}
	for(i=0;i<strlen(num);i++){
		if(i==1)  printf(".");
		printf("%c",num[i]);	
	}
	printf("e%d",n1-n2<0? n1-n2 : n1-n2-1);
	return 0;
}




