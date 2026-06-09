#include <math.h>
#include <stdio.h>
#include <string.h>
#define eps 1e-10
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (a) : (b))
int main() 
{
    char a[10000];
    gets(a);
	int str = strlen(a);
    int i = 0; 
    if (a[0] == '0') 
	{
        i = 2;
        while (1) 
		{
            if (a[i] == '0') i++;
            else break;
        }
        printf("%c", a[i]);
        if (i == str - 1)
            printf("e-%d", str - 2);
        else 
		{
	        printf(".");
	        for (int ii = i + 1; ii < str; ii++) 
			{
	         	printf("%c", a[ii]);
	        }
	        printf("e-%d", i - 1);
        }
    } 
	else 
	{
        i = 1;
        while (1) 
		{
            if (a[i] == '.') break;
            else i++;
        }
        printf("%c.", a[0]);
        for (int ii = 1; ii < i; ii++) 
		{
            printf("%c", a[ii]);
        }
        for (int ii = i + 1; ii < strlen(a); ii++) 
		{
            printf("%c", a[ii]);
        }
        printf("e%d", i - 1);
    }
}

