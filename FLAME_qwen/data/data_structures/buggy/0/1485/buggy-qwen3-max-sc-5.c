/*本次作业由本人独立完成，如有抄袭行为，愿承担由此带来的一切不良后果*/ 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()

{
    int i,j,k,m,n;
    char s[200]={0};
    scanf("%s",s);

    for(i=1;s[i]!='\0';i++){
        k=strlen(s);
       if(s[i]=='-'&&((isdigit(s[i-1])&&isdigit(s[i+1]))||(isupper(s[i-1])&&isupper(s[1+1]))||(islower(s[i-1])&&islower(s[i+1])))){
           j=s[i+1]-s[i-1]-2; // @@ [Logic error: j should be the number of characters to insert, which is (s[i+1] - s[i-1] - 1), not -2. Also, if s[i+1] == s[i-1]+1, j becomes -1, leading to invalid behavior.]
           for(m=1;k-m>=i+1;m++){
               s[k-m+j]=s[k-m]; // @@ [Buffer overflow risk: k-m+j may exceed array bounds or overwrite unintended memory because j can be negative or too large. Also, string length isn't updated properly.]
           }
        for(n=i;n<=i+j;n++){ // @@ [If j is negative (e.g., when s[i+1] <= s[i-1]), this loop condition becomes invalid and may not run or cause undefined behavior. Additionally, even if valid, it overwrites the '-' and part of the following character incorrectly.]
            s[n]=s[n-1]+1;
        }
        
        
       
    }
        
    }

    printf("%s",s); // @@ [The output may be incorrect due to flawed expansion logic and possible string corruption during in-place modification without proper null-termination maintenance.]
    
    
}