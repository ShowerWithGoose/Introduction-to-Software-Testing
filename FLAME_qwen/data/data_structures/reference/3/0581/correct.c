#include <stdio.h>
#include <string.h>

int main()
{
	int i,l,dot=0,num=0,t1=0,e=0;
	char ch[150]="";
	gets(ch);
	l=strlen(ch);
	for(i=0;i<l&&(dot==0||t1==0);i++)
	{
		if(ch[i]!='0')
		{
			if(ch[i]=='.')
			{
				dot=i;
			}
			else if(t1!=1)
			{
				num=i;
				t1=1;
			}
		}
	}
	if(dot==0)
	{
		e=l-num-1;
	}
	else if(dot>num)
	{
		e=dot-num-1;
	}
	else
	{
		e=dot-num;
	}
	printf("%c",ch[num]);
	if(num!=l-1) printf(".");
	for(i=num+1;i<l;i++)
	{
		if(ch[i]!='.')
		putchar(ch[i]);
	}
	printf("e%d\n",e);
	return 0;
}

