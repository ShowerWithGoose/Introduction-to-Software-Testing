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
       if(s[i]=='-'&&((isdigit(s[i-1])&&isdigit(s[i+1]))||(isupper(s[i-1])&&isupper(s[1+1]))||(islower(s[i-1])&&islower(s[i+1])))){ // @@ Typo: s[1+1] should be s[i+1]; also missing condition s[i-1] < s[i+1] to ensure expansion only when the right character is greater than the left.
           j=s[i+1]-s[i-1]-2; // @@ Incorrect calculation for the number of characters to insert; should be s[i+1]-s[i-1]-1.
           for(m=1;k-m>=i+1;m++){
               s[k-m+j]=s[k-m];
           }
        for(n=i;n<=i+j;n++){ // @@ Off-by-one error in loop condition; should be n < i + j to correctly fill the inserted characters without overwriting.
            s[n]=s[n-1]+1;
        }
        
        
       
    }
        
    }

    printf("%s",s);
    
    
}