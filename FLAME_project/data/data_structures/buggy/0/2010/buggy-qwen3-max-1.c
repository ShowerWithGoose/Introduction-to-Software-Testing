#include<stdio.h>
int main(){
   char s[10001];
   gets(s);
   int i,k;
   for(i=0;s[i]!='\0';i++){
   
       if (s[i]=='-'){
                if ((s[i-1]>='A'&&s[i+1]<='S'&&s[i+1]-s[i-1]>0)||(s[i-1]>='a'&&s[i+1]<='s'&&s[i+1]-s[i-1]>0)||(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)){ @@ [The condition checks incorrect upper bounds: 'S' and 's' instead of 'Z' and 'z'. Also, it doesn't ensure both characters are of the same type (e.g., allows 'A' to 's'). Additionally, accessing s[i-1] when i=0 leads to out-of-bounds read.]
             for(k=1;k<s[i+1]-s[i-1];k++){
       printf("%c",s[i-1]+k);        
                }
   
   }
   else printf("%c",s[i]); @@ [This else is incorrectly paired with the inner if, causing characters after '-' to be printed even when expansion occurs, leading to duplication. Also, the logic prints characters one by one instead of building/outputting the full string correctly.]
  
}else printf("%c",s[i]); @@ [This else is paired with the outer if (s[i]=='-'), but due to flawed control flow, non-'-' characters may be printed multiple times or skipped. The entire output logic is flawed because it mixes immediate printing with expansion, making it impossible to handle overlapping or consecutive expansions correctly.]
   
   }
   
   return 0;
}