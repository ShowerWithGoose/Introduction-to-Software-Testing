#include <stdio.h>
#include <string.h>
char t[100];
void exchange(char s[])
{
	int i,j,k;
	j=0;
	if(s[0]!='0')
	{
		for (i=0; s[i]!='\0'&&s[i]!='.'; i++,j++)
			t[j]=s[i];
		k=i-1;
		for (int l=i+1; s[l]!='\0'; l++,j++)
			t[j]=s[l];
		printf("%c.",t[0]);
		for (int m=1; m<strlen(t); m++)
			printf("%c",t[m]);
		printf("e%d",k);
	}
	if(s[0]=='0')
	{
		for (i=2; s[i]=='0'; i++)
			;
		k=i-1;
		for (int l=i; s[l]!='\0'; l++,j++)
			t[j]=s[l];
		printf("%c",t[0]);
		if(strlen(t)>1)
			{
				printf(".");
				for (int m=1; m<strlen(t); m++)
						printf("%c",t[m]);
			}
		printf("e-%d",k);
	
	}
	return;
	
}
int main(int argc, char *argv[]) {
	char s[100];
	gets(s);
	exchange(s);
	return 0;
}


