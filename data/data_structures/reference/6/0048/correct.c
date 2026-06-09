#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000000

int data[MAXSIZE]; 

int main()
{
	int op, temp, site = 0;
	while (1)
	{
		scanf ("%d", &op);
		if (op == 1)
		{
			if (site < 100)
			{
				scanf ("%d", &data[site]);
				site++;
			}
			else
			{
				printf ("error ");
			}
		}
		else if (op == 0)
		{
			if (site > 0)
			{
				printf ("%d ", data[site - 1]);
				site--;
			}
			else
			{
				printf ("error ");
			}
		}
		else if (op == -1)
		{
			break;
		}
	}
	return 0; 
}




