#include<stdio.h>
#include<string.h> 
int main()
{
	char a[10000];
	gets(a);
	int i,m1,m2,len,m;
	len = strlen(a);
	for(i=0;i<strlen(a);i++)
	{
		if(i==len-1||i == 0)
		printf("%c",a[i]);
		else
		{
			if(a[i] == '-')
			{
				if(a[i+1] >= a[i-1])
				{
					if(a[i-1] >= '0'&&a[i+1] <='9')
					{
                    m1 = a[i-1]+1;
                    m2 = a[i+1]-1;   
                    for(m = m1;m <= m2;m++)
                        printf("%c",m);
                        m1 = 0;
                        m2 = 0;
                }
                else if(a[i-1] >= 'A'&&a[i+1] <='Z')
					{
                    m1 = a[i-1]+1;
                    m2 = a[i+1]-1;   
                    for(m = m1;m <= m2;m++)
                        printf("%c",m);
                        m1 = 0;
                        m2 = 0;
                }
                else if(a[i-1] >= 'a'&&a[i+1] <='z')
					{
                    m1 = a[i-1]+1;
                    m2 = a[i+1]-1;   
                    for(m = m1;m <= m2;m++)
                        printf("%c",m);
                        m1 = 0;
                        m2 = 0;
                }
                else
                {
                   printf("%c",a[i]);}
					}
					else
                {
                   printf("%c",a[i]);}
				}
				else
                {
                   printf("%c",a[i]);}
			}}
			printf("\n");
		return 0;
		}



