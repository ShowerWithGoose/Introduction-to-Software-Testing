#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ex(char , char);
int main(){

    char in[9999], out[9999];
    gets(in);

    int i=1, j=1;
    out[0] = in[0];
    for(i=1; i<=strlen(in); i++){
        if(in[i] == '-' && ex(in[i-1],in[i+1]) == 1){
            for(int k=1; k<(in[i+1]-in[i-1]); k++){
                out[j++] = in[i-1] + k;
            }
        }
        else
            out[j++] = in[i];
    }
    printf("%s", out);
    return 0;
}
int ex(char a, char b){
    if((a>='a' && a<='z') && (b>='a' && b<='z'))
        return 1;
    if((a>='A' && a<='Z') && (b>='A' && b<='Z'))
        return 1;
    if((a>='0' && a<='9') && (b>='0' && b<='9'))
        return 1;
    return 0;
}

