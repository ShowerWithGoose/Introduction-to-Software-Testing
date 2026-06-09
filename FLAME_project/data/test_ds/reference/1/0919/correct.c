#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,k,t;
	char s1[207],s2[207];
	scanf("%s",s1);
	s2[0] = s1[0];
	for(i=1,j=1;s1[i] != '\0';i++)
	{
		if (s1[i] != '-')
		{
			s2[j++] = s1[i];
		}else if((s1[i-1]>='A'&&s1[i-1]<='Z'&&s1[i+1]>='A'&&s1[i+1]<='Z'&&s1[i-1]<s1[i+1])||
		(s1[i-1]>='a'&&s1[i-1]<='z'&&s1[i+1]>='a'&&s1[i+1]<='z'&&s1[i-1]<s1[i+1])||
		(s1[i-1]>='0'&&s1[i-1]<='9'&&s1[i+1]>='0'&&s1[i+1]<='9'&&s1[i-1]<s1[i+1])) 
		{
			for(t=1;t+s1[i-1]<s1[i+1];t++)
			{
				s2[j++] = s1[i-1] + t;
			}
		}else{
			s2[j++] = s1[i];
		}
	}
	s2[j] = '\0';
	printf("%s",s2);
	return 0;
}




