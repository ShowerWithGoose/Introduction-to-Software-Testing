#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char a[1000]={0};
int i,k,len;
int main()
{
	scanf("%s",a);
	len=strlen(a);

	
	for(i=0;i<len;i++)
	{
		if(('A'<=a[i]  && a[i]<='Z') || ('a'<=a[i] && a[i]<='z') || ('0'<=a[i] && a[i]<='9'))
		{
			printf("%c",a[i]);
		}
		if(a[i]=='-')
		{
			if(('A'<=a[i-1] && a[i-1]<'Z') && ('A'<a[i+1] && a[i+1]<='Z') && a[i-1]<a[i+1])
			for(k=0;k<(a[i+1]-a[i-1]-1);k++)
			printf("%c",a[i-1]+k+1);
			else if(('a'<=a[i-1] && a[i-1]<'z') && ('a'<a[i+1] && a[i+1]<='z') && a[i-1]<a[i+1])
			for(k=0;k<(a[i+1]-a[i-1]-1);k++)
			printf("%c",a[i-1]+k+1);
			else if(('0'<=a[i-1] && a[i-1]<'9') && ('0'<a[i+1] && a[i+1]<='9') && a[i-1]<a[i+1])
			for(k=0;k<(a[i+1]-a[i-1]-1);k++)
			printf("%c",a[i-1]+k+1);
			else
			printf("-");
		}
	}

return 0;
}


