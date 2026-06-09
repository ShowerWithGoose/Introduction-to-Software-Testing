#include<stdio.h>
#include<string.h>
#include<ctype.h>
char data[10000];
int main()
{
  int len,i,k,j;
  gets(data);
  len=strlen(data);
   for(i=0;i<len;i++)
   {
     if(data[i]=='-'&& i<len-2) // @@ [The condition `i < len - 2` is incorrect. It should be `i > 0 && i < len - 1` to ensure both `data[i-1]` and `data[i+1]` are valid. The current condition skips processing '-' at position `len-2`, which is the last valid position for expansion (e.g., in "a-u", '-' is at index 1 of length 3, so `i=1` and `len-2=1`, but loop condition allows it; however, more critically, it fails to check `i > 0`, leading to out-of-bounds access when i=0. Also, `i < len - 2` excludes the case where '-' is at `len-2`, which is actually valid since `i+1 = len-1` is within bounds.]
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