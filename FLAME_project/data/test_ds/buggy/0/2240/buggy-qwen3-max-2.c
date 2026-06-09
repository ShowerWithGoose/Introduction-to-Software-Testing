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
    
    if(s[i+1]-s[i-1]<=0)
    k=1;
    if(k==1)
    return;
    else{
        for(int j=1;s[i+1]-s[i-1]>j;j++)
        printf("%c",s[i-1]+j); @@ [The loop condition should be `j < s[i+1] - s[i-1]` or equivalent, but more critically, the function does not print the character after the '-', and also fails to handle cases where '-' appears at the start or end of string (though test case doesn't trigger that). However, the main error causing wrong output for "B-e" is that the type check passes one side as uppercase and the other as lowercase, but the current logic checks each side independently without ensuring both are same type. For "B-e": 'B' is uppercase, 'e' is lowercase — they are different types, so expansion should not happen. But in the code, the first condition checks if both are lowercase — false; second checks both digits — false; third checks both uppercase — 'e' is not uppercase, so false. So k remains 1, and function returns without printing '-'. However, the calling loop already skipped printing '-', and fk() prints nothing, so '-' is omitted entirely, leading to "Be" instead of "B-e". The core issue is that when expansion is not performed, the '-' should still be printed, but the design of main() only prints non-'-' characters, and fk() prints nothing when not expanding, thus dropping the '-'.]
    }
}