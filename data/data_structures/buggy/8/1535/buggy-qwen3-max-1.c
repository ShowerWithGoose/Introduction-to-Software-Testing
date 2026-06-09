#include<stdio.h>
#include<string.h>
int main()
{
   char str[1000];
   while(gets(str)!=NULL) // @@ [The function 'gets' is unsafe and has been removed from the C standard library in C11; many compilers no longer support it, leading to compilation errors. Use 'fgets' instead.]
   {
        puts(str);
   }
   return 0;
}