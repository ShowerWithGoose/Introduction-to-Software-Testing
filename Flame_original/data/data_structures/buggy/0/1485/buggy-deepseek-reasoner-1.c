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
       if(s[i]=='-'&&((isdigit(s[i-1])&&isdigit(s[i+1]))||(isupper(s[i-1])&&isupper(s[1+1]))||(islower(s[i-1])&&islower(s[i+1])))){ // @@ [Error: s[1+1] should be s[i+1]; missing condition that a[i-1] < a[i+1] for expansion; may cause out-of-bounds if '-' is at end]
           j=s[i+1]-s[i-1]-2; // @@ [Error: j may be negative if a[i-1] >= a[i+1], leading to invalid shifts]
           for(m=1;k-m>=i+1;m++){ // @@ [Error: k is not updated after expansion, causing shifts based on original length; also loop condition may skip or misplace characters]
               s[k-m+j]=s[k-m]; // @@ [Error: shifting using static k leads to overwriting or incorrect placement; also null terminator may be lost]
           }
        for(n=i;n<=i+j;n++){ // @@ [Error: loop should start at i (overwrite '-'), but j calculation may be off; also does not adjust outer loop index i to skip expanded part, causing re‑processing]
            s[n]=s[n-1]+1;
        }
        
        
       
    }
        
    }

    printf("%s",s);
    
    
}