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
            y=0; // @@ [This line incorrectly resets y to 0 for every non-'.' character. As a result, if the decimal point is not at index 0, y will be set to 0 in the last iteration where s[j] != '.', overwriting the correct position of the decimal point. This causes incorrect exponent calculation later.]
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
                printf("%c.",s[i]); // @@ [This should print s[i] as the first significant digit, but it skips all leading zeros correctly. However, the exponent calculation "i-1" is off by one because the first non-zero digit is at position i, and the decimal point was at position 1, so the exponent should be -(i - 1). But more critically, this branch assumes the number starts with "0.", which may not hold if y != 1 due to prior error.]
                for(j=i+1;j<=x-1;j++){
                    printf("%c",s[j]);
                }
                printf("e-%d",i-1); // @@ [Exponent should be -(i - 1), but printed as negative of (i - 1). However, the real issue stems from incorrect y due to earlier error.]
            }
        }
    }
    else{
        printf("%c.",s[0]);
        for(j=1;j<=x-1;j++){
            if(s[j]=='.'){
                j++; // @@ [This skips the next character after '.', but if '.' is at the end or followed by nothing, this may cause out-of-bound access or skipping valid digits. Also, this logic fails to handle cases where there are multiple digits before the decimal point correctly because it always prints s[0] then all non-'.' characters, but doesn't account for the correct number of digits moved.]
            }
            else{
                printf("%c",s[j]);
            }
        }
        printf("e%d",y-1); // @@ [Because y is incorrectly set to 0 when there's no '.' or due to the loop logic error, y-1 becomes -1 even for numbers like "87899.999...", where y should be 5 (position of '.'). Thus, exponent becomes -1 instead of 4. In the test case, y ends up as 0, so exponent is -1, but the printed exponent is 4 because the code actually uses y from a broken logic — however, in reality, due to the earlier error setting y=0, this prints e-1, but observed output is e4, meaning y was somehow 5. Contradiction suggests the actual bug is that the 'else { y=0; }' inside the loop destroys the correct y. For input "87899.999...", the loop sets y=0 for j=0 ('8'), then j=1 ('7') → y=0, ..., until j=5 ('.') → y=5 and break. So maybe y is correct? But wait: the test input has trailing zeros and digits: "87899.9999999999000999". The buggy output drops a '9', printing "8.7899999999999000999" instead of "8.78999999999999000999". So the issue is not y, but digit copying. Looking closer: in the 'else' block (y != 1), it prints s[0], then from j=1 to end, skipping '.' by doing j++. But when it sees '.', it does j++, which skips the next digit. For example, in "87899.999...", at j=5 (the '.'), it does j++, so j becomes 6, and the loop increments j again (j++ in for), so j=7 → thus, the first digit after '.' (at index 6) is skipped. This causes loss of one '9'.]
        }
    }
    return 0;
}