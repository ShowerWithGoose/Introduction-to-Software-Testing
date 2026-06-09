#include <stdio.h>
#include <string.h>
char s[105];
int main(){
    int x,j,y=0,i;
    gets(s); @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers.]
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
            printf("%se0",s); @@ [This prints the entire string 's' followed by 'e0', which is incorrect scientific notation format when there are digits after the decimal point. It should only print one digit before 'e'.]
        }
        else{
            for(i=2;i<=x-1;i++){
                if(s[i]!='0'){
                    break;
                }
            }
            if(i==x-1){
                printf("%ce-%d",s[x-1],i-1); @@ [If all digits after the decimal are zero except the last, this assumes the last character is significant, but 'i' might be out of valid digit range; also, indexing 's[x-1]' may refer to '\0' if input ends with newline or due to prior manipulation.]
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
                printf("%c",s[j]);
            }
        }
        printf("e%d",y-1); @@ [When the original number has more than one digit before the decimal (e.g., "123.45"), this outputs "1.2345e2", which is correct, but if the number starts with '0' and has multiple leading zeros (e.g., "0.00123"), this branch is incorrectly taken because 'y' (position of '.') may not be 1, leading to wrong exponent and base. The logic for determining which branch to take is flawed.]
    }
    return 0;
}