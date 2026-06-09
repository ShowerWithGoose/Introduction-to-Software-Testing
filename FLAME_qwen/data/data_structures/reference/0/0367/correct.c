#include <stdio.h>
#include <string.h>
int main()
{	char str[1000];
	gets(str);
	char *p=strchr(str,'-');
	char *q=str;
	int i;
	while(p!=NULL)
	{	
		if((*(p+1)>='a'&&*(p+1)<='z'&&*(p-1)>='a'&&*(p-1)<='z')||(*(p+1)>='A'&&*(p+1)<='Z'&&*(p-1)>='A'&&*(p-1)<='Z')||(*(p+1)>='0'&&*(p+1)<='9'&&*(p-1)>='0'&&*(p-1)<='9'))
		{	if(*(p+1)-*(p-1)>0)
			{	*p='\0';
				printf("%s",q);
				
				for(i=1;i<=*(p+1)-*(p-1)-1;i++)
				printf("%c",*(p-1)+i);
				q=p+1;
				
			}
		}
		
		p=strchr(p+1,'-');
	}
	printf("%s",q);
	return 0;
}

