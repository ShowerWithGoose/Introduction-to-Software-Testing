#include<stdio.h>
#include<string.h>
int main ()
{
	char a[10000],b[10000];
	gets(a);
	int i,j,k;
	for(i=0,j=0;a[i]!='\0';i++)
	{
		if (a[i]=='-'&&(a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>a[i-1]||a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>a[i-1]||a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>a[i-1]))
		{for(k=1;a[i-1]+k<=a[i+1];k++){  b[j++]=a[i-1]+k;
		                                  }
									i+=1;	  }
		else
		b[j++]=a[i];                                  
		}
	puts(b);		
	return 0;
}

