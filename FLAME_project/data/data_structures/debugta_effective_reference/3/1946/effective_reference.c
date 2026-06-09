#include <stdio.h>
#include <string.h>
char s[100];

int nmsl(int xy){
    int sb=0;
    for(;s[xy]!='\0';xy++){
        if(s[xy]>='0'&&s[xy]<='9'){
            sb+=s[xy]-'0';
        }
    }
    return sb;
}

void op(void){
    int op=0,jb,sb,xy,zn=0,xc=0,l=strlen(s);
    if(s[1]=='.'&&s[0]!='0'){
        printf("%c.",s[0]);
        for(xy=2;xy<l;xy++){
            if(s[xy]>'0'&&s[xy]<='9'){
                printf("%c",s[xy]);
            }
            else if(s[xy]=='0'){
                sb=nmsl(xy);
                if (sb!=0){
                   printf("0");
                }
                else break;
            }
        }
        printf("e0");
        return ;
    }
    for(xy=0;xy<l;xy++){
        if(s[xy]=='.') {
            op=xy;
            break;
        }
    }
    for(xy=0;xy<l;xy++){
        if(!zn){
            if(s[xy]>'0'&&s[xy]<='9'){
            printf("%c",s[xy]);
            jb=xy;
            zn=1;
            }
        } 
        else {
            if(s[xy]>'0'&&s[xy]<='9'){
                if(xc)
                printf("%c",s[xy]);
                else {
                    printf(".%c",s[xy]);
                    xc=1;
                }
            }
            else if(s[xy]=='0'){
                sb=nmsl(xy);
                if(!xc){
                    if(sb!=0)
                    {
                        printf(".0");
                        xc=1;
                    }
                }
                else{
                    
                    if (sb!=0){
                        printf("0");
                    }
                    else break;
                }
            }
        }
    }
    if(s[1]!='.') printf("e%d",op-jb-1);
    else 
    printf("e%d",op-jb);
} 

int main()
{
    scanf("%s",s);
    op();
    return 0;
}
