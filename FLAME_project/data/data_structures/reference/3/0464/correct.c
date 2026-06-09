#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

char ch[105];
int main()
{
    gets(ch);

    int cnt=1;

    if(ch[0]=='0'){
        int i;
        for(i=2;ch[i]=='0';i++){
            cnt++;
        }

        printf("%c",ch[i]);
        i++;
        if(ch[i]!='\0'){
            printf(".");
        }

        while(ch[i]!='\0'){
            printf("%c",ch[i]);
            i++;
        }
        printf("e-%d",cnt);

        return 0;
    }

    int i=0;
    cnt=0;
    printf("%c.",ch[i]);
    for(i=1;ch[i]!='.';i++){
        cnt++;
        printf("%c",ch[i]);
    }
    i++;

    while(ch[i]!='\0'){
        printf("%c",ch[i]);
        i++;
    }

    printf("e%d",cnt);

    return 0;
}

