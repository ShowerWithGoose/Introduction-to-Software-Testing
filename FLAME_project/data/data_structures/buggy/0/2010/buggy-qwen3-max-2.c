#include<stdio.h>
int main(){
   char s[10001];
   gets(s);
   int i,k;
   for(i=0;s[i]!='\0';i++){
   
       if (s[i]=='-'){
                if ((s[i-1]>='A'&&s[i+1]<='S'&&s[i+1]-s[i-1]>0)||(s[i-1]>='a'&&s[i+1]<='s'&&s[i+1]-s[i-1]>0)||(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)){ @@ // Incorrect range checks: 'S' and 's' are arbitrary upper bounds; should check that both chars are in same category (e.g., both uppercase) without hardcoding 'S'/'s'. Also, accessing s[i-1] when i=0 causes undefined behavior.
             for(k=1;k<s[i+1]-s[i-1];k++){
       printf("%c",s[i-1]+k);        
                }
   
   }
   else printf("%c",s[i]); @@ // This else is incorrectly paired with the inner if, not the outer if (s[i]=='-'), causing characters after '-' to be printed twice in some cases.
  
}else printf("%c",s[i]); @@ // This else corresponds to the outer if (s[i]=='-'), but due to incorrect nesting, non-'-' characters are printed here AND possibly inside the inner else, leading to duplication or omission.
   
   }
   
   return 0;
}