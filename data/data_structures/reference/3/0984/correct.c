#include<stdio.h>
#include<string.h>
int main()
{
	char s[120];
	gets(s);
	int i,j,k,zhishu,flag=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='.')
		  j=i;
		else if(s[i]>='1'&&s[i]<='9'&&flag==0)
		  {
		  	k=i;
		  	flag=1;
		  }	  
	}
	if(j>k)
	  zhishu=j-k-1;
	else
	  zhishu=j-k;
	flag=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='1'&&s[i]<='9'&&flag==0)
		  	flag=1;
		if(flag>=1&&s[i]!='.')
		  {
		  	if(flag==2)
		  	  printf(".");
		  	printf("%c",s[i]);
		  	flag++;
		  }  
    }
    printf("e%d",zhishu);
    return 0;
}

