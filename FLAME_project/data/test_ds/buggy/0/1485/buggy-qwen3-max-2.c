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
           j=s[i+1]-s[i-1]-2; // @@ [The value of j is incorrect. It should represent the number of characters to insert, which is (s[i+1] - s[i-1] - 1), not minus 2. Also, if s[i+1] <= s[i-1], expansion shouldn't happen, but this isn't checked.]
           for(m=1;k-m>=i+1;m++){
               s[k-m+j]=s[k-m]; // @@ [This shifting logic is flawed. The amount to shift depends on how many characters are inserted, but j may be negative or wrong, leading to buffer overflow or incorrect placement. Also, the loop condition and indexing are error-prone.]
           }
        for(n=i;n<=i+j;n++){
            s[n]=s[n-1]+1; // @@ [This overwrites the '-' and subsequent characters incorrectly. It assumes j is non-negative and that expansion is always valid, but doesn't handle cases where s[i+1] <= s[i-1]. Also, it doesn't skip the original right character after expansion.]
        }
        
        
       
    }
        
    }

    printf("%s",s); // @@ [The algorithm fails to properly expand ranges like 'B-F' because of multiple logic errors: incorrect j calculation, wrong shifting, and not advancing the index i after expansion, causing reprocessing or corruption. Additionally, in the condition, 's[1+1]' is a typo—it should be 's[i+1]'.]
    
    
}