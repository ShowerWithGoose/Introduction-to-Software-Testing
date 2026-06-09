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
    
    if(s[i+1]-s[i-1]<=0) // @@ [Error: This condition incorrectly sets k=1 when the characters are equal or reversed, but it should also handle the case where the difference is 1 (e.g., "a-b"), which should not output anything between them. The reference program uses s[i-1]+j != s[i+1] as the loop condition, which correctly handles this by not entering the loop when the difference is 1. Here, the condition s[i+1]-s[i-1]<=0 sets k=1 for equal or reversed, but for difference 1, k remains 0 and the loop runs with j starting at 1, but the condition s[i+1]-s[i-1]>j (i.e., 1>1) is false, so no output occurs, which is correct. However, the logic is fragile and differs from the reference.]
    k=1;
    if(k==1)
    return;
    else{
        for(int j=1;s[i+1]-s[i-1]>j;j++) // @@ [Error: The loop condition uses > instead of !=, which may cause incorrect behavior for edge cases. The reference program uses s[i-1]+j != s[i+1] to ensure it stops exactly before the end character. Using > might skip characters if the difference is negative (though that case is already handled by the previous check), but more importantly, it does not match the reference logic and could lead to off-by-one errors in some scenarios.]
        printf("%c",s[i-1]+j);
    }
}