#include <stdio.h>
#include <string.h>
char s[105];
int main(){
    int x,j,y=0,i;
    gets(s); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, the problem states input has no sign, but this code handles '-', which is unnecessary and leads to logic errors]
    x=strlen(s);
    if(s[0]=='-'){ // @@ [Problem states input has no sign, so handling '-' is incorrect and leads to wrong processing]
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
            y=0; // @@ [This assignment inside else overwrites y incorrectly; y should retain its value if '.' not found yet]
        }
    }
    if(y==1){ // @@ [This condition assumes decimal point is at index 1, but doesn't handle general cases like numbers < 1 (e.g., "0.00123") correctly]
        if(s[0]>'0'){
            printf("%se0",s); // @@ [Incorrect output format: includes entire string instead of normalized scientific notation base]
        }
        else{
            for(i=2;i<=x-1;i++){
                if(s[i]!='0'){
                    break;
                }
            }
            if(i==x-1){ // @@ [Off-by-one error: loop ends at i=x-1, so i==x-1 means last char was non-zero, but condition implies all were zero]
                printf("%ce-%d",s[x-1],i-1); // @@ [Uses s[x-1] which may be '\0' or invalid; should use first non-zero digit]
            }
            else{
                printf("%c.",s[i]); // @@ [s[i] is first non-zero after zeros, but printing it as base without checking if it's valid]
                for(j=i+1;j<=x-1;j++){
                    printf("%c",s[j]);
                }
                printf("e-%d",i-1); // @@ [Exponent calculation is incorrect for numbers like "0.00123"; should be -(i-1) or similar based on position relative to decimal]
            }
        }
    }
    else{
        printf("%c.",s[0]); // @@ [Assumes first digit is non-zero and always prints with decimal, even if number is like "123.45" which should become "1.2345e2"]
        for(j=1;j<=x-1;j++){
            if(s[j]=='.'){
                j++; // @@ [Skipping '.' by incrementing j inside loop causes next character to be skipped due to loop's j++]
            }
            else{
                printf("%c",s[j]);
            }
        }
        printf("e%d",y-1); // @@ [Exponent y-1 is only correct if number >= 1 and has decimal point; fails for integers or numbers without decimal]
    }
    return 0;
}