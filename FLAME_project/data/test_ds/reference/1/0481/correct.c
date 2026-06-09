#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	char s[1000];
	char s_expand[1200];
	scanf("%s",s);
	int i=1,j=1,k,p;
	s_expand[0]=s[0]; 
	while(i<strlen(s))
	{
		if(s[i]=='-'&&s[i-1]<s[i+1])
		{
			k=s[i+1]-s[i-1];
			if((s[i-1]>='0'&&s[i+1]<='9')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='a'&&s[i+1]<='z'))
			{
				for(p=1;p<k;p++)
				{
					s_expand[j++]=s[i-1]+p;
				}
				i++;	
			}
			else 
			{
				s_expand[j++]=s[i++];
			}
		}
		else
		{
			s_expand[j++]=s[i++];
		}
	} 
	printf("%s",s_expand);
	return 0;
}




