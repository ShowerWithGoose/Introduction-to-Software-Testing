#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    
    for(int i=0;s[i]!='\0';i++)
    {
    
            if(s[i+1]-s[i-1]<26&&(s[i+1]-s[i-1]>=0)&&s[i]=='-') // @@ [This condition is flawed: it assumes all valid ranges have difference <26, which fails for digits (e.g., '0'-'9' has diff 9 but is valid), and doesn't check character types match (e.g., allows 'a'-'Z'). Also accesses s[i-1] when i=0 causing undefined behavior.]
            {
                for(int q=1;q<s[i+1]-s[i-1];q++) // @@ [Loop condition uses difference directly without verifying character categories are same; also prints expansion even for invalid cross-category cases like '0'-'A'.]
                {
                    printf("%c",(char)(s[i-1]+q));
                }
                
            }
        
        else
        printf("%c",s[i]); // @@ [Fails to handle '-' correctly in invalid cases: when '-' is not part of a valid expansion, it should print the '-', but this code only prints s[i] (which is '-') in the else branch. However, due to incorrect condition above, some invalid '-' may be skipped or misprocessed. Also, when i points to a character that is part of an expansion (like 'a' in "a-c"), it prints it normally, but then the '-' triggers expansion — this leads to double-printing of boundary characters or missing '-'. Specifically, in "a-c", 'a' is printed in else, then '-' triggers printing 'b', then 'c' is printed later — which is correct for that part. But the main issue is the lack of type checking and unsafe array access.]
    }

    return 0;
}