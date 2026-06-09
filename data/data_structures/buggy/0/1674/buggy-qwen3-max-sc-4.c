#include<stdio.h>
#include<string.h>
#include<ctype.h>
char data[10000];
int main()
{
  int len,i,k,j;
  gets(data); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in some environments, this leads to compilation errors because 'gets' was removed in C11]
  len=strlen(data);
   for(i=0;i<len;i++)
   {
     if(data[i]=='-'&& i<len-2) // @@ [Condition 'i<len-2' is incorrect; it should be 'i>0 && i<len-1' to safely access data[i-1] and data[i+1]. Current condition allows i=len-2, then i+1 = len-1 (valid), but fails to prevent i=0 where data[i-1] is invalid. Also, when i=len-1, the loop wouldn't enter here, but the real issue is accessing data[i-1] when i=0.]
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