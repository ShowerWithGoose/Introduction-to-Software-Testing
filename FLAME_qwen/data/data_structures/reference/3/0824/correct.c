#include <stdio.h>
#include <string.h>
char s[100+5];
int i,j,x,sp,sn,len,move,head;
int main()
{
	gets(s);
	len=strlen(s);
	//printf("%d",len);
	for(sp=1;s[sp]!='.';sp++)
	{
	}
	//printf("--------point's position=%d\n",sp);//sp为point所在位置的数组下标 
	for(sn=0;s[sn]=='.'||s[sn]=='0';sn++)
	{
	}
	//printf("--------first_not0_num's position=%d\n",sn);
	head=sn;
	x=sp-sn;
	if(x>0)x=x-1;
	printf("%c",s[sn]);
	if(sn+1!=len)printf(".");
	for(i=sn+1;s[i]!='\0';i++)
	{
		if(s[i]=='.')continue;
		else printf("%c",s[i]);
	}
	printf("e%d",x);
	/*if(sp>1)
	{
		printf("%c",s[0]);
		printf("%c",s[sp]);
		for(i=1;i<sp;i++)
		{
			printf("%c",s[i]);
		}
		move=i-1;
		for(j=sp+1;j<len;j++)
		{
			printf("%c",s[j]);
		}
		printf("e%d",move);
		
	}
	else
	{
		//if(s[0]!=0)
		
		printf("------first_not0_num'position=%d\n",sn);
		printf("%c",s[sn]);
		
		if(sn!=0)move=sn-1;
		else move=sn;
		if(sn<len-1)printf(".");
		for(i=sp+1;i<len;i++)
		{
			printf("%c",s[i]);
		}
		printf("e%d",move);
	}*/
	return 0;
}
	


