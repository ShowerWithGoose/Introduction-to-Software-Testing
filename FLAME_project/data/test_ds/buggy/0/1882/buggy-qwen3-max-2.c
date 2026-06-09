#include <stdio.h>
#include <ctype.h>
int main() {
    char s[1145];
    scanf("%s",&s); // @@ [The program uses hardcoded outputs based only on the first character, completely ignoring the actual expansion logic required by the problem. It does not process the string dynamically or handle ranges correctly.]
    if(s[0]=='a') // @@ [This condition assumes that any input starting with 'a' should produce a fixed output, which is incorrect. The correct behavior depends on the full pattern (e.g., a-c-g0-A), not just the first character.]
    {
        if(s[1]=='-') // @@ [Even this nested check is insufficient; it doesn't parse or expand multiple ranges like "a-c" and "c-g", nor does it handle invalid expansions like "g0" or "0-A".]
        printf("abcdefghijklmnopqrstuBCDEF"); // @@ [This output is completely wrong for input "a-c-g0-A"; it expands far beyond 'g' and incorrectly processes non-matching ranges like "0-A" as uppercase letters.]
        else printf("abcdefg0-A"); // @@ [This branch is unreachable for the given test case since s[1] is '-', but even if reached, it's still a hardcoded guess, not a proper expansion.]
    }
    else  if(s[0]=='d') // @@ [Hardcoded response for inputs starting with 'd'; no actual parsing or expansion logic exists in the program.]
        printf("dcu012345678"); // @@ [Arbitrary output with no relation to proper range expansion rules.]
    else  if(s[0]=='B') // @@ [Same issue: hardcoded output instead of implementing the specification.]
        printf("B-e"); // @@ [Fails to expand or validate "B-e" (which should not expand because B is uppercase and e is lowercase), yet outputs it unchanged — but only because it's hardcoded, not due to correct logic.]
    else  if(s[0]=='t') // @@ [Another hardcoded case with no general solution.]
        printf("toooold08A-a"); // @@ [No relation to the problem's expansion rules; clearly just matching expected outputs for hidden test cases without real implementation.]
    return 0;
}