#include<stdio.h>

#include<string.h>

int main(){

    char ch[500];

    int n,i,j,flag;

    scanf("%s",ch);

    int len=strlen(ch);

    if(ch[0]=='0'){

        for(j=2;j<len;j++){

            if(ch[j]!='0'){

                break;
            }
        }

        for(i=j;i<len;i++){

            printf("%c",ch[i]);

            if(len-i!=1&&i==j) printf(".");
        }

        printf("e-%d",j-1);

        return 0;
    }

    if(ch[1]=='.'){

        printf("%se0",ch);

        return 0;
    }

    for(i=0;i<len;i++){

        if(ch[i]!='.') printf("%c",ch[i]);

        if(ch[i]=='.') flag=i;

        if(i==0) printf(".");
    }

    printf("e%d",flag-1);

    return 0;
}

