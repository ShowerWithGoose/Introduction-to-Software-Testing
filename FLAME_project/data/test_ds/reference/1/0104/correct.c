#include<stdio.h>

int check2(int o)
{
	return ((o>='A')&&(o<='Z'))||((o>='a')&&(o<='z'))||((o>='0')&&(o<='9'));
}

int check(int o)
{
	return check2(o)||(o=='-')||(o==' ');
}

int ck(char o,char p)
{
	if(o>='0'&&o<='9')
	{
		return p>='0'&&p<='9';
	}else
	if(o>='a'&&o<='z')
	{
		return p>='a'&&p<='z';
	}else
	if(o>='A'&&o<='Z')
	{
		return p>='A'&&p<='Z';
	}else return 0;
}

int main()
{
	char ch=getchar(),la=0;
	while(!check(ch)) ch=getchar();
	int bo=0;
	while(check(ch)) 
	{
		if(check2(ch))
		{
			if(la!=0)
			{
				if(la<ch)
				{
					if(bo)
					{
						if(ck(la,ch))
						{
							for(int i=la;i<ch;i++) 
								printf("%c",i);
						}else printf("%c-",la);
					}else printf("%c",la);
					bo=0;
				}else 
				{
					if(bo)
					{
						printf("%c-",la);
					}else printf("%c",la);
				}
			}
			la=ch;
		}else 
		{
			if(ch==' ') {printf("%c ",la);la=0;}
			if(ch=='-'&&la==0) printf("-");
			if(ch=='-') bo=1;
		}
		ch=getchar();
	}	
	printf("%c",la);
	return 0;
}

