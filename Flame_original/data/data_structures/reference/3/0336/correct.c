#include <stdio.h>
int main()
{
	char s[105]={'\0'};
	gets(s);
	int i,j=0,num_dot=0,num_num=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!='0'&&s[i]!='.')
		j++;
	}
	while(s[num_dot]!='.')
	{
		num_dot++;
	}
	while(s[num_num]=='0'||s[num_num]=='.')
	{
		num_num++;
	}
	if(j==1)
	printf("%c",s[num_num]);
	else
	{
		printf("%c.",s[num_num]);
		for(i=num_num+1;i<strlen(s),j>1;i++)
		{
			if(s[i]!='.')
			printf("%c",s[i]);
			if(s[i]!='0'&&s[i]!='.')
			j--;
		}
	}
	if(num_dot<num_num)
	printf("e%d",num_dot-num_num);
	else
	printf("e%d",num_dot-num_num-1);
	return 0;
}

