#include<stdio.h>
#include<string.h>
#include<math.h> 
char s1[1000];
char s2[1000];
int main()
{
	int i=0,j=0,k=0;
	scanf("%s",s1);
	for(i=0,j=0;s1[i]!='\0';i++,j++)
	{
		s2[j]=s1[i];
		if(s1[i+1]=='-')//确定-位置 
		{
			if(s1[i]<s1[i+2]&&s1[i]>='a'&&s1[i+2]<='z')//判断-前后是否符合要求 
			{
				for(k=1;s1[i]+k<s1[i+2];k++,j++)
				{
					s2[j+1]=s1[i]+k;
				}
				i++;
			}
			else if(s1[i]<s1[i+2]&&s1[i]>='A'&&s1[i+2]<='Z')
			{
				for(k=1;s1[i]+k<s1[i+2];k++,j++)
				{
					s2[j+1]=s1[i]+k;
				}
				i++;
			}
			else if(s1[i]<s1[i+2]&&s1[i]>='0'&&s1[i+2]<='9')
			{
				for(k=1;s1[i]+k<s1[i+2];k++,j++)
				{
					s2[j+1]=s1[i]+k;
				}
				i++;
			}
		}
		
	}
	s2[j]=='\0';
	printf("%s",s2);
	
	
	
return 0;
}




