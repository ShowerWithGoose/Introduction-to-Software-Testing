#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define ll long long //9223372036854775807£¨>10^18£©   int -2^31=-21 4748 3648  2^31-1=21 4748 3647
#define ull unsigned ll
#define db double

char s[2000];
int main()
{
	int flag1,flag2,flag3,t,dw,j,sp;
	gets(s);
	flag1=0;
	flag2=0;
	flag3=1;
	t=strlen(s);
	for(int i=0;i<t;i++)
	{
		if(s[i]>'0'&&s[i]<='9')
		{
			flag1+=1;
			if(flag1==1)
			{
				sp=i;
			}
		}  
		else if(s[i]=='.')
		{
			flag2=1;
			dw=i;
			if(flag1>1)
			{
				for(int j=i;j>1;j--)
				{
					s[j]=s[j-1];
				}
				s[1]='.';
			}
			if(!flag1)
			{
				flag3=0;
			}
		}
	}
	if(!flag2)
	{
		if(flag1==1)
		{
			printf("%ce",s[0]);
			printf("%d",t-1);
		}
		else if(!flag1)
		{
			printf("0e0");
		}
		else
		{
			for(j=t;j>1;j--)
		    {
			    s[j]=s[j-1];
	    	}
	    	for(j=t;j>1;j--)
	    	{
	    		if(s[j]=='0')
	    		{
	    			s[j]='\0';
				}
				else 
				   goto out;
			}
			out:
	    	s[1]='.';
		    printf("%se",s);
		    printf("%d",t-1);
		}
	}
	else
	{
		if(flag3)
		{
			for(j=t-1;j>=1;j--)
	    	{
	    		if(s[j]=='0')
	    		{
	    			s[j]='\0';
				}
				else 
				   goto ot;
			}
			ot:
			printf("%se",s);
			printf("%d",dw-1);
		}
		else
		{
			if(flag1==1)
			{
				printf("%ce-",s[sp]);
				printf("%d",sp-1);
			}
			else if(!flag1)
			{
				printf("0e0");
			}
			else
			{
				printf("%c.",s[sp]);
				for(j=t-1;j>=sp;j--)
	    	    {
	    		    if(s[j]=='0')
	    		    {
	    			    s[j]='\0';
				    }
				else 
				   goto oat;
			    }
			    oat:
			    for(j=sp+1;s[j]!='\0';j++)
			    {
			    	printf("%c",s[j]);
				}
				printf("e-%d",sp-1);
			}
		}
	}
} 

