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
           j=s[i+1]-s[i-1]-2; // @@ [This computes the number of characters to insert incorrectly; it should be s[i+1] - s[i-1] - 1, and only if expansion is valid]
           for(m=1;k-m>=i+1;m++){
               s[k-m+j]=s[k-m]; // @@ [This shifts characters but does not ensure the buffer has enough space; also, j may be negative if s[i+1] <= s[i-1], leading to undefined behavior]
           }
        for(n=i;n<=i+j;n++){
            s[n]=s[n-1]+1; // @@ [This overwrites the '-' and subsequent characters without checking if j >= 0; also, it doesn't handle the case where no expansion should occur (e.g., when s[i+1] <= s[i-1])]
        }
        
        
       
    }
        
    }

    printf("%s",s);
    
    
}