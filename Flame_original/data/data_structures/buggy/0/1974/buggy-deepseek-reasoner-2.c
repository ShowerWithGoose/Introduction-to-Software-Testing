#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h> // @@ [Non-standard header, may cause compilation error on some systems. Use <stdlib.h> instead if malloc is needed.]
char bef[1000],aft[1000];


void expand(char bef[]){
    int i,j,k;
    int len = strlen(bef);
    for(i=0,k=0;i<len;i++,k++){ // @@ [When i=0, later accesses to bef[i-1] are out-of-bounds. Also expansion may cause k to exceed 999.]
        //printf("%c",bef[i]);
        aft[k]=bef[i];
        if(bef[i]=='-'){ // @@ [No check for i==0 or i==len-1 leads to out-of-bounds access.]
            if(((bef[i-1]-'a'>=0)&&bef[i-1]-'z'<=0&&(bef[i+1]-'a'>=0)&&(bef[i+1]-'z'<=0))||((bef[i-1]-'0'>=0)&&bef[i-1]-'9'<=0&&(bef[i+1]-'0'>=0)&&(bef[i+1]-'9'<=0))||((bef[i-1]-'A'>=0)&&bef[i-1]-'Z'<=0&&(bef[i+1]-'A'>=0)&&(bef[i+1]-'Z'<=0))){ // @@ [Missing parentheses around second range checks? Actually parsed correctly, but the out-of-bounds access is the real issue. Also no check that i+1 is within bounds.]
                for(j=1;bef[i-1]+j<bef[i+1];j++,k++){ // @@ [k increments inside loop; if many characters are added, aft may overflow (max 999). Also k-- afterward may cause incorrect indexing.]
                    aft[k]=bef[i-1]+j;
                }
                k--;
            }
        }
    }
}


int main()
{
    scanf("%s",bef);
    expand(bef);
    puts(aft);
    
     return 0;
 }