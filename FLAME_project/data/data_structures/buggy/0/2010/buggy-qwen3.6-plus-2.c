#include<stdio.h>
int main(){
   char s[10001];
   gets(s);
   int i,k;
   for(i=0;s[i]!='\0';i++){
   
       if (s[i]=='-'){ @@ [The logic fails to check if the characters before and after '-' are of the same type (e.g., both lowercase, both uppercase, or both digits). It also incorrectly restricts the upper bound of the second character (e.g., <= 'S' or <= 's') instead of just checking if it's greater than the first character and within the valid range.]
                if ((s[i-1]>='A'&&s[i+1]<='S'&&s[i+1]-s[i-1]>0)||(s[i-1]>='a'&&s[i+1]<='s'&&s[i+1]-s[i-1]>0)||(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)){ @@ [The condition checks for specific upper bounds ('S', 's') which is incorrect. It should verify that both characters are in the same category (lowercase, uppercase, or digit) and that the second character is strictly greater than the first.]
             for(k=1;k<s[i+1]-s[i-1];k++){ @@ [This loop prints the expanded characters but does not handle the printing of the surrounding characters correctly in the context of the whole string flow, leading to missing output for the start character if not handled elsewhere.]
       printf("%c",s[i-1]+k);        
                }
   
   }
   else printf("%c",s[i]); @@ [This else branch prints the '-' itself if the expansion condition fails, which is correct for invalid expansions, but the overall structure misses printing the character preceding the '-' when expansion occurs or doesn't occur properly in sequence.]
  
}else printf("%c",s[i]); @@ [This prints the current character if it's not '-'. However, when expansion happens, the character before '-' was already printed in a previous iteration, but the expansion logic here only prints the middle part. The main issue is that the character before '-' is printed in its own iteration, then if the next char is '-', expansion happens. But if expansion doesn't happen, '-' is printed. This logic is flawed because it doesn't look ahead correctly or manage state.]
   
   }
   
   return 0;
}