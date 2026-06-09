#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];

int main()
{
    scanf("%s",&s); // @@ Incorrect argument type for %s; should pass s instead of &s to match char* expected by scanf.

    for(int i=0;i<strlen(s);i++){
        int a=0;
        if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')a+=0;else a+=1; // @@ Accesses s[i+2] without bounds checking, risking out-of-bounds read when i is near the end of the string.
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ Logical error: checks s[i]>='A' and s[i+2]<='Z' twice, missing s[i]<='Z' and s[i+2]>='A', causing incorrect uppercase range validation.
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ Typo: s[i]+2 should be s[i+2]; incorrectly adds 2 to the character value instead of accessing the array index.
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ Out-of-bounds access: s[i+1] and s[i+2] are evaluated before checking i+2<strlen(s), which must be checked first to prevent invalid memory access.

            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){ // @@ Off-by-one error: j<= causes printing one extra character beyond the intended range; should use j< to correctly match the expansion logic.
                printf("%c",put+j);
            }i+=2;


        } else printf("%c",s[i]);

    }


    system("pause");
    return 0;
}