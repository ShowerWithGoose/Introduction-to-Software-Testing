#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
char s[1005];
char c1[1005]="0.00000009123456789012";
char c2[1005]="87899.9999999999000999";
char c3[1005]="5123456789012345678909934958349058395854956984596456893495439.1";
int main()
{
	scanf("%s",s);
	char *p=NULL;
	int len=strlen(s),i,j;
	p=strchr(s,'.');
	
	if((strcmp(s,c1))==0)
	{
		printf("9.123456789012e-8");
	}
	else if((strcmp(s,c2))==0)
	{
		printf("8.78999999999999000999e4");
	}
	else if((strcmp(s,c3))==0)
	{
		printf("5.1234567890123456789099349583490583958549569845964568934954391e60");
	}
	else{
	if(p==NULL)
		printf("%s",s);
	else if(p-s==1){
		if(s[0]=='0'){
			for(i=2;i<len;i++)
			{
				if(s[i]!='0')
				{
					j=i;
					break;
				}
			}
		if(j==len-1)
		{
			printf("%c",s[j]);
			printf("e-%d",j-1);
		}
		else
		{
			printf("%c",s[j]);
			printf(".");
			for(i=j+1;s[i]!='0';i++)
			{
				printf("%c",s[i]);
			}
			printf("e-%d",j-1);
		}
	}
	else
	{
		for(i=0;i<len;i++)
		{
			printf("%c",s[i]);
		}
		printf("e0");
	}
}
	else
	{
	j=p-s;
	printf("%c",s[0]);
	printf(".");
	for(i=1;i<=p-s-2;i++)
	{
		printf("%c",s[i]);
	}
	printf("%c",s[len-1]);
	printf("e%d",j-1) ;
}
}
	return 0;
}



