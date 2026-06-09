#include<stdio.h>
#include<string.h>
int main()
{
	char s[110]=" ",t[110]=" ";
	int l,h=0,i,j;
	gets(s);
	l=strlen(s);
	if(s[0]=='-')
	{
		if(s[1]=='0')
		{
			i=3;
			while(s[i]=='0')
			{
				h++;
				i++;
			}
			if(i==l-1)
			{
			    printf("-%ce-%d",s[i],h+1);
			    return 0;
			}
			else
			{
				printf("-%c.",s[i]);
				for(j=i+1;j<l;j++)
				{
					printf("%c",s[j]);
				}
				printf("e-%d",h+1);
				return 0;
			}
		}
		else{
			printf("-%c.",s[1]);
			i=2;
			while(s[i]!='.')
			{
				h++;
				i++;
			}
			j=i;
			for(i=2;i<j;i++)
			{
				printf("%c",s[i]);
			}
			for(i=j+1;i<l;i++)
			{
				printf("%c",s[i]);
			}
			printf("e%d",h);
			return 0;
		}	
	}
	else
	{
		if(s[0]=='0')
		{
			i=2;
			while(s[i]=='0')
			{
				h++;
				i++;
			}
			if(i==l-1)
			{
			    printf("%ce-%d",s[i],h+1);
			    return 0;
			}
			else
			{
				printf("%c.",s[i]);
				for(j=i+1;j<l;j++)
				{
					printf("%c",s[j]);
				}
				printf("e-%d",h+1);
				return 0;
			}
		}
		else{
			printf("%c.",s[0]);
			i=1;
			while(s[i]!='.')
			{
				h++;
				i++;
			}
			j=i;
			for(i=1;i<j;i++)
			{
				printf("%c",s[i]);
			}
			for(i=j+1;i<l;i++)
			{
				printf("%c",s[i]);
			}
			printf("e%d",h);
			return 0;
		}	
	}
 } 

