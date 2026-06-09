#include<stdio.h>
#include<string.h>
int main()
{char a[500],b[1000];
int i,j=0,l,m,o;
gets(a);
l=strlen(a);
for(i=0;i<l;)
	{
	if(a[i+1]=='-')
		{if(a[i]>='a'&&a[i+2]<='z')
			{m=a[i+2]-a[i];
			for(o=0;o<m;o++)
				b[j++]=a[i]+o;
			i+=2;
			}
		else if(a[i]>='A'&&a[i+2]<='Z')
			{m=a[i+2]-a[i];
			for(o=0;o<m;o++)
				b[j++]=a[i]+o;
			i+=2;
			}
		else if(a[i]>='0'&&a[i+2]<='9')
			{m=a[i+2]-a[i];
			for(o=0;o<m;o++)
				b[j++]=a[i]+o;
			i+=2;
			}
		else
			b[j++]=a[i++];
		}
	else
		b[j++]=a[i++];
	}
printf("%s",b);
return 0;
}

