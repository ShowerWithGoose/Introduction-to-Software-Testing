#include <stdio.h>
#include <string.h>

#define MAXN 100000

char s[MAXN],str[MAXN]; 

void expand(char a[])
{
	char b[MAXN];
	strcpy(b,a);
	memset(str,0,sizeof(str));
	char *p=strchr(b,'-');
	if(p==NULL)
	{
		printf("%s",b);
		return;
	}
	char x=*(p-1),y=*(p+1);
	*p='\0';
	strcpy(str,p+1); 
	printf("%s",b);
	if(((x>='a')&&(x<='z')&&(y>='a')&&(y<='z'))||((x>='A')&&(x<='Z')&&(y>='A')&&(y<='Z'))||((x>='0')&&(x<='9')&&(y>='0')&&(y<='9')))
	{
		for(int i=x+1;i<y;i++)
		{
			char c=i;
			printf("%c",c);
		}
	}
	else
	{
		printf("-");
	}
	expand(str);
}

int main()
{
	scanf("%s",s);
	expand(s);
	return 0;
}

