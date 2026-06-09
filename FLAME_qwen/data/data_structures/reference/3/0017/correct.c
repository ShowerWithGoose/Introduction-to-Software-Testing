#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int i,start,end,num,t,w1,w2;
	char a[100] = {},c;
	gets(a);
	w1 = strlen(a); 
	if(a[0] == '0')
	{
		for (i = 0;i < w1;i++)
		{
			if (a[i] >= 49 && a[i] <= 57)
			{
				c = a[i];
				start = i;
				num = start - 1;
				break;
			}
		}
		printf("%c",c);
		if (i == w1 - 1)
		{
			printf("e-");
			printf("%d",num);
		}
		else
		{
			printf(".");
			for(i = start + 1;i < w1;i++)
			{
				printf("%c",a[i]);
			}
			printf("e-");
			printf("%d",num);
		}
    }
    else
    {
    	char b[100],ti;
    	int t;
    	for (i = 0,t = 0;i <=w1;i++)
    	{
    		if(a[i] == '.')
    		{
    			start = i;
    			num = start - 1;//123.45
			}
			else
			{
				b[t] = a[i];//12345
				t++;
			}
		}
		w2 = strlen(b);
		for (t = 0;t <= w2;t++)
		{
			if (t<1)
				printf("%c",b[t]);
			else if (t==1)
				printf(".");
			else
			{
				printf("%c",b[t-1]);
			}
		}
		
		printf("e");
		printf("%d",num);
	}
}


