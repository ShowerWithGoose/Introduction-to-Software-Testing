#include<stdio.h>
int main(){
   char s[10001];
   gets(s); // @@ [Use of unsafe function 'gets' which has been removed from newer C standards; may cause compilation error with modern compilers]
   int i,k;
   for(i=0;s[i]!='\0';i++){
   
       if (s[i]=='-'){
                if ((s[i-1]>='A'&&s[i+1]<='S'&&s[i+1]-s[i-1]>0)||(s[i-1]>='a'&&s[i+1]<='s'&&s[i+1]-s[i-1]>0)||(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)){ // @@ [Incorrect range checks: e.g., 's[i+1]<='S'' should be 's[i+1]<='Z'' and similarly 's[i+1]<='s'' should be 's[i+1]<='z''; also missing check that s[i-1] is within valid range for its category]
             for(k=1;k<s[i+1]-s[i-1];k++){
       printf("%c",s[i-1]+k);        
                }
   
   }
   else printf("%c",s[i]); // @@ [Misplaced else: this else corresponds to the inner if checking expansion conditions, but it should output '-' when condition fails; however, due to incorrect nesting, '-' is never printed when expansion doesn't occur]
  
}else printf("%c",s[i]); // @@ [This else corresponds to the outer if (s[i]=='-'), but due to earlier misplaced else, logic is broken; also, when s[i]=='-' and expansion condition fails, nothing prints the '-', leading to missing characters]
   
   }
   
   return 0;
}