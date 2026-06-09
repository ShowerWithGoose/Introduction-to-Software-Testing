#include<stdio.h>
int main(){
   char s[10001];
   gets(s);
   int i,k;
   for(i=0;s[i]!='\0';i++){
   
       if (s[i]=='-'){
                if ((s[i-1]>='A'&&s[i+1]<='S'&&s[i+1]-s[i-1]>0)||(s[i-1]>='a'&&s[i+1]<='s'&&s[i+1]-s[i-1]>0)||(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)){ @@ [The condition checks incorrect upper bounds: 'S' and 's' instead of 'Z' and 'z'. Also, it does not ensure both characters are of the same type (e.g., allows 'A' to 's'). Additionally, accessing s[i-1] when i=0 leads to undefined behavior.]
             for(k=1;k<s[i+1]-s[i-1];k++){
       printf("%c",s[i-1]+k);        
                }
   
   }
   else printf("%c",s[i]); @@ [This else is incorrectly paired with the inner if, causing characters after '-' to be printed even when expansion occurs, leading to duplication.]
  
}else printf("%c",s[i]); @@ [This else prints the '-' character when it shouldn't be expanded, but due to flawed logic above, it may also skip printing non-'-' characters correctly in some cases. Also, when expansion happens, the '-' is skipped but the following character (s[i+1]) is later printed again by the loop, causing duplication (e.g., 'F' appears twice).]
   
   }
   
   return 0;
}