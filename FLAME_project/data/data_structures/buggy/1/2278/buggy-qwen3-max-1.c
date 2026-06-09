#include<stdio.h>
#include<string.h>
char a[85];
char b[85];
int main()
{
    scanf("%s",&a); // @@ [The problem expects an integer N as input, but this code reads a string into 'a'. It should read an integer using %d and an int variable, not %s into a char array.]
    scanf("%s",&b); // @@ [This line is completely unnecessary for the problem. The problem only requires one integer input N, but this tries to read a second string, which doesn't exist in the input.]
    int l1=strlen(a); // @@ [Since 'a' was read as a string, l1 becomes the number of digits in N, not N itself. For example, if input is "1", l1=1 (which accidentally works), but if input were "10", l1=2 instead of 10, leading to wrong behavior. However, the bigger issue is that the entire approach is wrong: it should use integer N directly, not its string length.]
    int l2=strlen(b); // @@ [This is meaningless because 'b' is uninitialized or contains garbage; also, the problem does not require a second input.]
    {
        
    } // @@ [The main logic to generate permutations is entirely missing. This empty block does nothing, so no output is produced, causing Wrong Answer.]
}