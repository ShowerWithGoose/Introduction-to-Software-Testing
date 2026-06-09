#include<stdio.h>
#include<string.h>
#include<ctype.h>
char ch[105];
int num,f,bum1;
char ch2[105],first,fi[105];
int main()
{
	gets(ch);
	if(ch[0]=='0')
	{
		num+=2;
		while(ch[num]=='0')
		num++;
		bum1=num;
		while(ch[bum1]!='\0')
		{
			if(f==0)
			first=ch[bum1],f++;
			else
			{
				ch2[f-1]=ch[bum1];
				f++;
			}
			bum1++;
		}
		if(f!=1)
		printf("%c.%se-%d",first,ch2,num-1);
		else
		printf("%ce-%d",first,num-1);
	}
	else
	{
		while(ch[num]!='.')
		{
			if(f==0)
			first=ch[num],f++,num++;
			else
			fi[num-1]=ch[num],num++;
		}
		f=num-1;
		num++;
		while(ch[num]!='\0')
		{
			fi[num-2]=ch[num];
			num++;
		}
		printf("%c.%se%d",first,fi,f);
	}
	return 0;
}

