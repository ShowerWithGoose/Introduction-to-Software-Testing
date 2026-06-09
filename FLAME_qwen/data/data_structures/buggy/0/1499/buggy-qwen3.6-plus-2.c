#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a); // @@ The 'gets' function has been removed from the C11 standard and will cause a compilation error on modern compilers; use 'fgets' or 'scanf' instead.
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){ // @@ The loop condition 'toa<strlen(a)-1' causes the last character of the input string to be skipped and not printed.
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++;
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){ // @@ The type checking logic is incorrect; it only verifies the left character is >= the range start and the right character is <= the range end, failing to ensure both characters are within the same valid range (e.g., both digits, both uppercase, or both lowercase).
                for(int i=(int)(a[toa-1]);i<(int)(a[toa+1]);i++){ // @@ The loop condition 'i<(int)(a[toa+1])' stops before printing the character after '-', resulting in an incomplete expansion range that misses the end character.
                    printf("%c",(char)i);
                }
            }else{
                printf("%c%c%c",a[toa-1],a[toa],a[toa+1]);
            }
            toa++;
        }
    }
}