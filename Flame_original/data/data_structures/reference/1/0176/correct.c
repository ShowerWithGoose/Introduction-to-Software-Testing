#include <stdio.h>
#include <string.h>
char s[]="123456789a";
int flag[10]={0};
char put[10];
int len;
void fa(int ); 
int main()
{
	int n;
	scanf("%d",&n);
	s[n]=0;
	len=strlen(s)-1;
	fa(0);
	return 0;
}
void fa(int n)
{
	int i;
	for(i=0;i<=len;i++)
	{
		if(!flag[i])
		{
			flag[i]=1;
			put[n]=s[i];
			if(n==len)
			{
				for(n=0;n<len;n++)
				{
					if(put[n]=='a')
					printf("10 ");
					else printf("%c ",put[n]);
				}
				if(put[len]=='a')	printf("10\n");
				else printf("%c\n",put[len]);
			}
			else fa(n+1);
			flag[i]=0;
		}
	}
}



