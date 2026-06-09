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
           j=s[i+1]-s[i-1]-2; // @@ [This calculation is incorrect: it should be s[i+1] - s[i-1] - 1 to get the number of characters to insert between s[i-1] and s[i+1]. Also, j can be negative if s[i+1] <= s[i-1], leading to undefined behavior.]
           for(m=1;k-m>=i+1;m++){
               s[k-m+j]=s[k-m]; // @@ [If j is negative (e.g., when s[i+1] <= s[i-1]), this writes to an invalid memory location before the string start, causing buffer underflow or corruption.]
           }
        for(n=i;n<=i+j;n++){
            s[n]=s[n-1]+1; // @@ [This loop assumes j >= 0, but j may be negative. Also, it overwrites the '-' and part of the following characters without ensuring proper bounds or that expansion condition (s[i-1] < s[i+1]) is met.]
        }
        
        
       
    }
        
    }

    printf("%s",s);
    
    
}