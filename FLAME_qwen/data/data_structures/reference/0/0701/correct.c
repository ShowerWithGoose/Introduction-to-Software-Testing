#include <stdio.h>
#include <string.h>
char a[1000],b[1000];
int main()
{
	gets(a);
	strcpy(b,a);
	int i=1,j=1,k=1;
	for(;i<=strlen(b)-1;i++,j++)
	{
		if(b[i]=='-'&&((b[i-1]>='0'&&b[i+1]<='9'&&b[i-1]<=b[i+1])||(b[i-1]>='A'&&b[i+1]<='Z'&&b[i-1]<=b[i+1])||(b[i-1]>='a'&&b[i+1]<='z'&&b[i-1]<=b[i+1])))
		{
			if((b[i-1]>='0'&&b[i+1]<='9'&&b[i-1]<=b[i+1])||(b[i-1]>='A'&&b[i+1]<='Z'&&b[i-1]<=b[i+1])||(b[i-1]>='a'&&b[i+1]<='z'&&b[i-1]<=b[i+1]))//符合条件 
			{ 
				k=1;
				a[j]=b[i-1]+k;//填充 
				for(;a[j]<b[i+1]-1;)
				{
					j++;
					k++;
					a[j]=b[i-1]+k;//填充完毕 
				}
			}
		}
		else
		{
			a[j]=b[i];
		}
	}
	puts(a);
	return 0;
}

