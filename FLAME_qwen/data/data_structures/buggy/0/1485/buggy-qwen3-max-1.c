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
           j=s[i+1]-s[i-1]-2; // @@ [Logic error: j should represent the number of characters to insert, but this calculation is off by one and doesn't handle cases where no expansion is needed (e.g., adjacent chars). Also, if s[i+1] == s[i-1]+1, j becomes -1, leading to invalid array access.]
           for(m=1;k-m>=i+1;m++){
               s[k-m+j]=s[k-m]; // @@ [Buffer overflow risk: when j is negative (e.g., 'a-b'), k-m+j may be less than 0 or overwrite unintended memory. Also, the shifting logic is flawed because it doesn't account for the correct new length after insertion.]
           }
        for(n=i;n<=i+j;n++){
            s[n]=s[n-1]+1; // @@ [Incorrect expansion logic: starts overwriting from position i (the '-'), but should replace '-' and subsequent positions with expanded characters. Also fails when j is negative.]
        }
        
        
       
    }
        
    }

    printf("%s",s); // @@ [Potential undefined behavior: if expansion increases string length beyond original, null terminator may be lost or buffer overrun occurs. Also, if j is negative, string may become corrupted.]
    
    
}