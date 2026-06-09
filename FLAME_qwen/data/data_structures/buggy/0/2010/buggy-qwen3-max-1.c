#include<stdio.h>
int main(){
   char s[10001];
   gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
   int i,k;
   for(i=0;s[i]!='\0';i++){
   
       if (s[i]=='-'){
                if ((s[i-1]>='A'&&s[i+1]<='S'&&s[i+1]-s[i-1]>0)||(s[i-1]>='a'&&s[i+1]<='s'&&s[i+1]-s[i-1]>0)||(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)){ // @@ [Incorrect range checks: e.g., 's[i+1]<='S'' should be 's[i+1]>='A' && s[i+1]<='Z'', similarly for lowercase; also missing validation that both sides are same type]
             for(k=1;k<s[i+1]-s[i-1];k++){
       printf("%c",s[i-1]+k);        
                }
   
   }
   else printf("%c",s[i]); // @@ [Misplaced 'else': it pairs with inner 'if', but should output '-' when condition fails; logic structure is broken causing incorrect output or undefined behavior]
  
}else printf("%c",s[i]); // @@ [This 'else' pairs with the outer 'if (s[i]=='-')', but due to misplaced braces, the control flow is incorrect]
   
   }
   
   return 0;
}