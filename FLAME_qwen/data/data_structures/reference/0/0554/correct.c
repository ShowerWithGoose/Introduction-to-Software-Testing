#include<stdio.h>

#include<string.h>

int check(char,char);

int main(){

    char ch[10000];

    char chk;

    int i;

    scanf("%s",ch);

    int len=strlen(ch);

    for(i=0;i<len;i++){

        if(i>=1&&i<len-1&&ch[i]=='-'&&check(ch[i-1],ch[i+1])==1){

            for(chk=ch[i-1]+1;chk<=ch[i+1];chk++){

                printf("%c",chk);
            }

            i++;

            continue;
        }

        printf("%c",ch[i]);
    }

    return 0;
}

int check(char a,char b){

    if(a>='0'&&a<='9'&&b>='0'&&b<='9'&&a<b) return 1;

    if(a>='a'&&a<='z'&&b>='a'&&b<='z'&&a<b) return 1;

    if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'&&a<b) return 1;

    return 0;
}



