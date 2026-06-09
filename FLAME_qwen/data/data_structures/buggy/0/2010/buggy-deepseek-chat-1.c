#include<stdio.h>
int main(){
   char s[10001];
   gets(s);
   int i,k;
   for(i=0;s[i]!='\0';i++){
   
       if (s[i]=='-'){
                if ((s[i-1]>='A'&&s[i+1]<='S'&&s[i+1]-s[i-1]>0)||(s[i-1]>='a'&&s[i+1]<='s'&&s[i+1]-s[i-1]>0)||(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)){ // @@ [Error: The condition uses '<=' for the upper bound (e.g., s[i+1]<='S' and s[i+1]<='s') instead of checking that both characters are within the same full range. For example, 'S' is not the end of uppercase letters; it should be 'Z'. Also, the condition should check that both characters are letters/digits of the same type, not just that the second is less than or equal to a specific letter. Additionally, the condition s[i+1]-s[i-1]>0 is redundant with the later check in the for loop, but the main issue is the incorrect range check.]
             for(k=1;k<s[i+1]-s[i-1];k++){
       printf("%c",s[i-1]+k);        
                }
   
   }
   else printf("%c",s[i]);
  
}else printf("%c",s[i]);
   
   }
   
   return 0;
}