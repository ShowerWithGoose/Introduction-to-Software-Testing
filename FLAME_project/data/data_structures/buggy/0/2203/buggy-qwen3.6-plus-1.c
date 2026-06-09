#include<stdio.h>
#include<string.h>
int p(char a);
int main() {
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0; i<len; i++) {
        if(s[i]=='-'&&p(s[i-1])==p(s[i+1])&&s[i-1]<s[i+1]) { // @@ The condition s[i-1]<=s[i+1] allows expansion when characters are equal (e.g., a-a), which should output nothing between them, but the loop while(s[i-1]<s[i+1]) handles it correctly by not entering. However, the problem states "character after ... is greater than the one before", so strict inequality < is correct. The original code had <= which is logically slightly off for the requirement "greater than", but functionally similar here. More importantly, see below.
            while(s[i-1]<s[i+1]) {
                s[i-1]++;
                printf("%c",s[i-1]);
            }
            i+=2;
        }
        if(s[i]!='-') // @@ This if statement is executed even if the previous if block was entered and modified i. If the previous block expanded a range, i was incremented by 2. The loop then increments i again. This logic is flawed because it prints characters that might have already been processed or skips checks incorrectly. Specifically, if an expansion happens, we print the expanded chars. Then we hit this if. If s[i] (which is now the char after the range end) is not '-', it prints it. But the loop increment will move past it. The main issue is the interaction between the expansion logic and the printing logic.
        printf("%c",s[i]);
        else i--; // @@ This else belongs to the if(s[i]!='-'). If s[i] is '-', and it wasn't expanded (because the first if failed), we enter this else. i-- compensates for the loop's i++, effectively keeping i at the '-' position? No, the loop does i++. So if we are at '-', and don't expand, we print nothing? No, the first if checks for '-'. If it fails (e.g. types mismatch), we go to the second if. s[i] is '-', so s[i]!='-' is false. We go to else. i--. Then loop does i++. So i stays same. Next iteration, s[i] is still '-'. Infinite loop if '-' is not expandable.
    }
    return 0;
}
int p(char a) {
    if(a>='0'&&a<='9')
        return 0;
    else if(a>='a'&&a<='z')
        return 1;
    else return 2;
}