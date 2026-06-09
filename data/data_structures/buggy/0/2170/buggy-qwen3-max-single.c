#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char s[100000];
    int j=0;
    gets(s); // @@ [Using `gets` is unsafe and deprecated; however, the primary error causing test failure is logic-related, not compilation. But note: the reported error was "gcc: not found", which is environment-related, not code-related. However, assuming the real issue is logical bugs leading to wrong output, we analyze logic errors below.]
    int l=strlen(s);
    printf("%c",s[0]);
    for(int i=1;i<l;i++){
        if(s[i]=='-'){
            if(s[i-1]>=48&&s[i-1]<=57&&s[i+1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++; // @@ [Incrementing `i` here skips the next character after '-', but if multiple conditions match (e.g., digit and letter ranges accidentally), it may cause incorrect skipping or double processing. Also, using separate `if`s instead of `else if` can cause overlapping expansions.]
            }
            if(s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ [This should be `else if`; otherwise, after handling digits, it may incorrectly also handle uppercase if conditions coincidentally met (though unlikely due to ASCII ranges, it's logically flawed). More critically, if the first `if` doesn't match, this runs independently, but then the final `else` only applies to this last `if`, not the whole group.]
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++; // @@ [Same issue: incrementing `i` here without ensuring prior conditions didn't already handle it leads to potential double increment or missed characters.]
            }
            if(s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ [Should be `else if`; same structural flaw. The `else` below only pairs with this `if`, so if any earlier `if` matched and expanded, but this one doesn't, the `else` won't trigger, yet the '-' was already handled — but actually, the bigger issue is that if none of the three `if`s match, only then should we print '-'. However, because they are independent `if`s, the `else` only covers the last condition.]
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++; // @@ [Same problem: inconsistent control flow due to missing `else if` chain.]
            }
            else printf("%c",s[i]); // @@ [This `else` only corresponds to the last `if` (lowercase check). So if input is like 'a-5', the digit check fails, uppercase fails, lowercase fails → `else` prints '-'. But if input is '5-a', digit check fails, uppercase fails, lowercase check: '5' is not >=97, so fails → `else` prints '-'. That seems okay. However, consider 'A-d': digit fails, uppercase: 'd' is not <=90 → fails, lowercase: 'A' is not >=97 → fails → `else` prints '-'. Correct. BUT: what if the string ends with '-'? Then `s[i+1]` is out of bounds → undefined behavior. Also, when `i == l-1`, `s[i+1]` accesses beyond string. This causes crash or garbage.]
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}