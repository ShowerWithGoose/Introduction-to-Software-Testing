#include <stdio.h>
#include <string.h>

int main(void){
    char a[1000];
    gets(a); // @@ [Using gets() is unsafe and deprecated; it may cause buffer overflow. Also, in many modern compilers/environments, gets() is removed entirely, leading to a compilation error.]
    int toa=0;
    for(toa=0;toa<strlen(a)-1; ){ // @@ [Loop condition stops at strlen(a)-1, so the last character is never printed if it's not part of a '-' pattern. This causes incorrect output for trailing characters. Additionally, if the string ends with '-', accessing a[toa+1] may read beyond the string.]
        if(a[toa+1]!='-'){
            printf("%c",a[toa]);
            toa++;
        }else{
            toa++;
            if(((int)(a[toa-1])>=48&&(int)(a[toa+1])<=57&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=65&&(int)(a[toa+1])<=90&&(int)(a[toa-1])<=(int)(a[toa+1]))||((int)(a[toa-1])>=97&&(int)(a[toa+1])<=122&&(int)(a[toa-1])<=(int)(a[toa+1]))){ // @@ [Incorrect range checks: e.g., for digits, it checks a[toa-1]>=48 (correct) but a[toa+1]<=57 without ensuring a[toa+1]>=48. Similarly for letters. This allows mixed-type cases like '0-Z' to pass if numeric value conditions coincidentally hold. Also, equality (<=) allows same-character ranges like 'a-a', which should not expand per problem statement requiring the latter char to be greater.]
                for(int i=(int)(a[toa-1]);i<(int)(a[toa+1]);i++){ // @@ [This loop prints from a[toa-1] to a[toa+1]-1, but per problem, expansion of 'a-d' should output 'abcd', meaning it should start from a[toa-1]+1 and go up to a[toa+1]. However, note that the reference program does this correctly. But here, the logic is flawed because it includes the starting character again (which was already printed or will be handled incorrectly due to overall flow). Also, combined with earlier logic errors, this leads to wrong output.]
                    printf("%c",(char)i);
                }
            }else{
                printf("%c%c%c",a[toa-1],a[toa],a[toa+1]); // @@ [This prints three characters at once, but the main loop only increments toa by 1 after this block, causing the next iteration to skip a[toa+1] and potentially reprocess or miss characters. Also, if multiple '-' exist, overlapping or missed processing occurs. Moreover, if this else block runs, it prints a[toa-1] again, which might have already been printed in a previous step.]
            }
            toa++;
        }
    }
}