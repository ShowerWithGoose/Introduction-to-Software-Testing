#include<stdio.h>
#include<string.h>
int main()
{
	char s[100],t[100]={0};
	int a=0,b=0,c;
	scanf("%s",s);
	c=strlen(s);
	while(a<c)
	{
		if(a==0)
		{
			t[b]=s[a];
			a++,b++;
		}
	    else if(s[a-1]<s[a+1]&&s[a]=='-'&&(('0'<=s[a-1]&&'9'>=s[a+1])||('a'<=s[a-1]&&'z'>=s[a+1])||('A'<=s[a-1]&&'Z'>=s[a+1])))
	    {
			for(int i=s[a-1]+1;i<s[a+1];i++)
	    	{
	    		t[b++]=i;
			}
			a++;
		}
	    else
	    {
			t[b]=s[a];
			a++,b++;
		}
	}
	printf("%s",t);
	return 0;
}

