#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int findpoint(char *s){
    int i=-1;
    while(s[++i]!='.'){
        if(s[i]=='\0')return 0;
    }
    return i;
}

int jump(char *a,char *b){
    int i=0;
    if(a[0]=='0'){//向后移动
        while(b[i++]=='0'){}
        return -i;
    }
    else{return (int)strlen(a)-1;}
}



int main() {
    char s[205],sint[205]="",sflt[205]="";
    gets(s);
    int i=findpoint(s);
    strncat(sint, s, i);
    strcat(sflt, s+i+1);
    int step=jump(sint,sflt);
    if(step<0 && -step==strlen(sflt))printf("%c%se%d",sflt[-step-1],sflt-step,step);
    else if(step<0)printf("%c.%se%d",sflt[-step-1],sflt-step,step);
    else printf("%c.%s%se%d",sint[0],sint+1,sflt,step);
    return 0;
}

