#include <stdio.h>
#include <string.h>
char s[105];
int main(){
    int x,j,y=0,i;
    gets(s); // @@ unsafe function, may cause buffer overflow
    x=strlen(s);
    if(s[0]=='-'){
        printf("-");
        for(i=0,j=1;j<=x-1;j++,i++){
            s[i]=s[j];
        }
        s[x-1]=0; // @@ potential out-of-bounds if x==0 (empty input)
        x=strlen(s);
    }
    for(j=0;j<=x-1;j++){ // @@ loop may have no iterations if x==0, y remains 0
        if(s[j]=='.'){
            y=j;
            break;
        }
        else{
            y=0;
        }
    }
    if(y==1){
        if(s[0]>'0'){
            printf("%se0",s);
        }
        else{
            for(i=2;i<=x-1;i++){ // @@ assumes index 1 is '.'; works only if y==1
                if(s[i]!='0'){
                    break;
                }
            }
            if(i==x-1){
                printf("%ce-%d",s[x-1],i-1); // @@ prints exponent using i-1, correct for valid input
            }
            else{
                printf("%c.",s[i]);
                for(j=i+1;j<=x-1;j++){
                    printf("%c",s[j]);
                }
                printf("e-%d",i-1);
            }
        }
    }
    else{ // handles y!=1 (including y==0 for no decimal point)
        printf("%c.",s[0]); // @@ may output '.' with empty s[0] if y==0 (invalid input)
        for(j=1;j<=x-1;j++){
            if(s[j]=='.'){
                j++;
            }
            else{
                printf("%c",s[j]);
            }
        }
        printf("e%d",y-1); // @@ exponent calculated as y-1; if y==0, prints e-1, incorrect for empty input
    }
    return 0;
}