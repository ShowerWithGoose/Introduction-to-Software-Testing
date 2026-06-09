#include <stdio.h>

int main()
{

   char k;
   int count=0;
   int now=0;
   char puting[1000];
   gets(puting);
   while(puting[now]!='\0')
   {
     
     if(puting[now]!='-')
   {
     printf("%c",puting[now]);
     
   }
  else if(puting[now]=='-')
     {
       if(puting[now-1]>='a'&&puting[now-1]<='z'&&puting[now+1]>='a'&&puting[now+1]<='z'&&puting[now-1]<puting[now+1])
       {
         char k=puting[now-1]+1;
         
         while(k<puting[now+1])
         {
           printf("%c",k++);

         }
       }
        else if(puting[now-1]>='0'&&puting[now-1]<='9'&&puting[now+1]>='0'&&puting[now+1]<='9'&&puting[now-1]<puting[now+1])
       {
         char k=puting[now-1]+1;
          while(k<puting[now+1])
         {
           printf("%c",k++);

         }
       }
      else if(puting[now-1]>='A'&&puting[now-1]<='Z'&&puting[now+1]>='A'&&puting[now+1]<='Z'&&puting[now-1]<puting[now+1])
       {
         char k=puting[now-1]+1;
         while(k<puting[now+1])
         {
           printf("%c",k++);

         }
       }
      else 
      printf("%c",puting[now]);
     }
     now++;
   }
  
    return 0;
    
}
