#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];

int main()
{
    scanf("%s",&s);

    for(int i=0;i<strlen(s);i++){
        int a=0;
        if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')a+=0;else a+=1; // @@ [Logic error: This condition checks only lowercase, but adds 0 if true, else 1. However, the following two conditions have incorrect bounds and logic.]
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ [Incorrect condition: 's[i+2]<='Z'' is written before ensuring 's[i+2]>='A'', and also 's[i]>='A'' is redundant; more critically, it should check both s[i] and s[i+2] are uppercase, but the order of conditions may cause undefined behavior if i+2 is out of bounds. Also, this line has a typo: it checks s[i+2]<='Z' twice and misses checking s[i]<='Z'.]
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ [Incorrect condition: 's[i]+2>='0'' is meaningless; should be 's[i]<='9''. Also, doesn't verify s[i] is a digit properly.]
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ [Condition 'a!=3' is flawed because a counts how many type checks failed; but due to earlier logic errors, a may not reflect correct type matching. Also, the bound check 'i+2<strlen(s)' is placed too late—previous lines already access s[i+2] without ensuring i+2 is valid, causing potential buffer overread.]
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){ // @@ [Loop prints from s[i] to s[i+2] inclusive, but problem requires expansion like a-c → abc (i.e., up to but not including the end? Actually, example shows a-d → abcd, so inclusive of end. However, reference program prints up to s[i+2]-1. But expected output for a-c-g is abcdefg, meaning a-c → abc, then c-g → cdefg, so overall abcdefg. So this loop is correct in being inclusive. However, the real issue is that after expanding a-c, the next character is '-', but the code skips to i+2, so after processing a-c (i=0), i becomes 2, then loop increments to 3, which is 'g', so '-g' is not processed as part of a new range. But in input "a-c-g", after expanding a-c, we should continue and see c-g. However, the current code consumes three characters (a, -, c) and sets i+=2, so next i is 3 (pointing to '-'), but then loop increments i to 4, skipping the '-' between c and g. So the logic fails to chain expansions. But more fundamentally, the type-checking logic is broken.]
                printf("%c",put+j);
            }i+=2;


        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}