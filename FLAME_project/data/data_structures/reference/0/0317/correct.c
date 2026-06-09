#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main()
{
	int i,j;
	char a[100];
	
	gets(a);
	
	
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i+1]!='-')
			printf("%c",a[i]);
		else
		{
			if(i<=strlen(a)-3 && (('A'<=a[i] && a[i]<='Z' && 'A'<=a[i+2] && a[i+2]<='Z') || ('a'<=a[i] && a[i]<='z' && 'a'<=a[i+2] && a[i+2]<='z') || ('0'<=a[i] && a[i]<='9' && '0'<=a[i+2] && a[i+2]<='9')) && a[i]<a[i+2])	
				for(j=0;a[i]+j<a[i+2];j++)
					printf("%c",a[i]+j);
			else
				for(j=0;j<=1;j++)
					printf("%c",a[i+j]);
			i+=1;
		}
	}

	return 0;
}




