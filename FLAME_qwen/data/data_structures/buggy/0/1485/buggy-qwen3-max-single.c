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
           j=s[i+1]-s[i-1]-2; // @@ [If s[i+1] <= s[i-1], j becomes negative, leading to invalid array access or incorrect behavior. Also, expansion should only occur when s[i+1] > s[i-1].]
           for(m=1;k-m>=i+1;m++){
               s[k-m+j]=s[k-m]; // @@ [When j is negative (e.g., if no expansion should happen), this shifts characters left incorrectly. Also, buffer overflow may occur if j is positive and the string grows beyond 200.]
           }
        for(n=i;n<=i+j;n++){
            s[n]=s[n-1]+1; // @@ [This overwrites the '-' and subsequent characters without preserving the original structure correctly. Also, if j is negative, loop condition may be invalid.]
        }
        
        
       
    }
        
    }

    printf("%s",s);
    
    
}