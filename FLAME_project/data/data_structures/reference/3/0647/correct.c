#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	int point=0;
	scanf("%s",s);
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]=='.') 
		{
            point =i;
            break;
        }
	}
	if(point==1 && s[0]!='0')
	{
		printf("%s",s);
		printf("e0");
	}
	else if(point>=2)
	{
        printf("%c",s[0]);
		printf(".");
        int j=1;
		for(j=1;j<point;j++)
		printf("%c",s[j]);
		for(j=point+1;j<strlen(s);j++)
		printf("%c",s[j]);	
		printf("e%d",point-1);
	} 
	else if(point==1 && s[0]=='0')
	{
		int j=point+1;
		for(j=point+1;s[j]=='0';j++);
		int cnt = j;
		if(cnt==strlen(s)-1)
		{
			printf("%c",s[cnt]);
			printf("e-%d",cnt-1);
		}
		else
		{
		   printf("%c.",s[cnt]);
		   for(j++;j<=strlen(s)-1;j++)
		   {
		     	printf("%c",s[j]);
		   }
		   printf("e-%d",cnt-1);
	    }
	}
}

