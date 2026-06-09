#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 1024

char count[max]={0}, sym[max]={0};
int num[max]={0}, geshu;

void del(){
    int i, j ;
    char c, count2[max]={0} ;

    i=0 ;
    j=0 ;
    for (i=0; i<strlen(count); i++) {
        c = count[i] ;
        if (c!=' ') {
            count2[j] = c ;
            j ++ ;
            }
        }

    strcpy(count, count2) ;
}

int judge(){
    int i ,nu=0, len = strlen (sym);

    for (i = 0; i < len; i++){
        if (sym[i]=='*'||sym[i]=='/')
            nu++;
    }
    if (nu==0)
        return 0;
    else //if (nu!=0)
        return 1;
}

int restore(){
    int i, n ;
    int cur_int ;
    char c ;

    n = 0 ;    // 数字的个数为0
    cur_int = 0 ;   // 数为0

    // 如果第一个字符不是数字而是运算符，则将整个表达式后移，然后人为补一个0
    // -5+3=  --> 0-5+3
    c = count[0] ;
    if (isdigit(c)==0) {
        strcpy(&count[1], &count[0]) ;
        count[0]='0' ;
    }

    for (i=0;i<strlen(count);i++){
        c = count[i] ;
        if ( isdigit(c) )
            cur_int = cur_int*10 + c - '0' ;
        else  {
            num[n] = cur_int ;
            sym[n] = c ;
            cur_int = 0 ;
            n ++ ;
            }
        }

    return n ;
}

void move(int pos){
    int i;
    for (i=pos+1;i<geshu;i++){
        num[i]=num[i+1];
    }
    num[i]=0;
}

void chengchu_gxp(){
    int i=0;
    int total ;
    char c ;

    total = geshu ;

    while ( total ) {
        c = sym[i] ;
        switch ( c ) {
            case '*' :
                num[i] = num[i] * num[i+1] ;
                strcpy(&sym[i],&sym[i+1]);
                move(i);
                geshu--;
                break ;
            case '/' :
                num[i] = num[i] / num[i+1] ;
                strcpy(&sym[i],&sym[i+1]);
                move(i);
                geshu--;
                break ;
            case '+' :
            case '-' :
                i++ ;
                break ;
            default :
                break ;
            }
        total -- ;
        }
}


int sum(){
    int i,s;
    for (i=0,s=num[0];sym[i]!='=';i++){
        if(sym[i]=='+'){
            s=s+num[i+1];
        }
        if(sym[i]=='-'){
            s=s-num[i+1];
        }
    }
    return s;
}


int main()
{
    int s,jud;

    gets(count);
    del();
    geshu=restore();

    jud=judge();
    if (jud==0){
        s=sum();
        printf("%d",s);
        return 0;
    }

    else if (jud==1){
        chengchu_gxp();
        s=sum();
        printf("%d",s);
        return 0;
    }

}



