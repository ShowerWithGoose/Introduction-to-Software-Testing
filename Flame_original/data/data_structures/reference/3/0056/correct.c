#include<stdio.h>
#include<string.h>
char a[100000],b[100000];
int main()
{
	gets(a);
	int i,s1,s2,c;
	int find1=0,find2=0;
	for(i=0;i<strlen(a);i++)
	{
		if(find1&&find2)
		break;
		else if(a[i]=='.')
		{
			s1=i;
			find1=1;
		}
		else if(a[i]!='0'&&!find2)
		{
			s2=i;
			find2=1;
		}
    } 
	if(s1>s2)
	c=s1-s2-1;
	else
	c=s1-s2;
	int j=0;
	for(i=s2;i<strlen(a);i++)
	{
		if(a[i]=='.')
		continue;
		else if(i==s2)
		{
			if(a[i+1])
			{
				b[j]=a[i];
				j++;
				b[j++]='.';
			}
			else
			{
				b[j]=a[i];
				j++;
			}
		} 
		else
			{
				b[j]=a[i];
				j++;
			}
	}
	b[j]='\0';
	printf("%se%d",b,c);
	return 0;
}


