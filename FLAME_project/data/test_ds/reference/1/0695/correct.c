#include<stdio.h>
#include<string.h>
int main()
{
	char a[10000],b[10000],record;
	scanf("%s",&a);
	int i,j;
	for(i=0,j=0;a[i]!='\0';i++)
	{
		if(a[i]!='-')
		{
			b[j++]=a[i];
		}else{
			if((a[i-1]<='Z'&&a[i-1]>='A')&&(a[i+1]<='Z'&&a[i+1]>='A')&&a[i-1]<a[i+1])
			{
				record=a[i-1];
				for(record++;record<=a[i+1];record++)b[j++]=record;
				i++; 
			}
			else if((a[i-1]<='z'&&a[i-1]>='a')&&(a[i+1]<='z'&&a[i+1]>='a')&&a[i-1]<a[i+1])
			{
				record=a[i-1];
				for(record++;record<=a[i+1];record++)b[j++]=record;
				i++;
			}
			else if((a[i-1]<='9'&&a[i-1]>='0')&&(a[i+1]<='9'&&a[i+1]>='0')&&a[i-1]<a[i+1])
			{
				record=a[i-1];
				for(record++;record<=a[i+1];record++)b[j++]=record;
				i++;
			}
			else{
				b[j++]=a[i];
			} 
		}
	}
	b[j]='\0';
	printf("%s",b);
	return 0;
 } 

