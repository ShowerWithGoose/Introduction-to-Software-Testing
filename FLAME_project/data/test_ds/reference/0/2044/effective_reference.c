#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 1024

int judge(char s[],int pos){
    if(s[pos-1]>=s[pos+1])
        return 0;
    if((isdigit(s[pos-1])&&isdigit(s[pos+1]))||(islower(s[pos-1])&&islower(s[pos+1]))||(isupper(s[pos-1])&&isupper(s[pos+1])))
        return 1;
}

void expand(int jud,int pos,char s[],char e[],char *p_s){
    int i;

    if (jud!=1){//s[]cdeT - bcd
                //e[]cdeT(p)->cedT-b
        strncat(e,p_s,2);
    }
    else { //ADEa - g - m02
           //ADEa bcdef g
        for(i=1;i<=s[pos+1]-s[pos-1];i++){
            e[strlen(e)]=(char)(s[pos-1]+i);
        }
    }

}
//ADEa-g-m02
int main()
{
    char *p_s,s[max]={0},e[max]={0};
    int i,j;

    gets(s);

    //ADEa - g - m02
    //ADEa(bcdefg)

    //s[]cdeT-bcd
    //e[]cdeT-b

    for (i=0,j=0;i<strlen(s);i++){
        if(s[i]!='-'){
            j=strlen(e);
            e[j]=s[i];
        }
        else {
            p_s=&s[i];
            expand(judge(s,i),i,s,e,p_s);
            i++;
        }
    }

    puts(e);

    return 0;
}



