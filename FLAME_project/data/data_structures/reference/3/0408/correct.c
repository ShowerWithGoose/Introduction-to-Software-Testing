#include <stdio.h>
#include <string.h>
int main()
{
	char s[105];
	gets(s);
	int len=strlen(s),i=0,flag;
    if(s[0]!='0')
{
	    printf("%c.",s[0]);
		for(i=1;i<len;i++)
	 {
		if(s[i]=='.') flag=i;
		else printf("%c",s[i]);
	 }
	    printf("e%d",flag-1);
}
	
	else
{
	for(i=1;i<len;i++)
	{
		if(s[i]!='0'&&s[i]!='.') 
		{
			flag=i;
			if(i==len-1) printf("%c",s[i]);
			else printf("%c.",s[i]);
			break;
		}
	}
	for(i+=1;i<len;i++)
    {
		printf("%c",s[i]);
    }
	printf("e-%d",flag-1);
	
}

	return 0;
}



