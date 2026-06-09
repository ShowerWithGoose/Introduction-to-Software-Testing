#include<stdio.h>
#include<string.h>
char in[1000000],out[1000000];
int judge(char a,char b)
{
	
	if(a>='0'&&a<='9')
	   if(b>='0'&&b<='9')
	    return 1;
	    if(a>='A'&&a<='Z')
			   if(b>='A'&&b<='Z')
			    return 1;
			    if(a>='a'&&a<='z')
					   if(b>='a'&&b<='z')
					    return 1;
	
	return 0;
}
int main()
{

scanf("%s",in+1);
in[0]='p';
for(int i=1;i<=strlen(in);i++)
{
	
	if(in[i+1]!='-'&&in[i-1]!='-'&&in[i]!='-')
	printf("%c",in[i]);
	else if(in[i+1]=='-')
	{
		
		if(judge(in[i],in[i+2]))
		{
			if(in[i+2]>in[i])
			{
				if(in[i-1]!='-')
				for(int j=in[i];j<=in[i+2];j++)
							{
								printf("%c",j);
							}
				else
				for(int j=in[i]+1;j<=in[i+2];j++)
											{
												printf("%c",j);
											}
			}
			
				else
					{
						if(in[i-1]!='-')
						printf("%c-%c",in[i],in[i+2]);
						else
						printf("-%c",in[i+2]);
					}
		}
		else
		{
			if(in[i-1]!='-')
			printf("%c-%c",in[i],in[i+2]);
			else
			printf("-%c",in[i+2]);
		}
		
		
	}
	
	
}
	

}

