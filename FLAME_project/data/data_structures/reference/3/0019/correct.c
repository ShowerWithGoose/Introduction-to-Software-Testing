#include<stdio.h>
#include<string.h>
void deletechar(char s[],char c)
{
	int length = strlen(s);
	int i,j;
	for(i = 0,j = 0;s[i]!='\0';i++)
	{
		if(s[i] != c)
		{
			s[j++] = s[i];
		}
	}
	s[j] = '\0';//不加这个会补齐？？？？？ 
}
int j;
int main()
{
	int count = 0;
	char a[102];
	gets(a);
	int c;
	int i,flat = 0,flat2 = 0,d = 0,len,flat3 = 0;
	for(i = 0;a[i]!='\0';i++)
	{
		if(a[i] != '0'&&a[i]!='.')
			count++;
			
	}
	for(i = 0;a[i]!='\0';i++)
	{
		if(a[i] != '.')
			d++;
	}
	len = strlen(a);
	if(d==len)
	{	
			
		for(i = 0;a[i]!='\0';i++)
		{
		
			printf("%c",a[i]);
		}
		printf("e0");
	}
	for(i = 0;a[i]!='\0';i++)
	{
		if(a[0] == '0'&&a[1] == ".")
		{
			for(j = 2;a[j] != '\0';j++)
			{
				if(a[j] == '0')
					flat3++;
			}
		}	
	}
	for(i = 0;a[i]!='\0';i++)
	{
		flat++;
		if(a[i] == '.')
		{
			break;
		}		
	}
	c = strlen(a) - flat - 1;
	if(a[0] == '0'&&d !=len)
	{
		for(i = 2;;i++)
		{
			if(a[i] == '0')
				flat2++;
			if(a[i] != '0')
				break;
		}
		if(count == 1)
			{
				printf("%ce-%d",a[len-1],len-2);
				return 0;
			}
		printf("%c.",a[flat2+2]);
		for(i = flat2 + 3;a[i] != '\0';i++)
		{
			printf("%c",a[i]);

		}
		printf("e-%d",flat2 + 1);
		
    } 
    else if(a[0] != '0'&&d != len)
    {
    	printf("%c.",a[0]);
    	
    	for(i = 1;a[i] != '\0';i++)
    	{
    		if(a[i] == '.')
    			i++;
    		printf("%c",a[i]);
    	}	
		printf("e%d",flat-2);
    }	
	return 0;
}


