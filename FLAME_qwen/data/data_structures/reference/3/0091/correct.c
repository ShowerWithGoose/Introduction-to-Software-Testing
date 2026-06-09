#include <stdio.h>
#include <string.h>
#define size 512
int main()
{
	char a[100];
	fgets(a,size,stdin);
	int i,j;//i表示小数点前数字个数，j表示小数点后0的个数 
	int k;//使用k=1表示指数部分大于等于0，k=0表示指数部分小于0，需要加'-'
	int m;//计数 
	for(i=0;a[i]!='.';i++);
	for(j=0;a[j+i+1]=='0';j++);
    if(i>=2||(i==1&&a[0]>'0'))
    	k=1;
    else k=0;
    if(k>=1)
    {
    	printf("%c.",a[0]);
    	for(m=1;m<=strlen(a)-2;m++)
    	{
    		if(a[m]=='.')
    		continue;
    		else
    		printf("%c",a[m]);
		}
		printf("e");
		printf("%d",i-1);
	}
	if(k==0)
	{
		printf("%c",a[i+j+1]);
		if(i+j+1<strlen(a)-2)
		printf(".");
		for(m=i+j+2;m<=strlen(a)-2;m++)
		{
			printf("%c",a[m]);
		}
		printf("e-");
		printf("%d",j+1);
	}
	return 0;
}



