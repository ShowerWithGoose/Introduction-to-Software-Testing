#include <stdio.h>

char a[200];
int n, b, c;

int f(char x);


int main()
{
	gets (a);
	for(n=0;n<200;n++)
	{
		if((int)a[n] == 45)
		{
			if(f(a[n-1]) == f(a[n+1]))
			{
				b=(int)a[n-1];
				c=(int)a[n+1];
				if(c > b)
				{
					b++;
					while(b != c)
					{
					printf("%c", b);
					b++;
					}
					
				}
				else
				printf("%c",a[n]);
			}
			else
			printf("%c",a[n]);
		}
		else
		{
		if(a[n] == '\0')
		break;
		else	
		printf("%c", a[n]);
		}
	}
		

	return 0;
}

int f(char x){
	if((int)x>47 && (int)x<58)
		return 1;
		else if((int)x>64 && (int)x<91)
			return 2;
			else if((int)x>96 && (int)x<122)
				return 3;
}



