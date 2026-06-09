#include <stdio.h>
#include <string.h>
char input[999],output[999];
void copy(int a, int b,int c)
{
	int i,j;
	for(i=c,j=0;j<=b-a;j++)
	{
		output[i+j]=input[a+j];
	}
}
int main()
{
	gets(input);
	int i,j,mark=0,k=0,flag=0;
	for(i=0;i<strlen(input);i++)
	{
		if(input[i]=='-')
		{
			if('A'<=input[i-1] && input[i-1]<='Z')
			{
				if(input[i-1]+1<input[i+1] && 'A'<=input[i+1] && input[i+1]<='Z')
					flag=1;
			}
			if('a'<=input[i-1] && input[i-1]<='z')
			{
				if(input[i-1]+1<input[i+1] && 'a'<=input[i+1] && input[i+1]<='z')
					flag=2;
			}
			if('0'<=input[i-1] && input[i-1]<='9')
			{
				if(input[i-1]+1<input[i+1] && '0'<=input[i+1] && input[i+1]<='9')
					flag=3;
			}
			if(flag==0)
			{
				i++;
				continue;
			}
			else
			{
				copy(mark,i-1,k);
				k=k+i-1-mark;
				for(j=1;j<=input[i+1]-input[i-1];j++)
				{
					output[k+j]=input[i-1]+j;
				}
				k=k+j;
				mark=i+2;
				flag=0;
			}
		}
	}
	if(mark+1<=strlen(input))
	{
		copy(mark,strlen(input)-1,k);
	}
	puts(output);
	return 0;
}



