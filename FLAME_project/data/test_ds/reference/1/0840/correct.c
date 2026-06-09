#include<stdio.h>
#include<math.h>
#include<string.h>

char a[105];
int main(void)
{
	int i;
	char x,y,z;
	scanf("%s",&a);
	for(i = 0; a[i] != '\0'; i++)
	{
		if(a[i] == '-' && a[i - 1] < a[i + 1])
		{
			if(a[i - 1] >= 'a' && a[i + 1] <= 'z')
			{
				x = a[i - 1] + 1;
				while(x < a[i + 1])
				{
					printf("%c",x);
					x++;
				}
			}
			else if(a[i - 1] >= 'A' && a[i + 1] <= 'Z')
			{
				y = a[i - 1] + 1;
				while(y < a[i + 1])
				{
					printf("%c",y);
					y++;
				}
			}
			else if(a[i - 1] >= '0' && a[i + 1] <= '9')
			{
				z = a[i - 1] + 1;
				while(z < a[i + 1])
				{
					printf("%c",z);
					z++;
				}
			}
			else 
			printf("%c",a[i]);
		}
		else
		printf("%c",a[i]);
	}
	
	return 0;
}



