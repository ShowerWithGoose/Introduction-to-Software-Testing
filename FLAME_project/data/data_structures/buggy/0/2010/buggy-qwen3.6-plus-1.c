#include<stdio.h>
int main(){
   char s[10001];
   gets(s);
   int i,k;
   for(i=0;s[i]!='\0';i++){
   
       if (s[i]=='-'){
                if ((s[i-1]>='A'&&s[i+1]<='S'&&s[i+1]-s[i-1]>0)||(s[i-1]>='a'&&s[i+1]<='s'&&s[i+1]-s[i-1]>0)||(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)){ // @@ The condition checks are incorrect. It restricts the end character to 'S', 's', or '9' arbitrarily, failing cases like 'a-u'. It also fails to verify that both characters are of the same type (e.g., both uppercase, both lowercase, or both digits).
             for(k=1;k<s[i+1]-s[i-1];k++){
       printf("%c",s[i-1]+k);        
                }
   
   }
   else printf("%c",s[i]); // @@ This prints the '-' character when expansion conditions are not met, but it fails to print the preceding character which was already printed in the previous iteration, leading to missing characters or logic errors in sequence. More critically, the logic for printing non-expanded parts is flawed because the loop prints s[i] for every non-'-' char, but when '-' is encountered and not expanded, it prints '-', but the previous char was already printed. However, the main issue is the expansion condition.
  
}else printf("%c",s[i]);
   
   }
   
   return 0;
}