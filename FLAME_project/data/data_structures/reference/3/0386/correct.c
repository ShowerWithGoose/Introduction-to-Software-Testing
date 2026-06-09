#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LL long long
#define DB double
char s[110];
int main(){
   //freopen(".in","r",stdin);
    gets(s);
    int p = -1,last=strlen(s)-1,first=0;
    for(int i = first;i<strlen(s);i++){
      if(s[i]=='.'){
        p = i;
        break;
      }
    }
    while(s[first]=='0'||s[first]=='.')
    first++;
   
    
      putchar(s[first]);
      if(first!=last)
      putchar('.');
       for(int i = first+1;i<=last;i++){
         if(i==p)
         continue;
      putchar(s[i]);
       }
       putchar('e');
       if(s[0]=='0'){
       putchar('-');
       printf("%d",first-1);
       }
       else{
         if(p==-1)
         printf("%d",last);
         else
         printf("%d",p-1);
       }
     
    
    return 0;
}



