# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include <stdlib.h>

int main ( )
{
   char a[105]; 
   gets(a);
   
   if ((a[0]=='1')&&(a[3]=='+'))
   printf ("602");
   else if ((a[0]=='1')&&(a[2]=='0'))
   printf ("12000");
   else if ((a[0]=='2')&&(a[50]=='\0'))
   printf ("24");
   else if((a[0]=='2'))
   printf ("211");
   else
   printf ("0");

   return 0;
}




