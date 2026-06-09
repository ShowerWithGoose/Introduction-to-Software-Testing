#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	char str[10000]={'\0'};
	int i,i1,i2,i3,i4,a=0;
	gets(str);
	if(str[0]-'0'==0)
	{
		if(strlen(str)==3)
		{
			str[0]=str[2];
			str[1]='e';
			str[2]='-';
			str[3]='1';
		}
		else
		{
		for(i=2;i<=strlen(str);i++)
		if(str[i]-'0'==0)
		a++;	
		else
		break;
		str[0]=str[a+2];
		for(i1=a+3;i1<strlen(str);i1++)
		str[i1-a-1]=str[i1];
		for(i2=1;i2<=a+1;i2++)
		str[i1-i2]='\0';
		str[strlen(str)]='e';
		str[strlen(str)]='-';
		a+=1;
		if(a<=9)
		str[strlen(str)]=a+'0';
		if(a>=10&&a<=99)
		{
			str[strlen(str)]=a/10+'0';
			str[strlen(str)]=a%10+'0';
		}
		if(a>=100&&a<=999) 
		{
			str[strlen(str)]=a/100+'0';
			str[strlen(str)]=a/10%10+'0';
			str[strlen(str)]=a%10+'0';
		}	
		}
		
	}
	else
	{
		for(i3=1;i3<=strlen(str);i3++)
		{
			if(str[i3]-'.'!=0)
			a++;
			else
			break;
		}
		for(i4=0;i4<=a-1;i4++)
		str[a+1-i4]=str[a-i4];
		str[1]='.';
		str[strlen(str)]='e';
		if(a<=9)
		str[strlen(str)]=a+'0';
		if(a>=10&&a<=99)
		{
			str[strlen(str)]=a/10+'0';
			str[strlen(str)]=a%10+'0';
		}
		if(a>=100&&a<=999) 
		{
			str[strlen(str)]=a/100+'0';
			str[strlen(str)]=a/10%10+'0';
			str[strlen(str)]=a%10+'0';
		}
	}
	printf("%s",str);
}	
		

