#include<stdio.h>
#include<string.h>
int p(char a);
int main() {
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0; i<len; i++) {
        if(s[i]=='-'&&p(s[i-1])==p(s[i+1])&&s[i-1]<s[i+1]) { // @@ The condition s[i-1]<=s[i+1] allows expansion when characters are equal (e.g., a-a), which should output nothing between them, but the loop while(s[i-1]<s[i+1]) handles it correctly by not entering. However, the problem states "character after ... is greater than the one before", so strict inequality < is correct. The original code had <= which is technically allowed by the loop logic but semantically slightly off. More importantly, the next line has a logic error in printing.
            while(s[i-1]<s[i+1]) {
                s[i-1]++;
                printf("%c",s[i-1]);
            }
            i+=2;
        }
        if(s[i]!='-') // @@ This if statement is executed even if the previous if block was entered and modified i. If the previous block expanded a range, i was incremented by 2. The current character s[i] is now the character after the range end. If this character is not '-', it gets printed. This is correct for the next iteration. However, there is a subtle bug: if the expansion happened, we skipped the '-' and the end char. The loop increments i at the end of the for loop. So if we did i+=2, and then the for loop does i++, we skip 3 characters total from the start of the range? No. Let's trace: i points to '-'. We expand. We set i += 2. Now i points to the character after the end char. The for loop increments i++. So next iteration i points to the character after that. We missed printing the character after the end char if it wasn't part of another expansion? Wait. Inside the if, we print the expanded chars. We do NOT print the start char or the end char explicitly in the expansion block. The start char was printed in a previous iteration (when i was at start-1? No, when i was at start, it was printed as a normal char). Let's trace "a-c". i=0 ('a'): not '-', prints 'a'. i=1 ('-'): matches. s[0]='a', s[2]='c'. Loop: s[0] becomes 'b', prints 'b'. s[0] becomes 'c', stops. i becomes 1+2=3. Loop ends. For loop increments i to 4. End. Output: "ab". Missing 'c'. The expansion logic is flawed because it modifies the start character in place and doesn't print the final character of the range.
        printf("%c",s[i]);
        else i--;
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