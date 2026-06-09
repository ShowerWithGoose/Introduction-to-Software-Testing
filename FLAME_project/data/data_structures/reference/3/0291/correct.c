#include<stdio.h>
int main()
{
	char s[200],s2[200];
	gets(s);
	int i=1,j=0,k=0,m=2,n=0,cnt=0,front=0;
	for(i=1;s[i]!='\0';i++)
	{
		if(s[i]=='.')
		{
			for(j=0;j<i;j++)
			{
				front = (int)(s[j] - '0') + front*10;
			}
			if(front<10&&front>0)
			{
				for(n=0;s[n]!='\0';n++)
					printf("%c",s[n]);
				printf("e0");
				break;
			}
			if(front==0)
			{
				k=i+1;
				for(k;s[k]!='\0';k++)
				{
					if(s[k]!='0')
						break;
					else
						cnt++;
				}
				s2[0]=s[k];
				if(s[k+1]=='\0')
				{
					
					printf("%c",s2[0]);
					printf("e-%d",cnt+1);
				}
				else
				{
					s2[1]='.';
					for(k+=1;s[k]!='\0';k++)
					{
						s2[m]=s[k];
						m++;
					}
					s2[m]='\0';
					for(n=0;s2[n]!='\0';n++)
						printf("%c",s2[n]);
					printf("e-%d",cnt+1);
				}
			}
			else
			{
				s2[0]=s[0];
				s2[1]='.';
				for(k=1;s[k]!='\0';k++)
				{
					if(s[k]=='.')
						continue;
					s2[m]=s[k];
					m++;
				}
				s2[m]='\0';
				for(n=0;s2[n]!='\0';n++)
					printf("%c",s2[n]);
				printf("e%d",i-1);
			}
		}
	}
	return 0;
 } 

