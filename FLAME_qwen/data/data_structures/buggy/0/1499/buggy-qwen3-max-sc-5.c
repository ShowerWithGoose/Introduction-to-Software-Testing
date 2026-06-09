#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers due to security risks. Should use 'fgets' instead.]
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){ // @@ [Loop condition may skip the last character if it's not part of a '-' pattern, leading to incomplete output. Also, if string length is 0 or 1, strlen(a)-1 becomes negative, causing undefined behavior.]
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++;
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){ // @@ [Incorrect range checks: e.g., for digits, it checks a[toa-1] >= '0' but a[toa+1] <= '9', without ensuring a[toa+1] >= '0'. Same issue for letters. This allows invalid cross-type cases like 'a-9' to pass if ASCII values coincidentally satisfy the flawed condition.]
                for(int i=(int)(a[toa-1]);i<(int)(a[toa+1]);i++){ // @@ [This loop prints from a[toa-1] up to (but not including) a[toa+1], which omits the final character of the range. According to problem, 'a-d' should become 'abcd', but this would only print 'abc'. Also, it prints the starting character again, which was already printed in previous steps, causing duplication.]
                    printf("%c",(char)i);
                }
            }else{
                printf("%c%c%c",a[toa-1],a[toa],a[toa+1]); // @@ [This prints three characters at once, but the first character (a[toa-1]) may have already been printed in a prior iteration, leading to duplication. The logic for handling non-expandable '-' is flawed due to overlapping output.]
            }
            toa++;
        }
    }
}