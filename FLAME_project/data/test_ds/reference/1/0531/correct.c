#include <stdio.h>
int identify(char x)
{
	if(x>='0'&&x<='9')
	return 1;
	else if(x>='a'&&x<='z')
	return 2;
	else if(x>='A'&&x<='Z')
	return 3;
}
int main()
{
	char a[1001];
	char b[1001];
	int i,j,k;
	scanf("%s",a);
    for(i=0,j=0;i<1000&&a[i]!='\0';i++,j++)
    {
    	if(a[i]=='-')
    	{
    		if((identify(a[i-1])==identify(a[i+1]))&&(a[i+1]>a[i-1]))
    		{
    			for(k=1;k<=a[i+1]-a[i-1]-1;k++)
    			b[j+k-1]=a[i-1]+k;
    			j+=a[i+1]-a[i-1]-2;
    			
			}
			else
			b[j]=a[i];
		}
		else
		b[j]=a[i];
		
		
	}
	b[j]='\0';
	printf("%s",b);
	return 0;
    
}

