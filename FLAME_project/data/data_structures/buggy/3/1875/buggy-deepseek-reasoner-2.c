#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char s[1000000]={0};
    gets(s);
    int len=strlen(s);
    int i,j;
    int cnt1=0,cnt2,mark1,mark2; // @@ Uninitialized variables cnt2, mark1, mark2 may lead to undefined behavior.
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
        printf("%c",s[mark1]); // @@ mark1 may be uninitialized if no non-zero digit found (e.g., input "0.0").
        if(mark1!=len-1){ // @@ mark1 may be uninitialized.
            printf(".");
        }
        for(i=mark1+1;i<len;i++){ // @@ mark1 may be uninitialized.
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
        if(mark2==1){ // @@ mark2 may be uninitialized if decimal point not found (e.g., input "W").
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