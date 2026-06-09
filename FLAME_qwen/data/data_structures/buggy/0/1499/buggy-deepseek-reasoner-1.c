#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a); // @@ [gets is deprecated and may cause compilation error in modern C; use fgets instead]
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){ // @@ [Loop condition stops before last character; should be toa<strlen(a) to process all characters]
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++;
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){ // @@ [Condition incorrectly checks only lower bound of left and upper bound of right; should check both bounds for same type; also should use < instead of <= for left<right]
                for(int i=(int)(a[toa-1]);i<(int)(a[toa+1]);i++){
                    printf("%c",(char)i);
                }
            }else{
                printf("%c%c%c",a[toa-1],a[toa],a[toa+1]);
            }
            toa++; // @@ [Increment is incorrect for the non-expansion case; after printing left, dash, and right, toa should be increased by 2 to skip the already printed right character, otherwise it will be printed again]
        }
    }
}