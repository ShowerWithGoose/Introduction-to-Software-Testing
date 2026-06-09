#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1]; // @@ [This computes the difference between characters, but the loop below incorrectly assumes digit-like increment using ('1' - '0'), which is 1, but this only works for digits. For letters, it should just increment by 1 per character, not scaled by ('1'-'0'). However, the real issue is that the loop prints from str[i-1]+1 to str[i+1]-1, but uses a wrong step multiplier. Also, if the range is large (e.g., 'a' to 'z'), this may work numerically but the use of ('1'-'0') is misleading and unnecessary; however, the critical bug is in the loop condition and indexing logic.]
    for (int k = 1; k < c; k++) { // @@ [The loop runs while k < c, where c = str[i+1] - str[i-1]. This correctly iterates over the intermediate characters, BUT the expression str[i - 1] + k * ('1' - '0') is equivalent to str[i - 1] + k*1, which is okay numerically, but the bigger issue is that this function never prints the endpoints, which is correct per problem (since main prints non-'-' chars), BUT the main issue is that this function assumes valid input without checking bounds or type consistency beyond what's done in main. However, the actual fatal error causing wrong output is elsewhere.]
        printf("%c", str[i - 1] + k * ('1' - '0')); // @@ [Using ('1' - '0') is redundant (equals 1), but not wrong per se. However, this line is not the primary cause of the observed test failure. The real issue lies in the main loop's handling of string traversal and boundary conditions.]
    }
}

int main() {

    gets(str); // @@ [Use of gets() is unsafe and deprecated, but more importantly, in the test case input "W", there is no '-', so the loop should just print "W". However, the buggy output is "a" and expected is "r", which suggests the test case might actually be different. But given the provided test case input is "W", expected output should be "W", not "r". There seems to be a mismatch. However, assuming the test case is as stated, the real bug is likely an out-of-bound access when i=0 and str[i]=='-', but in this test case there's no '-'. Yet the program outputs "a" for input "W", which is impossible unless the input was misread. But looking closer: the actual critical bug is that when the string has no '-', the loop prints each character normally. So why output "a"? Possibly the test case isn't "W" alone. Alternatively, the real bug is in the print function's logic when called, but for input "W", print() is never called. Therefore, the issue must be elsewhere. However, note: the problem states Test Case Input: W, Buggy Output: a, Expected Output: r — this is inconsistent. But focusing on code flaws: the main bug is that when accessing str[i-1] and str[i+1], the code does not check if i-1 >=0 or i+1 < strlen(str). For example, if the string starts with '-', then i=0, and str[i-1] is str[-1] → undefined behavior. Similarly, if '-' is at the end, str[i+1] is out of bounds. This can cause crashes or garbage output. In particular, for a single character "W", the loop runs i=0, str[0]='W' != '-', so it prints 'W'. So the reported behavior doesn't match. But given the instructions, we must find errors in the code as written. The most definite error is lack of bounds checking before accessing str[i-1] and str[i+1].]
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            if (isupper(str[i - 1]) && isupper(str[i + 1])) { // @@ [No check that i-1 >= 0 and i+1 < strlen(str). If '-' is first or last character, this accesses invalid memory.]
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (islower(str[i - 1]) && islower(str[i + 1])) { // @@ [Same bounds issue: no validation that i-1 and i+1 are within string bounds.]
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (isdigit(str[i - 1]) && isdigit(str[i + 1])) { // @@ [Again, no bounds checking before accessing adjacent characters.]
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-");
                }
            } else {
                printf("-");
            }
        } else {
            printf("%c", str[i]);
        }
    }
    return 0;
}