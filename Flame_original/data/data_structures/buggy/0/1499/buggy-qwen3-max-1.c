#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers. It should be replaced with 'fgets'.]
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){ // @@ [Loop condition stops at strlen(a)-1, which may skip the last character if it's not part of a '-' pattern, leading to incomplete output. Also, if the string ends with '-', accessing a[toa+1] could be out-of-bounds in some cases.]
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++;
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){ // @@ [Incorrect range checks: e.g., for digits, it checks a[toa-1]>=48 (correct) but a[toa+1]<=57 without ensuring a[toa+1]>=48; similarly for letters. This allows mixed-type cases like '0-Z' to pass if ASCII values coincidentally satisfy the flawed condition. Also, equality (<=) allows non-increasing sequences, but problem requires strictly increasing (arr[i-1] < arr[i+1]).]
                for(int i=(int)(a[toa-1]);i<(int)(a[toa+1]);i++){ // @@ [This loop prints from a[toa-1] to a[toa+1]-1, but according to the problem, expansion of 'a-d' should produce 'abcd', meaning it should include both endpoints. However, the reference program only prints the characters between, excluding the endpoints, because the endpoints are printed elsewhere. But in this buggy code, when expansion occurs, the left character (a[toa-1]) was already printed in a previous iteration, and the right character (a[toa+1]) will never be printed because the loop skips ahead. This leads to missing the final character of the range.]
                    printf("%c",(char)i);
                }
            }else{
                printf("%c%c%c",a[toa-1],a[toa],a[toa+1]); // @@ [When no expansion is done, it prints three characters at once. However, the left character (a[toa-1]) might have already been printed in a previous iteration (since the loop prints characters one by one unless a '-' is found), leading to duplication. For example, input "a-b" would print 'a' in the first branch, then when '-' is found, it prints 'a', '-', 'b' again — causing 'aab' or similar incorrect output.]
            }
            toa++;
        }
    }
}