# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include <stdlib.h>

int main ( )
{
   char c,a,b,d; 
   scanf ("%c",&a);
   printf ("%c",a);
   while (scanf ("%c",&c) != EOF)
   {
   	if (c == '-')
   	{
   		scanf ("%c",&b);
   		if ((a<b) && (('a'<=a)&&('z'>=a))&&(('a'<=b)&&('z'>=b)))
   		{
   			d = a + 1;
			while (d <= b)
			{
				printf ("%c",d);
				d ++;
			}
		}
   		else if ((a<b) && (('A'<=a)&&('Z'>=a))&&(('A'<=b)&&('Z'>=b)))
   		{
   			d = a + 1;
			while (d <= b)
			{
				printf ("%c",d);
				d ++;
			}	
		}
   		else if ((a<b) && (('0'<=a)&&('9'>=a))&&(('0'<=b)&&('9'>=b)))
   		{
   			d = a + 1;
			while (d <= b)
			{
				printf ("%c",d);
				d ++;
			}	
		}
		else 
		printf ("-%c",b);		
		a = b;
	}	

	else
	{
		a = c;
		printf ("%c",c);
	}
   }

   return 0;
}


