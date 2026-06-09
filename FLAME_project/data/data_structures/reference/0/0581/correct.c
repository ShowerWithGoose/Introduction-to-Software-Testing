#include <stdio.h>

int cmp(char a,char b)
{
	if(a<b&&((a>='0'&&b<='9')||(a>='a'&&b<='z')||(a>='A'&&b<='Z')))
	return b-a-1;
	else return -1;
}

int main()
{
	int i=0,j=0,k,c;
	char in[100]="",out[100]="";
	scanf("%s",&in);
	while(in[i]!='\0')
	{
		if(in[i]=='-'&&i>0&&in[i+1]!='\0')
		{
			c=cmp(in[i-1],in[i+1]);
			if(c!=-1)
			{
				for(k=0;k<c;k++)
				{
					out[j++]=in[i-1]+k+1;
				}
			}
			else out[j++]='-';
		}
		else out[j++]=in[i];
		i++;
	}
	puts(out);
	return 0;
}


