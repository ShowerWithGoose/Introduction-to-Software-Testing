#include<stdio.h>
#include<string.h>
#define MAX 2000
int main()
{
	char str[MAX];
	scanf("%s",str);
	char *p=str;
for(int i=0;str[i]!='\0';i++)
{
    if(str[i]!='-')
    {printf("%c",str[i]);}
    else
{
	p=strchr(p,'-') ;
		if(*(p-1)>='a'&&*(p+1)<='z'&&*(p-1)<*(p+1))
		{
			for(int i=*(p-1)+1;i<*(p+1);i++)
			{
				printf("%c",i);
			}
		}
		else if(*(p-1)>='A'&&*(p+1)<='Z'&&*(p-1)<*(p+1))
		{
			for(int i=*(p-1)+1;i<*(p+1);i++)
			{
				printf("%c",i);
			}
		}
		else if(*(p-1)>='0'&&*(p+1)<='9'&&*(p-1)<*(p+1))
		{
			for(int i=*(p-1)+1;i<*(p+1);i++)
			{
				printf("%c",i);
			}
		}
    
    else
    {
    	printf("-");
	}
		p++;
}
}
	return 0;
}

