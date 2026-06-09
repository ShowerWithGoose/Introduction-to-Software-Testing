#include <stdio.h>
#include <string.h>
int main()
{
	char s[205] ;
	int len,i=0,j=0,k=0,l=0;
	gets(s);
	len=strlen(s) ;
	for(i=0;i<len;i++)//找出. 
	{
		if(s[i]=='.')
		{
			k=i;
			break;
		}
	}
	if(k==1)
	{
		if(s[0]=='0')
		{
			for(i=2;i<len;i++)
			{
				if(s[i]!='0')
				{
					j=i;
					break;
				}
			}
			if(j!=len-1) //0.222 
			{
				printf("%c.",s[j]) ;
				l=j+1;
				for(;l<len;l++)
				printf("%c",s[l]) ;
				printf("e-%d",j-1) ;
			}
			else //0.0002
			{
				printf("%c",s[j]) ;
				l=j+1;
				for(;l<len;l++)
				printf("%c",s[l]) ;
				printf("e-%d",j-1) ;
			}
		}
		else//3.14
		{
			for(i=0;i<len;i++)
			printf("%c",s[i]) ;
			printf("e0") ;
		}
	}
	else//说明是10000.1这种的
	 {
	 	printf("%c.",s[0]) ;
	 for(i=1;i<len;i++)
	 {
	 	if(s[i]!='.')
		 printf("%c",s[i]) ;
	 }
	 printf("e%d",k-1) ;
	 }
	return 0;
}



