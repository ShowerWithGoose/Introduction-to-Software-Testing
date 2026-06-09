#include<stdio.h>
#include<string.h>
int main()
{
   char str[1000];
   while(gets(str)!=NULL) // @@ [Compilation error: gets is deprecated and not standard in C11; may cause implicit declaration error.]
   {
        puts(str);
   }
   return 0;
}