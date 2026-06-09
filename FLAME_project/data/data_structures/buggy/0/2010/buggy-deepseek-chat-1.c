#include<stdio.h>
int main(){
   char s[10001];
   gets(s);
   int i,k;
   for(i=0;s[i]!='\0';i++){
   
       if (s[i]=='-'){
                if ((s[i-1]>='A'&&s[i+1]<='S'&&s[i+1]-s[i-1]>0)||(s[i-1]>='a'&&s[i+1]<='s'&&s[i+1]-s[i-1]>0)||(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)){ // @@ The condition incorrectly uses <= 'S', <= 's', and <= '9' to check the upper bound of the second character, which should be >= 'A', >= 'a', >= '0' and <= 'Z', <= 'z', <= '9' respectively. Also, the condition should check that both characters are within the same valid range, not just the second character's upper bound.
             for(k=1;k<s[i+1]-s[i-1];k++){
       printf("%c",s[i-1]+k);        
                }
   
   }
   else printf("%c",s[i]); // @@ This prints only the '-' when expansion conditions are not met, but the problem requires that the '-' and surrounding characters be output unchanged in such cases. The logic should print the '-' and the preceding character (if not already printed) and handle the case where no expansion occurs.
  
}else printf("%c",s[i]); // @@ This prints the current character when it is not '-', but it does not handle the case where the '-' is at the beginning or end of the string, or when the preceding character is not printed before expansion. The overall logic fails to output the first character before a '-' that is expanded, and incorrectly handles non-expansion cases.
   
   }
   
   return 0;
}