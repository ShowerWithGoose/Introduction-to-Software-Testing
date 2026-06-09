#include <stdio.h>
#include <string.h>

int getP(char a[])
{
	int i=0;
	while(a[i++]!='.');
	return (i-1);
 } 
 
int main()
{
	char ori[105]="",put[105]="";
	int i,j,k;
	gets(ori);
	
	if(ori[0]=='0')
	{
		i=2;
		while(ori[i++]=='0');
		if(ori[i]=='\0')
		{
			printf("%ce%d",ori[--i],2-i);
		}
		else
		{
			i--;
			put[0]=ori[i++];
			put[1]='.';
			for(j=2;ori[i]!='\0';j++,i++)
			put[j]=ori[i];
			printf("%se%d",put,j-i);
		}
	}
	else
	{
		if(ori[1]=='.')
		printf("%se0",ori);
		else if(ori[1]=='\0')
		printf("%ce0",ori[0]);
		else
		{
			i=2;
			while(ori[i++]!='.');
			put[0]=ori[0];
			put[1]='.';
			for(k=1,j=2;k<i-1;k++,j++)
				put[j]=ori[k];
			for(k=i;ori[k]!='\0';k++,j++)
				put[j]=ori[k];
			printf("%se%d",put,i-2);
		}
	}
	return 0;
}

