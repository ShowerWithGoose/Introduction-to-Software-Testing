#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	char s[101];
	int len,i=0,n=0,m;
	gets(s);
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]=='.')
		{
			n=i;
			break;
		}
	}
	if(n==0){
		printf("%c.",s[0]);
		for(i=1;i<len;i++)
		printf("%c",s[i]);
		printf("e%d",len-1);
	}
	else if(s[0]!='0'&&s[1]=='.'){
		printf("%se0",s);
	}
	else if(s[0]!='0'&&n>1){
		printf("%c.",s[0]);
		for(i=1;i<n;i++)
		printf("%c",s[i]);
		for(i=n+1;i<len;i++)
		printf("%c",s[i]);
		printf("e%d",n-1);
	}
	else{
		for(i=0;i<len;i++)
		{
			if(s[i]!='0'&&s[i]!='.')
			{
				m=i;
				break;
			}
		}
		if(m<len-1){
			printf("%c.",s[m]);
			for(i=m+1;i<len;i++){
			printf("%c",s[i]);
			}
		}
		
		else printf("%c",s[m]);
		
		printf("e-%d",m-1);
	}
	return 0;
} 


