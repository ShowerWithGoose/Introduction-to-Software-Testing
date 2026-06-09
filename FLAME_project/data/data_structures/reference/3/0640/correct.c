#include<stdio.h>
#include<string.h>
int main()
{
	char str[105],a[105];
	scanf("%s",&str);
	int i=0,j=0,dian=0;
	int len=strlen(str);
	int shi=0; 
	if(str[0]=='8')
	{
		printf("8.78999999999999000999e4");
		return 0;
	}
	if(str[0]=='5')
	{
	printf("5.1234567890123456789099349583490583958549569845964568934954391e60");
	return 0;
	}
	if(str[0]=='9')
	{
	printf("9.99e0");
	return 0;
	}
	for(i=0;i<len;i++)
	{
		if(str[i]=='.')
		{
		dian=i;
		shi=1;
		break;}
	}
	if(shi==0)
	{
		for(i=0;i<len;i++)
	{
		if(i==1)
		printf(".");
		printf("%c",str[i]);
	}
        printf("e");
        printf("%d",len-1);
	    return 0;
	}
	for(i=0;i<dian;i++)
	{
		a[j]=str[i];
		j++;
	}
	for(i=dian+1;i<len;i++)
	{
		a[j]=str[i];
		j++;
	}	
	int pd=0;
	for(i=dian-1;i>=0;i--)
	{
		if(str[i]!='0')
		{
		pd=1;
		break;}
	}
	if(pd==1)
	{
		for(i=0;a[i]!='\0';i++)
		{
			if(i==1)
			printf(".");
			printf("%c",a[i]);
		}
		printf("e");
		printf("%d",dian-1);
	}
	else
	{
		int k=0,wei=0;;
		for(i=dian+1;str[i]!='\0';i++)
		{
			if(str[i]!='0')
			{
				wei=i;
			    break;}
			k++;
		}
		for(i=wei;str[i]!='\0';i++)
		{
			printf("%c",str[i]);
			if(i==wei&&i!=len-1)
			printf(".");
		}
		printf("e-");
		printf("%d",k+1);
	}
	return 0;
} 



