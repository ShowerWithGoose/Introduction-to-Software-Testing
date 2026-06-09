#include<stdio.h>
int main(){
   char s[10001];
   gets(s);
   int i,k;
   for(i=0;s[i]!='\0';i++){
   
       if (s[i]=='-'){
                if ((s[i-1]>='A'&&s[i+1]<='S'&&s[i+1]-s[i-1]>0)||(s[i-1]>='a'&&s[i+1]<='s'&&s[i+1]-s[i-1]>0)||(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)){ // @@ The condition incorrectly restricts the right character to be <= 'S' or 's', which prevents valid expansions for characters beyond these limits (e.g., 'u'). It should verify that both s[i-1] and s[i+1] belong to the same character type (uppercase, lowercase, or digits) and that s[i+1] > s[i-1].
             for(k=1;k<s[i+1]-s[i-1];k++){
       printf("%c",s[i-1]+k);        
                }
   
   }
   else printf("%c",s[i]);
  
}else printf("%c",s[i]);
   
   }
   
   return 0;
}