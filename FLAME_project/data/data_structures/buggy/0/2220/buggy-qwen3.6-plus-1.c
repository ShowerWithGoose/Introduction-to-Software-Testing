#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str);
    //printf("%c",str[3]);
    int len=strlen(str);
    //printf("%d",len);
    printf("%c",str[0]); 
    for(int i=1;i<len;i++)
    {
        if(str[i]=='-')
        {
        if(((str[i-1]-'a')>=0 )&& ((str[i-1]-'a')<=26)){ // @@ The condition `<= 26` is incorrect for checking lowercase letters 'a'-'z'. 'a'-'a' is 0, 'z'-'a' is 25. It should be `<= 25`. Also, this check alone doesn't ensure it's a lowercase letter if other characters map into this range, but primarily the bound is wrong. More importantly, the logic structure below fails to handle the "else" case correctly for mixed types or invalid ranges because the `if` blocks are sequential and not mutually exclusive in a way that prevents multiple outputs or missed outputs for the '-' character itself.
            if(((str[i+1]-'a')>=0 && (str[i+1]-'a')<=26)&&(str[i+1]>str[i-1])){ // @@ Same boundary error `<= 26` should be `<= 25`.
                
                int k;
                k=str[i+1]-str[i-1];
                int m;
                m=(str[i-1]);
                for(int v=1;v<k;v++)
                {
                    char q;
                    q=(m+v);
                    printf("%c",q);
                }
            }
            else {
                printf("%c",str[i]); // @@ This prints the '-' if the expansion condition fails for lowercase. However, if the characters are not both lowercase, this block is skipped entirely, and execution falls through to the next `if`. If none of the `if` conditions are met (e.g., mixed case like a-R), the '-' is never printed because the `else` belongs only to the inner `if` of the first block, or is missing for the others. Actually, looking closely: if the first `if` (lowercase check) is true, but the inner `if` (expansion valid) is false, it prints '-'. But if the first `if` is false (e.g. uppercase), it goes to the second `if`. If the second `if` is true but inner false, it prints '-'. If all outer `if`s are false (e.g. digit or invalid), nothing prints the '-'. This is a major logical flaw. The `else` here only applies to the immediate preceding `if`.
            }
        }
            if(((str[i-1]-'A')>=0 )&& ((str[i-1]-'A')<=26)){ // @@ Boundary error `<= 26` should be `<= 25`. Also, logical structure issue: if the first `if` was entered but didn't print '-', and this one is entered, we might print '-' again or fail to print it if this one also doesn't match. The fundamental issue is that the code assumes if one type check fails, another might succeed, but if *none* succeed (like mixed case or invalid), the '-' is lost.
            if(((str[i+1]-'A')>=0 && (str[i+1]-'A')<=26)&&(str[i+1]>str[i-1])){ // @@ Boundary error `<= 26` should be `<= 25`.
                
                int k;
                k=str[i+1]-str[i-1];
                int m;
                m=(str[i-1]);
                for(int v=1;v<k;v++)
                {
                    char q;
                    q=(m+v);
                    printf("%c",q);
                }
            }
            else {
                printf("%c",str[i]); // @@ Similar logic error. If the previous lowercase block executed its `else` and printed '-', this block might also execute its `else` and print '-' again if the char is somehow considered uppercase too (which shouldn't happen for distinct chars, but the logic is flawed). More critically, if the char is a digit, none of these outer `if`s run, and '-' is not printed.
            }
        }
            if(((str[i-1]-'0')>=0 )&& ((str[i-1]-'0')<=9)){
            if(((str[i+1]-'0')>=0 && (str[i+1]-'0')<=9)&&(str[i+1]>str[i-1])){
                
                int k;
                k=str[i+1]-str[i-1];
                int m;
                m=(str[i-1]);
                for(int v=1;v<k;v++)
                {
                    char q;
                    q=(m+v);
                    printf("%c",q);
                }
            }
            // @@ Missing else clause to print str[i] ('-') if the digit expansion condition is not met. If the previous blocks didn't print '-' (because they were false), and this block's inner if is false, '-' is never printed. This is why "0-A" results in missing '-'. The '0' is printed by the `else` at the end of the loop for the char '0', then '-' is encountered. The first `if` (lower) is false. The second `if` (upper) is false. The third `if` (digit) is true for '0', but the inner check fails because 'A' is not a digit. So nothing is printed for '-'. Then 'A' is printed in the next iteration.
        }
        }
        else{
            printf("%c",str[i]); 
        } 
    }
return 0;
}