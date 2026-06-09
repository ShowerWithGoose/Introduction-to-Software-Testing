#include<stdio.h>
int main()
{
	char s[1000]=" ",t[1000]=" ";
	int i,j=0;
	char k1,k2;
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='-'&&s[i+1]!='\0')
		{
			k1=s[i-1];
			k2=s[i+1];
			if(k2>='0'&&k2<='9'&&k1>='0'&&k1<='9'&&k1<k2)
			{
				for(j;k1<k2-1;j++)
				{
				    t[j]=k1+1;
				    k1+=1;
				}
			}
			else if(k2>='a'&&k2<='z'&&k1>='a'&&k1<='z'&&k1<k2)
			{
				for(j;k1<k2-1;j++)
				{
				    t[j]=k1+1;
				    k1+=1;
				}
			}
			else if(k2>='A'&&k2<='Z'&&k1>='A'&&k1<='Z'&&k1<k2)
			{
				for(j;k1<k2-1;j++)
				{
				    t[j]=k1+1;
				    k1+=1;
				}
			}
			else
			{
				t[j]=s[i];
				j++;
			}
		}
		else
		{
			t[j]=s[i];
			j++;
		}
	}
	puts(t);
	return 0;
}

