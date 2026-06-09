#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
char s[100000]; 
int main()
{
	int i,j;
	scanf("%s",s);
	int k=0;
	while (s[k]!='\0')
	{
		if (s[k]=='-')
		{
			if (islower(s[k-1])&&islower(s[k+1]))
			{
				for (j=s[k-1]-'a'+1;j<=s[k+1]-'a';j++)
				 printf("%c",j+'a');
				 	k+=2;
			}
			else if (isupper(s[k-1])&&isupper(s[k+1]))
			{
				for (j=s[k-1]-'A'+1;j<=s[k+1]-'A';j++)
				 printf("%c",j+'A');
				 	k+=2;
			}
			else if (s[k-1]>='0'&&s[k-1]<='9'&&s[k+1]>='0'&&s[k+1]<='9')
			{
				for (j=s[k-1]-'0'+1;j<=s[k+1]-'0';j++)
				 printf("%c",j+'0');
				 	k+=2;
			}
		   else {
		   	printf("%c",s[k]);
		   	k++;
		   }
		}
		else {
			printf("%c",s[k]);
			k++;
		}
	}
	return 0;
}


