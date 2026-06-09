#include <stdio.h>
#include <string.h>
int main()
{
	char a[999],s;
	int o,i,n,m,p,q,k,l,f;
	scanf("%s",&a);
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		if(a[i]=='-')
		{
	    if('0'<a[i+1]&&a[i+1]<='9'&&'0'<=a[i-1]&&a[i-1]<'9'&&a[i-1]<a[i+1])
	    { 
			s=a[i-1]+1;
			while(1)
			{
				printf("%c",s);
				s=s+1;
		        if(s>=a[i+1])
		        {
				break;
				}
			}
		}
		else if('a'<a[i+1]&&a[i+1]<='z'&&'a'<=a[i-1]&&a[i-1]<'z'&&a[i-1]<a[i+1])
		{
			s=a[i-1]+1;
			while(1)
			{
				printf("%c",s);
				s=s+1;
		        if(s>=a[i+1])
		        {
				break;
				}
			}
		}
		else if('A'<a[i+1]&&a[i+1]<='Z'&&'A'<=a[i-1]&&a[i-1]<'Z'&&a[i-1]<a[i+1])
		{
			s=a[i-1]+1;
			while(1)
			{
				printf("%c",s);
				s=s+1;
		        if(s>=a[i+1])
		        {
				break;
				}
			}
		}
	    else printf("%c",a[i]);
        }
        else printf("%c",a[i]);
    }
	return 0;
}



