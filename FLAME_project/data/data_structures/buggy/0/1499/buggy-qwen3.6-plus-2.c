#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a);
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++;
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){ // @@ The condition checks if the end character is within the valid range (e.g., <=57) but fails to check if the start character is also within that same specific range (e.g., >=48 && <=57). It only checks if the start is >=48. This allows mixed types like 'a' (97) and 'B' (66) to potentially pass incorrect logic or, more critically, in the case of 'B-F', it checks if 'B'>=65 (True) and 'F'<=90 (True) and 'B'<'F' (True). However, the loop below prints from start to end-1.
                for(int i=(int)(a[toa-1]);i<(int)(a[toa+1]);i++){
                    printf("%c",(char)i);
                }
            }else{
                printf("%c%c%c",a[toa-1],a[toa],a[toa+1]);
            }
            toa++;
        }
    }
}