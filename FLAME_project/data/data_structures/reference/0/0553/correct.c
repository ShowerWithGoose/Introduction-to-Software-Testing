#include<stdio.h>
#include<string.h>
int main()
{
	char c0,c,c1,i;
	while((c=getchar())!=EOF){
		if(c!='-')
		{
			c0=c;
			putchar(c);
		}
		else{
			c1=getchar();
			if((c0>='a'&&c0<='z'&&c1>='a'&&c1<='z'&&c0<c1)||(c0>='A'&&c0<='Z'&&c1>='A'&&c1<='Z'&&c0<c1)||(c0>='0'&&c0<='9'&&c1>='0'&&c1<='9'&&c0<c1))
			{
				for(i=c0+1;i<=c1;i++)
				{
					putchar(i);
				}
				c0=c1;
			}
			else{
				putchar(c);
				putchar(c1);
			}
		}
	}
	return 0;
}

