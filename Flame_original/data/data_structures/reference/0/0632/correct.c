#include<stdio.h>
char s[10001];//多大范围？ 
int i,j,flag;

int main()
{
	gets(s);//输入会有问题吗？
	/*if(s[1]=='\0') 
	 {
	 	printf("%s",s); 
	 	return 0;
	 }*/
	for(i=0;s[i]!='\0';i++)
	 {
	 	if(flag==1)
	 	{
	 		for(j=s[i-1]+1;j!=s[i+1];j++)
			  printf("%c",j);
			flag=0;
		 }
		else
		 {
		 	printf("%c",s[i]);
		 	if(s[i+1]=='-')
		 	 {
		 	 	if(s[i]<s[i+2])
				  if((s[i]>='a'&&s[i]<='z'&&
				   s[i+2]>='a'&&s[i+2]<='z')||
				   (s[i]>='A'&&s[i]<='Z'&&
				   s[i+2]>='A'&&s[i+2]<='Z')||
				   (s[i]>='0'&&s[i]<='9'&&
				   s[i+2]>='0'&&s[i+2]<='9'))
				   flag=1;
			  }
		 }
	 }
	return 0;
 } 



