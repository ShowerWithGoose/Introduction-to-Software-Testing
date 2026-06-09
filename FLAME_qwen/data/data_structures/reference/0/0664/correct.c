#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char a[500];
	scanf("%s",a);
	int k=strlen(a),i; 
	for(i=0;i<k;i++)
	{
		if((((islower(a[i]))&&islower(a[i+2]))||(isupper(a[i]))&&isupper(a[i+2])||(isdigit(a[i]))&&(isdigit(a[i+2])))&&(a[i+1]=='-')&&(a[i]<a[i+2]))
		{
			int len;
			len=a[i+2]-a[i];
			for(int j=0;j<len;j++)
			printf("%c",a[i]+j);
			i++;
		}
		else 
		printf("%c",a[i]);
	}
	return 0;
}

