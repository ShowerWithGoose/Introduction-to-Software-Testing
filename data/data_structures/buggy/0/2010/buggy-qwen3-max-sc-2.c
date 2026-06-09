#include<stdio.h>
int main(){
   char s[10001];
   gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
   int i,k;
   for(i=0;s[i]!='\0';i++){
   
       if (s[i]=='-'){
                if ((s[i-1]>='A'&&s[i+1]<='S'&&s[i+1]-s[i-1]>0)||(s[i-1]>='a'&&s[i+1]<='s'&&s[i+1]-s[i-1]>0)||(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)){ // @@ [Incorrect range checks: e.g., 's[i+1]<='S'' should be 's[i+1]>='A'' for uppercase; similarly for lowercase, should check both bounds properly]
             for(k=1;k<s[i+1]-s[i-1];k++){
       printf("%c",s[i-1]+k);        
                }
   
   }
   else printf("%c",s[i]); // @@ [Misplaced 'else': it pairs with the inner 'if', but should pair with the outer 'if (s[i]=='-')'; causes logic error and possibly missing output]
  
}else printf("%c",s[i]); // @@ [This 'else' is paired with the 'if (s[i]=='-')', but due to incorrect nesting above, the control flow is broken]
   
   }
   
   return 0;
}