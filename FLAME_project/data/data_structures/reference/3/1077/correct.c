#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	char s[105];
	int i,j,k,m,n,q,p,t,x;
	scanf("%s",s);
	m=strlen(s);
		if(s[0]>'0')
		{
			for(i=0;i<m;i++)
			{ 
				if(s[i]=='.')
				{
					j=i-1;
				}
			}
			for(x=j+1;x<m;x++)
			{
				s[x]=s[x+1];
			}
			printf("%c",s[0]);
			printf(".");
			for(n=1;n<m-1;n++)
			{
				printf("%c",s[n]);
			}
			printf("e");
			printf("%d",j);
		}
		else if(s[0]=='0')
		{
			for(q=2;q<m;q++)
			{
				if(s[q]!='0')
				{
				k=q-1;
				p=q;
				break;
				}
			}
			printf("%c",s[p]);
			if(s[q+1]!='\0')
			{
				printf(".");
			} 
			for(t=p+1;t<m;t++)
			{
				printf("%c",s[t]);
			}
			printf("e");
			printf("-");
			printf("%d",k);
			
		}
	return 0;
}

