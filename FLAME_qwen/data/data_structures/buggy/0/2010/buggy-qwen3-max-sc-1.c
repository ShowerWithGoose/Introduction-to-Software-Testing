#include<stdio.h>
int main(){
   char s[10001];
   gets(s); // @@ [Use of unsafe and deprecated function 'gets' which may cause buffer overflow; also, in some environments, this leads to compilation failure if strict standards are enforced]
   int i,k;
   for(i=0;s[i]!='\0';i++){
   
       if (s[i]=='-'){
                if ((s[i-1]>='A'&&s[i+1]<='S'&&s[i+1]-s[i-1]>0)||(s[i-1]>='a'&&s[i+1]<='s'&&s[i+1]-s[i-1]>0)||(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)){ // @@ [Incorrect range checks: for uppercase, it should be s[i+1] >= 'A' and <= 'Z', not <= 'S'; similarly for lowercase, should be <= 'z', not <= 's'. Also missing lower bound check for s[i+1] in all three conditions. This causes incorrect expansion logic and potential undefined behavior.]
             for(k=1;k<s[i+1]-s[i-1];k++){
       printf("%c",s[i-1]+k);        
                }
   
   }
   else printf("%c",s[i]); // @@ [Misplaced else: this else corresponds to the inner if (the condition checking character ranges), but due to missing braces, it incorrectly handles cases where '-' is not expanded. It should print the '-' itself when expansion doesn't occur, but currently skips printing '-' entirely in non-expansion cases.]
  
}else printf("%c",s[i]); // @@ [This else corresponds to the outer if (s[i]=='-'), but due to flawed nesting and missing handling of the '-' character when expansion is not performed, the '-' is never printed in non-expandable cases. The logic fails to output the '-' when conditions aren't met.]
   
   }
   
   return 0;
}