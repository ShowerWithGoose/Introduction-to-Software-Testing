#include <stdio.h>
int flag;
void expand(int from,int to); 
int main()
{
	int sign=getchar(),from,to;
	while(sign!=-1&&sign!='\n')
	{
		while(sign!=-1&&sign!='\n'&&sign!='-')
		{
			from=sign;
			printf("%c",from);
			sign=getchar();
		}
		if(sign==-1||sign=='\n')
			break;
		to=getchar();
		expand(from,to);
		from=to;
		sign=getchar();
	}
	return 0;
}
void expand(int from,int to)
{
	int cnt;
	if(from>='a'&&to>='a'&&from<='z'&&to<='z'&&to>from)
		for(cnt=from+1;cnt<=to;cnt++)
			printf("%c",cnt);
	else if(from>='A'&&to>='A'&&from<='Z'&&to<='Z'&&to>from)
		for(cnt=from+1;cnt<=to;cnt++)
			printf("%c",cnt);
	else if(from>='0'&&to>='0'&&from<='9'&&to<='9'&&to>from)
		for(cnt=from+1;cnt<=to;cnt++)
			printf("%c",cnt);
	else
		printf("-%c",to);
}

