#include <stdio.h>
#include <string.h>
char s[105];
int main(){
    int x,j,y=0,i;
    gets(s);
    x=strlen(s);
    if(s[0]=='-'){
        printf("-");
        for(i=0,j=1;j<=x-1;j++,i++){
            s[i]=s[j];
        }
        s[x-1]=0;
        x=strlen(s);
    }
    for(j=0;j<=x-1;j++){
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
            for(i=2;i<=x-1;i++){
                if(s[i]!='0'){
                    break;
                }
            }
            if(i==x-1){
                printf("%ce-%d",s[x-1],i-1);
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
    else{
        printf("%c.",s[0]);
        for(j=1;j<=x-1;j++){
            if(s[j]=='.'){
                j++;
            }
            else{
                printf("%c",s[j]); // @@ The loop condition `j<=x-1` combined with the logic inside fails to correctly handle all digits when skipping the decimal point. Specifically, when `s[j]=='.'`, `j` is incremented, but the loop increment `j++` in the `for` statement happens afterwards, effectively skipping the character after the decimal point as well if not careful, or more accurately, the logic `if(s[j]=='.') j++;` skips the dot, but then the `else` prints `s[j]`. However, the issue in the test case `87899.9999999999000999` is that the output is missing a `9`. Let's trace: `s` is `87899.9999999999000999`. `y=5`. Loop `j` from 1 to 19. `j=1` ('7') print. `j=2` ('8') print. `j=3` ('9') print. `j=4` ('9') print. `j=5` ('.') -> `j` becomes 6. Loop end `j` becomes 7. `j=7` ('9') print. Wait, `s[6]` is '9'. It was skipped. When `j=5`, `s[5]=='.'`, so `j` becomes 6. Then the `for` loop does `j++`, so `j` becomes 7. The character at `s[6]` (the first '9' after the decimal) is never printed. This explains the missing digit.
            }
        }
        printf("e%d",y-1);
    }
    return 0;
}