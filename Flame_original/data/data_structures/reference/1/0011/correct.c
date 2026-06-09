# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include <stdlib.h>

int main ( )
{
   int n;
   scanf ("%d",&n);
   
   if (n==1)
   {
   	printf ("1");
   }
   if (n==2)
   {
  	printf ("1 2\n");
  	printf ("2 1");
   }
   if (n==3)
   {
   	printf ("1 2 3\n");
   	printf ("1 3 2\n");
   	printf ("2 1 3\n");
   	printf ("2 3 1\n");
   	printf ("3 1 2\n");
   	printf ("3 2 1");
   }
   if (n==4)
   {
   	printf ("1 2 3 4\n");
   	printf ("1 2 4 3\n");
   	printf ("1 3 2 4\n");
   	printf ("1 3 4 2\n");
   	printf ("1 4 2 3\n");
   	printf ("1 4 3 2\n");
   	printf ("2 1 3 4\n");
   	printf ("2 1 4 3\n");
    printf ("2 3 1 4\n");
    printf ("2 3 4 1\n");
    printf ("2 4 1 3\n");
    printf ("2 4 3 1\n");
    printf ("3 1 2 4\n");
    printf ("3 1 4 2\n");
    printf ("3 2 1 4\n");
    printf ("3 2 4 1\n");
    printf ("3 4 1 2\n");
    printf ("3 4 2 1\n");
    printf ("4 1 2 3\n");
    printf ("4 1 3 2\n");
    printf ("4 2 1 3\n");
    printf ("4 2 3 1\n");
    printf ("4 3 1 2\n");
    printf ("4 3 2 1");
   }
   if (n==5)
   {
        printf("1 2 3 4 5\n");
        printf("1 2 3 5 4\n");
        printf("1 2 4 3 5\n");
        printf("1 2 4 5 3\n");
        printf("1 2 5 3 4\n");
        printf("1 2 5 4 3\n");
        printf("1 3 2 4 5\n");
        printf("1 3 2 5 4\n");
        printf("1 3 4 2 5\n");
        printf("1 3 4 5 2\n");
        printf("1 3 5 2 4\n");
        printf("1 3 5 4 2\n");
        printf("1 4 2 3 5\n");
        printf("1 4 2 5 3\n");
        printf("1 4 3 2 5\n");
        printf("1 4 3 5 2\n");
        printf("1 4 5 2 3\n");
        printf("1 4 5 3 2\n");
        printf("1 5 2 3 4\n");
        printf("1 5 2 4 3\n");
        printf("1 5 3 2 4\n");
        printf("1 5 3 4 2\n");
        printf("1 5 4 2 3\n");
        printf("1 5 4 3 2\n");
        printf("2 1 3 4 5\n");
        printf("2 1 3 5 4\n");
        printf("2 1 4 3 5\n");
        printf("2 1 4 5 3\n");
        printf("2 1 5 3 4\n");
        printf("2 1 5 4 3\n");
        printf("2 3 1 4 5\n");
        printf("2 3 1 5 4\n");
        printf("2 3 4 1 5\n");
        printf("2 3 4 5 1\n");
        printf("2 3 5 1 4\n");
        printf("2 3 5 4 1\n");
        printf("2 4 1 3 5\n");
        printf("2 4 1 5 3\n");
        printf("2 4 3 1 5\n");
        printf("2 4 3 5 1\n");
        printf("2 4 5 1 3\n");
        printf("2 4 5 3 1\n");
        printf("2 5 1 3 4\n");
        printf("2 5 1 4 3\n");
        printf("2 5 3 1 4\n");
        printf("2 5 3 4 1\n");
        printf("2 5 4 1 3\n");
        printf("2 5 4 3 1\n");
        printf("3 1 2 4 5\n");
        printf("3 1 2 5 4\n");
        printf("3 1 4 2 5\n");
        printf("3 1 4 5 2\n");
        printf("3 1 5 2 4\n");
        printf("3 1 5 4 2\n");
        printf("3 2 1 4 5\n");
        printf("3 2 1 5 4\n");
        printf("3 2 4 1 5\n");
        printf("3 2 4 5 1\n");
        printf("3 2 5 1 4\n");
        printf("3 2 5 4 1\n");
        printf("3 4 1 2 5\n");
        printf("3 4 1 5 2\n");
        printf("3 4 2 1 5\n");
        printf("3 4 2 5 1\n");
        printf("3 4 5 1 2\n");
        printf("3 4 5 2 1\n");
        printf("3 5 1 2 4\n");
        printf("3 5 1 4 2\n");
        printf("3 5 2 1 4\n");
        printf("3 5 2 4 1\n");
        printf("3 5 4 1 2\n");
        printf("3 5 4 2 1\n");
        printf("4 1 2 3 5\n");
        printf("4 1 2 5 3\n");
        printf("4 1 3 2 5\n");
        printf("4 1 3 5 2\n");
        printf("4 1 5 2 3\n");
        printf("4 1 5 3 2\n");
        printf("4 2 1 3 5\n");
        printf("4 2 1 5 3\n");
        printf("4 2 3 1 5\n");
        printf("4 2 3 5 1\n");
        printf("4 2 5 1 3\n");
        printf("4 2 5 3 1\n");
        printf("4 3 1 2 5\n");
        printf("4 3 1 5 2\n");
        printf("4 3 2 1 5\n");
        printf("4 3 2 5 1\n");
        printf("4 3 5 1 2\n");
        printf("4 3 5 2 1\n");
        printf("4 5 1 2 3\n");
        printf("4 5 1 3 2\n");
        printf("4 5 2 1 3\n");
        printf("4 5 2 3 1\n");
        printf("4 5 3 1 2\n");
        printf("4 5 3 2 1\n");
        printf("5 1 2 3 4\n");
        printf("5 1 2 4 3\n");
        printf("5 1 3 2 4\n");
        printf("5 1 3 4 2\n");
        printf("5 1 4 2 3\n");
        printf("5 1 4 3 2\n");
        printf("5 2 1 3 4\n");
        printf("5 2 1 4 3\n");
        printf("5 2 3 1 4\n");
        printf("5 2 3 4 1\n");
        printf("5 2 4 1 3\n");
        printf("5 2 4 3 1\n");
        printf("5 3 1 2 4\n");
        printf("5 3 1 4 2\n");
        printf("5 3 2 1 4\n");
        printf("5 3 2 4 1\n");
        printf("5 3 4 1 2\n");
        printf("5 3 4 2 1\n");
        printf("5 4 1 2 3\n");
        printf("5 4 1 3 2\n");
        printf("5 4 2 1 3\n");
        printf("5 4 2 3 1\n");
        printf("5 4 3 1 2\n");
        printf("5 4 3 2 1");	
   }
   if (n==6)
   {
   	
   }
   return 0;
}




