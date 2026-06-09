#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	char a[105]={0};
	gets(a);
	//先找到第一位
	//再找到小数点
	//如果第一位在小数点前面 统计两者位数差-1 即为e的幂 
	//如果第一位在小数点后面 统计两者位数差 即为e的幂的相反数
	//如果只有一位非0数字 输出数字+e+幂
	//如果有多位数字 将小数点移到第二位+e+幂
	int i=0,fnl,dl,pow,fonl,fonn=0;
	//fnl=firstnumlocation dl=dotlocation pow=power(幂) fonl=最后一个非0数字位置 fonn=非0数字个数 
	while(a[i]=='0'||a[i]=='.')
	{
		i++;
	} 
	fnl=i;
	
	i=0;
	while(isdigit(a[i]))
	{
		i++;
	} 
	dl=i;
	
	if(fnl<dl)
	{
		pow=dl-fnl-1;
	}
	else if(fnl>dl)
	{
		pow=dl-fnl;
	}
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]>'0'&&a[i]<='9')
		{
			fonl=i;
			fonn++;
		}
	}
	if(fonn==1)
	{
		printf("%ce%d",a[fonl],pow); 
	}
	else if(fonn>1&&fnl<dl)
	{
		for(i=dl;i>1;i--)
		{
			a[i]=a[i-1];
		}
		a[1]='.';
		printf("%se%d",a,pow);
	}
	else if(fonn>1&&fnl>dl)
	{
		a[0]=a[fnl];
		a[1]='.';
		strcpy(a+2,a+fnl+1);
		printf("%se%d",a,pow);
	}
	
	return 0;
}

//#include<string.h>
//memset()
//strlen()
//strcmp()
//strcpy()
//strstr()

//<ctype.h>
//isalnum()
//isalpha()
//islower()
//isupper()
//tolower()
//toupper()


