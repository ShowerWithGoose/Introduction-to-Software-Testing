#include<stdio.h>
#include<string.h>
#include<math.h>
main()
{
	char s[88], s1[88];
	gets(s);
	int len = strlen(s), i, j = 0;
	for(i = 0; i < len; i++)
	{
		if(s[i] != ' ')s1[j++] = s[i];
	}
	int num = 0;
	int a[88], b[88];
	int k = 0;
	for(i = 0; i < j; i++)
	{
		if(s1[i] == '+')
		{
			a[num] = -1; 
			num++;
		}
		else if(s1[i] == '-')
		{
			a[num] = -2;
			num++;
		 } 
		else if(s1[i] == '*')
		{
			a[num] = -3;
			num++;
		}
		else if(s1[i] == '/')
		{
			a[num] = -4;
			num++;
		}
		else if(s1[i] >='0' && s1[i] <= '9')
		{
			a[num] =s1[i] - '0';
			num++;
		}
	}
	for(i = 0; i < num - 1; i++)
	{
		if(a[i] >= 0 &&a[i + 1] >= 0)
		{
			a[i + 1] = 10*a[i] + a[i + 1];
			a[i] = -10;
		}
	}
	for(i = 0; i < num; i++)
	{
		if(a[i] != -10)b[k++] = a[i];
	}
	for(i=0;i < k - 1;i++)
	{
		if(b[i]==-3)
			{
				b[i+1]=b[i-1]*b[i+1];
				b[i] = -10;
				b[i-1] = -10;
			}
	    if(b[i]==-4)
			{
				b[i+1]=b[i-1]/b[i+1];
				b[i] = -10;
				b[i-1] = -10;
			}
	}
    int c[85];
    int l=0;
    for(i=0;i<k;i++)
    {
    	if(b[i]!=-10)
    	{
    		c[l++]=b[i];
		}
	}
	int sum=c[0];
	for(i=1;i <= l;i++)
	{
		if(c[i - 1] == -1) sum += c[i];
		else if(c[i - 1] == -2) sum -= c[i];
	}
	printf("%d",sum);
 } 
 

