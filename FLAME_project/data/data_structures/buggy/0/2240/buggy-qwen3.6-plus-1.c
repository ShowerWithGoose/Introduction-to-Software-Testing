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
    // @@ The function fk is called when '-' is encountered. If expansion is valid, it prints the intermediate characters. However, it does NOT print the '-' itself or the surrounding characters if expansion is INVALID. In the main loop, when '-' is found, fk(i) is called. If fk returns without printing anything (because k==1), the '-' and the context are lost from output because the main loop only prints non-'-' characters directly. Wait, looking at main: if(s[i]!='-') printf... else fk(i). So if fk(i) decides NOT to expand, it returns void. The '-' is never printed. The previous char was already printed by the previous iteration of the loop. The next char will be printed by the next iteration. But the '-' itself is skipped.
}
// To fix: If expansion is not performed, the '-' must be printed.
// Let's re-evaluate line 28-30.
// If k==1, we return. But we should have printed the '-'.
// The structure of main prevents printing '-' easily inside fk if we just return.
// We need to print '-' if no expansion occurs.

// Let's look at the specific failure: Input "B-e".
// 'B' is printed by main.
// '-' is encountered. fk(1) is called.
// Inside fk:
// s[0]='B', s[2]='e'.
// Check 1: 'B' is not lowercase. k remains 1.
// Check 2: 'B' is not digit. k remains 1.
// Check 3: 'B' is uppercase, 'e' is not uppercase. k remains 1.
// Check 4: s[2]-s[0] > 0. k remains 1.
// if(k==1) return; -> Returns without printing anything.
// Main loop continues.
// 'e' is printed by main.
// Output: "Be".
// Expected: "B-e".
// The error is that when expansion is invalid, the '-' character is not output.

void fk_corrected_logic_needed(int i) {
    // This is just analysis, not changing code yet.
}

// The fix should be in fk. If k==1, we must print '-'.
// Or, change main to handle it. But instructions say annotate errors in provided code.
// The error is logically in fk: it fails to output the delimiter when expansion is skipped.

// Let's annotate the return statement or the logic block.

// Actually, I can only add @@ to existing lines.

// Line 30: return; @@ When expansion is invalid (k==1), the function returns without printing the '-' character, causing it to be missing from the output. It should print '-' before returning.