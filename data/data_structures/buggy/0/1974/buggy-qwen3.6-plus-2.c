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
        aft[k]=bef[i];
        if(bef[i]=='-'){ // @@ Potential out-of-bounds access if '-' is at index 0 or len-1; should verify i>0 && i<len-1 before accessing bef[i-1] and bef[i+1]
            if(((bef[i-1]-'a'>=0)&&bef[i-1]-'z'<=0&&(bef[i+1]-'a'>=0)&&(bef[i+1]-'z'<=0))||((bef[i-1]-'0'>=0)&&bef[i-1]-'9'<=0&&(bef[i+1]-'0'>=0)&&(bef[i+1]-'9'<=0))||((bef[i-1]-'A'>=0)&&bef[i-1]-'Z'<=0&&(bef[i+1]-'A'>=0)&&(bef[i+1]-'Z'<=0))){ // @@ Missing condition bef[i-1] < bef[i+1]; expansion should only happen when the right character is strictly greater than the left
                for(j=1;bef[i-1]+j<bef[i+1];j++,k++){
                    aft[k]=bef[i-1]+j;
                }
                k--; // @@ Unconditionally decrements k, removing '-' even when no expansion occurs (e.g., a-a or z-a), violating the requirement to output unchanged for invalid ranges
            }
        }
    }
}


int main()
{
    scanf("%s",bef);
    expand(bef);
    puts(aft); // @@ 'aft' is not explicitly null-terminated after the loop, which may cause puts to print garbage characters
    
     return 0;
 }