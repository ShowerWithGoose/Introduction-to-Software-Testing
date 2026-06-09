#include<stdio.h>
#include<string.h>
int p(char a);
int main() {
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0; i<len; i++) {
        if(s[i]=='-'&&p(s[i-1])==p(s[i+1])&&s[i-1]<=s[i+1]) { // @@ [The condition should require s[i-1] < s[i+1], not <=, because expansion is only done when the character after '-' is greater than the one before it. Also, this check accesses s[i-1] and s[i+1] without verifying that i>0 and i+1<len, leading to out-of-bounds access for strings starting or ending with '-'.]
            while(s[i-1]<s[i+1]) { // @@ [This loop modifies s[i-1] in place, which corrupts the original string and affects subsequent comparisons. It also prints intermediate characters but doesn't handle the full expansion correctly in context of the whole string.]
                s[i-1]++;
                printf("%c",s[i-1]);
            }
            i+=2; // @@ [Skipping ahead by 2 may skip necessary characters or cause misalignment, especially since the string has been modified during expansion.]
        }
        if(s[i]!='-')
        printf("%c",s[i]); // @@ [This prints the current character if it's not '-', but due to prior modifications and index manipulations, it may print incorrect or duplicate characters, or miss some. Also, when a valid expansion occurs, the character before '-' (s[i-1]) was already printed inside the while loop, so printing s[i] (which could be the next character after '-') may lead to duplication or omission.]
        else i--; // @@ [Decrementing i when encountering an unexpanded '-' causes the loop to reprocess the same '-' again, potentially leading to infinite loops or incorrect output. Moreover, unexpanded '-' should just be printed as-is, but the logic here disrupts the control flow.]
    }
    return 0;
}
int p(char a) {
    if(a>='0'&&a<='9')
        return 0;
    else if(a>='a'&&a<='z')
        return 1;
    else return 2; // @@ [This returns 2 for uppercase letters and any other character. However, the problem states that only [a-z], [A-Z], and [0-9] should be processed. For non-alphanumeric characters, p() still returns 2, which may incorrectly allow expansions like between two symbols if they both return 2, violating the requirement. Also, uppercase letters are not handled distinctly from other non-lowercase/non-digit chars in the caller logic because the condition only checks equality of p() values, not whether they belong to valid same-type ranges.]
}