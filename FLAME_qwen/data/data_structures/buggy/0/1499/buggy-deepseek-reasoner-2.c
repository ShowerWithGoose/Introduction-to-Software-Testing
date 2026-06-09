#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a);
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){ // @@ Loop condition should be toa<strlen(a) to include the last character
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++; // @@ This increments past the before character without printing it; before character should be printed before expansion
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){ // @@ Condition should use '<' rather than '<=' and also check lower bound for second character (e.g., a[toa+1]>=48 for digits)
                for(int i=(int)(a[toa-1]);i<(int)(a[toa+1]);i++){ // @@ This loop prints only middle characters; missing print of before and after characters
                    printf("%c",(char)i);
                }
            }else{
                printf("%c%c%c",a[toa-1],a[toa],a[toa+1]);
            }
            toa++; // @@ This increment skips the after character, causing it not to be printed
        }
    }
}