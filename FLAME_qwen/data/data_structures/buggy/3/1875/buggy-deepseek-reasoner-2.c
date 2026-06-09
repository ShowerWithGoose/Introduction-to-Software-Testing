#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char s[1000000]={0};
    gets(s); // @@ Unsafe function gets() can cause buffer overflow; in modern C standards it is removed, leading to compilation error.
    int len=strlen(s);
    int i,j;
    int cnt1=0,cnt2,mark1,mark2;
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
        printf("%c",s[mark1]); // @@ If no non-zero digit is found (e.g., input "0.0"), mark1 remains uninitialized, causing undefined behavior.
        if(mark1!=len-1){
            printf(".");
        }
        for(i=mark1+1;i<len;i++){
            printf("%c",s[i]);
        }
        printf("e-%d",cnt1);
    }else{
        for(i=0;i<len;i++){
            if(s[i]!='.'){
                cnt2++;
            }else{
                mark2=i;
                break;
            }
        }
        if(mark2==1){
            printf("%se0",s);
        }else{
            printf("%c.",s[0]);
            for(i=1;i<len;i++){
                if(s[i]!='.'){
                    printf("%c",s[i]);
                }
            }
            printf("e%d",cnt2-1);
        }
    }
    return 0;
}