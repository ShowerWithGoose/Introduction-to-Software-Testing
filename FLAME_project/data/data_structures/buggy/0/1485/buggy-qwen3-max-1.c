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
           j=s[i+1]-s[i-1]-2; // @@ [j should be s[i+1] - s[i-1] - 1 to get the correct number of characters to insert between s[i-1] and s[i+1]; current calculation misses the last character]
           for(m=1;k-m>=i+1;m++){
               s[k-m+j]=s[k-m];
           }
        for(n=i;n<=i+j;n++){
            s[n]=s[n-1]+1; // @@ [This overwrites the '-' and subsequent characters incorrectly; it should start from s[i-1]+1 and fill up to s[i+1]-1, but logic fails when j is miscalculated and loop bounds are wrong]
        }
        
        
       
    }
        
    }

    printf("%s",s); // @@ [The loop does not handle multiple expansion cases correctly (e.g., a-uB-F), and fails to skip already processed expanded parts, leading to incorrect output like missing 'BCDEF']
    
    
}