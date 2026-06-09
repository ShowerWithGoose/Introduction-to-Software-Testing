#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char s[1000000]={0};
    gets(s); // @@ [Using gets() is unsafe and deprecated; more critically, it may include the newline in some environments, but the main issue is logic errors below. However, the primary bugs are logical, not this.]
    int len=strlen(s);
    int i,j;
    int cnt1=0,cnt2,mark1,mark2; // @@ [cnt2 is used uninitialized in the else branch if the loop doesn't run, leading to undefined behavior.]
    for(i=0;i<len;i++){
        if(s[i]!='.'){
            if(s[i]=='0'){
                cnt1++;
            }else{
                mark1=i;
                break;
            }
        }
    }
    if(cnt1>=1){
        printf("%c",s[mark1]);
        if(mark1!=len-1){
            printf(".");
        }
        for(i=mark1+1;i<len;i++){
            printf("%c",s[i]); // @@ [This prints all characters after mark1, including '.', which violates the requirement of only printing digits.]
        }
        printf("e-%d",cnt1); // @@ [The exponent calculation is incorrect. It assumes all leading zeros before the first non-zero digit contribute to a negative exponent, but doesn't account for the position of the decimal point correctly.]
    }else{
        for(i=0;i<len;i++){
            if(s[i]!='.'){
                cnt2++; // @@ [cnt2 was never initialized to 0, so this increment starts from garbage value.]
            }else{
                mark2=i;
                break;
            }
        }
        if(mark2==1){
            printf("%se0",s); // @@ [This prints the entire original string, which may have multiple digits before the decimal (e.g., "12.3" becomes "12.3e0"), violating the scientific notation format requiring only one non-zero digit before the decimal or as integer.]
        }else{
            printf("%c.",s[0]);
            for(i=1;i<len;i++){
                if(s[i]!='.'){
                    printf("%c",s[i]); // @@ [Again, this prints all non-dot characters after index 0, which may include extra digits before the decimal point that should not appear in normalized scientific notation.]
                }
            }
            printf("e%d",cnt2-1); // @@ [Due to cnt2 being uninitialized and incorrect counting logic, the exponent is wrong. Also, the normalization logic fails when there are multiple digits before the decimal.]
        }
    }
    return 0;
}