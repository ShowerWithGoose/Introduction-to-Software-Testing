#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char s[500],s1[500];
	gets(s);
	int i,j,k,len,len1,flag=0;
	len=strlen(s); 
	len1=len;
	for(i=0;i<len;i++)
	{
		s1[i]=s[i];
	}
	for(i=0;i<len1;i++)
	{
		while(s1[i]=='.')
		{
			for(j=i;j<=len;j++)
			{
				s1[j]=s1[j+1];
			}
			len1--;
		}
	}//删.
	//puts(s1);
	i=0;j=0;
	for(i=0;i<len;i++)
	{
		if(s[i]!='0'&&s[i]!='.')
		{
			k=i;//k为首个有效数字位置
			flag++; 
		}
		if(flag==1)
		break;
	}
	for(i=0;i<len;i++)
	{
		if(s[i]=='.')
		{
			j=i;//j为小数点位置 
		}
	}
		//printf("%d %d\n",k,j);
		if(k>j)//0.000xx
		{
			if(s[k+1]=='\0')//0.00x
			printf("%ce-%d",s[k],k-j);
			else//0.00xxx
			{
				printf("%c",s[k]);
				printf(".");
				for(i=k+1;i<len;i++)
				{
					printf("%c",s[i]);
				}
				printf("e-%d",k-j);
			}
		}
		else if(k<j)//xxx.xxx
		{
			if((j-k)==1)//x.xxxx
			{
				for(i=0;i<len;i++)
				{
					printf("%c",s[i]);
				}
				printf("e0");
			}
			else//xxx.xxx
			{
				printf("%c.",s1[0]);
				for(i=1;i<len1;i++)
				{
					printf("%c",s1[i]);
				}
				printf("e%d",j-k-1);
			}
		}
		
	return 0;
}

