#include<stdio.h>
#include<string.h>
#include<ctype.h>
char data[10000];
int main()
{
  int len,i,k,j;
  gets(data); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow and is removed in C11. Also, some compilers may not support it, leading to compilation errors.]
  len=strlen(data);
   for(i=0;i<len;i++)
   {
     if(data[i]=='-'&& i<len-2) // @@ [Condition 'i<len-2' is incorrect; it should be 'i>0 && i<len-1' to safely access data[i-1] and data[i+1]. As written, when i == len-2, i+1 is len-1 (valid), but the condition excludes the last possible '-' at position len-2 unnecessarily, and more critically, allows i=0 to enter the block, causing data[-1] access.]
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