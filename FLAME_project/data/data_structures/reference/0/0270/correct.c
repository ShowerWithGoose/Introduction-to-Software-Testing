#include<stdio.h>
char a[1000],b[1000]; 
int i,j,k,l;
int main()
{	
	gets(a);
	for(i=0,j=0;a[i]!='\0';i++,j++)
	{
		if(a[i]=='-'&&(a[i-1]-0)*(a[i+1]-0)>0&&(a[i-1]-':')*(a[i+1]-':')>0&&(a[i-1]-'[')*(a[i+1]-'[')>0)
		{
			l=a[i+1]-a[i-1];
			
			for(k=1;k<l;k++,j++)
			{
				b[j]=a[i-1]+k;
			}
			i=i+1;
			b[j]=a[i];		
		}
		else
		{
			b[j]=a[i];
		}
	}
puts(b);
return 0;		
}


