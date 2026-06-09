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
     if(data[i]=='-'&& i<len-2)@@ // @@ Error: missing check for i>0; accessing data[i-1] when i=0 causes out-of-bounds.
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