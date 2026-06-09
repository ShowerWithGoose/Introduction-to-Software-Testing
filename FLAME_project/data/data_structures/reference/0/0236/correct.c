#include<stdio.h>
#include<string.h>
int main()
{
	char a[10000],b[10000];
	int i,j,k,step,t;
	gets(a);
	b[0]=a[0];
	for(i=j=1; a[i]!='\0'; i++,j++)
	{
		b[j]=a[i];
		if(a[i]=='-'&&a[i-1]<a[i+1]-1&&(('a'<=a[i-1]&&a[i-1]<='z'&&'a'<=a[i+1]&&a[i+1]<='z')||('0'<=a[i-1]&&a[i-1]<='9'&&'0'<=a[i+1]&&a[i+1]<='9')||('A'<=a[i-1]&&a[i-1]<='Z'&&'A'<=a[i+1]&&a[i+1]<='Z')))
		{
			step=a[i+1]-a[i-1]-1;
			for(t=1;t<=step;t++)
			b[j++]=a[i-1]+t;
			j--;
		}
		
	}
	b[j]='\0';
	printf("%s", b);
}

