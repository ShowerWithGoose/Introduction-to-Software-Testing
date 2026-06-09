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
    
    if(s[i+1]-s[i-1]<=0) // @@ [This condition incorrectly handles the case when the difference is 0 (e.g., "a-a"), which should not be expanded, but the logic sets k=1 and returns, which is correct. However, the condition should also handle the case when the character after '-' is less than the one before, which is already covered by <=0. The real issue is that the expansion loop below uses `s[i+1]-s[i-1]>j` which will not print the last character (e.g., for "a-d", it prints 'b' and 'c' but not 'd'), missing the final character in the expansion.]
    k=1;
    if(k==1)
    return;
    else{
        for(int j=1;s[i+1]-s[i-1]>j;j++) // @@ [The loop condition should be `s[i+1]-s[i-1]>=j` to include the last character in the expansion. For example, "a-d" should output 'b', 'c', 'd', but this loop only outputs 'b' and 'c'.]
        printf("%c",s[i-1]+j);
    }
}