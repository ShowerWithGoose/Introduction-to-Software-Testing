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
        printf("%c",s[i-1]+j); @@ [The loop condition should be `j < s[i+1] - s[i-1]` or equivalent, but more critically, the function does not print the character after the dash (e.g., 'e' in a-e), and also fails to handle cases where expansion should not occur due to mixed types (like B-e) because the type checks are incomplete — they don't ensure both characters are of the same category. For input "B-e", 'B' is uppercase and 'e' is lowercase, so expansion should not happen, but current logic sets k=0 only if both are in the same group; however, the conditions are written such that if one is uppercase and the other lowercase, none of the if-blocks trigger, so k remains 1, which correctly skips expansion. But wait: in "B-e", s[i-1]='B' (>= 'A' and <= 'Z'), s[i+1]='e' (>= 'a' and <= 'z'), so none of the three conditions are fully satisfied, so k stays 1, and function returns without printing '-', which causes the '-' to be omitted. The main loop prints non-'-' chars directly, and for '-', it calls fk(i) which may return without printing anything, thus dropping the '-'. Hence, the '-' is lost in output when no expansion occurs.]
    }
}