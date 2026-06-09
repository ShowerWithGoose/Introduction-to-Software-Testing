#include<stdio.h>
int main(){
   char s[10001];
   gets(s);
   int i,k;
   for(i=0;s[i]!='\0';i++){
   
       if (s[i]=='-'){
                if ((s[i-1]>='A'&&s[i+1]<='S'&&s[i+1]-s[i-1]>0)||(s[i-1]>='a'&&s[i+1]<='s'&&s[i+1]-s[i-1]>0)||(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)){ // @@ Error: The condition `s[i+1]<='S'` and `s[i+1]<='s'` incorrectly restricts the upper bound to 'S' and 's' instead of 'Z' and 'z', causing valid expansions like 'A-Z' or 'a-z' to be skipped. Also, the condition `s[i+1]-s[i-1]>0` is redundant since it's already implied by the loop condition, but the main issue is the incorrect range check.
             for(k=1;k<s[i+1]-s[i-1];k++){
       printf("%c",s[i-1]+k);        
                }
   
   }
   else printf("%c",s[i]);
  
}else printf("%c",s[i]);
   
   }
   
   return 0;
}