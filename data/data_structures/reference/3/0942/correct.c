#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    scanf("%s",s);
    int flag=0;
    for(int i=0;s[i]!='.';i++){
        if(s[i]-'0'>0) flag=1;
    }
    // printf("%d",flag);
    int cnt=0;
    if(flag==1){
        printf("%c.",s[0]);
        int i;
        for(i=1;s[i]!='.';i++){
                printf("%c",s[i]);
                cnt++;
        }
        i++;
        for(;s[i]!='\0';i++){
            printf("%c",s[i]);
        }
    printf("e%d",cnt);
    }else {
        // printf("here");
        int cnt=1;
        int i;
        for(i=2;s[i]=='0';i++){
            cnt++;
        }
        printf("%c",s[i]);
        if(s[i+1]!='\0') printf(".");
        i++;
        for(;s[i]!='\0';i++){
            printf("%c",s[i]);
        }
        printf("e-%d",cnt);
    }
    return 0;
}
