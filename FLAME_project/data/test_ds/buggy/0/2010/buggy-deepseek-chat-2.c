#include<stdio.h>
int main(){
   char s[10001];
   gets(s);
   int i,k;
   for(i=0;s[i]!='\0';i++){
   
       if (s[i]=='-'){
                if ((s[i-1]>='A'&&s[i+1]<='S'&&s[i+1]-s[i-1]>0)||(s[i-1]>='a'&&s[i+1]<='s'&&s[i+1]-s[i-1]>0)||(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)){ // @@ The condition incorrectly uses <= 'S', <= 's', and <= '9' to check the upper bound of the second character, which restricts expansion only when the second character is within a limited range (e.g., 'S' instead of 'Z'). It should check that both characters are within the same valid range (e.g., 'A' to 'Z', 'a' to 'z', '0' to '9') and that the second character is greater than the first.
             for(k=1;k<s[i+1]-s[i-1];k++){
       printf("%c",s[i-1]+k);        
                }
   
   }
   else printf("%c",s[i]);
  
}else printf("%c",s[i]);
   
   }
   
   return 0;
}