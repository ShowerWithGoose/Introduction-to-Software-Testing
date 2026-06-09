#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
	char ch[10005];
	char ch0[1005];
	gets(ch);
	for(int i,j=0;i<strlen(ch);i++)
	{
		if(ch[i]!=' ')
		{
			ch0[j]=ch[i];
			j++;
		}
		if(ch0[i]>='0'&&ch0[i]<='9')
			num++;
		
	}
	if(num==(strlen(ch0)-1))
	{
		for(int k=0;k<strlen(ch0)-1;k++)
			printf("%c",ch0[k]);
	}
	
	return 0;
}

