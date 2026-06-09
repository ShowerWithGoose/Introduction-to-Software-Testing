#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

char ch[105];

void f(char x,char y)
{
    int flg=0;
    if(isdigit(x)&&isdigit(y))flg=1;
    if(isupper(x)&&isupper(y))flg=1;
    if(islower(x)&&islower(y))flg=1;

    if(!flg){
        printf("%c-",x);
        return;
    }

    for(int i=x;i<y;i++){
        printf("%c",i);
    }
}

int main()
{
    gets(ch);

    int len=strlen(ch);

    int i;
    for(i=0;(i+2)<len;i++){
        if(ch[i+1]=='-'){
            f(ch[i],ch[i+2]);
            i++;
            continue;
        }

        printf("%c",ch[i]);
    }

    printf("%c%c",ch[i],ch[i+1]);

    return 0;
}

