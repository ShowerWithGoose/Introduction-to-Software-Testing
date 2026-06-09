#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
char bef[1000],aft[1000];


void expand(char bef[]){
    int i,j,k;
    int len = strlen(bef);
    for(i=0,k=0;i<len;i++,k++){
        //printf("%c",bef[i]);
        aft[k]=bef[i]; // @@ Unconditionally copies the '-' character. If expansion occurs, '-' should be replaced/removed, not kept in the output.
        if(bef[i]=='-'){
            if(((bef[i-1]-'a'>=0)&&bef[i-1]-'z'<=0&&(bef[i+1]-'a'>=0)&&(bef[i+1]-'z'<=0))||((bef[i-1]-'0'>=0)&&bef[i-1]-'9'<=0&&(bef[i+1]-'0'>=0)&&(bef[i+1]-'9'<=0))||((bef[i-1]-'A'>=0)&&bef[i-1]-'Z'<=0&&(bef[i+1]-'A'>=0)&&(bef[i+1]-'Z'<=0))){ // @@ Fails to explicitly check if bef[i+1] > bef[i-1] as required by the problem. Also causes out-of-bounds memory access when i=0 or i=len-1.
                for(j=1;bef[i-1]+j<bef[i+1];j++,k++){
                    aft[k]=bef[i-1]+j;
                }
                k--; // @@ Incorrectly decrements k, causing index misalignment. The next iteration's k++ will overwrite the last expanded character or skip a position.
            }
        }
    }
}


int main()
{
    scanf("%s",bef);
    expand(bef);
    puts(aft); // @@ The aft array is not explicitly null-terminated after the loop. Should add aft[k] = '\0'; before printing to ensure correct string output.
    
     return 0;
 }