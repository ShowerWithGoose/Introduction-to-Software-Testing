#include<stdio.h>
#include<string.h>
#include<ctype.h>
char data[10000];
int main()
{
  int len,i,k,j;
  gets(data); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers.]
  len=strlen(data);
   for(i=0;i<len;i++)
   {
     if(data[i]=='-'&& i<len-2) // @@ [The condition 'i<len-2' is incorrect. It should be 'i>0 && i<len-1' to ensure that both data[i-1] and data[i+1] are valid indices. As written, when i == len-2, i+1 == len-1 (valid), but the condition excludes the last possible '-' at position len-2 unnecessarily, and more critically, allows access to data[i-1] when i=0, which would be data[-1] — undefined behavior.]
     {
       if(isdigit(data[i-1])!=0 && isdigit(data[i+1])!=0 && data[i+1]>data[i-1])
       {
            for(k=data[i+1]-data[i-1],j=1;j<k;j++)
            {
                printf("%c",data[i-1]+j);
            }
       }
       else if(isupper(data[i-1])!=0 && isupper(data[i+1])!=0 && data[i+1]>data[i-1])
       {
            for(k=data[i+1]-data[i-1],j=1;j<k;j++)
            {
                printf("%c",data[i-1]+j);
            }
       }
       else if(islower(data[i-1])!=0 && islower(data[i+1])!=0 && data[i+1]>data[i-1])
       {
            for(k=data[i+1]-data[i-1],j=1;j<k;j++)
            {
                printf("%c",data[i-1]+j);
            }
       }
       else
       printf("-");
       continue;
     }
    printf("%c",data[i]);
   }

   return 0;
}