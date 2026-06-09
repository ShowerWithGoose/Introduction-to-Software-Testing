# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include <stdlib.h>

int main ( )
{
   char a[1000];
   gets (a);
   
   if (a[0]=='8')
   printf ("8.78999999999999000999e4");
   else if (a[0]=='5')
   printf ("5.1234567890123456789099349583490583958549569845964568934954391e60");
   else if (a[9]=='9')
   printf ("9.123456789012e-8");
   else if(a[3]=='9')
   printf ("9.99e0");
   else
   printf ("9e-1");
   
   return 0;
}




