#include<stdio.h>
#include<string.h>
int p(char a);
int main() {
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0; i<len; i++) {
        if(s[i]=='-'&&p(s[i-1])==p(s[i+1])&&s[i-1]<=s[i+1]) { @@ [Accesses s[i-1] and s[i+1] without checking bounds; when i=0, s[i-1] is out of bounds, and when i=len-1, s[i+1] is out of bounds. Also, condition should be s[i-1] < s[i+1], not <=, per problem requirements.]
            while(s[i-1]<s[i+1]) { @@ [Modifies s[i-1] which affects future comparisons; also prints one extra character beyond the correct range (should stop before s[i+1]).]
                s[i-1]++;
                printf("%c",s[i-1]);
            }
            i+=2; @@ [Skipping ahead by 2 may cause missed characters or out-of-bounds access, especially if '-' is at the end or near boundaries.]
        }
        if(s[i]!='-')
        printf("%c",s[i]);
        else i--; @@ [Decrementing i inside loop can cause infinite loop or reprocessing same character, especially when '-' is not expanded.]
    }
    return 0;
}
int p(char a) {
    if(a>='0'&&a<='9')
        return 0;
    else if(a>='a'&&a<='z')
        return 1;
    else return 2; @@ [Returns 2 for uppercase letters AND any other character (like '-', symbols), which causes incorrect type matching (e.g., 'A' and '-' both return 2, leading to false expansion).]
}