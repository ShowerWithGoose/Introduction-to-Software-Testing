#include<stdio.h>
int main()
{
	char a[200],b[200];
	scanf("%s",&a);
    int i=0,j=0,c;
	while(a[i]!='\0')
	{
		if(a[i]!='-') b[j]=a[i],i++,j++;
		else
		{
			if((a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])||(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1])||(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1]))
			{
			b[j]=a[i-1]+1;
			while(b[j]<a[i+1])
			{
			   b[j+1]=b[j]+1;
			   j++;
		    }
		    i=i+2;
		    j++;
		    }
		    else
			{
				b[j]=a[i],i++,j++;
			}
		}
    }
	for(int k=0;k<=j-1;k++)

		printf("%c",b[k]);
	
	return 0;
} 

