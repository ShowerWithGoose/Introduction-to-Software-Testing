#include<stdio.h>
#include<stdlib.h>//申请内存malloc(例如 ：int*a；a=（int*）malloc（number*sizeof（int））；接下来就拿a当数组来用就可以了,最后要还内存free（a）a指的是最开始的原地址)
#include<math.h> // 开方sqrt(x)  x的y次方pow(x,y)
#include<stdbool.h> //C99 bool : true or false 布尔量本质还是整数,故输出还是1或0
#include<string.h>
#include<time.h>
int main()
{
	char a[105];
	gets(a);
	int i;
	char inte[105];
	for (i=0;a[i]!='.';i++)
	{
		inte[i]=a[i];
	}
	inte[i]='\0';
	int leni=i;
	char dec[105];
	int j=0;
	i++;
	while (a[i]!='\0')
	{
		dec[j]=a[i];
		j++;
		i++;
	}
	dec[j]='\0';
	int lend=j;
	if (inte[0]=='0')
	{
		int i=0;
		for (i=0;dec[i]=='0';i++);
		printf ("%c",dec[i]);
		i++;
		int j=i;
		if (dec[i]!='\0')
		{
			printf (".");
		}
		while (dec[i]!='\0')
		{
			printf ("%c",dec[i]);
			i++;
		}
		printf ("e");
		printf ("-%d\n",j);
	}
	else
	{
		int i=leni-1;
		printf ("%c",inte[0]);
		printf (".");
		int j=1;
		while (inte[j]!='\0')
		{
			printf ("%c",inte[j]);
			j++;
		}
		j=0;
		while (dec[j]!='\0')
		{
			printf ("%c",dec[j]);
			j++;
		}
		printf ("e%d",i);
	}
	return 0;
}

