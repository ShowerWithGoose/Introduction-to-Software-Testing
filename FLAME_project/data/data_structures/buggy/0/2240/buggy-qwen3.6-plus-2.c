#include<stdio.h>

char s[1025] = {'\0'};

void fk(int i);

int main(){
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!='-') printf("%c",s[i]);
        else fk(i);
    }
    return 0;
}

void fk(int i)
{
    int k=1;
    if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a')
    k=0;
    else if(s[i-1]<='9'&&s[i+1]<='9'&&s[i-1]>='0'&&s[i+1]>='0')
    k=0;
    else if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A')
    k=0;
    
    if(s[i+1]-s[i-1]<=0) // @@ The condition checks if the end character is not greater than the start character. If true, it sets k=1 (invalid). However, this check happens AFTER the type checks. If types don't match, k remains 1. If types match but order is wrong, k becomes 1. This logic is actually correct for invalidating expansion. The error lies elsewhere.
    k=1;
    if(k==1)
    return;
    else{
        for(int j=1;s[i+1]-s[i-1]>j;j++)
        printf("%c",s[i-1]+j);
    }
    // @@ Missing output of the '-' character and the end character when expansion is NOT performed. 
    // The problem states: "For other cases ... no expansion is performed, and the input is output unchanged."
    // Currently, if k==1, the function returns without printing anything. The main loop already skipped printing '-'.
    // So for "B-e", main prints 'B', calls fk(1). fk sees types don't match (B is upper, e is lower), so k stays 1. Returns.
    // Main loop continues. Next char is 'e'. Main prints 'e'. Output "Be".
    // Expected: "B-e".
    // The issue is that when expansion is NOT performed, we must output the '-' and the following character(s) as they are.
    // But the main loop skips printing '-'. And fk() doesn't print it either if it returns early.
    // Also, fk() doesn't print the end character s[i+1] in the expansion case? 
    // Let's look at the expansion loop: for(j=1; s[i+1]-s[i-1]>j; j++) printf("%c", s[i-1]+j);
    // If range is a-c: s[i-1]='a', s[i+1]='c'. Diff=2. j=1: 2>1 true, print 'b'. j=2: 2>2 false. Stop.
    // It prints 'b'. It does NOT print 'c'. The main loop will eventually print 'c' when i advances to i+1?
    // In main: i points to '-'. fk(i) is called. Inside fk, we look at s[i-1] and s[i+1].
    // After fk returns, main loop increments i. So next iteration i points to s[i+1] (the end char).
    // So if expansion happens, fk prints the middle chars. Main loop later prints the end char. This seems okay for expansion.
    // BUT, if expansion DOES NOT happen, fk returns without printing anything. The '-' was skipped by main. The end char will be printed by main in the next iteration.
    // So we are missing the '-' in the output when expansion fails.
    // To fix: if k==1, we should print '-' and then return? Or just print '-'?
    // If we print '-' in fk when k==1, then for "B-e": main prints 'B'. fk prints '-'. Main next iter prints 'e'. Result "B-e". Correct.
    // What about valid expansion "a-c"? main prints nothing for 'a' yet? No, main loop: i=0 ('a'), prints 'a'. i=1 ('-'), calls fk. fk prints 'b'. Returns. i=2 ('c'), prints 'c'. Result "abc". Correct.
    // So the fix is: when k==1 (expansion invalid), print the '-' character.
}